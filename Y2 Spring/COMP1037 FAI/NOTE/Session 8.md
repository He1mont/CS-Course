## Session 8: Neural Networks

>   ### Outline
>
>   -   Basic ideas
>       -   weight
>       -   activation function
>       -   threshold
>   -   Neural network architectures
>       -   **single-layer: perceptron**
>       -   multi-layer
>       -   recurrent
>   -   Linear separability
>   -   **Training a NN**



#### 1. The First Neural Networks

-   a set of inputs (dendrites)
-   a set of resistances/weights (synapses)
-   a processing element (neuron)
-   a single output (axon)

<img src="assets/Screenshot 2023-04-10 at 23.36.55.png" alt="Screenshot 2023-04-10 at 23.36.55" style="zoom:50%;" />

-   The activation function for unit Y is

    `f(y_in) = 1 (fire) if y_in >= 0; else 0 (not fire)`

-   Neurons in a McCulloch-Pitts network are connected by directed, weighted paths

-   If the weight on a path is **positive**, the path is **excitatory**, otherwise **inhibitory**

    -   x1 and x2 <u>encourage</u> the neuron to fire
    -   x3 <u>prevents</u> the neuron from firing

-   Each neuron has a **fixed threshold.**

    -   if the net input into the neuron is greater than or equal to the threshold, it fires

<img src="assets/Screenshot 2023-04-10 at 23.37.31.png" alt="Screenshot 2023-04-10 at 23.37.31" style="zoom:40%;" />



-   Activation Functions

<img src="assets/Screenshot 2023-05-14 at 17.40.38.png" alt="Screenshot 2023-05-14 at 17.40.38" style="zoom:40%;" />



#### 2. Neural Network Architectures

-   Three different classes of network architectures
    -   single-layer feed-forward, called as **perceptron**
    -   multi-layer feed-forward
        -   a ==hidden layer== is the layer between input and output
    -   recurrent

<img src="assets/Screenshot 2023-04-10 at 23.43.16.png" alt="Screenshot 2023-04-10 at 23.43.16" style="zoom:40%;" />



-   Perceptron

<img src="assets/Screenshot 2023-04-11 at 12.41.40.png" alt="Screenshot 2023-04-11 at 12.41.40" style="zoom:50%;" />



#### 3. Linear Separability

-   Functions that can be separated in this way are called **Linearly Separable**
-   ==Only **Linear Separable** functions can be represented by a single layer NN (**perceptron**)==
    -   **NN** is the abbreviation for <u>Neural Network</u>
    -   **ANN**  is the abbreviation for <u>Artificial Neural Network</u>

<img src="assets/Screenshot 2023-04-11 at 12.46.25.png" alt="Screenshot 2023-04-11 at 12.46.25" style="zoom:40%;" />



-   Linear Separability is possible in more than 3 dimensions
-   Visualize ANN with 3 inputs
    -   write the truth table
    -   draw a 3D graphical representation

<img src="assets/Screenshot 2023-04-11 at 12.49.33.png" alt="Screenshot 2023-04-11 at 12.49.33" style="zoom:30%;" />



#### 4. Training a NN

<img src="assets/Screenshot 2023-04-11 at 12.52.09.png" alt="Screenshot 2023-04-11 at 12.52.09" style="zoom:40%;" />

```
While epoch produces an error
	check next inputs(pattern) from epoch
	Err = T - O
	
	If Err != 0 then
		w_{i} = w_{i} + LR * X_{i} * Err
	End If
	
End While
```

-   Training Value `T`: the expected output
-   Output Value `O`: the actual output
-   Error, `Err` = Expected output - Actual output
-   $w_{i} = w_{i} + LR * X_{i} * Err$
    -   $X_{i}$ : Inputs to the neuron
    -   $w_{i}$: Weight from input $X_{i}$ to the output
    -   $LR$: The learning rate
        -   ==How quickly the network converges==
        -   It is set by experimentation, typically 0.1



#### 5. Training a Perceptron: <a href="file:///Users/sgs/Desktop/FAI/LEC/Session8_Neural_Networks.pdf">**An example from Session 8**</a>

-   The learning process
    -   Randomly assign initial weights
    -   Do:
        -   present the network with input
        -   calculate the error value in the output
        -   adjust the weighting of the inputs according to the error
    -   **until no error value exists for all inputs**





## The following content is from lab06 `neural_net.ipynb`



#### 6. Multi-Layer Perception

-   `feed-forward`
    -   the process of passing the outputs down the layer
-   `Backpropagation` algorithm
    -   it does the opposite of what we were doing up to this point
    -   instead of feeding the input forward, it track the error backwards
-   `epochs`
    -   the number of times we iterate over the dataset
-   `bias`
    -   sometimes we add another node to the input of each layer, called `bias`
    -   this is a constant value that will be fed to the next layer, usually set to 1



#### 2. `Backpropagation` algorithm

-   a common <u>cost function</u>: **Mean Squared Error** (MSE)
    -   `n` is the number of training examples
    -   $\hat{y}$ is our prediction
    -   $y$ is the correct prediction

$$
MSE = \frac{1}{n}\sum^{n}_{i=1}(y-\hat{y})^2
$$

























