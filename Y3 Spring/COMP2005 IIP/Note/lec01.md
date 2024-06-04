# lec01: Digital Images and Point Processes

[toc]

## Digital Image Formation

###  A Simple Camera Model

-   A simple camera model is the **pinhole camera model**
    -   Light passes through a small hole and falls on an **image plane**
    -   The image is inverted and scaled
    -   Early cameras used this approach

<img src="assets/Screenshot 2024-02-25 at 21.56.34.png" alt="Screenshot 2024-02-25 at 21.56.34" style="zoom:50%;" />

-   **Real cameras do not have ‘pinholes’**
    -   A pinhole lets very little light in, leading to **long exposures**
    -   Larger holes lead to **blurred** images
    -   A **lens** can make a large hole act like a small one

### Sampling and Quantisation

-   **Sampling**: Digitisation of the **spatial coordinates**
    -   determines **spatial resolution**
-   **Quantisation**: Digitisation of the **light intensity function**
    -   determines gray level, colour or dariometic resolution
    -   How much of the light energy is quantized

<img src="assets/Screenshot 2024-05-25 at 17.10.36.png" alt="Screenshot 2024-05-25 at 17.10.36" style="zoom:50%;" />

>   **采样**是指在空间上对图像信号进行离散化的过程。具体来说，它涉及到选择图像中的特定位置并记录这些位置的颜色（或灰度）值。采样决定了图像的空间分辨率，即图像的细节程度和尺寸。
>
>   **量化**是指将采样点的颜色（或灰度）值从一个连续的范围映射到有限的离散级别的过程。这个过程决定了图像的颜色深度，即图像可以表示的颜色的数量。

### Sampling

-   How many samples to take => how many pixels in the image
-   The  Nyquist Rate
    -   Samples must be taken at a rate that *is **twice the frequency** of the highest frequency component to be reconstructed*.
    -   Under-sampling: sampling at a rate that is **below the Nyquist rate**.
    -   **Aliasing**: artefacts that result from under-sampling.

**Aliasing （混叠）**

-   Aliasing occurs when **two signals (images) become indistinguishable** when sampled
-   In our case the two signals are **the true image** (the image that would be seen if there were no quantisation) and the one reconstructed by the human vision system from a sampled image

**Anti-aliasing**

-   Aliasing can be introduced when an image is resampled, **if the sampling rate of the new image is less than the Nyquist rate of the original**
-   **Smooth out high frequency signals before sampling** so its impossible to “see” the alias

<img src="assets/Screenshot 2024-02-25 at 22.08.54.png" alt="Screenshot 2024-02-25 at 22.08.54" style="zoom: 50%;" />

### Quantisation

-   How many grey levels to store
-   Determines the number of levels of color/intensity to be represented at each pixel
-   Sampling and quantisation occur naturally during image acquisition, but can also be applied to existing images
    -   e.g. during **resizing and compression**


**Re-Sampling and Re-Sizing**

-   When **downsampling**
    -   need to compute a summary pixel value from each local area

<img src="assets/Screenshot 2024-05-25 at 17.26.42.png" alt="Screenshot 2024-05-25 at 17.26.42" style="zoom:50%;" />

-   When **upsampling**
    -   need to interpolate from the known values to produce an estimate at the unknown 

<img src="assets/Screenshot 2024-05-25 at 17.27.00.png" alt="Screenshot 2024-05-25 at 17.27.00" style="zoom:50%;" />

**Re-quantisation**

-   Pixel values are integers in a fixed range
-   Grey level resolution can be dropped by dividing each pixel value by a constant, **but there is a side effect**
-   Can’t increase grey level resolution of a single pixel
-   **Super-resolution methods** exist that combine multiple exposures of the same scene, and so have more than one measurement of each pixel

## Acquiring Colour Images

### Bayer Pattern

>   Bayer Pattern由重复的2x2格子组成，这个格子包含两个绿色、一个红色和一个蓝色滤镜。这种排列模仿了人类视觉系统的特性，因为人眼对绿色的敏感度比红色和蓝色要高。因此，Bayer Pattern给予绿色通道更多的像素，以提供更高的亮度分辨率，从而改善整体图像质量。

-   B is measured, G is the mean of the 4 neighbours, R is the mean of the diagonals

<img src="assets/Screenshot 2024-02-25 at 22.23.54.png" alt="Screenshot 2024-02-25 at 22.23.54" style="zoom:50%;" />

<img src="assets/Screenshot 2024-02-25 at 22.25.34.png" alt="Screenshot 2024-02-25 at 22.25.34" style="zoom:50%;" />

### Colour vs. Greyscale

-   Many image processing methods were developed for single value images
-   We can covert an RGB image to greyscale using

$$
i = 0.3 * r+0.59*g+0.11*b
$$

<img src="assets/Screenshot 2024-02-25 at 22.27.14.png" alt="Screenshot 2024-02-25 at 22.27.14" style="zoom:50%;" />

