# Created by Li-Zenn Ang
# Supervised by Dr Tissa Chandesa
# Last Updated:

import cv2
import numpy as np
from matplotlib import pyplot as plt


# Check if mouse has been clicked
def on_mouse(event, x, y, flags, params):
    global seed
    if event == cv2.EVENT_LBUTTONDOWN:
        # Get the x and y coordinates of the place clicked
        seed = (x, y)


# Region Growing algorithm
def regiongrow(img, seed, threshold):
    height, width = img.shape

    # Create a matrix to keep track of areas visited
    visited = np.zeros((height, width))
    # Create a matrix of the result of region growing
    result = np.zeros((height, width))

    pixel_list = [seed]

    while pixel_list:
        x, y = pixel_list.pop()

        # Ensure the x and y is within the image bounds and the area has not been visited
        if x < 0 or y < 0 or x >= width or y >= height or visited[y, x] == 1:
            continue

        visited[y, x] = 1

        # Check if the difference in pixel intensity is within the threshold set
        if abs(int(img[y, x]) - int(img[seed[1], seed[0]])) <= threshold:
            # If it is, set the corresponding pixel in the result to 255
            result[y, x] = 255

            # Add the neighbouring pixels to the list to check
            pixel_list.append((x + 1, y))
            pixel_list.append((x - 1, y))
            pixel_list.append((x, y + 1))
            pixel_list.append((x, y - 1))

    return result


seed = None

# Read in the image
img = cv2.imread('./Images/defective_weld.tif', cv2.IMREAD_GRAYSCALE)
cv2.namedWindow("Image")
# If any mouse events are detected, run the function "on_mouse"
cv2.setMouseCallback('Image', on_mouse)
while seed is None:
    cv2.imshow('Image', img)
    cv2.waitKey(1)
cv2.destroyAllWindows()

# Adjust the threshold as desired
threshold = 80

# Run the region growing algorithm with the selected seed and threshold
result = regiongrow(img, seed, threshold)

# Display the results
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(13, 6))
ax1.imshow(img, cmap="gray")
ax1.set_title("Original Image")
ax2.imshow(result, cmap="gray")
ax2.set_title('Region Growing')
plt.tight_layout()
plt.show()