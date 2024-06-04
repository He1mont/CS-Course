# Created by Ziling Wu
# Supervised by Dr Armaghan Moemeni
# Last Updated: December 4th, 2023

import cv2
import numpy as np
import random
from tqdm import tqdm


class Region:
    """
    class for a sub-region (a segmentation)
    """

    def __init__(self, coords, slice):
        """
        :param coords: coordinates of piexels in the region
        :param slice: an image slice of the region
        """
        self.coords = coords
        self.slice = slice
        # obtain the mean pixel value of the region
        self.mean = np.mean(self.slice)
        # obtain the standard deviation of the region
        self.std = np.std(slice)
        # initialize edges connected to the neighbour of the region
        self.edges = []
        # initialize an index for the region
        self.index = None

    def split(self):
        """
        divide the region to four sub-regions
        :return: four sub-regions
        """

        def adjacent(bbox1, bbox2):
            """
            judge if two bounding boxes are adjacent
            :param bbox1: bounding box of the first region, [xmin. ymin, xmax, ymax]
            :param bbox2: bounding box of the second region, [xmin. ymin, xmax, ymax]
            :return:
            """
            xmin1, ymin1, xmax1, ymax1 = bbox1
            xmin2, ymin2, xmax2, ymax2 = bbox2
            return xmin1 == xmax2 or xmax1 == xmin2 or ymin1 == ymax2 or ymax1 == ymin2

        def connectSubregion2Neighbour(subregion):
            """
            connect subregion to the region's neighbours
            :param subregion:
            :return:
            """
            # traver edges connected to the regions' neighbours
            for edge in self.edges:
                # obtain a neighbour
                neighbour = edge.queryNeighbouor(self)
                # obtain the bbox of the neighbour and the subregion
                bbox1, bbox2 = neighbour.returnBbox(), subregion.returnBbox()
                # judge if the neighbour is next to the subregion
                if adjacent(bbox1, bbox2):
                    # create a new edge to connect the neighbour and the subregion
                    new_edge = Edge(neighbour, subregion)
                    # put the new edge in the neighbour's edges
                    neighbour.edges.append(new_edge)
                    subregion.edges.append(new_edge)

        # obtain the height and width of the region
        height, width = self.slice.shape
        # obtain the meshgrid for the region
        meshgrid = self.coords.reshape(2, height, width)
        # obtain the coordinates for the four sub-regions
        coord_left_top = meshgrid[:, :height // 2, :width // 2].reshape(2, -1)
        coord_right_top = meshgrid[:, :height // 2, width // 2:].reshape(2, -1)
        coord_left_bottom = meshgrid[:, height // 2:, :width // 2].reshape(2, -1)
        coord_right_bottom = meshgrid[:, height // 2:, width // 2:].reshape(2, -1)
        # obtain the image slice for each sub-region
        slice_left_top = self.slice[:height // 2, :width // 2]
        slice_right_top = self.slice[:height // 2, width // 2:]
        slice_left_bottom = self.slice[height // 2:, :width // 2]
        slice_right_bottom = self.slice[height // 2:, width // 2:]
        # create sub-regions
        left_top = Region(coord_left_top, slice_left_top)
        right_top = Region(coord_right_top, slice_right_top)
        left_bottom = Region(coord_left_bottom, slice_left_bottom)
        right_bottom = Region(coord_right_bottom, slice_right_bottom)
        # create edges between each sub-region
        left_top2left_bottom = Edge(left_top, left_bottom)
        right_top2right_bottom = Edge(right_top, right_bottom)
        left_top2right_top = Edge(left_top, right_top)
        left_bottom2right_bottom = Edge(left_bottom, right_bottom)
        # connect each subregion
        left_top.edges = [left_top2right_top, left_top2left_bottom]
        right_top.edges = [left_top2right_top, right_top2right_bottom]
        left_bottom.edges = [left_bottom2right_bottom, left_top2left_bottom]
        right_bottom.edges = [left_bottom2right_bottom, right_top2right_bottom]
        # connect each subregion with current-region's neighbours
        connectSubregion2Neighbour(left_top)
        connectSubregion2Neighbour(right_top)
        connectSubregion2Neighbour(left_bottom)
        connectSubregion2Neighbour(right_bottom)
        # remove the connection between the region and its neighbours
        for edge in self.edges:
            # obtain a neighbour
            neighbour = edge.queryNeighbouor(self)
            # remove the edge of current region from the neighbour's edge
            neighbour.edges.remove(edge)
        # return subregions
        return left_top, right_top, left_bottom, right_bottom

    def returnBbox(self):
        """
        return the bounding box of the region
        :return:
        """
        xmin = self.coords[0, 0]
        ymin = self.coords[1, 0]
        xmax = self.coords[0, -1] + 1
        ymax = self.coords[1, -1] + 1
        return xmin, ymin, xmax, ymax


class Edge:
    """
    a class for edge
    """

    def __init__(self, left, right):
        self.left = left  # one region connected by the edge
        self.right = right  # another region connected by the edge
        self.weight = 0  # the weight of the edge, initially 0
        # initialize weight
        self.calculateWeight()

    def calculateWeight(self):
        """
        calculate the weight of the edge
        :return:
        """
        self.weight = abs(self.left.mean - self.right.mean)

    def queryNeighbouor(self, query):
        """
        return neighbour of the query connected by the edge
        :param query:
        :return:
        """
        return self.right if query == self.left else self.left


class SplitMergeMaster:
    """
    the algorithm for split&merge
    """
    def __init__(self, image, split_thresh=14, merge_thresh=17):
        """
        :param image: image to be segmented
        :param split_thresh: the threshold for split
        :param merge_thresh: the threshold for merge
        """
        self.image = image.copy()
        self.split_thresh = split_thresh
        self.merge_thresh = merge_thresh
        # initialize the meshgrid of the image
        self.meshgrid = np.stack(np.meshgrid(np.arange(image.shape[1]), np.arange(image.shape[0])), axis=0).reshape(2, -1)
        # initialize the graph
        self.regions = []
        self.edges = []

    def _split(self):
        """
        split
        :return:
        """
        # initialize the region whose area is the whole image
        regions = [Region(self.meshgrid, self.image)]
        # split
        while len(regions) != 0:
            # obtain a region to split
            region = regions.pop()
            # judge if the region can be split
            if region.std >= self.split_thresh and region.slice.shape[0] > 1 and region.slice.shape[1] > 1:
                # split the region and obtain subregions
                left_top, right_top, left_bottom, right_bottom = region.split()
                # put the subregions in the waiting list to be visited
                regions.extend([left_top, right_top, left_bottom, right_bottom])
            else:
                # a minimal region is found
                # initialize index of the region
                region.index = len(self.regions)
                self.regions.append(region)
        # obtain all edges of the graph
        for region in self.regions:
            self.edges.extend(region.edges)
        # remove duplicated edges
        self.edges = list(set(self.edges))

    def _merge2regions(self, region1, region2, current_edge):
        """
        merge two regions by adding region2 to region 1
        :param region1:
        :param region2:
        :param current_edge: edge connecting these two regions
        :return:
        """
        # update combine region1 and region2's coordinates
        region1.coords = np.hstack([region1.coords, region2.coords])
        # update region1's mean value
        region1.mean = (np.sum(self.image[region1.coords[1, :], region1.coords[0, :]]) + np.sum(self.image[region2.coords[1, :], region2.coords[0, :]])) / (region1.coords.shape[1] + region2.coords.shape[1])
        # update weights of edges connected to these two regions
        for edge in region2.edges:
            # connect the edge from region2 to region1
            if edge.left == region2:
                edge.left = region1
            if edge.right == region2:
                edge.right = region1
            # update weight of the edge
            edge.calculateWeight()
        region1.edges.extend(region2.edges)
        region1.edges = list(set(region1.edges))
        # remove region2 from all regions
        self.regions[region2.index] = None

    def segmentation(self):
        """
        conduct split and merge segmentation
        :return:
        """
        # split
        self._split()

        # merge
        while True:
            # sort edges where edges' weights are organized in ascending order
            self.edges.sort(key=lambda x: x.weight)
            # initialize a sign to indicate if the segmentation is over
            no_more_change = True
            # traverse each edge to see if any two regions can be merged
            for edge in self.edges:
                # merge when the edge connects two disjoint regions and its weight is less than the threshold
                if edge.left != edge.right and edge.weight <= self.merge_thresh:
                    no_more_change = False
                    # merge
                    self._merge2regions(edge.left, edge.right, edge)
                    break
            # break if no more regions are merged
            if no_more_change:
                break

        # obtain the segmentation result
        masks = []  # segmented masks
        for region in self.regions:
            if region is not None:
                # create a mask for the segmented region
                mask = np.zeros(self.image.shape, dtype=np.uint8)
                mask[region.coords[1, :], region.coords[0, :]] = 1
                masks.append(mask)
        # return all segmented masks
        masks.sort(reverse=True, key=lambda x: np.sum(x))
        return np.stack(masks, axis=0)

    @staticmethod
    def visualization(masks):
        """
        visualize the segmentation results and the image
        :param masks: masks segmented
        :return:
        """
        # obtain the number of colours
        colour_num = min(100, masks.shape[0])
        # generate random colours along each channel
        R = random.sample(list(range(256)), colour_num)
        G = random.sample(list(range(256)), colour_num)
        B = random.sample(list(range(256)), colour_num)
        # initialize an empty tensor to represent the visualization map
        visual_map = np.zeros((masks.shape[1], masks.shape[2], 3), dtype=np.uint8)
        # visualization
        for i in range(colour_num):
            visual_map[masks[i] == 1] = [R[i], G[i], B[i]]
        # return the visualization map
        return visual_map

if __name__ == "__main__":
    # read the image
    image = cv2.imread("Tree.tif", cv2.IMREAD_GRAYSCALE)
    image = cv2.resize(image, (int(0.4 * image.shape[1]), int(0.4 * image.shape[0])), cv2.INTER_AREA)
    # segmentation
    split_merge = SplitMergeMaster(image=image, split_thresh=14, merge_thresh=20)
    masks = split_merge.segmentation()

    # visualization
    canvas = split_merge.visualization(masks=masks)
    cv2.imshow("image", image)
    cv2.imshow("masks", canvas)
    cv2.waitKey(0)
    cv2.destroyAllWindows()