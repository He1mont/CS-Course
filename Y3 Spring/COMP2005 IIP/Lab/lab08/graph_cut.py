# Created by Ziling Wu
# Supervised by Dr Armaghan Moemeni
# Last Updated: December 4th, 2023


import math
import cv2
import numpy as np
from tqdm import tqdm


class Edge:
    """
    a class for edge
    """

    def __init__(self, _from, to):
        self._from = _from  # vertex the edge starts from
        self.to = to  # vertex the edge ends to
        self.weight = 0  # the weight of the edge, initially 0
        # parameters for max flow
        self.capacity = 0  # capacity of this link

    def calculateWeight(self, beta, K=None, dist_bkg=None, dist_obj=None):
        """
        calculate the weight of the edge
        :param beta: weight for n-link cost
        :param K: weight for t-link ground truth
        :param dist_bkg: colour distribution for background
        :param dist_obj: colour distribution for object(foreground)
        :return:
        """
        # calculate weight for n-link
        if self._from.isTerminal is not True and self.to.isTerminal is not True:
            self.weight = 50 * math.exp(-(self._from.pixel_value - self.to.pixel_value) ** 2 / beta) / \
                          math.sqrt((self._from.row - self.to.row) ** 2 + (self._from.col - self.to.col) ** 2)
        # calculate weight for t-link
        elif self._from.isTerminal:
            # edge from source to pixel
            if self.to.label is None:
                # the pixel has not been assigned to a label
                self.weight = - math.log(0.00000001 + dist_bkg[int(self.to.pixel_value)])
            elif self.to.label == 1:
                # the pixel is assigned to foreground
                self.weight = K
            elif self.to.label == 0:
                # the pixel is assigned to background
                self.weight = 0
        elif self.to.isTerminal:
            # edge from pixel to sink
            if self._from.label is None:
                # the pixel has not been assigned to a label
                self.weight = - math.log(0.00000001 + dist_obj[int(self._from.pixel_value)])
            elif self._from.label == 1:
                # the pixel is assigned to foreground
                self.weight = 0
            elif self._from.label == 0:
                # the pixel is assigned to background
                self.weight = K
        # update capacity
        self.capacity = self.weight


class Vertex:
    """
    a class for a pixel, which is represented as a vertex in the graph
    """

    def __init__(self, pixel_value=None, row=None, col=None, label=None, isTerminal=False):
        self.pixel_value = pixel_value  # the pixel value of the vertex
        self.label = label  # the assignment of the pixel: 0->background, 1->foreground(object)
        self.isTerminal = isTerminal  # terminals indicator
        # initialize the coordinate of the pixel
        self.row = row  # the index of row
        self.col = col  # the index of col
        self.edges = {}  # out link edges
        # parameters for max flow
        self.tree = None
        self.parent = None
        self.isActive = False


