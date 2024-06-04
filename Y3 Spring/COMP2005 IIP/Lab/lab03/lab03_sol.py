# Created by Li-Zenn Ang
# Supervised by Dr Tissa Chandesa
# Last Updated:

import cv2
from matplotlib import pyplot as plt

img = cv2.imread("./Images/noisyCameraman.tif")

# Mean Filtering
mean3 = cv2.blur(img, (3, 3))
mean5 = cv2.blur(img, (5, 5))
mean7 = cv2.blur(img, (7, 7))

# Display the results
fig, (ax1, ax2, ax3, ax4) = plt.subplots(1, 4, figsize=(13, 6))
ax1.set_title('Original Image')
ax1.imshow(img, cmap="gray")
ax2.set_title('Mean Filter 3x3')
ax2.imshow(mean3, cmap="gray")
ax3.set_title('Mean Filter 5x5')
ax3.imshow(mean5, cmap="gray")
ax4.set_title('Mean Filter 7x7')
ax4.imshow(mean7, cmap="gray")

plt.tight_layout()
plt.show()

# Gaussian Filtering
gaussian1 = cv2.GaussianBlur(img, (3, 3), 0.5)
gaussian2 = cv2.GaussianBlur(img, (7, 7), 1)
gaussian3 = cv2.GaussianBlur(img, (9, 9), 1.5)

# Display the results
fig, (ax1, ax2, ax3, ax4) = plt.subplots(1, 4, figsize=(13, 6))
ax1.set_title('Original Image')
ax1.imshow(img, cmap="gray")
ax2.set_title('Sigma = 0.5')
ax2.imshow(gaussian1, cmap="gray")
ax3.set_title('Sigma = 1.0')
ax3.imshow(gaussian2, cmap="gray")
ax4.set_title('Sigma = 1.5')
ax4.imshow(gaussian3, cmap="gray")

plt.tight_layout()
plt.show()

# Median Filtering
median3 = cv2.medianBlur(img, 3)
median5 = cv2.medianBlur(img, 5)
median7 = cv2.medianBlur(img, 7)

# Display the results
fig, (ax1, ax2, ax3, ax4) = plt.subplots(1, 4, figsize=(13, 6))
ax1.set_title('Original Image')
ax1.imshow(img, cmap="gray")
ax2.set_title('Median Filter 3x3')
ax2.imshow(median3, cmap="gray")
ax3.set_title('Median Filter 5x5')
ax3.imshow(median5, cmap="gray")
ax4.set_title('Median Filter 7x7')
ax4.imshow(median7, cmap="gray")

plt.tight_layout()
plt.show()

# Anisotropic Diffusion
# Changing K values
anisotropic5K = cv2.ximgproc.anisotropicDiffusion(img, 0.1, 5, 1)
anisotropic25K = cv2.ximgproc.anisotropicDiffusion(img, 0.1, 25, 1)
anisotropic50K = cv2.ximgproc.anisotropicDiffusion(img, 0.1, 50, 1)
# Changing the no. of iterations
anisotropic1I = cv2.ximgproc.anisotropicDiffusion(img, 0.1, 5, 1)
anisotropic2I = cv2.ximgproc.anisotropicDiffusion(img, 0.1, 5, 2)
anisotropic3I = cv2.ximgproc.anisotropicDiffusion(img, 0.1, 5, 3)

# Display the results
fig, axs = plt.subplots(2, 4, figsize=(13, 6))
axs[0, 0].set_title('Original Image')
axs[0, 0].imshow(img, cmap="gray")
axs[0, 1].set_title('K=5')
axs[0, 1].imshow(anisotropic5K, cmap="gray")
axs[0, 2].set_title('K=25')
axs[0, 2].imshow(anisotropic25K, cmap="gray")
axs[0, 3].set_title('K=50')
axs[0, 3].imshow(anisotropic50K, cmap="gray")
axs[1, 0].set_title('Original Image')
axs[1, 0].imshow(img, cmap="gray")
axs[1, 1].set_title('1 Iteration')
axs[1, 1].imshow(anisotropic1I, cmap="gray")
axs[1, 2].set_title('2 Iterations')
axs[1, 2].imshow(anisotropic2I, cmap="gray")
axs[1, 3].set_title('3 Iterations')
axs[1, 3].imshow(anisotropic3I, cmap="gray")

plt.tight_layout()
plt.show()

# Bilateral Filtering
# Changing the sigma values
bilateral100s = cv2.bilateralFilter(img, 10, 100, 100)
bilateral150s = cv2.bilateralFilter(img, 10, 150, 150)
bilateral200s = cv2.bilateralFilter(img, 10, 200, 200)
# Changing the d values
bilateral10d = cv2.bilateralFilter(img, 10, 150, 150)
bilateral25d = cv2.bilateralFilter(img, 25, 150, 150)
bilateral50d = cv2.bilateralFilter(img, 50, 150, 150)

# Display the results
fig, axs = plt.subplots(2, 4, figsize=(13, 6))
axs[0, 0].set_title('Original Image')
axs[0, 0].imshow(img, cmap="gray")
axs[0, 1].set_title('Sigma = 100')
axs[0, 1].imshow(bilateral100s, cmap="gray")
axs[0, 2].set_title('Sigma = 150')
axs[0, 2].imshow(bilateral150s, cmap="gray")
axs[0, 3].set_title('Sigma = 200')
axs[0, 3].imshow(bilateral200s, cmap="gray")
axs[1, 0].set_title('Original Image')
axs[1, 0].imshow(img, cmap="gray")
axs[1, 1].set_title('d = 10')
axs[1, 1].imshow(bilateral10d, cmap="gray")
axs[1, 2].set_title('d = 25')
axs[1, 2].imshow(bilateral25d, cmap="gray")
axs[1, 3].set_title('d = 50')
axs[1, 3].imshow(bilateral50d, cmap="gray")

plt.tight_layout()
plt.show()