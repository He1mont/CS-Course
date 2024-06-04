# Created by Ziling Wu
# Supervised by Dr Armaghan Moemeni
# Last Updated: December 4th, 2023


import cv2
import numpy as np

# read the image
img = cv2.imread('CMS_livingroom.png')

print("Select a ROI and then press SPACE or ENTER button!\nCancel the selection process by pressing c button!")
# let the user draw a bounding box
rect = cv2.selectROI('input', img, False, printNotice=False)

# initialize the mask indicating foreground and background with 0
mask = np.zeros(img.shape[:2], np.uint8)

# initialize the foreground and background model
bgdModel = np.zeros((1, 65), np.float64)
fgdModel = np.zeros((1, 65), np.float64)

# conduct segmentation
mask, bgdModel, fgdModel = cv2.grabCut(img, mask, rect, bgdModel, fgdModel, 5, cv2.GC_INIT_WITH_RECT)

# select the foreground and possible foreground as the segmented mask
result = np.where((mask == cv2.GC_FGD) | (mask == cv2.GC_PR_FGD), 1, 0).astype('uint8')

# visualization
canvas = np.zeros((img.shape[0], img.shape[1], 3))
canvas = canvas.astype(np.uint8)
canvas[result == 1, 2] = 255
cv2.imshow("visualization", cv2.addWeighted(img, 0.7, canvas, 0.3, 0))
cv2.waitKey(0)
cv2.destroyAllWindows()