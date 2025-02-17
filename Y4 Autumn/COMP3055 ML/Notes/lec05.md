# lec05: Machine Learning Theory and Practice

[toc]

## Polynomial Curve Fitting

<img src="./assets/截屏2024-10-17 10.02.35.png" alt="截屏2024-10-17 10.02.35" style="zoom:50%;" />

> - Plot of a training data set of N = 10 points, each comprising an observation of the input variable `x` along with the corresponding target variable `t`. 
> - The green curve shows the function $\sin(2 \pi x)$ used to **generate the data**. 
> - Our goal is to **predict the value of `t` for some new value of `x`**, without knowledge of the green curve.

- **Classification vs. Regression**
    - Classification: predict a **label** (discrete value)
    - Regression: predict a **response** (continuous value)

### Regression Problem

- $X = (x_1, \dots, x_N)^T$ , $T = (t_1, \dots, t_N)^T$ , 
- **Training set**: generated with $t_n = \sin(2\pi x_n) + b_n,\ n = 1,2,\dots, N $  
    - where $b_n$ is random noise having a **Gaussian Distribution.**
- **Goal**: predict the target value of `t` for some new input value `x`
    - implicitly trying to discover the underlying function $\sin(2\pi x_n)$.
- **Uncertainty**: the observed data are corrupted with **noise**.

### Polynomial Function

- We fit the training data using a polynomial function (linear models) of the form:

$$
y(x,w) = w_0 + w_1x^1 + \cdots + w_Mx^M = \sum_{j=0}^M w_jx^j
$$

- Where 
    - `M` is the **order of the polynomial** (degree of freedom),
    - polynomial coefficients `w0, ..., w_M` are collectively denoted by the vector $w$ (**Weight**)
- **Target**: find the values of **polynomial coefficients**
    - Step 1: Fit the polynomial to the training data
    - Step 2: minimize the **error function**

$$
E(w) = \frac{1}{2} \sum_{n=1}^N \left(y(x_n,w) - t_n \right)^2
$$

<img src="./assets/截屏2024-10-17 10.16.27.png" alt="截屏2024-10-17 10.16.27" style="zoom:33%;" />

- Where
    - E(w) measures the **misfit** between the function `y(x,w)` and the training set data points
    - 1/2 is included for later convenience

### Model Selection

<img src="./assets/截屏2024-10-17 10.15.49.png" alt="截屏2024-10-17 10.15.49" style="zoom:50%;" />

- **Goal**: achieve good generalization by making **accurate predictions** for new data.
- We use **Root-mean-square (RMS)** error on data

$$
E_{RMS} = \sqrt{2 E(w^*)/N}
$$

- Where
    - 𝑁 allows us to compare different sizes of data set
    - $w^*$ is the solution of minimizing $E(w)$

### Overfitting

**Overfitting can occur when:**

- Learning is performed for **too long** (e.g. in Neural Networks).
- The examples in the training set are **not representative** of all possible situations (**is usually the case**!).
- Model parameters are adjusted to **uninformative features** in the training set that have no causal relation to the true underlying target function!
- **Increasing the size** of the data set reduces the overfitting problem.

<img src="./assets/截屏2024-10-17 10.19.40.png" alt="截屏2024-10-17 10.19.40" style="zoom:50%;" />

### Regularization

- Regularization can control the overfitting phenomenon by adding **penalty term to the error function** to discourage the coefficients from reaching large values.

$$
E(w) = \frac{1}{2} \sum_{n=1}^N \left(y(x_n,w) - t_n \right)^2 + \frac{\lambda}{2}\|w\|^2
$$

- Where
    - $\| w \|^2 = w^T w = w_0^2 + w_1^2 + \dots + w^2_M$
    - Coefficient $\lambda$ governs the relative importance of the regularization term compared with the sum-ofsquares error term.

<img src="./assets/截屏2024-10-17 10.27.15.png" alt="截屏2024-10-17 10.27.15" style="zoom:50%;" />

- Table of the coefficients $w^*$ for `M = 9` polynomials with various values for the regularization parameter 𝜆 .
- $\lambda$ controls the **effective complexity** of the model and hence determines the **degree of overfitting**

## Cross Validation

- **Idea #1**: Choose hyperparameters that work best on the data
- **Idea #2**: Split data into **train and test**, choose hyperparameters that work best on **test data**
- **Idea #3**: Split data into **train, val, and test**; choose hyperparameters on **val** and evaluate on **test**
- **Idea #4**: **Cross-Validation**: Split data into **folds**, try each fold as validation and average the results

<img src="./assets/截屏2024-10-17 10.33.14.png" alt="截屏2024-10-17 10.33.14" style="zoom:50%;" />

