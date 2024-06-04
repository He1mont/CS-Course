# Created by Li-Zenn Ang
# Supervised by Dr Tissa Chandesa
# Last Updated:

import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread("./Images/Square-Hole.jpg", cv2.IMREAD_UNCHANGED)
# img = cv2.imread("./Images/text_broken.tif", cv2.IMREAD_UNCHANGED)

# Structuring Elements
# rectangle = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
rectangle3 = np.ones((3, 3), np.uint8)
rectangle5 = np.ones((5, 5), np.uint8)
rectangle7 = np.ones((7, 7), np.uint8)

ellipse3 = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3, 3))
ellipse5 = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5))
ellipse7 = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (7, 7))

cross3 = cv2.getStructuringElement(cv2.MORPH_CROSS, (3, 3))
cross5 = cv2.getStructuringElement(cv2.MORPH_CROSS, (5, 5))
cross7 = cv2.getStructuringElement(cv2.MORPH_CROSS, (7, 7))

# Dilation
fig, axs = plt.subplots(3, 4, figsize=(13, 7))
axs[0, 0].set_axis_off()
axs[1, 0].imshow(img, cmap="gray")
axs[1, 0].set_title("Original Image")
axs[2, 0].set_axis_off()
axs[0, 1].imshow(cv2.dilate(img, rectangle3), cmap="gray")
axs[0, 1].set_title("Rectangle 3x3")
axs[0, 2].imshow(cv2.dilate(img, rectangle5), cmap="gray")
axs[0, 2].set_title("Rectangle 5x5")
axs[0, 3].imshow(cv2.dilate(img, rectangle7), cmap="gray")
axs[0, 3].set_title("Rectangle 7x7")
axs[1, 1].imshow(cv2.dilate(img, ellipse3), cmap="gray")
axs[1, 1].set_title("Ellipse 3x3")
axs[1, 2].imshow(cv2.dilate(img, ellipse5), cmap="gray")
axs[1, 2].set_title("Ellipse 5x5")
axs[1, 3].imshow(cv2.dilate(img, ellipse7), cmap="gray")
axs[1, 3].set_title("Ellipse 7x7")
axs[2, 1].imshow(cv2.dilate(img, cross3), cmap="gray")
axs[2, 1].set_title("Cross 3x3")
axs[2, 2].imshow(cv2.dilate(img, cross5), cmap="gray")
axs[2, 2].set_title("Cross 5x5")
axs[2, 3].imshow(cv2.dilate(img, cross7), cmap="gray")
axs[2, 3].set_title("Cross 7x7")
plt.tight_layout()
plt.show()

# Erosion
img = cv2.imread("./Images/Squares.tif", cv2.IMREAD_UNCHANGED)

fig, axs = plt.subplots(3, 4, figsize=(13, 7))
axs[0, 0].set_axis_off()
axs[1, 0].imshow(img, cmap="gray")
axs[1, 0].set_title("Original Image")
axs[2, 0].set_axis_off()
axs[0, 1].imshow(cv2.erode(img, rectangle3), cmap="gray")
axs[0, 1].set_title("Rectangle 3x3")
axs[0, 2].imshow(cv2.erode(img, rectangle5), cmap="gray")
axs[0, 2].set_title("Rectangle 5x5")
axs[0, 3].imshow(cv2.erode(img, rectangle7), cmap="gray")
axs[0, 3].set_title("Rectangle 7x7")
axs[1, 1].imshow(cv2.erode(img, ellipse3), cmap="gray")
axs[1, 1].set_title("Ellipse 3x3")
axs[1, 2].imshow(cv2.erode(img, ellipse5), cmap="gray")
axs[1, 2].set_title("Ellipse 5x5")
axs[1, 3].imshow(cv2.erode(img, ellipse7), cmap="gray")
axs[1, 3].set_title("Ellipse 7x7")
axs[2, 1].imshow(cv2.erode(img, cross3), cmap="gray")
axs[2, 1].set_title("Cross 3x3")
axs[2, 2].imshow(cv2.erode(img, cross5), cmap="gray")
axs[2, 2].set_title("Cross 5x5")
axs[2, 3].imshow(cv2.erode(img, cross7), cmap="gray")
axs[2, 3].set_title("Cross 7x7")
plt.tight_layout()
plt.show()

# Opening
img = cv2.imread("./Images/Cells.png", cv2.IMREAD_GRAYSCALE)
ret, img = cv2.threshold(img, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)

opening = cv2.morphologyEx(img, cv2.MORPH_OPEN, rectangle5)

fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))
ax1.imshow(img, cmap="gray")
ax1.set_title("Original Image")
ax2.imshow(opening, cmap="gray")
ax2.set_title("Opening")
plt.tight_layout()
plt.show()

# Closing
img = cv2.imread("./Images/dark_blobs.tif", cv2.IMREAD_UNCHANGED)

kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (21, 21))
closing = cv2.morphologyEx(img, cv2.MORPH_CLOSE, kernel)

fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))
ax1.imshow(img, cmap="gray")
ax1.set_title("Original Image")
ax2.imshow(closing, cmap="gray")
ax2.set_title("Closing")
plt.tight_layout()
plt.show()

# Boundary Extraction

img = cv2.imread("./Images/lincoln.tif", cv2.IMREAD_UNCHANGED)
dilate = cv2.dilate(img, rectangle3)
erode = cv2.erode(img, rectangle3)

fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(12, 6))
ax1.imshow(img, cmap="gray")
ax1.set_title("Original Image")
ax2.imshow(dilate - img, cmap="gray")
ax2.set_title("Using Dilation")
ax3.imshow(img - erode, cmap="gray")
ax3.set_title("Using Erosion")
plt.tight_layout()
plt.show()