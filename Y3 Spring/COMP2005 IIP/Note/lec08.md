# lec08: Segmentation

[toc]

## What is segmentation

-   **To identify meaningful regions** (why we do it)
-   We can partition or group pixels according to local image properties
    -   Intensity or colour from original images, or computed values based on image operators
    -   Textures or patterns that are unique to each type of region
    -   Spectral profiles that provide multidimensional image data
-   Elaborate systems may use a combination of properties

**Approaches**

-   **Clustering**
    -   Seeks groups of **similar pixels**, with no regard for where they are – views images as uncorrelated data
-   **Region-based**
    -   Focus on finding physically connected sets of pixels

    -   E.g., region growing, split and merge
-   **Edge-based**
    -   Emphasise the boundaries between regions

    -   E.g., **watersheds**
-   Note: **Thresholding + connected components is a form of segmentation**, but treats grey/colour and spatial information independently

## Region-based Segmentation

**We want smooth regions in the image**

-   We still want the pixels **in each region to be similar**, and those **in adjacent regions to be different**
-   One way to do this is to **work with regions rather than pixels**

**Two methods**

-   **Region Growing:** 从小到大
    -   Start with a small ‘seed’ and expand by adding similar pixels
-   **Split & Merge:** 从大到小
    -   Splitting divides regions that are inconsistent

    -   Merging combines adjacent regions that are consistent

### Region Growing 区域生长

**Region growing starts with a small patch of seed pixels**

-   Algorithm

    -   Compute statistics about the region

    -   Check neighbours to see if they can be added

    -   Recompute the statistics

-   This procedure repeats until the region stops growing

    -   Simple example: we compute the **mean grey level** of pixels in the region

    -   Neighbours are added if their grey level is near the average

<img src="assets/Screenshot 2024-04-20 at 23.16.03.png" alt="Screenshot 2024-04-20 at 23.16.03" style="zoom:50%;" />

### Split and Merge

**Split**

-   We start by taking the whole image to be one region
    -   We compute some measure of internal similarity

    -   If this indicates there is too much variety, we divide the region
    -   Repeat until no more splits, or we reach a minimum region size
-   Some details are needed
    -   How to we measure **similarity**? – **standard deviation** are commonly used

    -   How do we determine **whether to split** or not? **thresholding** is easy
    -   How do we **split regions**? – **quadtrees** are a common method

**Quadtrees**

<img src="assets/Screenshot 2024-04-20 at 23.19.06.png" alt="Screenshot 2024-04-20 at 23.19.06" style="zoom:50%;" />

<img src="assets/Screenshot 2024-04-20 at 23.19.31.png" alt="Screenshot 2024-04-20 at 23.19.31" style="zoom:50%;" />

**Merge**

-   Splitting give us
    -   Regions that are small, consistent, or both

    -   Rather too many regions, as adjacent ones may be very similar
    -   We can now combine adjacent regions to make bigger ones
-   Merge
    -   We merge two regions if they are adjacent and similar

    -   Need a measure of similarity – can compare their **mean grey level**, or use statistical tests
    -   Repeat the merging until you can do no more
-   We consider merging adjacent regions
    -   Two regions are merged if their **mean grey levels differ by less than 25**

    -   This leads to less regularly shaped regions, but they are larger and still consistent

## Edge-based Segmentation (Watersheds)

-   Do region-based methods focus too much on regions?

-   Edge represent **discontinuities in image intensity**
-   Regions should then be areas without edges, and should be bounded by edges
-   One class of edge-based segmentation uses watersheds

>   **分水岭算法**
>
>   -   任意的灰度图像可以被看做是地质学表面，高亮度的地方是山峰，低亮度的地方是山谷。
>   -   给每个孤立的山谷（局部最小值）不同颜色的水（标签），当水涨起来，根据周围的山峰（梯度），不同的山谷也就是不同的颜色会开始合并，**要避免山谷合并，需要在水要合并的地方建立分水岭**，直到所有山峰都被淹没，所创建的分水岭就是分割边界线，这个就是分水岭的原理。

