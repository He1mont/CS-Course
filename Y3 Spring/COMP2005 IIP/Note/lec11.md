# lec11: Convolutional Neural Networks - CNN

[toc]

## Background

**Traditional Pipeline for Machine Learning**

<img src="assets/Screenshot 2024-05-25 at 00.02.14.png" alt="Screenshot 2024-05-25 at 00.02.14" style="zoom:50%;" />

**Classical Neural Network**

<img src="assets/Screenshot 2024-05-25 at 00.04.19.png" alt="Screenshot 2024-05-25 at 00.04.19" style="zoom:50%;" />

**Convolutional Neural Network**

-   Make the assumption the input is **an image**
-   Neural networks that use convolution in place of general matrix multiplication in at least one of their layers.
-   An end-to-end learned solution to many vision tasks
-   Local analysis matches the natural structure of the most images
-   Learn hierarchical models of image content

<img src="assets/Screenshot 2024-05-25 at 00.04.57.png" alt="Screenshot 2024-05-25 at 00.04.57" style="zoom:50%;" />

-   **Multilayer Perceptron Network - MLP**
    -   Wide application scenario–not just images 
    -   Neurons are fully connected–can’t scale well to large size data (e.g.images)
-   **Convolutional Neural Network - CNN**
    -   Neurons are arranged in‘3D’, each neuron is only connected to a small region of previous layer 
    -   Typical CNN structure: Input-conv-activation-pool- fully connected- output

**Convolutional Neural Network Architecture**

<img src="assets/Screenshot 2024-05-25 at 00.06.08.png" alt="Screenshot 2024-05-25 at 00.06.08" style="zoom:50%;" />

## Components of CNN

<img src="assets/Screenshot 2024-05-25 at 00.06.31.png" alt="Screenshot 2024-05-25 at 00.06.31" style="zoom:50%;" />

### Locally Connected Layers - Traditional NN

<img src="assets/Screenshot 2024-05-25 at 00.18.12.png" alt="Screenshot 2024-05-25 at 00.18.12" style="zoom:50%;" />

<img src="assets/Screenshot 2024-05-25 at 00.18.24.png" alt="Screenshot 2024-05-25 at 00.18.24" style="zoom:50%;" />

### Convolution Layers

<img src="assets/Screenshot 2024-05-25 at 00.18.40.png" alt="Screenshot 2024-05-25 at 00.18.40" style="zoom:50%;" />

**Parameters for training process**

-   **Number of Filters**
    -   Defines the depth of the output feature map(s)
-   **Stride**
    -   number of pixels the filtering window moves after each operation
-   **Zero-padding**
    -   Adds zeroes to every side of the input boundaries 
    -   ensures filters fit the input image

**Convolution**

-   We wish to convolve the input image with a set of learnable, small-size filters
-   size(W); filter size(F); zero padding(P); stride(S)
    -   F, conv filter size,is like are captive field
-   Output volume size calculation: (W-F+2P)/S+1

<img src="assets/Screenshot 2024-05-25 at 00.22.20.png" alt="Screenshot 2024-05-25 at 00.22.20" style="zoom:50%;" />

<img src="assets/Screenshot 2024-05-25 at 00.22.41.png" alt="Screenshot 2024-05-25 at 00.22.41" style="zoom:50%;" />

-   **Most important layer**
    -   Performs major computations

    -   Takes in **input image**, performs filtering which produces **feature map(s)**

    -   Filters using image processing techniques (e.g., edge detection, blur and sharpen)

    -   Filtering is performed using `3x3` kernels to perform the dot product

<img src="assets/Screenshot 2024-05-28 at 20.54.04.png" alt="Screenshot 2024-05-28 at 20.54.04" style="zoom:50%;" />

### Pooling Layer

>   **Reduces the dimensionality of the resulting conv layer**

-   A number of pooling methods exist, including subsampling
-   Effect is to reduce the resolution of the filter outputs
-   Subsequent convolutional layers therefore access larger areas of the image

<img src="assets/Screenshot 2024-05-28 at 20.56.04.png" alt="Screenshot 2024-05-28 at 20.56.04" style="zoom:50%;" />

-   Three types of pooling operation
    -   Average pooling
    -   Max pooling
    -   Global averge pooling

-   **Effect of Pooling**
    -   Reduce the **spatial size** of the representation and reduce the amount of parameters
    -   ﻿﻿Effectively down-sampling the input to increase the receptive field size
    -   ﻿﻿Max operation with stride of 2 is a popular choicel

### Activation Function

-   determines to neural network's output

<img src="assets/Screenshot 2024-05-28 at 20.58.13.png" alt="Screenshot 2024-05-28 at 20.58.13" style="zoom:50%;" />

### Fully Connected Layer

-   Utilises features extracted from previous layers, performs task classification
-   Global feature learning: fully connected to all activations in the previous layer, as the same in MLP.
-   ﻿﻿Softmax - converts the prediction to the range of [0.. 1] for each class

<img src="assets/Screenshot 2024-05-28 at 21.08.06.png" alt="Screenshot 2024-05-28 at 21.08.06" style="zoom:50%;" />

### Output Layer

-   Performs a logistic function to classify tasks

-   Uses Softmax activation function where probability ranges from 0 to 1 – scores given to each class
-   Sometimes, embedded within the FC layer
