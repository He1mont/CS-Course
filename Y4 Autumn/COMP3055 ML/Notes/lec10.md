# lec10: Data Processing and Representation

[toc]

## Problems

- **Object Detection**: Many detection windows
- Each window is very high dimension data

<img src="./assets/截屏2024-11-04 16.16.03.png" alt="截屏2024-11-04 16.16.03" style="zoom:50%;" />

### Processing Methods

<img src="./assets/截屏2024-11-04 16.16.52.png" alt="截屏2024-11-04 16.16.52" style="zoom: 33%;" />

## Feature Extraction/Dimensionality Reduction

- It is impossible to processing raw image data (pixels) directly
    - Too many of them (or data dimensionality too high)
    - **Curse of dimensionality** problem
- Process the raw pixel to produce a smaller set of numbers which will **capture most information** contained in the original data 
    - this is often called a **feature vector (feature extraction)**
- Basic Principle
    - From a raw data (vector) X of N-dimension to a new vector Y of n-dimension **(n << N)** 
    - via a **transformation matrix A** such that Y will capture most information in X

**Principal Component Analysis (PCA)**

- Goal: We wish to explain/summarize the underlying **variance-covariance** structure of a large set of variables through **a few linear combinations** of these variables.

- Application:
    - Data Visualization, Data Reduction, Data Classification
    - Trend Analysis, Factor Analysis, Noise Reduction

### An Example

> **The movement of an ideal spring**
>
> - Using 3 cameras, each records 2d projection of the ball’s position. We record the data for 1 minutes at 200Hz
> - We have 12,000, 6-d data
> - Determining that only the dynamics along x are important and the rest are redundant.

<img src="./assets/截屏2024-11-04 16.23.51.png" alt="截屏2024-11-04 16.23.51" style="zoom: 33%;" />

<img src="./assets/截屏2024-11-04 16.26.42.png" alt="截屏2024-11-04 16.26.42" style="zoom:50%;" />

- 虽然有六个维度，但是我们知道弹簧的变动只和一个维度有关系，因此可以只简化成一个一维向量

<img src="./assets/截屏2024-11-04 23.11.45.png" alt="截屏2024-11-04 23.11.45" style="zoom: 67%;" />

## Variance and Covariance 方差和协方差

- Given $A =\{a_1,a_2,\dots,a_n\}, B =\{b_1,b_2,\dots,b_n\} $ with mean value $\mu_A, \mu_B$
    - PPT 里给的例子是假设均值为0

- The variance of A and B are defined as

$$
\sigma_A^2 = \frac{1}{n}\sum_i (a_i - \mu_A)^2,\quad \sigma_B^2 = \frac{1}{n}\sum_i (b_i - \mu_B)^2,
$$

- The covariance (redundancy) of A and B

$$
\sigma^2_{AB} = \frac{1}{n}\sum_i (a_i - \mu_A)(b_i - \mu_B)
$$

### Signal-to-Noise Ratio SNR 信噪比

>SNR可以作为特征选择和评估数据质量的一个参考指标
>
>- 高信噪比通常意味着特征和目标变量之间的相关性强，模型能够从数据中学习到有价值的模式
>- 而低信噪比则表示特征含有大量随机性或无关信息，容易导致模型过拟合或泛化性能差

### Redundancy 冗余

<img src="./assets/截屏2024-11-04 23.18.56.png" alt="截屏2024-11-04 23.18.56" style="zoom: 67%;" />

### Covariance Matrix 协方差矩阵

- Given matrix $X = [x_{mn}]$, the covariance matrix of the data is defined as

$$
S_X = \frac{1}{n-1}XX^T
$$

- Covariance measures the **degree of the linear relationship** between variables. A large positive value indicates positively correlated data. 
- The absolute magnitude of the covariance measures the degree of redundancy.
- The $ij^{th}$ element of $S_X$ is the **dot product** between the vector of the $i^{th}$ measurement type with the vector of the $j^{th}$ measurement type.
- $S_X$ is an $m*m$ square matrix, where
    - The **diagonal terms** of $S_X$ are the **variance** of particular measurement type
    - The **off-diagonal terms** of $S_X$ are the **covariance** between measurement types

- It describes all **relationships** between pairs of measurements in our data set.
- A larger covariance indicates **large correlation (more redundancy)**, zero covariance indicates entirely uncorrelated data.

