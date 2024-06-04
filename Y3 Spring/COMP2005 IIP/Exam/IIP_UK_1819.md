# IIP UK 18-19

## 1. Image Compression

(a)

-   Coding redundancy
-   Spatial redundancy
-   Psychovisual redundancy

(b)

>   -   Run-length encoding needs adjacent pixels to be equal
>   -   Pixels are more often highly correlated (dependent)
>   -   Each pixel value (except at the boundaries) is predicted based on its neighbors (e.g., linear combination) to get a predicted image.
>   -   The difference between the original and predicted images yields a differential or residual image with a reduced set of values.
>   -   The differential image is encoded using Huffman coding, or similar.

(c)

| Pixel value | Huffman Coding |
| ----------- | -------------- |
| 0           | 11             |
| 1           | 01             |
| 2           | 101            |
| 3           | 000            |
| 4           | 001            |
| 5           | 10011          |
| 6           | 1000           |
| 7           | 10010          |

## 2. Intensity Transforms and Filtering

(a)

>   Gamma correction is a point transform which raises each pixel value to a power:

$$
g(x,y) = f(x,y)^{\gamma}
$$



When an image is displayed on the screen, the hardware applies an intensity transform to it so that it generates the voltage that we want.

(b)

(i)

Linear intensity transforms: $g(x,y) = a\cdot f(x,y) + b$

-   a is gain that controls the contrast 
-   b is bias that controls the brightness

(ii)

>   -   Changing the gain **stretches the histogram** and changes its shape
>   -   Changing the bias **shifts the histogram** but keep its shape

(c)

Let g(x,y) be the output image, f(x,y) be the input image
$$
g(x,y) = \frac{255}{40} \cdot (f(x,y)-10) + 0
$$
**Contrast stretching**

(d)

(i) 5.56 => 6

(ii) -8

(iii) 6

## 3. Segmentation

(a)

**Watershed algorithm**

-   Sort the pixels from low to high
-   For each pixel
    -   if all its neighbours are unlabeled, give it a new label
    -   if it has neighbours with a single label, it gets that label
    -   if it has neighbours with two or more labels, it's a watershed
-   Defects:
    -   a very basic version
    -   generates thick watershed and sensitive to noise

**Results**: BCAA/BCCA/BBCA/BBCC

(b)

>   Since we have digital images with a discrete number of grey values

Since w we use **bin sort**. 

-   Make a bin for each possible values
-   Traverse each pixel and put it in the corresponding bin

(c)