class GraphCut:
    """
    implementation of graph cut
    """

    def __init__(self, image, dist_bkg, dist_obj, prior_bkg, prior_obj):
        """
        :param image: image to be segmented
        :param dist_bkg: colour distribution for background
        :param dist_obj: colour distribution for object(foreground)
        :param prior_bkg: prior pixels of background
        :param prior_obj: prior pixels of object(foreground)
        :return:
        """
        self.image = image
        # obtain the size of the image
        self.row = image.shape[0]
        self.col = image.shape[1]
        # initialize colour distribution
        self.background_distribution = dist_bkg
        self.foreground_distribution = dist_obj
        # initialize prior pixels
        self.prior_bkg = prior_bkg
        self.prior_obj = prior_obj
        # initialize weight for n-links
        self.beta = 0
        # initialize weight fot t-link ground truth
        self.K = 0
        # a list storing all vertices
        self.vertices = []
        # initialize edges
        self.edges = []
        # source node that indicates foreground
        self.source = Vertex(isTerminal=True)
        # sink node that indicates background
        self.sink = Vertex(isTerminal=True)
        # initialize graph
        self._initialize_graph()

    def _initialize_graph(self):
        # transfer each pixel into vertex
        for i in tqdm(range(self.row), desc="Initializing nodes: "):
            row = []
            for j in range(self.col):
                # add a new vertex
                if (i, j) in self.prior_bkg:
                    # this pixel is assigned as background by the user
                    vertex = Vertex(self.image[i, j], i, j, label=0)
                elif (i, j) in self.prior_obj:
                    # this pixel is assigned as foreground by the user
                    vertex = Vertex(self.image[i, j], i, j, label=1)
                else:
                    # the pixel is not assigned by the user
                    vertex = Vertex(self.image[i, j], i, j)
                row.append(vertex)
            self.vertices.append(row)
        # initialize n-link edges
        sigmas = []  # list for calculating beta
        for i in tqdm(range(self.row), desc="Initializing n-links: "):
            for j in range(self.col):
                if i - 1 >= 0 and j - 1 >= 0:
                    # create top left edge
                    topLeft = Edge(self.vertices[i][j], self.vertices[i - 1][j - 1])
                    # put the edge into the graph
                    self.edges.append(topLeft)
                    # connect the edge with corresponding vertex
                    self.vertices[i][j].edges[(i - 1, j - 1)] = topLeft
                    # save camera noise
                    sigmas.append((topLeft._from.pixel_value - topLeft.to.pixel_value) ** 2)
                if i - 1 >= 0:
                    # create top edge
                    top = Edge(self.vertices[i][j], self.vertices[i - 1][j])
                    # put the edge into the graph
                    self.edges.append(top)
                    # connect the edge with corresponding vertex
                    self.vertices[i][j].edges[(i - 1, j)] = top
                    # save camera noise
                    sigmas.append((top._from.pixel_value - top.to.pixel_value) ** 2)
                if i - 1 >= 0 and j + 1 <= self.col - 1:
                    # create top right edge
                    topRight = Edge(self.vertices[i][j], self.vertices[i - 1][j + 1])
                    # put the edge into the graph
                    self.edges.append(topRight)
                    # connect the edge with corresponding vertex
                    self.vertices[i][j].edges[(i - 1, j + 1)] = topRight
                    # save camera noise
                    sigmas.append((topRight._from.pixel_value - topRight.to.pixel_value) ** 2)
                if j + 1 <= self.col - 1:
                    # create right edge
                    right = Edge(self.vertices[i][j], self.vertices[i][j + 1])
                    # put the edge into the graph
                    self.edges.append(right)
                    # connect the edge with corresponding vertex
                    self.vertices[i][j].edges[(i, j + 1)] = right
                    # save camera noise
                    sigmas.append((right._from.pixel_value - right.to.pixel_value) ** 2)
                if i + 1 <= self.row - 1 and j + 1 <= self.col - 1:
                    # create bottom right edge
                    bottomRight = Edge(self.vertices[i][j], self.vertices[i + 1][j + 1])
                    # put the edge into the graph
                    self.edges.append(bottomRight)
                    # connect the edge with corresponding vertex
                    self.vertices[i][j].edges[(i + 1, j + 1)] = bottomRight
                    # save camera noise
                    sigmas.append((bottomRight._from.pixel_value - bottomRight.to.pixel_value) ** 2)
                if i + 1 <= self.row - 1:
                    # create bottom edge
                    bottom = Edge(self.vertices[i][j], self.vertices[i + 1][j])
                    # put the edge into the graph
                    self.edges.append(bottom)
                    # connect the edge with corresponding vertex
                    self.vertices[i][j].edges[(i + 1, j)] = bottom
                    # save camera noise
                    sigmas.append((bottom._from.pixel_value - bottom.to.pixel_value) ** 2)
                if i + 1 <= self.row - 1 and j - 1 >= 0:
                    # create bottom left edge
                    bottomLeft = Edge(self.vertices[i][j], self.vertices[i + 1][j - 1])
                    # put the edge into the graph
                    self.edges.append(bottomLeft)
                    # connect the edge with corresponding vertex
                    self.vertices[i][j].edges[(i + 1, j - 1)] = bottomLeft
                    # save camera noise
                    sigmas.append((bottomLeft._from.pixel_value - bottomLeft.to.pixel_value) ** 2)
                if j - 1 >= 0:
                    # create left edge
                    left = Edge(self.vertices[i][j], self.vertices[i][j - 1])
                    # put the edge into the graph
                    self.edges.append(left)
                    # connect the edge with corresponding vertex
                    self.vertices[i][j].edges[(i, j - 1)] = left
                    # save camera noise
                    sigmas.append((left._from.pixel_value - left.to.pixel_value) ** 2)
        # initialize beta
        self.beta = 2 * sum(sigmas) / len(sigmas)
        # initialize weights of n-link edges
        for edge in self.edges:
            edge.calculateWeight(self.beta)
        # initialize K
        self.K = 1 + max(self.edges, key=lambda e: e.weight).weight
        # initialize t-link edges
        for i in tqdm(range(self.row), desc="Initializing t-links: "):
            for j in range(self.col):
                # initialize source link
                edge_source = Edge(self.source, self.vertices[i][j])
                # initialize sink link
                edge_sink = Edge(self.vertices[i][j], self.sink)
                # calculate weights
                edge_source.calculateWeight(self.beta, self.K, self.background_distribution,
                                            self.foreground_distribution)
                edge_sink.calculateWeight(self.beta, self.K, self.background_distribution,
                                          self.foreground_distribution)
                # connect edges with corresponding vertices
                self.source.edges[(i, j)] = edge_source
                self.vertices[i][j].edges["sink"] = edge_sink

    def _max_flow(self):
        """
        max flow algorithm
        :return:
        """

        def tree_cap(p, q):
            """
            return the capacity of the link from p to q if p belongs to S else from q to p
            :return:
            """
            if p.tree == 'S':
                # link from p to q
                return p.edges["sink"].capacity if q.isTerminal else p.edges[(q.row, q.col)].capacity
            elif p.tree == 'T':
                # link from q to p
                return q.edges["sink"].capacity if p.isTerminal else q.edges[(p.row, p.col)].capacity

        def collect_path(p):
            """
            collect path from source to p or from p to sink
            :return:
            """
            current_node = p
            path = []  # collected path
            while True:
                # push current node in the path
                path.append(current_node)
                # terminate if reach source or sink
                if current_node.isTerminal:
                    if current_node.tree == 'S':
                        path.reverse()
                    break
                else:
                    # obtain parent of p
                    parent = current_node.parent
                    # update current node
                    current_node = parent
            return path

        def findAugmentingPath(activeNodes):
            """
            find a augmenting path
            :return:
            """
            path = []  # augmenting path found
            while len(activeNodes) != 0:
                # pick an active node p
                p = activeNodes[0]
                # traverse all p's neighbors
                for coordinate, edge in p.edges.items():
                    # obtain neighbor
                    neighbor = edge.to
                    # if the edge is not saturated
                    if tree_cap(p, neighbor) > 0:
                        if neighbor.tree is None:
                            # push the neighbor into p's tree
                            neighbor.tree = p.tree
                            neighbor.parent = p
                            # set the neighbor active
                            if not neighbor.isActive:
                                activeNodes.append(neighbor)
                                neighbor.isActive = True
                        if p.tree != neighbor.tree:
                            # gather path
                            if p.tree == 'S':
                                path = collect_path(p)
                                path.extend(collect_path(neighbor))
                            else:
                                path = collect_path(neighbor)
                                path.extend(collect_path(p))
                            return path
                # set p passive
                activeNodes.pop(0)
                p.isActive = False
            return path

        def augmentation(path, orphans):
            # obtain edges capacity on the path
            edges_capacity = []
            for i in range(len(path) - 1):
                # obtain two adjacent nodes
                current_node = path[i]
                next_node = path[i + 1]
                # collect edges capacity
                capacity = current_node.edges["sink"].capacity if next_node.isTerminal else current_node.edges[
                    (next_node.row, next_node.col)].capacity
                edges_capacity.append(capacity)
            # find the bottleneck of the path
            min_flow = min(edges_capacity)
            # update residual graph
            for i in range(len(path) - 1):
                # obtain two adjacent nodes on the path
                p = path[i]
                q = path[i + 1]
                # obtain edge from p to q
                edge_pq = p.edges["sink"] if q.isTerminal else p.edges[(q.row, q.col)]
                # update p->q capacity
                edge_pq.capacity -= min_flow
                # update q->p capacity
                if not p.isTerminal and not q.isTerminal:
                    # obtain edge from q to p
                    edge_qp = q.edges[(p.row, p.col)]  # q->p
                    # update q->p capacity
                    edge_qp.capacity += min_flow
            # detect orphans
            for i in range(len(path) - 1):
                # obtain two adjacent nodes on the path
                p = path[i]
                q = path[i + 1]
                # obtain edge from p to q
                edge_pq = p.edges["sink"] if q.isTerminal else p.edges[(q.row, q.col)]
                # find orphan
                if edge_pq.capacity == 0:
                    # when p and q come from S
                    if p.tree == q.tree == 'S':
                        # make q an orphan
                        q.parent = None
                        orphans.append(q)
                    # when p and q come from T
                    elif p.tree == q.tree == 'T':
                        # make p an orphan
                        p.parent = None
                        orphans.append(p)

        def isOriginOrphan(node):
            """
            judge if the origin of a node is an orphan
            :return: true if an orphan
            """
            # initialize current node
            current_node = node
            while True:
                parent = current_node.parent
                # when reach the root
                if parent is None:
                    if current_node.isTerminal:
                        return False
                    else:
                        return True
                # update current node
                current_node = parent

        def adoption(orphans, activeNodes):
            while len(orphans) != 0:
                # pop an orphan
                orphan = orphans.pop()
                # traverse all the neighbors of the orphan
                for coordinate, edge in orphan.edges.items():
                    # obtain neighbor
                    neighbor = edge.to
                    # judge if the neighbor is a valid new parent
                    if neighbor.tree == orphan.tree and tree_cap(neighbor, orphan) > 0 and not isOriginOrphan(neighbor):
                        # if the neighbor is valid, then set the neighbor as new parent
                        orphan.parent = neighbor
                        break
                # if there is no valid parent for the orphan
                if orphan.parent is None:
                    # traverse all the neighbors of the orphan
                    for coordinate, edge in orphan.edges.items():
                        # obtain neighbor
                        neighbor = edge.to
                        if neighbor.tree == orphan.tree:
                            # make all the neighbor connected to the orphan active
                            if tree_cap(neighbor, orphan) > 0:
                                if not neighbor.isActive:
                                    neighbor.isActive = True
                                    activeNodes.append(neighbor)
                            # make the neighbor whose parent is current orphan as an orphan
                            if neighbor.parent == orphan:
                                neighbor.parent = None
                                orphans.append(neighbor)
                    orphan.tree = None
                    if orphan.isActive:
                        activeNodes.remove(orphan)
                        orphan.isActive = False

        # initialize tree sets
        A = [self.source, self.sink]  # set of active nodes
        # make source and sink active
        self.source.isActive = True
        self.sink.isActive = True
        O = []  # orphans

        # set tree of source and sink node
        self.source.tree = 'S'
        self.sink.tree = 'T'
        # conduct max flow algorithm
        while True:
            print(f"\rSteps left: {len(A)}", end="")
            # find an augmenting path
            path = findAugmentingPath(A)
            # terminate if there is no more augmenting path found
            if len(path) == 0:
                break
            # augment on the path
            augmentation(path, O)
            # adopt orphans
            adoption(O, A)

    def updateTlinkWeights(self, add_obj_pixles, add_bkg_pixels):
        """
        uodate t-link weights with additional pixels assigned by user
        :param add_obj_pixles: additional pixels of foreground
        :param add_bkg_pixels: additional pixels of background
        :return:
        """
        # update foreground additional pixels
        for pixel in add_obj_pixles:
            if self.vertices[pixel[0]][pixel[1]].label == 0:
                # if the pixel is assigned with a opposite label of previous one
                # update capacity of source->p
                self.source.edges[pixel].capacity += 2 * self.K
                # update weight of source->p
                self.source.edges[pixel].weight += 2 * self.K
            elif self.vertices[pixel[0]][pixel[1]].label is None:
                # obtain cp
                Rp_bkg = - math.log(
                    0.00000001 + self.background_distribution[int(self.vertices[pixel[0]][pixel[1]].pixel_value)])
                Rp_obj = - math.log(
                    0.00000001 + self.foreground_distribution[int(self.vertices[pixel[0]][pixel[1]].pixel_value)])
                # update capacity of source->p
                self.source.edges[pixel].capacity += self.K + Rp_obj
                # update capacity of p->sink
                self.vertices[pixel[0]][pixel[1]].edges["sink"].capacity += Rp_bkg
                # update weight of source->p
                self.source.edges[pixel].weight += self.K + Rp_obj
                # update weight of p->sink
                self.vertices[pixel[0]][pixel[1]].edges["sink"].weight += Rp_bkg
            # update label of the pixel
            self.vertices[pixel[0]][pixel[1]].label = 1
        # update background additional pixels
        for pixel in add_bkg_pixels:
            if self.vertices[pixel[0]][pixel[1]].label == 1:
                # if the pixel is assigned with a opposite label of previous one
                # update capacity of p->sink
                self.vertices[pixel[0]][pixel[1]].edges["sink"].capacity += 2 * self.K
                # update weight of p->sink
                self.vertices[pixel[0]][pixel[1]].edges["sink"].weight += 2 * self.K
            elif self.vertices[pixel[0]][pixel[1]].label is None:
                # obtain cp
                Rp_bkg = - math.log(
                    0.00000001 + self.background_distribution[int(self.vertices[pixel[0]][pixel[1]].pixel_value)])
                Rp_obj = - math.log(
                    0.00000001 + self.foreground_distribution[int(self.vertices[pixel[0]][pixel[1]].pixel_value)])
                # update capacity of source->p
                self.source.edges[pixel].capacity += Rp_obj
                # update capacity of p->sink
                self.vertices[pixel[0]][pixel[1]].edges["sink"].capacity += self.K + Rp_bkg
                # update weight of source->p
                self.source.edges[pixel].weight += Rp_obj
                # update weight of p->sink
                self.vertices[pixel[0]][pixel[1]].edges["sink"].weight += self.K + Rp_bkg
            # update label of the pixel
            self.vertices[pixel[0]][pixel[1]].label = 0
        # refresh vertices if additional background assigned by the user
        if len(add_bkg_pixels) != 0:
            for i in range(self.row):
                for j in range(self.col):
                    self.vertices[i][j].tree = None
                    self.vertices[i][j].parent = None
                    self.vertices[i][j].isActive = False

    def segmentation(self):
        """
        conduct segmentation based on solving max flow problem
        :return:
        """
        foregrounds = []  # a list containing pixels classified in foreground
        backgrounds = []  # a list containing pixels classified in background
        # conduct max flow
        self._max_flow()
        # collect segmentation results
        for i in range(self.row):
            for j in range(self.col):
                # obtain a pixel
                vertex = self.vertices[i][j]
                # obtain the assignment
                if vertex.tree == 'S':
                    foregrounds.append((i, j))
                else:
                    backgrounds.append((i, j))
        return foregrounds, backgrounds


