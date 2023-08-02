## Session 9: Introduction to Machine Learning

>   ### Outline
>
>   -   Step1: Function with unknown parameters
>   -   Step2: Define loss from training data
>       -   $e$: mean absolute error (MAE)
>       -   $L$: loss
>       -   error surface
>   -   Step3: Optimization
>       -   Gradient Descent
>   



[**Here is a tutorial from Youtube by the original author.**](https://www.youtube.com/playlist?list=PLJV_el3uVTsNxV_IGauQZBHjBKZ26JHjd)

#### 1. Machine Learning Steps

-   Step1: Function with Unknown Parameters
-   Step2: Define loss from training data
-   Step3: Optimization



##### Step1. Function with Unknown Parameters 

-   $y = b + wx_{1}$
    -   $y$ : number of  views on 2/26
    -   $x_{1}$ : number of views on 2/25
    -   $w$ and $b$ are unknown parameters, learned from data
    -   w: weight, b: bias
    -   **The linear model may be too simple**



##### Step 2. Define Loss from Training Data

-   Loss is a function of parameters, evaluating how good a set of values is
-   denoted by $L(b,w)$, we take $L(0.5k, 1)$ as example

<img src="assets/Screenshot 2023-04-18 at 14.09.46.png" alt="Screenshot 2023-04-18 at 14.09.46" style="zoom:40%;" />

<img src="assets/Screenshot 2023-04-18 at 14.10.12.png" alt="Screenshot 2023-04-18 at 14.10.12" style="zoom:40%;" />

-   Loss: 
    $$
    \begin{equation*}
        L = \frac{1}{N}\sum_{n}e_{n}
    \end{equation*}
    $$
-   $e = |y - \hat{y}|$

    -   L is mean absolute error (MAE)
    -   ==we choose MAE in the above example==
-   $e = (y - \hat{y})^2$
    -   L is mean square error (MSE)

-   Error Surface

    -   try different parameters w and b, and calculate its loss
    -   **the smaller Loss, the better**


<img src="assets/Screenshot 2023-04-19 at 22.21.24.png" alt="Screenshot 2023-04-19 at 22.21.24" style="zoom:40%;" />



##### Step3. Optimization

-   Gradient Descent
    -   Randomly pick an initial value $w^{0}$
    -   **主元的思想**，我们可以把b当作参数，先考虑w
        -   $w^{1} \leftarrow w^{0} - \eta \frac{\partial L}{\partial W}|_{w = w^{0}}$
    -   $\eta$ : learning rate
        -   called hyperparameters
    -   Update $w$ iteratively
        -   $\eta \frac{\partial L}{\partial W}|_{w = w^{0}}>0$ : increase $w$
        -   $\eta \frac{\partial L}{\partial W}|_{w = w^{0}}<0$ : decrease $w$ 

<img src="assets/Screenshot 2023-04-18 at 14.22.51.png" alt="Screenshot 2023-04-18 at 14.22.51" style="zoom:40%;" />

-   -   Update $w$ and $b$ iteratively

<img src="assets/Screenshot 2023-04-19 at 22.42.04.png" alt="Screenshot 2023-04-19 at 22.42.04" style="zoom:40%;" />



#### 2. Unknown Parameteres

-   All **piecewise linear curves** could be obtained by 
    -   constant + sum of a set of **Sigmoid function**

$$
\begin{eqnarray*}
	y &=& b + \sum_{i}c_{i}sigmoid(b_{i}+w_{i}x_{1})\\
	  &=& b + \sum_{i}c_{i}sigmoid(b_{i}+\sum_{j}w_{ij}x_{j})
\end{eqnarray*}
$$

<img src="assets/Screenshot 2023-04-19 at 22.51.28.png" alt="Screenshot 2023-04-19 at 22.51.28" style="zoom:35%;" />

-   **Sigmoid Function**
    -   w change slopes
    -   b used for shifting
    -   c change height

<img src="assets/Screenshot 2023-04-19 at 22.52.28.png" alt="Screenshot 2023-04-19 at 22.52.28" style="zoom:40%;" />

-   New Model:

<img src="assets/Screenshot 2023-04-19 at 23.25.44.png" alt="Screenshot 2023-04-19 at 23.25.44" style="zoom:40%;" />

<img src="assets/Screenshot 2023-04-19 at 23.27.32.png" alt="Screenshot 2023-04-19 at 23.27.32" style="zoom:40%;" />

-   **Conclusion**

<img src="assets/Screenshot 2023-04-19 at 23.29.23.png" alt="Screenshot 2023-04-19 at 23.29.23" style="zoom:40%;" />



#### 3. Optimization

$$
\begin{equation*}
	\theta^{*} = arg \min_{\theta} L
\end{equation*}
$$

-   where $\theta$ is a matrix of $\theta$ values
-   (Randomly) Pick initial values $\theta^{0}$

<img src="assets/Screenshot 2023-04-19 at 23.36.53.png" alt="Screenshot 2023-04-19 at 23.36.53" style="zoom:40%;" />



#### 4. Activation Functions

-   Sigmoid
-   ReLU
    -   用两个max函数来拟合Sigmoid函数

<img src="assets/Screenshot 2023-04-19 at 23.39.20.png" alt="Screenshot 2023-04-19 at 23.39.20" style="zoom:40%;" />

-   modify our Model by **ReLU**

<img src="assets/Screenshot 2023-04-19 at 23.42.13.png" alt="Screenshot 2023-04-19 at 23.42.13" style="zoom:40%;" />



#### 5. Neural Networks

-   Many layers means Deep => Deep Learning

<img src="assets/Screenshot 2023-04-19 at 23.50.33.png" alt="Screenshot 2023-04-19 at 23.50.33" style="zoom:40%;" />