### Objective of PCA

- Minimize **redundancy**, measured by the **magnitude of the covariance**
- Maximize the **signal**, measured by the **variance** (diagonal element of the covariance matrix)
- If our goal is to **reduce redundancy**, then we want each variable **co-vary** a little as possible
    - Precisely, we want the covariance between separate measurements to be **zero**
    - **Diagonalise** the covariance matrix

### Remove Redundancy

- Optimal covariance matrix $S_Y$- **off-diagonal terms set zero**
- Therefore removing redundancy, diagonalises $S_Y$

## Solving PCA

### Diagonalising the Covariance Matrix

- There are many ways to diagonalizing SY, PCA choose the simplest method. (**eigenvector decomposition**)
- PCA assumes all **basis vectors** are orthonormal. P is an **orthonormal matrix**
- PCA assumes the directions with the **largest variances** are the most important or most principal.
- PCA works as follows
    - PCA first selects **a normalised direction** in m-dimensional space along which **the variance of X is maximised** – it saves the direction as p1 
    - It then finds another direction, along which variance is maximised subject to the orthonormal condition – it restricts its search to all directions perpendicular to all previous selected directions.
    - The process could continue until m directions are found. The resulting ORDERED set of p’s are the **principal components**
    - The variances associated with each direction p i quantify how principal (important) each direction is – thus rank-ordering each basis according to the corresponding variance.

### Karhunen-Loeve Transform KLT

<img src="./assets/截屏2024-11-17 16.22.49.png" alt="截屏2024-11-17 16.22.49" style="zoom: 67%;" />

### Solving PCA Eigenvectores of Covariance

$$
Y = PX,\quad S_Y = \frac{1}{n-1}YY^T
$$

- Find some **ortho-normal** matrix P such that $S_Y$ is diagonalized.
- The row of P are **the principal components** of X

$$
\begin{align*}
S_Y &= \frac{1}{n-1}YY^T = \frac{1}{n-1}PX(PX)^T \\
 &=\frac{1}{n-1}PXX^TP^T = \frac{1}{n-1}P(XX^T)P^T\\
 &= \frac{1}{n-1}PAP^T
\end{align*}
$$

- **$A = XX^T$ is a symmetric matrix, which can be diagonalised by an orthonormal matrix of its eigenvectors** 

$$
A= EDE^T
$$

- D is a diagonal matrix, E is a matrix of eigenvectors of A arranged as **columns**

<img src="./assets/截屏2024-11-17 16.35.30.png" alt="截屏2024-11-17 16.35.30" style="zoom: 67%;" />
$$
S_Y = \frac{1}{n-1}D
$$

- The **principal component** of $X$ are the **eigenvectors** of the covariance matrix of $X$ ($S_X$ ); or the rows of P
- The ith diagonal value of $S_Y$ is the variance of X along $p_i$

## PCA Procedures in a 2D Numerical Example

### Step 1: Subtract the mean

- All the x values have average(x) subtracted and y values have average(y) subtracted from them. 
    - This produces **a data set whose mean is zero.**
- Subtracting the mean makes **variance and covariance calculation easier** by simplifying their equations. The variance and co-variance values are not affected by the mean value.

<img src="./assets/截屏2024-11-06 13.28.35.png" alt="截屏2024-11-06 13.28.35" style="zoom:50%;" />

### Step 2: Calculate the Covariance Matrix

<img src="./assets/截屏2024-11-06 13.30.31.png" alt="截屏2024-11-06 13.30.31" style="zoom: 33%;" />

- since the **non-diagonal elements** in this covariance matrix are **positive**, we should expect that both the x and y variable **increase together** (**x与y正向关**)

### Step 3: Calculate eigenvectors and eigenvalues

<img src="./assets/截屏2024-11-06 13.32.06.png" alt="截屏2024-11-06 13.32.06" style="zoom: 33%;" />

## Feature Extraction

- Reduce dimensionality and form feature vector
    - the eigenvector with the highest eigenvalue is the principal component of the data set.
    - In our example, the eigenvector with the larges eigenvalue was the one that pointed down the middle of the data.
    - Once eigenvectors are found from the covariance matrix, the next step is to **order them by eigenvalue**, highest to lowest. This gives you the components in order of significance.







