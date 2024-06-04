# Created by Li-Zenn Ang
# Supervised by Dr Tissa Chandesa
# Last Updated:
# Referenced: https://docs.opencv.org/4.x/d3/db4/tutorial_py_watershed.html

import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread("./Images/blob.tif")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
ret, otsu = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)

kernel = np.ones((5,5), np.uint8)
opening = cv2.morphologyEx(otsu, cv2.MORPH_OPEN, kernel)

background = cv2.dilate(opening, kernel)

distTransform = cv2.distanceTransform(opening, cv2.DIST_L2, 5)
ret, foreground = cv2.threshold(distTransform, 0.4 * distTransform.max(), 255, 0)
foreground = foreground.astype("uint8")

unknown = cv2.subtract(background, foreground)

ret, marker = cv2.connectedComponents(foreground)
marker = marker + 1
marker[unknown == 255] = 0
markers = cv2.watershed(img, marker)

result = img.copy()
result[markers == -1] = [0, 0, 255]

# Display the results
fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(13, 6))
ax1.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
ax1.set_title('Original')
ax2.imshow(foreground, cmap="gray")
ax2.set_title('Foreground')
ax3.imshow(cv2.cvtColor(result, cv2.COLOR_BGR2RGB))
ax3.set_title("Watershed")
plt.tight_layout()
plt.show()