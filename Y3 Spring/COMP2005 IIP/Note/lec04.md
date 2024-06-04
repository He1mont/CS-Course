# lec04: Thresholding & Binary Image Processing

[toc]

## What is Thresholding

**Binary Image Processing**

- The result is a binary image
  - Pixels can have only two values, 0 or 1
  - Binary images also need noise removal, enhancement, etc

<img src="assets/Screenshot 2024-02-23 at 15.09.51.png" alt="Screenshot 2024-02-23 at 15.09.51" style="zoom:50%;" />

**Binarisation: Thresholding**

- A dark object on a light background in a grey-level image
- Choose a threshold value `T`
- Consider each pixel in turn
- Basic idea extends to colour, define sets of colour values that correspond to objects

## Adaptive Thresholding

-   If the user chooses t for each of a set of images there is no guarantee the results will be consistent
-   Automatic methods choose a threshold based on image properties: histograms are commonly used

<img src="assets/Screenshot 2024-02-23 at 15.15.30.png" alt="Screenshot 2024-02-23 at 15.15.30" style="zoom:50%;" />

### Otsu Thresholding

- Assumes histograms are **bimodal**
  - two regions can be separated by one threshold
- Think of the histogram as made of two normal **Gaussian distributions**, described by their means and deviations

<img src="assets/Screenshot 2024-02-23 at 15.21.25.png" alt="Screenshot 2024-02-23 at 15.21.25" style="zoom:50%;" />

- Find the threshold which **minimises a weighted sum** of the variation of the two regions that threshold produces
  - Weights are the areas of the histogram assigned to each region

$$
S_w^2(t) = q_1(t)S_1^2(t) + q_2(t)S_2^2(t)
$$

- This is small when the two regions are both physically small and have low deviations
- **The algorithm**
  - consider all possible threshold values (0 - 255)
  - compute weighted sum
  - pick `t` with smallest value
  - **如果是 RGB 图像的话就就分成三个通道，分开找 threshold**

### Unimodal Thresholding

- **Unimodal**: there is often only **one peak**, e.g., text is mainly white, with a small amount of black
- **Rosin’s unimodal method**
  - Finds the **peak**
  - Draws a line from there to **the top of the furthest bin**
  - Finds the **top of the bin** that is furthest from this line; that bin value is the threshold
  - The threshold is selected at the point of the histogram that **maximizes** the **perpendicular distance** from the histogram to the straight line.

<img src="assets/Screenshot 2024-02-23 at 15.28.06.png" alt="Screenshot 2024-02-23 at 15.28.06" style="zoom:50%;" />

### Local Adaptive Methods

- Imaging conditions and object properties can vary within a single image as well as across sets of images
- Histograms can be too complex for any method’s assumption to be true

<img src="assets/Screenshot 2024-02-23 at 15.37.13.png" alt="Screenshot 2024-02-23 at 15.37.13" style="zoom:50%;" />

- Assumptions about histograms may, however, be true for local areas of the image
- Divide image into **subregions**, apply a threshold selection method independently to each
- The histograms of each vertical strip of this image **are bimodal**
- **Otsu** can be applied to each strip

<img src="assets/Screenshot 2024-02-23 at 15.39.03.png" alt="Screenshot 2024-02-23 at 15.39.03" style="zoom:50%;" />
