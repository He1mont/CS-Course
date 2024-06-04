# Created by Li-Zenn Ang
# Supervised by Dr Tissa Chandesa
# Last Updated:

import cv2
from matplotlib import pyplot as plt

img = cv2.imread("./Images/some text.png", cv2.IMREAD_GRAYSCALE)

# Manual thresholding
threshold=127
ret, thresh_img = cv2.threshold(img, threshold, 255, cv2.THRESH_BINARY)
print(thresh_img)

# Otsu thresholding
ret, otsu = cv2.threshold(img, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

# Adaptive thresholding using mean
adaptMean = cv2.adaptiveThreshold(img, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 9, 21)

# Adaptive thresholding using Gaussian-weighted sum
adaptGaussian = cv2.adaptiveThreshold(img, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 9, 21)

# Display the results
fig, axs = plt.subplots(2, 3, figsize=(13, 6))
axs[0,0].set_title("Original Image")
axs[0,0].imshow(img, cmap="gray")
axs[0,1].set_title('Manual Thresholding')
axs[0,1].imshow(thresh_img, cmap="gray")
axs[0,2].set_title('Otsu Thresholding')
axs[0,2].imshow(otsu, cmap="gray")
axs[1,0].set_title('Adaptive Thresholding (Mean)')
axs[1,0].imshow(adaptMean, cmap="gray")
axs[1,1].set_title('Adaptive Thresholding (Gaussian)')
axs[1,1].imshow(adaptGaussian, cmap="gray")
axs[1,2].set_axis_off()

plt.tight_layout()
plt.show()