# IIP MY 21-22

## 1. Intensity Transform, Filtering and Thresholding

**(a)**

Contrast manipulation is a kind of linear transform. The general form of linear transform is stated below, where a is the gain that controls the contrast and streches the histogram in x direction and b is the bias that control the brightness and shifts the histograms
$$
g(x,y) = a\cdot f(x,y) + b
$$
One example of contrast manipulation is contrast stretching, which convert a source image from an old range to a new range. The fomula is stated below
$$
g(x,y) = \frac{max(t)-min(t)}{max(s) - min(s)} \cdot (f(x,y) - min(s)) + min(t)
$$
**(b)**
$$
g(x,y) = \frac{255}{80-46} \cdot (f(x,y) - 46
$$
**(c)**

**Convolution:**

-   The operator of convolution is represented as a 2D array (mask)
-   The mask is put over each pixel of the input image
-   The weighted sum is written to the same position to the output image

**Examples**

-   Gaussian Filter, 1st derivative filter like sobel

**(d)**

-   (i) 145
-   (ii) 145

**(e)**

-   Bilateral Filtering modifies Gaussian smoothing using similarity
-   One gaussian weights pixels that near the source
-   Another Gaussian weights pixels that have similar intensity values to the source

**(f)**

-   Otsu thresholding is a thresholding technique for bimodal images

## 2. Derivatives, Edges and Whole Image Methods

**(a)**

-   1st derivative method focuses on the change of neighbouring values

**(b)**

| Raw Data | 1st  | 2nd  |
| -------- | ---- | ---- |
| 9        | /    | /    |
| 9        | 0    | -2   |
| 7        | -2   | 0    |
| 5        | -2   | 1    |
| 4        | -1   | 0    |
| 3        | -1   | -2   |
| 0        | -3   | 11   |
| 8        | 8    | -16  |
| 0        | -8   | 9    |
| 1        | 1    | -2   |
| 0        | -1   | /    |

**(c)**

略，x和y的operator写一下

**(d)**

x = -12, y = -4

**(e)**

-   Histogram equalisation uses a cumulated density function to compute the accumulated property for each pixel
-   while contrast stretching is just a linear transform as g(x,y) = a*f(x,y) + b

**(f)**

| input | output | output prob |
| ----- | ------ | ----------- |
| 0     | 1      | 0.2         |
| 1     | 2      | 0.05        |
| 2     | 3      | 0.2         |
| 3     | 3      | 0.2         |
| 4     | 4      | 0.1         |
| 5     | 5      | 0.2         |
| 6     | 6      | 0.05        |
| 7     | 7      | 0.2         |

## 3. Segmentation and Suerpixels

**(a)**

-   why: to identify meaningful regions
-   how: to group pixels according to local image properties

**(b)**

-   Clustering: seek group similarities regardless of where they are
-   Region based: focus on finding physically connected set of pixels
    -   region growing
-   Edge based: emphasize boundaries between regions

**(c)**

SLIC 不考吧。。

**(d)**

-   Sort each pixel from low to high using bin sort
-   For each pixel:
    -   if all its neighbours are unlabelled, assign a new label
    -   if all its neighbours have only one label, it gets that label
    -   if all its neighbours have more than one label, it is a watershed













