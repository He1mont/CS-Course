# Created by Li-Zenn Ang
# Supervised by Dr Tissa Chandesa
# Last Updated:

# Import the cv2 and matplotlib library
import cv2
from matplotlib import pyplot as plt

# Read the image
img = cv2.imread("./Images/cameraman.tif", cv2.IMREAD_UNCHANGED)

# Display the image
cv2.imshow("Image", img)
cv2.waitKey(0)      # wait until user presses any key
cv2.destroyAllWindows()

# Write the image to the computer
cv2.imwrite("./Images/cameraman_copy.tif", img)

# Display the results of shape
# The tuple is (height, width)
# If an RGB image is read, the tuple will be (height, width, channels) where channels is the number of colour channels
print(img.shape)

# Rotate the image by 90 degrees. The function rotate only works in multiples of 90
degree90 = cv2.rotate(img, cv2.ROTATE_90_CLOCKWISE)
cv2.imshow("ImgRotate90", degree90)
cv2.waitKey(0)
cv2.destroyAllWindows()

# Get the height and width of the image to get the centre point
height, width = img.shape
centre = (width / 2, height / 2)

# Rotate the image by 30 degrees
# Creates a matrix for 2D rotation around the centre point.
matrix30 = cv2.getRotationMatrix2D(centre, 30, 1)
# Applies the matrix transformation on the image
degree30 = cv2.warpAffine(img, matrix30, (width, height))

# The same is done to rotate the image by 60 degrees. This method can be used to rotate by any degree.
matrix60 = cv2.getRotationMatrix2D(centre, 60, 1)
# Display the images in a single window
degree60 = cv2.warpAffine(img, matrix60, (width, height))

# Create the layout of the image in this case: 1 row and 3 columns
fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(12, 6))
ax1.imshow(degree30, cmap="gray")
ax1.set_title('30 degrees')
ax2.imshow(degree60, cmap="gray")
ax2.set_title('60 degrees')
ax3.imshow(degree90, cmap="gray")
ax3.set_title('90 degrees')
# Show the figure with the subplots
plt.show()

# Set a constant value for the lighter and darker image. The constant can be set to any number.
constant = 20

# img1 = img.copy()     # pass by value
# imt2 = img            # pass by reference

# Make a lighter image
light_img = img.copy()              # Make a copy of the original image
light_img = light_img.astype(int)   # Convert the image to type int
light_img = light_img + constant    # Add the constant to each pixel value in the image
light_img[light_img > 255] = 255    # If the pixel value is above 255, set it to 255 to prevent overflow
light_img = light_img.astype("uint8")   # Convert the image back to type uint8

# Make a darker image
dark_img = img.copy()
dark_img = dark_img.astype(int)
dark_img = dark_img - constant
dark_img[dark_img < 0] = 0
dark_img = dark_img.astype("uint8")

# Display the images in a single window
fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(12, 6))
ax1.imshow(img, cmap="gray")
ax1.set_title('Original Image')
ax2.imshow(light_img, cmap="gray")
ax2.set_title('Lighter Image')
ax3.imshow(dark_img, cmap="gray")
ax3.set_title('Darker Image')
plt.show()

# Set the threshold amount to 128
threshold = 128

thresh_img = img.copy()
thresh_img[thresh_img < threshold] = 0
thresh_img[thresh_img >= threshold] = 255

cv2.imshow("Threshold Image", thresh_img)
cv2.waitKey(0)

# Draw a black cross on the image
cross_img = img.copy()
halfHeight = int(height / 2)
halfWidth = int(width / 2)

# Set the pixel values of the centre row to 0
cross_img[halfHeight, :] = 0

# Set the pixel values of the centre column to 0
cross_img[:, halfWidth] = 0

# Display the result
cv2.imshow("Image with Cross", cross_img)
cv2.waitKey(0)