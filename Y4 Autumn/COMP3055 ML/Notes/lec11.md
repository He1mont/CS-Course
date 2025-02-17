# lec11: Perceptron, ADLINE and Delta Rule

[toc]

## Feature Engineering

- Feature engineering is the process of using domain knowledge to **extract features from raw data via data mining techniques**. These features can be used to improve the performance of machine learning algorithms.
- Process:
    - Brainstorming or testing features;
    - Deciding what features to create;
    - Creating features;
    - Checking how the features work with your model;
    - Improving your features if needed;
    - Go back to brainstorming/creating more features until the work is done.

## Perceptron

### Basic

- Perceptron takes a **vector** of real-valued inputs, calculates a **linear combination** of these inputs. 
- Then it outputs 1 if the result is greater than **some threshold** and -1 otherwise.

<img src="./assets/截屏2024-11-07 09.20.09.png" alt="截屏2024-11-07 09.20.09" style="zoom:50%;" />
$$
R = w_0 + \sum^n_{i=1}w_ix_i \quad

output = sign(R) = 
\begin{cases}
	1,  & \text{if } R \geq 0 \\
	-1, & \text{otherwise} \\
\end{cases}
$$

### Decision Surface

- Perceptron can be regarded as representing a hyperplane decision surface in the n-dimensional **feature space** of instances.
- The perceptron outputs a 1 for instances lying on one side of the hyperplane and a -1 for instances lying on the other side.
- This hyperplane is called the **Decision Surface**.
    - 例如在二维平面，Decision Surface就是将平面分成两部分的直线

<img src="./assets/截屏2024-11-07 09.24.37.png" alt="截屏2024-11-07 09.24.37" style="zoom: 50%;" />

### Representation Power

- The Decision Suface is linear
- Perceptron can only solve **LInearly Separable Problems**
- 在 PPT 里，AND OR 是 linearly separable 但是 XOR 不是

### Training Algorithm

**Training sample pairs (X, d),** 

- where X is the input vector, 
- d is the input vector’s classification (+1 or -1)

**Procedure**

1. Set the weight to small random values
2. Present X and calculate

$$
R = w_0 + \sum^n_{i=1}w_ix_i \quad

o = sign(R) = 
\begin{cases}
	1,  & \text{if } R \geq 0 \\
	-1, & \text{otherwise} \\
\end{cases}
$$

3. Update weight, where $0<\eta < 1$

$$
w_i \leftarrow w_i + \eta(d-o)x_i, \quad i=0,1,\dots,n
$$

4. Going back to step 2

**Convergence Theorem**

- The perceptron training rule will converge (finding a weight vector correctly classifies all training samples) within a finite number of iterations, **provided the training examples are linearly separable** and provided a sufficiently small h is used.

## Adaptive Linear Element (ADLINE)

### ADLINE vs. Perceptron

- When the problem is not linearly separable, perceptron will **fail to converge.**
- ADLINE can overcome this difficulty by finding a best fit approximation to the target.

<img src="./assets/截屏2024-11-07 09.39.51.png" alt="截屏2024-11-07 09.39.51" style="zoom: 33%;" />

### The ADLINE Error Function

- Given training pairs $(X(k), d(k)))$, the training error is defined as

$$
E(W) = \frac{1}{2}\sum_{k=1}^K (d(k)-o(k))^2,
\ \text{where}  \ o(k) = W^TX(k)
$$

<img src="./assets/截屏2024-11-07 09.47.14.png" alt="截屏2024-11-07 09.47.14" style="zoom: 33%;" />

### The Gradient Descent

> 想像成下山问题，梯度下降的本质是为了找到山底，在山路陡的地方加快下山脚步，在山路平缓的地方放慢脚步，因此需要考虑在当前位置的切线，即斜率（陡峭程度）

$$
W \leftarrow W - \eta \nabla E(W) \\
w_i \leftarrow w_i - \eta \frac{\partial E}{\partial w_i}
$$

- Sample 图见 PPT
- **Gradient of ADLINE Error Function**

$$
\begin{align*}
\frac{\partial E}{\partial w_i} 
&= \frac{1}{2}\sum^K_{k=1}\left (\frac{\partial}{\partial w_i}(d(k)-o(k))^2 \right) \\
&= \frac{1}{2}\sum^K_{k=1}\left( 2(d(k)-o(k)) \cdot \frac{\partial}{\partial w_i}\left((d(k)-o(k))  \right) \right) \\
&= \sum^K_{k=1}\left( (d(k)-o(k)) \cdot \frac{\partial}{\partial w_i}\left(d(k)-w_0 - \sum_{i=1}^n w_ix_i(k)  \right) \right) \\
&= \sum^K_{k=1}\left((d(k)-o(k)) \cdot (-x_i(k)) \right) \\
&= -\sum^K_{k=1}(d(k)-o(k)) \cdot x_i(k) \\
\end{align*}
$$

- Therefore the gradient descent for ADLINE is defined as 

$$
w_i \leftarrow w_i + \eta \sum^K_{k=1}(d(k)-o(k)) \cdot x_i(k)
$$

- **Batch Mode + Gradient Descent (GD)**: 每次更新所有 $w_i$
    $$
    \delta_i=-\sum^K_{k=1}(d(k)-o(k))x_i(k)\quad w_i\gets w_i - \eta\cdot\delta_i
    $$
    
- **Online Mode + Stochastic Gradient Descent (SGD)**: 每次更新一个 $w_i$，**用更小的learning rate**
    $$
    \delta_i=-(d(k)-o(k))x_i(k)\quad w_i\gets w_i - \eta\cdot\delta_i
    $$
    

## Training Iterations: Epoch

- Training is an iterative process; training samples will have to be used repeatedly for training.
- **an epoch is the presentation of all K sample for training once.**
- Normally, training will take many epochs to complete.

**Termination of Training**

- When a pre-set number of training epochs is reached
- When the error is smaller than a pre-set value.





