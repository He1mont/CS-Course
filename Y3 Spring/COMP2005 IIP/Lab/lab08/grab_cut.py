# Created by Ziling Wu
# Supervised by Dr Armaghan Moemeni
# Last Updated: December 4th, 2023


import cv2
import numpy as np
import math


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


class GrabCutMaster:
    def __init__(self, image):
        """
        integrate curve drawing and segmentation together
        """
        self.image = image.copy()  # a changeable image for showing
        self.image_for_segmentation = image.copy()  # keep image data unchanged for segmentation
        # obtain the size of the image
        self.row = image.shape[0]
        self.col = image.shape[1]
        # drawing params
        self.mode = None  # the mode for drawing background (0), foreground (1)
        self.radius = 2  # half of the thickness of the line to be drawn
        self.ix, self.iy = -1, -1  # start point when drawing a line
        self.complement = False  # user interaction for adding additional curves
        self.additional_points = []  # additional points given by the user
        self.bbox = None  # bbox indicating the foreground drwan by the user

    def collect_pixels_covered_by_curves(self, points, row, col):
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
                        results.append([y, x])
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

        return np.array(foregrounds), np.array(backgrounds)

    def draw_curve(self, event, x, y, flags, param):
        """
        draw a curve or bounding box by moving mouse
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
        if self.mode == 0 or self.mode == 1:
            # draw the curve
            # draw a point when the left mouse is clicked
            if event == cv2.EVENT_LBUTTONDOWN:
                cv2.circle(self.image, (x, y), self.radius, bgr, -1)
                # update start point
                self.ix, self.iy = x, y
                # collect sampled point
                self.additional_points.append(SamplePoint(x, y, self.mode, end=True))
            # keep drawing lines
            elif event == cv2.EVENT_MOUSEMOVE and flags == cv2.EVENT_FLAG_LBUTTON:
                cv2.line(self.image, (self.ix, self.iy), (x, y), bgr, thickness=2 * self.radius, lineType=cv2.LINE_AA)
                # update start point
                self.ix, self.iy = x, y
                # collect sampled point
                self.additional_points.append(SamplePoint(x, y, self.mode))
        elif self.mode == 2:
            # draw the bounding box
            if event == cv2.EVENT_LBUTTONDOWN:
                # when the left button is clicked
                self.ix, self.iy = x, y
            elif event == cv2.EVENT_MOUSEMOVE and flags == cv2.EVENT_FLAG_LBUTTON:
                # drag the mouse
                # remove last rectangle
                self.image = self.image_for_segmentation.copy()
                # draw the rectangle
                cv2.rectangle(self.image, (self.ix, self.iy), (x, y), (0, 0, 255), thickness=self.radius)
            elif event == cv2.EVENT_LBUTTONUP:
                # left button up
                # remove last rectangle
                self.image = self.image_for_segmentation.copy()
                # draw the rectangle
                cv2.rectangle(self.image, (self.ix, self.iy), (x, y), (0, 0, 255), thickness=self.radius)
                # update the coordinate of the bounding box
                xmin = max(0, min(x, self.ix))
                ymin = max(0, min(y, self.iy))
                xmax = min(max(x, self.ix), self.col)
                ymax = min(max(y, self.iy), self.row)
                self.bbox = [xmin, ymin, xmax, ymax]

    def segmentation(self):
        """
        do segmentation: direct the user to draw curves and show the segmentation results
        :return:
        """
        # give instructions to the user
        print("Press 'W' to draw a bounding box indicating the foreground, you are allowed to draw the bounding box for only one time")
        print("Press 'Enter' to start segmentation after finishing drawing the bounding box")
        print("Press 'S' to confirm the segmentation result")
        print("Press 'Esc' to quit")
        print("If you are not satisfied with the segmentation result, you can keep improving it by drawing curves")
        print("Press 'A' to draw foreground curves (red)")
        print("Press 'D' to draw background curves (blue)")
        print("Press 'Enter' to start segmentation after finishing drawing curves")

        # initialize drawing function
        cv2.namedWindow('image')
        cv2.setMouseCallback('image', self.draw_curve)

        # initialize segmmentation window
        cv2.namedWindow('seg')

        while True:
            # show the image
            cv2.imshow('image', self.image)
            # waiting for the user input
            pressedKey = cv2.waitKey(1) & 0xFF
            # draw bounding box if this is the first interaction
            if pressedKey == ord('w') and not self.complement:
                # set mode to bounding box
                self.mode = 2
            # set mode
            if pressedKey == ord('a') and self.complement:
                # set mode to foreground
                self.mode = 1
            elif pressedKey == ord('d') and self.complement:
                # set mode to background
                self.mode = 0
            elif pressedKey == ord('s') and self.complement:
                # press to return segmentation mask
                cv2.destroyAllWindows()
                return result
            elif pressedKey == 13:  # enter
                # only allow to draw rectangle one time
                if self.mode == 2:
                    self.mode = None
                # do segmentation if press enter
                # judge if it is the first time or additional curves
                if not self.complement:
                    # set further interactions as complimentary interactions
                    self.complement = True
                    # initialize the mask indicating foreground and background
                    mask = np.zeros(self.image_for_segmentation.shape[:2], dtype=np.uint8)
                    # initialize the rectangle of the bounding box drawn by the user
                    rect = [self.bbox[0], self.bbox[1], self.bbox[2] - self.bbox[0],
                            self.bbox[3] - self.bbox[1]]  # xmin. ymin, w, h
                    # temporal array for colour model
                    bgdmodel = np.zeros((1, 65), np.float64)  # background
                    fgdmodel = np.zeros((1, 65), np.float64)  # foreground
                    # segmentation
                    mask, bgdmodel, fgdmodel = cv2.grabCut(self.image_for_segmentation, mask, rect, bgdmodel, fgdmodel, 11,
                                mode=cv2.GC_INIT_WITH_RECT)
                    # obtain segmentation results
                    result = np.where((mask == cv2.GC_PR_FGD) | (mask == cv2.GC_FGD), 1, 0).astype('uint8')
                else:
                    # collect pixels under the curves given by the user
                    obj_pixels, bkg_pixels = self.collect_pixels_covered_by_curves(self.additional_points, self.row,
                                                                                   self.col)
                    # update mask
                    if len(obj_pixels) != 0:
                        mask[obj_pixels[:, 0], obj_pixels[:, 1]] = cv2.GC_FGD
                    if len(bkg_pixels) != 0:
                        mask[bkg_pixels[:, 0], bkg_pixels[:, 1]] = cv2.GC_BGD
                    # segmentation
                    mask, bgdmodel, fgdmodel = cv2.grabCut(self.image_for_segmentation, mask, None, bgdmodel, fgdmodel,
                                                           5, cv2.GC_INIT_WITH_MASK)
                    # obtain segmentation results
                    result = np.where((mask == cv2.GC_PR_FGD) | (mask == cv2.GC_FGD), 1, 0).astype('uint8')
                    # clear additional user input
                    self.additional_points = []
                # show trace
                canvas = np.zeros((self.row, self.col, 3))
                canvas = canvas.astype(np.uint8)
                canvas[result == 1, 2] = 255
                self.image = cv2.addWeighted(self.image_for_segmentation, 0.7, canvas, 0.3, 0)
                cv2.imshow('seg', canvas)
            elif pressedKey == 27:
                # quit if press 'esc'
                break
        cv2.destroyAllWindows()


if __name__ == '__main__':
    # read image
    image = cv2.imread("CMS_livingroom.PNG")
    grab_cut = GrabCutMaster(image)
    mask = grab_cut.segmentation()