class SamplePoint:
    def __init__(self, x, y, mode, end=False):
        """
        a point on drawn curves
        :param x: the col coordinate
        :param y: the row coordinate
        :param mode: the mode of the curve that the point belongs to
        :param end: True if the point is the start point of a curve
        """
        self.y = y
        self.x = x
        self.mode = mode
        self.end = end


class GraphCutMaster:
    def __init__(self, image):
        """
        integrate curve drawing and segmentation together
        """
        self.image = image.copy()   # a changeable image for showing
        self.image_for_segmentation = image.copy()  # keep image data unchanged for segmentation
        # obtain the size of the image
        self.row = image.shape[0]
        self.col = image.shape[1]
        # drawing params
        self.mode = None  # the mode for drawing background (0) or foreground (1)
        self.radius = 2  # half of the thickness of the line to be drawn
        self.ix, self.iy = -1, -1  # start point when drawing a line
        self.sample_points = []  # the sampled points on the drawn curve
        self.complement = False  # user interaction for adding additional curves
        self.additional_points = []  # additional points given by the user

    def collect_pixels(self, points, row, col):
        """
        collect pixels covered by the drawn curves
        :param points: a set of sample points on the curve
        :param row: row of the image
        :param col: col of the image
        :return:
        """

        def line_equ(x1, y1, x2, y2):
            """
            calculate the equ of the line with two ends (x1, y1) and (x2, y2)
            :return:
            """
            # calculate slope
            y1 = -y1
            y2 = -y2
            k = (y1 - y2) / (x1 - x2) if x1 != x2 else float("inf")
            # calculate bias
            b = (x1 * y2 - x2 * y1) / (x1 - x2) if x1 != x2 else float("inf")
            return k, b

        def distance(x, y, k, b):
            """
            return the distance between (x, y) and a line
            :param x: col
            :param y: row
            :param k: slope of the line
            :param b: bias of the line
            :return:
            """
            if k == float("inf") or k == 0:
                # if the line is vertical or horizontal
                return self.radius
            else:
                y = -y
                return abs(k * x - y + b) / math.sqrt(k ** 2 + 1)

        def search_bbox(x1, y1, x2, y2, radius, row, col):
            """
            return the search area around the line
            :param (x1, y1): first end of the line
            :param (x2, y2): second end of the line
            :param radius: half of the thickness of the line
            :param row: row of the image
            :param col: col of the image
            :return:
            """
            # the left top of the bounding box
            xmin = max(0, min(x1, x2) - radius)
            ymin = max(0, min(y1, y2) - radius)
            # the right bottom of the bounding box
            xmax = min(max(x1, x2) + radius, col - 1)
            ymax = min(max(y1, y2) + radius, row - 1)
            return xmin, ymin, xmax, ymax

        def return_pixels_covered_by_line(xmin, ymin, xmax, ymax, k, b):
            """
            return the pixels covered by the line
            :param (xmin, ymin): left top of the bounding box
            :param (xmax, ymax): right bottom of the bounding box
            :param k: slope of the line
            :param b: bias of the line
            :return:
            """
            results = []
            # traverse searching area
            for x in range(xmin, xmax + 1):
                for y in range(ymin, ymax + 1):
                    if distance(x, y, k, b) <= self.radius:
                        # put the pixel closed to the line within the range into results list
                        results.append((y, x))
            return results

        def return_pixels_covered_by_point(x, y, radius, row, col):
            """
            return the pixels covered by the point
            :param (x, y): coordinate of the point
            :param radius: half of the thickness of the line to be drawn
            :param row: row of the image
            :param col: col of the image
            :return:
            """
            # calculate search area
            xmin = max(0, x - radius)
            ymin = max(0, y - radius)
            xmax = min(col - 1, x + radius)
            ymax = min(row - 1, y + radius)

            # traverse searching area
            results = []
            for i in range(xmin, xmax + 1):
                for j in range(ymin, ymax + 1):
                    if (i - x) ** 2 + (j - y) ** 2 <= radius ** 2:
                        # put the pixel closed to the point within the range into results list
                        results.append((j, i))
            return results

        # initialize pixels set for pixels covered by the curve
        foregrounds = []
        backgrounds = []

        # traverse sample points
        for i in range(len(points)):
            point = points[i]
            # find pixels covered
            if point.end:
                # find pixels covered by a point
                results = return_pixels_covered_by_point(point.x, point.y, self.radius, row, col)
            else:
                # find pixels covered by a line
                # obtain the precedent point
                precedent = points[i - 1]
                # obtain the params of the line
                k, b = line_equ(precedent.x, precedent.y, point.x, point.y)
                # obtain the search area
                xmin, ymin, xmax, ymax = search_bbox(precedent.x, precedent.y, point.x, point.y, self.radius, row, col)
                # find pixels covered by the curve
                results = return_pixels_covered_by_line(xmin, ymin, xmax, ymax, k, b)
            # combine the result based on mode
            if point.mode == 0:
                # push the results into backgrounds
                backgrounds += results
            elif point.mode == 1:
                # push the results into foregrounds
                foregrounds += results
        return tuple(set(foregrounds)), tuple(set(backgrounds))

    def draw_curve(self, event, x, y, flags, param):
        """
        draw a curve by moving mouse
        :param event:
        :param x: the x-location of the mouse
        :param y: the y-location of the mouse
        :param flags:
        :param param:
        :return:
        """

        # set colour
        if self.mode == 0:
            # background colour
            bgr = (255, 0, 0)  # blue
        elif self.mode == 1:
            # foreground colour
            bgr = (0, 0, 255)  # red
        if self.mode is not None:
            # draw the curve
            # draw a point when the left mouse is clicked
            if event == cv2.EVENT_LBUTTONDOWN:
                cv2.circle(self.image, (x, y), self.radius, bgr, -1)
                # update start point
                self.ix, self.iy = x, y
                # collect sampled point
                if not self.complement:
                    self.sample_points.append(SamplePoint(x, y, self.mode, end=True))
                else:
                    self.additional_points.append(SamplePoint(x, y, self.mode, end=True))
            # keep drawing lines
            elif event == cv2.EVENT_MOUSEMOVE and flags == cv2.EVENT_FLAG_LBUTTON:
                cv2.line(self.image, (self.ix, self.iy), (x, y), bgr, thickness=2 * self.radius, lineType=cv2.LINE_AA)
                # update start point
                self.ix, self.iy = x, y
                # collect sampled point
                if not self.complement:
                    self.sample_points.append(SamplePoint(x, y, self.mode))
                else:
                    self.additional_points.append(SamplePoint(x, y, self.mode))

    @staticmethod
    def colour_hist(image, points):
        """
        calculate colour hist according to points
        :param image: input image
        :param points: coordinates of all the points of interest
        :return:
        """
        # calculate based on gray image
        gray = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
        # initialize empty vector
        hist = np.zeros(256)
        # calculate colour hist
        for point in points:
            hist[gray[point[0], point[1]]] += 1
        # normalize
        hist = hist / np.sum(hist)
        return hist

    def segmentation(self):
        """
        do segmentation: direct the user to draw curves and show the segmentation results
        :return:
        """
        # give instructions to the user
        print("Press 'A' to draw foreground curves (red)")
        print("Press 'D' to draw background curves (blue)")
        print("Press 'Enter' to start segmentation after finishing drawing the bounding box")
        print("If you are not satisfied with the segmentation result, you can keep improving it by drawing curves")
        print("Press 'S' to confirm the segmentation result")
        print("Press 'Enter' to start segmentation after finishing drawing curves")
        print("Press 'Esc' to quit")

        # initialize drawing function
        cv2.namedWindow('image')
        cv2.setMouseCallback('image', self.draw_curve)

        # initialize segmmentation window
        cv2.namedWindow('seg')

        while True:
            # show the image
            cv2.imshow('image', self.image)
            pressedKey = cv2.waitKey(1) & 0xFF
            # set mode
            if pressedKey == ord('a'):
                # set mode to foreground
                self.mode = 1
            elif pressedKey == ord('d'):
                # set mode to background
                self.mode = 0
            elif pressedKey == ord('s'):
                # press to return segmentation mask
                canvas = np.zeros((self.row, self.col))
                canvas = canvas.astype(np.uint8)
                canvas[foregrounds[:, 0], foregrounds[:, 1]] = 1
                canvas[backgrounds[:, 0], backgrounds[:, 1]] = 0
                cv2.destroyAllWindows()
                return canvas
            elif pressedKey == 13:
                # do segmentation if press enter
                # judge if it is the first time or additional curves
                if not self.complement:
                    self.complement = True
                    obj_pixles, bkg_pixels = self.collect_pixels(self.sample_points, self.row, self.col)
                    # calculate hist
                    fore_hist = self.colour_hist(self.image_for_segmentation, obj_pixles)
                    back_hist = self.colour_hist(self.image_for_segmentation, bkg_pixels)
                    # do segmentation
                    gray_image = cv2.cvtColor(self.image_for_segmentation, cv2.COLOR_RGB2GRAY)
                    gray_image = gray_image.astype(np.float64)
                    graph = GraphCut(gray_image,
                                     back_hist,
                                     fore_hist,
                                     bkg_pixels,
                                     obj_pixles)
                    foregrounds, backgrounds = graph.segmentation()
                else:
                    obj_pixles, bkg_pixels = self.collect_pixels(self.additional_points, self.row, self.col)
                    # update weights
                    graph.updateTlinkWeights(obj_pixles, bkg_pixels)
                    foregrounds, backgrounds = graph.segmentation()
                    # clear additional user input
                    self.additional_points = []
                # show trace
                foregrounds = np.array(foregrounds)
                backgrounds = np.array(backgrounds)
                canvas = np.zeros((self.row, self.col, 3))
                canvas = canvas.astype(np.uint8)
                canvas[foregrounds[:, 0], foregrounds[:, 1]] = (0, 0, 255)
                canvas[backgrounds[:, 0], backgrounds[:, 1]] = (0, 0, 0)
                self.image = cv2.addWeighted(self.image_for_segmentation, 0.7, canvas, 0.3, 0)
                cv2.imshow('seg', canvas)
            elif pressedKey == 27:
                # quit if press 'esc'
                break
        cv2.destroyAllWindows()


if __name__ == '__main__':
    # read image
    image = cv2.imread("CMS_livingroom.PNG")
    image = cv2.resize(image, (int(0.5 * image.shape[1]), int(0.5 * image.shape[0])), cv2.INTER_AREA)
    graph_cut = GraphCutMaster(image)
    mask = graph_cut.segmentation()
    cv2.imshow("mask", mask * 255)
    cv2.waitKey(0)
    cv2.destroyAllWindows()