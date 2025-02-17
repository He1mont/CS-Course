# lec16: RNN and LSTM

[toc]

## Recurrent Neural Networks

- Excellent models for problems more than o to-one
    - **Time series prediction** and classification.
    - **Sequence prediction** and classification.
    - Simplify some problems that are difficult for multilayer perceptron.

<img src="./assets/截屏2024-11-21 10.22.11.png" alt="截屏2024-11-21 10.22.11" style="zoom:50%;" />

- We can process a sequence of vectors $x$ by applying a recurrrenc formula at every time step
- The same function and the same set of params are used at every time step

<img src="./assets/截屏2024-11-21 10.28.30.png" alt="截屏2024-11-21 10.28.30" style="zoom: 33%;" />

- **Many to many**

<img src="./assets/截屏2024-11-21 10.35.52.png" alt="截屏2024-11-21 10.35.52" style="zoom: 33%;" />

- **Many to One**

<img src="./assets/截屏2024-11-21 10.36.37.png" alt="截屏2024-11-21 10.36.37" style="zoom: 33%;" />

- **In theory** RNN retains information from the **infinite past**.
    - All past hidden state has influence on the future state.
- **In practice** RNN has **little response** to the early states.
    - Little memory over what seen before.
    - The hidden outputs blowup or shrink to zeros.
    - The “memory” also depends on activation functions.
    - ReLU and Sigmoid do not work well. `Tanh` is OK but still not “memorize” for too long.
- Vanishing gradient problem
    - Deeper layers do not have meaningful weights.

## RNN vs. LSTM

### RNN

- Recurrent neurons receive past recurrent outputs and current input as inputs.
- Processed through a `tanh()` activation function
- Current recurrent output passed to next higher layer and next time step.

![截屏2024-11-21 10.46.06](./assets/截屏2024-11-21 10.46.06.png)

### LSTM

<img src="./assets/截屏2024-11-21 10.47.17.png" alt="截屏2024-11-21 10.47.17" style="zoom:50%;" />

- **Constant Error Carousel**
    - Key of LSTM: a **remembered cell** state
    - $C_t$ is the **linear history** carried by the constant error carousel.
    - Carries information through and only effected by a gate
    - Addition of history (gated).

## LSTM Gates

<img src="./assets/截屏2024-11-25 16.15.42.png" alt="截屏2024-11-25 16.15.42" style="zoom: 33%;" />

- A simple **sigmoid function** to project output in range (0, 1).
    - Information is let through (~1)
    - Information is not let through (~0)
- ⊗ : element-wise multiplication.

### Forget Gate

<img src="./assets/截屏2024-11-25 16.20.38.png" alt="截屏2024-11-25 16.20.38" style="zoom:50%;" />

- The first gate determines whether to carry over the history or forget it
    - Actually, determine how much history to carry over.
    - The memory `C` and hidden state `h` are distinguished.

### Input Gate

<img src="./assets/截屏2024-11-25 16.21.20.png" alt="截屏2024-11-25 16.21.20" style="zoom:50%;" />

- The second gate has two parts
    - A `tanh` unit determines if there is something new or interesting in the input.
    - A gate decides if it is worth remembering.

### Memory Cell Update

<img src="./assets/截屏2024-11-25 16.23.08.png" alt="截屏2024-11-25 16.23.08" style="zoom:50%;" />

- Add the output of input gate to the current memory cell
    - After the forget gate.
    - ⊕ : Element-wise addition.
    - Perform the forgetting and the state update

### Output and Output Gate

<img src="./assets/截屏2024-11-25 16.23.49.png" alt="截屏2024-11-25 16.23.49" style="zoom:50%;" />

- The output of the memory cell
    - Similar to input gate.
    - A `tanh` unit over the memory to output in range [-1, 1].
    - A sigmoid unit [0,1] decide the filtering.
    - Note the memory is carried through without `tanh`.

### "Peephole" Connection

<img src="./assets/截屏2024-11-25 16.24.47.png" alt="截屏2024-11-25 16.24.47" style="zoom:50%;" />

### The Complete LSTM Unit

<img src="./assets/截屏2024-11-25 16.25.24.png" alt="截屏2024-11-25 16.25.24" style="zoom:50%;" />

![截屏2024-11-25 16.54.58](./assets/截屏2024-11-25 16.54.58.png)

## Back Propagation Through Time (BPTT)

- Forward through entire sequence to **compute loss**
- Backward through entire sequence to **compute gradient**

<img src="./assets/截屏2024-11-25 16.30.23.png" alt="截屏2024-11-25 16.30.23" style="zoom:50%;" />

### Truncated BPTT

- Run forward and backward through chunks of the sequence instead of whole sequence
- Carry hidden states forward in time forever, but only backpropagate for some smaller number of steps

<img src="./assets/截屏2024-11-25 16.34.52.png" alt="截屏2024-11-25 16.34.52" style="zoom:50%;" />