<img src="assets/Screenshot 2024-05-24 at 22.01.04.png" alt="Screenshot 2024-05-24 at 22.01.04" style="zoom:50%;" />

**Watersheds in Images**

-   We start by finding images gradients
    -   Using methods like Sobel operators, we get a value for the gradient magnitude
    -   This can be viewed as a 3D ‘terrain’
-   We then slowly flood the terrain
    -   Flat areas of the image become areas of low gradient, so are valleys in the terrain

    -   Edges in the image have high gradient and so are ridges in the terrain

<img src="assets/Screenshot 2024-05-24 at 22.02.10.png" alt="Screenshot 2024-05-24 at 22.02.10" style="zoom:50%;" />

**Watersheds Algorithm**

-   Sort the pixels: **low to high**
-   For each pixels
    -   If it’s neighbours are all unlabelled, give it a new label

    -   If it has neighbours with a single label, it gets that label
    -   If it has neighbours with two or more labels, it is a watershed
-   This is a very basic version (**Defects**)
    -   It has certain problems in that it can give ‘**thick’ watersheds** rather than fine lines

    -   It is **sensitive to noise** and so can generate lots of small regions
    -   It does show the basic plan, though

**An example**

<img src="assets/Screenshot 2024-04-20 at 23.30.43.png" alt="Screenshot 2024-04-20 at 23.30.43" style="zoom:50%;" />

**Computing Watersheds**

-   Watershed based segmentations can be very **efficient**
    -   It is possible to implement it in $O(n)$ time, where **n is the number of pixels**

    -   Since it takes $O(n)$ time to read or write an image, this is as good as it can get in most situations
-   To implement watersheds we need to sort the pixels
    -   They need to be sorted from highest to lowest gradient

    -   Sorting is $O(n \log(n))$, so how do we get an $O(n)$ algorithm?

**Sorting in Linear Time**

-   In any situation where we have

    - A large number of values, and

    - Those values are drawn from a smaller set of possibilities
-   We can sort in linear time with a **bin sort**
    -   Make a bin `(a list, queue or stack)` for each possible value

    -   For each item: put it in the appropriate bin

## Segmentation and Superpixels

-   Segmentation has motivated development of some useful techniques, but:
    -   ‘segmentation’ is poorly defined
    -   trying to achieve meaningful, semantically correct results without knowledge of the application domain is optimistic at best
    -   segmentation methods really just divide the image into similar regions
-   So let’s accept that and forget the semantics…….

<img src="assets/Screenshot 2024-05-24 at 22.11.02.png" alt="Screenshot 2024-05-24 at 22.11.02" style="zoom:50%;" />

### Simple Linear Iterative Clustering SLIC

-   High-quality, compact, nearly uniform superpixels
-   Simple, efficient algorithm based on **K-means**
-   **Only parameter is number of superpixels required (K)**

1.   Initialize cluster centers on pixel grid in steps S
     -   Image has N pixels, you want K superpixels
     -   Each superpixel is a roughly square area of **roughly N/K pixels**
     -   Each superpixel is roughly **sqrt(N/K) by sqrt(N/K)**
     -   **S = sqrt(N/K)**
2.   Move centres to the position in a 3x3 window with the smallest intensity (or colour) gradient
     -   Move centres away from edges, onto flattest area available
     -   Only a small move, these are still initial positions
3.   Compare each pixel to all cluster centres within 2S pixels and assign it to the best matching centre
     -   Best matching = nearby and similar in colour
     -   Distance measure is sum of colour distance and image plane distance See the paper on Moodle for details

4. Recompute cluster centres as mean colour and position of the pixels belonging to each cluster

5. Repeat 3 and 4 until total change made to position and colour of centres is below a threshold, or for a fixed number of iterations