- Cross Validation is often used to **counter overfitting**.
- Partition the dataset into `S` groups, with training sets, a validation set and a testing set.
    - The training set is used to **determine the coefficients** w
    - The validation set is used to **optimize the model complexity** (hyperparameters, either M or 𝜆 in the previous example )
    - The testing set is used to **evaluate the final selected mode**
- The procedure is then repeated for all `S` possible choices, the performance scores from the `S` runs are then **averaged**.

<img src="./assets/截屏2024-10-17 10.36.50.png" alt="截屏2024-10-17 10.36.50" style="zoom:50%;" />

- For large datasets, a single split is usually sufficient.
- For smaller datasets, rely on cross validation
- Estimate the total error as the **average of each fold error**.

## Classification Measures

**Types**

- Error Rate (Accuracy)
- Precision/Recall
- F-measure
- ROC curve
- Confusion matrix

### Balanced vs. Unbalanced data

- **Balanced set**: (roughly) **equal number** of positive / negative examples

<img src="./assets/截屏2024-10-17 10.47.28.png" alt="截屏2024-10-17 10.47.28" style="zoom:50%;" />

- **Unbalanced set**: unequal number of positive / negative examples

<img src="./assets/截屏2024-10-17 10.47.39.png" alt="截屏2024-10-17 10.47.39" style="zoom:50%;" />

### Error Rate

- TP：真阳，TN：真阴，FP：假阳，FN：假阴
- **FP: Type I error, FN: Type II error**
- Classification **error rate**: 
    - $(TP + TN) / (TP + TN + FP + FN)$
    - Accuracy: 1 - **error rate**

### Precision/Recall

<img src="./assets/截屏2024-10-17 10.48.26.png" alt="截屏2024-10-17 10.48.26" style="zoom:50%;" />

- **Precision**: $TP / (TP+FP)$
- **Recall**: $TP/(TP+FN)$
- For the positive class:
    - Classifier A: Recall = 50%, Precision = 25% 
    - Classifier B: Recall = 0%, Precision = 0%

### F-measure

- Comparing different approaches is difficult when using multiple evaluation measures (e.g. Recall and Precision)
- F-measure combines **recall and precision into a single measure**:

$$
f_\beta = (1+\beta^2) \frac{PR}{(\beta^2P) + R } = \frac{1 + \beta^2}{\frac{1}{P} + \frac{\beta^2}{R}}
$$

- Where
    - $\beta$ is a non-negative real values
    - $\beta = 1$: F1-measure, Precision and Recall 同样重要
    - $\beta > 1$: F1-measure, 更重视 Recall
    - $\beta < 1$: F1-measure, 更重视 Precision

### ROC Curves

- **TPR（真阳性率/Recall/Sensitivity）**: 表示在所有实际为正类的样本中，模型正确分类为正类的比例
    - $TPR = TP / (TP + FN)$
- **FPR（假阳性率）**: 表示在所有实际为负类的样本中，模型错误分类为正类的比例
    - $FPR = FP / (FP + TN)$
- **Receiver Operator Characteristic (ROC)**：以 FPR 为横轴，TPR 为纵轴
- **Area Under Curve (AUC)**：ROC 曲线下的面积，用于量化 ROC 曲线的优劣
    - **AUC = 1**：完美分类器
    - **AUC = 0.5**：分类器和随机猜测一样，完全没有区分度
    - **AUC < 0.5**：分类器表现得比随机猜测还要差，通常表明模型反向分类

<img src="./assets/截屏2024-10-17 12.02.38.png" alt="截屏2024-10-17 12.02.38" style="zoom:50%;" />

### Confusion Matrix 混淆矩阵

- A visualization tool used to present the results attained by a learner.
- Easy to see if the system is commonly mislabeling one class as another.

<img src="./assets/截屏2024-10-17 12.57.30.png" alt="截屏2024-10-17 12.57.30" style="zoom:50%;" />

## Curse of Dimensionality 维度诅咒

- The amount of data needed to support the result often **grows exponentially** with the dimensionality.
- Consider the volume of a sphere of radius `r` in D dimensions
    - $V_3(r) = \frac{4}{3}\pi r^3$ , $V_D(r) = K_D r^D$ 
    - Where the constant $K_D$ depends only on D
- Consider the fraction of the volume of the sphere between radius $1-\epsilon$ and 1

$$
\frac{V_D(1) - V_D(1-\epsilon)}{V_D(1)} = 1- (1-\epsilon)^D
$$

- For large D, the fraction tend to **1** even for small values of $\epsilon$
- Therefore, **Distance functions losing their usefulness**






