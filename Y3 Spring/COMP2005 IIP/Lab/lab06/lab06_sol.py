# Created by Li-Zenn Ang
# Supervised by Dr Tissa Chandesa
# Last Updated:

import cv2
import numpy as np
from matplotlib import pyplot as plt

# Read the image as grayscale
img = cv2.imread("./Images/Opera house.jpeg", cv2.IMREAD_GRAYSCALE)

# Sobel in X direction
sobelx = cv2.Sobel(img, cv2.CV_64F, 1, 0, 5)

# Sobel in Y direction
sobely = cv2.Sobel(img, cv2.CV_64F, 0, 1, 5)

# Computing the gradient for the xy direction
gradient = np.sqrt(sobelx**2 + sobely**2)
# Normalise the result to the range [0 255]
sobelxy = cv2.normalize(gradient, None, 0, 255, norm_type=cv2.NORM_MINMAX, dtype=cv2.CV_8U)

# Display the results
fig, (ax1, ax2, ax3, ax4) = plt.subplots(1, 4, figsize=(13, 6))
ax1.imshow(img, cmap="gray")
ax1.set_title('Original')
ax2.imshow(np.absolute(sobelx), cmap="gray")
ax2.set_title('Sobel X')
ax3.imshow(np.absolute(sobely), cmap="gray")
ax3.set_title('Sobel Y')
ax4.imshow(np.absolute(sobelxy), cmap="gray")
ax4.set_title('Sobel X & Y')
plt.tight_layout()
plt.show()

# Laplacian of Gaussian
blur = cv2.GaussianBlur(img, (7, 7), 1)
log = cv2.Laplacian(blur, cv2.CV_64F, 3)

# Display the results
fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(13, 6))
ax1.imshow(img, cmap="gray")
ax1.set_title('Original')
ax2.imshow(np.absolute(log), cmap="gray")
ax2.set_title('Laplacian of Gaussian')
ax3.imshow(log, cmap="gray")
ax3.set_title("Laplacian of Gaussian")
plt.tight_layout()
plt.show()

# Canny edge detection
operahouse = cv2.Canny(blur, 25, 225)
water = cv2.Canny(blur, 50, 75)

# Display the results
fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(13, 6))
ax1.imshow(img, cmap="gray")
ax1.set_title('Original')
ax2.imshow(water, cmap="gray")
ax2.set_title('Water')
ax3.imshow(operahouse, cmap="gray")
ax3.set_title('Opera House')
plt.tight_layout()
plt.show()

# Hough Transform
img = cv2.imread("./Images/sudoku.jpg")
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

canny = cv2.Canny(img_gray, 50, 125)

# Hough Line Transform
lines = cv2.HoughLines(canny, 1, np.pi / 180, 175)

# Create a copy of the image
hough = img.copy()

# Calculate the coordinates of the line
for line in lines:
    rho, theta = line[0]
    a = np.cos(theta)
    b = np.sin(theta)
    x0 = a * rho
    y0 = b * rho
    x1 = int(x0 + 1000 * (-b))
    y1 = int(y0 + 1000 * a)
    x2 = int(x0 - 1000 * (-b))
    y2 = int(y0 - 1000 * a)

    # Draw the line on the copy of the image
    cv2.line(hough, (x1, y1), (x2, y2), (255, 0, 0), 1)

# Display the results
fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(13, 6))
ax1.imshow(img)
ax1.set_title("Original Image")
ax2.imshow(canny, cmap="gray")
ax2.set_title('Canny Edge Detection')
ax3.imshow(hough)
ax3.set_title('Hough Transform')
plt.tight_layout()
plt.show()