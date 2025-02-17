# lec06: Instance Learning

[toc]

## Instance Based Learning

- Directly compare new problem instances with instances seen in training
- No explicit modeling of the training data
- Complexity grows with the training data
- Classical instance based learning technique

## K-Nearest Neighbour 

### Algorithm

- Given training data $(X(1),D(1)), (X(2),D(2)), …, (X(N),D(N))$
- Define a distance metric between points in inputs space. 
    - Common measures are Euclidean Distance

$$
D(i,j) = \sqrt{\sum^n_{k=1}(X_k(i)-X_k(j))^2}
$$

- Find the K nearest training inputs to X, denoted these points as
    - $(X(1),D(1)), (X(2), D(2)), …, (X(k), D(k))$
- **The class identification of X: Majority rule**
    - Y = most common class in set $\{D(1), D(2), …, D(k)\}$ 

### Picking K

- Use **N fold cross validation** and Pick K to **minimize the cross validation error**
- For each of N training example
    - Find its K nearest neighbours
    - Make a classification based on these K neighbours
    - Calculate classification error
    - Output average error over all examples
- Use the K that gives lowest average error over the N training examples