## Colour Spaces

### HSV Space

-   HSV is based on **colour** rather than **light**
    -   **Hue**: what general colour is it 色相 0 - 360
    -   **Saturation**: how strongly coloured is it 饱和度 0% - 100%
    -   **Value**: how bright or dark is it 明度 0% - 100%

<img src="assets/Screenshot 2024-02-25 at 22.29.19.png" alt="Screenshot 2024-02-25 at 22.29.19" style="zoom:50%;" />

-   HSV separates colour from intensity making it less sensitive to **illumination changes**

<img src="assets/Screenshot 2024-02-25 at 22.30.01.png" alt="Screenshot 2024-02-25 at 22.30.01" style="zoom:50%;" />

>   假设你有一张图片，其中一个红色物体在不同的光照条件下被拍摄：
>
>   -   **在RGB模型中**：
>       -   在光照强烈时，红色物体的RGB值可能会变成（255, 100, 100）。
>       -   在光照较弱时，红色物体的RGB值可能会变成（150, 50, 50）。
>       -   RGB值的变化使得颜色的识别变得困难，因为颜色和亮度是混在一起的。
>   -   **在HSV模型中**：
>       -   在光照强烈时，红色物体的HSV值可能会是（0度, 60%, 100%）。
>       -   在光照较弱时，红色物体的HSV值可能会是（0度, 60%, 60%）。
>       -   这里，色相（Hue）和饱和度（Saturation）保持不变，只是明度（Value）变化。这样，在不同光照条件下，颜色识别更稳定。

## Intensity Transform 强度变换

### Linear Transforms

-   Two commonly used **point processes** are **multiplication by** and **addition of a constant**

$$
g(x,y) = a\cdot f(x,y) + b
$$

-   `a` is the **gain**, and controls **contrast**
-   `b` is the **bias** and controls **brightness**

**Negation**

-   Often used to make fine details **more visible**, e.g. in digital mammograms:

$$
g(x,y) = f_{\min} + f_{\max} - f(x,y)
$$

<img src="assets/Screenshot 2024-02-25 at 22.36.20.png" alt="Screenshot 2024-02-25 at 22.36.20" style="zoom:50%;" />

**Dynamic Range**

-   Digital images are sampled – they contain a **fixed number of data values**
-   Digital image representations can only store a fixed number of values
-   Intensity transforms can produce values that are
    -   **outside that range and so can’t be stored**
    -   **clustered in a small part of that range and so are hard to distinguish**
-   Some intensity transforms need data in a particular range

**Contrast Stretching 对比度拉伸**

-   To convert a source image in which intensities range from `min_s` to `max_s` to one in which they range from `min_t` to `max_t`

$$
g(x,y) = \frac{\max(t) - \min(t)}{\max(s) - \min (s)} \cdot (f(x,y) - \min(s)) + \min(t)
$$

-   The above equation is equivalent to 

$$
\frac{g(x,y) - \min(t)}{\max(t) - \min(t)} = \frac{f(x,y) - \min (s)}{\max(s) - \min (s)}
$$

>   假设我们有一幅灰度图像，像素值范围从50到200。我们希望将其对比度拉伸到0到255的范围：
>
>   1.  **原始灰度范围**：$I_{\min⁡}=50, \ I_{\max}=200$
>   2.  **目标灰度范围**：$G_{\min⁡}=0, \ G_{\max}=255$
>
>   应用线性变换公式，对于每个像素值 $I$：
>   $$
>   I'= \frac{255 - 0}{200 -50} \cdot (I - 50) + 0
>   $$

### Non-linear Transforms

**Thresholding**

<img src="assets/Screenshot 2024-02-25 at 22.45.09.png" alt="Screenshot 2024-02-25 at 22.45.09" style="zoom:50%;" />

**Grey Level Slicing**

-   Highlights a specific range of intensities

<img src="assets/Screenshot 2024-02-25 at 22.46.53.png" alt="Screenshot 2024-02-25 at 22.46.53" style="zoom:50%;" />

**Gamma Correction**

-   What is: a point intensity transform that raises a pixel value to a power using

$$
g(x,y) =c \cdot f(x,y)^{\gamma}
$$

-   When an image is displayed on a screen, the hardware used effectively applies an intensity transform
-   You send a voltage proportional to the intensity of a pixel, the screen displays an intensity that is related to that, but not how you may think

<img src="assets/Screenshot 2024-02-25 at 22.48.43.png" alt="Screenshot 2024-02-25 at 22.48.43" style="zoom:50%;" />

>   屏幕的亮度 *L* 与输入电压 *V* 的关系通常是非线性的。图中给出了一个例子，例如
>   $$
>   L \approx V^{2.5}
>   $$

### Key points

-   Point processes operate on each pixel independently
-   Linear processes change the appearance of the whole image
-   Non-linear processes can differentiate objects/image regions
