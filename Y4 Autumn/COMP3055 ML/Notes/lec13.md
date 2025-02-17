# lec13: Support Vector Machine

[toc]

## Linear Separators

<img src="./assets/截屏2024-11-11 17.20.02.png" alt="截屏2024-11-11 17.20.02" style="zoom:50%;" />

- We don't know which linear separator is optimal

### Classification Margin

<img src="./assets/截屏2024-11-11 17.24.53.png" alt="截屏2024-11-11 17.24.53" style="zoom:50%;" />

- Distance from example $x_s$ to the separator is $r = |w^Tx_s +b|/|w|$
- Examples closest to the hyperplane are support vectors.
- Margin $\rho$ of the separator is the distance between support vectors.
- **Maximizing the margin is good according to intuition.**
- Implying that **only support vectors matter**; other training examples are ignorable.

## Linear SVM Mathematically

- Let training set $\{(x_i,y_i)\}, x_i\in R^d, y_i\in \{-1,1\}$ be separated by a hyperplane with margin $r=2d$
- Then for each training example $(x_i , y_i )$

$$
\frac{w^Tx_i + b}{\| w\|} \left\{ 
\begin{array}{ll}
\le -d & \text{if } y_i = -1 \\
\ge d & \text{if } y_i = 1
\end{array}
\right. \Rightarrow \left( \frac{w^Tx_i + b}{\| w\|} \right )\cdot y_i \ge d
$$

- For every support vector $x_s$, the above inequality is an equality, **after rescaling**, we have

$$
(w^Tx_i + b )\cdot y_i = 1
$$

- Then the margin can be expressed as 

$$
d = \frac{|w^T x_s + b|}{\| w\|} = \frac{1}{\| w\|}, \quad r = 2d =\frac{2}{\|w\|}
$$

- We can formulate the quadratic optimization problem:
    - Find w and b such that $r = 2/\|w\|$  is maximized, which is the same as 
    - Find w and b such that $\Phi(w) = \|w\|^2/2$  is maximized

<img src="./assets/截屏2024-11-14 09.23.06.png" alt="截屏2024-11-14 09.23.06" style="zoom:50%;" />

- Need to optimize a **quadratic function** subject to linear constraints.
- Quadratic optimization problems are a well-known class of mathematical programming problems for which several (non-trivial) algorithms exist.
- The solution involves constructing a **dual problem** where a **Lagrange multiplier** $\alpha_i$ is associated with every inequality constraint in the primal (original) problem:

<img src="./assets/截屏2024-11-14 09.41.09.png" alt="截屏2024-11-14 09.41.09" style="zoom:50%;" />

- 略过中间的数学推导，只需要知道最后的 classifying function 与w无关

$$
f(x) = \sum \alpha_i y_i x_i^Tx + b
$$

## Soft Margin Classification

<img src="./assets/截屏2024-11-14 09.27.12.png" alt="截屏2024-11-14 09.27.12" style="zoom:50%;" />

- What if the training set is **not linearly separable?**
- **Slack variables** $\xi_i$ which measures the distance of the point to its marginal hyperplane **if it is on the wrong side**, **otherwise 0**, can be added to allow misclassification of difficult or noisy examples, resulting margin called **soft**.
- Applying Soft Margin, SVM tolerates a few dots to get misclassified and tries to balance the **trade-off** between finding a line that maximizes the margin and minimizes the misclassification.

<img src="./assets/截屏2024-11-14 09.28.52.png" alt="截屏2024-11-14 09.28.52" style="zoom:50%;" />

- **Parameter C** can be viewed as a way to **control overfitting**: it “trades off” the relative importance of maximizing the margin and fitting the training data

<img src="./assets/截屏2024-11-14 09.29.33.png" alt="截屏2024-11-14 09.29.33" style="zoom:50%;" />

- **Dual Problem Formulation**

<img src="./assets/截屏2024-11-14 09.41.24.png" alt="截屏2024-11-14 09.41.24" style="zoom:50%;" />

- 忽略中间的推导过程，最后得到一个与 w 无关的方程

$$
f(x) = \sum \alpha_i y_i x_i^Tx + b
$$

## Non-Linear SVM

- **General idea**: the original feature space can always be mapped to some **higher-dimensional feature space** where the training set is separable:
- 如果数据集在当前维度不可二分，那就映射到高维的feature map上

<img src="./assets/截屏2024-11-14 09.35.39.png" alt="截屏2024-11-14 09.35.39" style="zoom:50%;" />

### The "Kernel Trick"

- The linear classifier relies on inner product between vectors

$$
K(x_i,x_j) = x_i^T x_j
$$

- If every data point is mapped into high-dimens space via some transformation $\Phi:x \to \phi(x)$, the inner product becomes:

$$
K(x_i,x_j) = \phi(x_i)^T \phi(x_j)
$$

- A **kernel function** is a function that is equivalent to an inner product in some feature space.
- Thus, a kernel function **implicitly** maps data to a highdimensional space (without the need to compute each φ(x) explicitly).

### Kernel Functions

- **Mercer’s theorem**: Every semi-positive definite symmetric function is a kernel.

**Examples**

<img src="./assets/截屏2024-11-14 09.39.46.png" alt="截屏2024-11-14 09.39.46" style="zoom:50%;" />

### SVM Parameter Tuning

- The gamma parameter is the inverse of the standard deviation of the RBF kernel (Gaussian function), which is used as similarity measure between two points.
- Small gamma, large variance and vice versa.
- Large may cause complicated decision boundary or give rise to over-fitting.

### Non-Linear SVM Mathematically

- **Dual Problem Formulation**

<img src="./assets/截屏2024-11-14 09.42.05.png" alt="截屏2024-11-14 09.42.05" style="zoom:50%;" />

- The solution is as follows, where **optimization for finding $\alpha_i$ remains the same!**

$$
f(x) = \sum \alpha_i y_i K(x_i, x) + b
$$

### SVM and Kernel Methods

<img src="./assets/截屏2024-11-14 09.44.08.png" alt="截屏2024-11-14 09.44.08" style="zoom:50%;" />

- Mapping data points from low dimensional space to a higher dimensional space can make it possible to apply SVM even for non-linear data sample.
- ==We don’t need to know the **mapping function** itself, as long as we know the **Kernel function (Kernel Trick)**==
- How the tuning parameter gamma can lead to over fitting or bias in RBF kernel.

## Multi-Class Classification

- Some algorithms are designed for binary classification problems:
    - Logistic Regression
    - Perceptron
    - Support Vector Machines
- Instead, **heuristic methods** can be used to split a **multi-class classification** problem into **multiple binary classification** datasets and train a binary classification model each
    - One-vs-All (OVA)
    - One-vs-One (OvO)

### One-vs-All (OVA)

<img src="./assets/截屏2024-11-14 09.56.54.png" alt="截屏2024-11-14 09.56.54" style="zoom:50%;" />

### One-vs-One (OVO)

<img src="./assets/截屏2024-11-14 09.57.10.png" alt="截屏2024-11-14 09.57.10" style="zoom:50%;" />
