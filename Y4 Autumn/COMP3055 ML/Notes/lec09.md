# lec09: Decision Tree

[toc]

## Decision Trees

- A hierarchical data structure that represents data by implementing a divide and conquer strategy 
- Can be used as a **non-parametric** classification method
- Given a collection of examples, learn a decision tree that represents it 
- Use this representation to classify new examples
- Each node is associated with **a feature** (one of the elements of a feature vector that represent an object) 
- Each node test the value of its associated feature 
- There is **one branch for each value of the feature** 
- **Leaf node specify the categories (classes)** 
- Can categorize instances into multiple disjoint categories – multi-class

<img src="./assets/截屏2024-10-31 09.12.06.png" alt="截屏2024-10-31 09.12.06" style="zoom:50%;" />

### Variation of Decision Trees

- **Classification tree**
    - The output is **discrete** (label).
    - The leaves give the predicted class as well as the probability of class membership.
- **Regression tree**
    - The output is **continuous**.
    - The leaves give the predicted value of the output.
- Tree with binary splits
- Tree with multiway splits

**Regression Tree**

<img src="./assets/截屏2024-10-31 09.15.06.png" alt="截屏2024-10-31 09.15.06" style="zoom: 33%;" />

## Entropy and Information Gain

### Entropy 熵

- Consider
    - S is a sample of training examples 
    - p + is the proportion of **positive examples** in S 
    - p - is the proportion of **negative examples** in S 
    - Entropy measures the impurity of S

$$
Entropy(S) = -p_+\log(p_+) - p_-\log(p_-)
$$

- The idea: associate information with probability 
- A random event E with probability P(E) contains:

$$
I(E) = \log(\frac{1}{P(E)}) = -\log(P(E))
$$

- Entropy is the average information content of an image, a measure of histogram dispersion

$$
H = \sum_{k=0}^{L-1} p(r_k) \log_2p(r_k)
$$

> - 当所有类别概率相等时，熵最大，说明数据集的不确定性较高；
> - 反之，如果某个类别的概率接近 1，熵较低，数据的确定性更高。

### Information Gain 信息增益

- Gain(S, A) = expected **reduction in entropy** due to sorting on A

$$
Gain(S,A) = Entropy(S) - \sum_{v\in Values(A)}\frac{|S_v|}{|S|} \cdot Entropy(S_v)
$$

- Where 
    - `Values(A)` is the set of all possible values for attribute A, 
    - `S_v` is the subset of S which attribute A has value v
    - `|S|` and `|S_v|` represent **the number of samples** in set S and set S_v respectively

## Design Decision Tree Classifier

**Processes**

- Picking the root node
- Recursively branching

### Picking the root node

- Consider data with two Boolean attributes (A,B) and two classes + and –

<img src="./assets/截屏2024-10-31 09.16.50.png" alt="截屏2024-10-31 09.16.50" style="zoom:50%;" />

- The goal is to have the resulting decision tree **as small as possible** (Occam’s Razor)
- The main decision in the algorithm is **the selection of the next attribute** to condition on (start from the root node).
- We want attributes that split the examples to sets that are relatively **pure in one label**; this way we are closer to a leaf node.
- The most popular heuristics is based on **information gain**, originated with the ID3 system of Quinlan.

### Example: Tennis

- 先计算该数据集的熵 S

$$
Entropy(S) = -\frac{9}{14} \log(\frac{9}{14}) - \frac{5}{14}\log(\frac{5}{14}) = 0.94
$$

- 分别计算把每个 feature 当 root node之后的 information gain

$$
Gain(S,A) = Entropy(S) - \sum_{v\in Values(A)}\frac{|S_v|}{|S|} \cdot Entropy(S_v)
$$

- `Humidity: {High,3+,4-}, {Normal,6+,1-}`

$$
Gain(S, Humidity) = 0.94 - 
\frac{7}{14}\cdot(-\frac{3}{7}\log(\frac{3}{7})-\frac{4}{7}\log(\frac{4}{7})) - 
\frac{7}{14}\cdot(-\frac{6}{7}\log(\frac{6}{7})-\frac{1}{7}\log(\frac{1}{7})) = 0.151
$$

- `Wind: {Weak,6+,2-}, {Strong,3+,3-}`

$$
Gain(S, Wind) = 0.94 - 
\frac{8}{14}\cdot(-\frac{6}{8}\log(\frac{6}{8})-\frac{2}{8}\log(\frac{2}{8})) - 
\frac{6}{14}\cdot(-\frac{3}{6}\log(\frac{3}{6})-\frac{3}{6}\log(\frac{3}{6})) = 0.048
$$

- `Outlook: {Sunny,2+,3-}, {Overcast,4+,0-}, {Rain,3+,2-}`

$$
Gain(S, Outlook) = 0.94 - 
\frac{5}{14}\cdot(-\frac{2}{5}\log(\frac{2}{5})-\frac{3}{5}\log(\frac{3}{5})) - 
\frac{4}{14}\cdot(-\frac{4}{4}\log(\frac{4}{4})-\frac{0}{4}\log(\frac{0}{4})) -
\frac{5}{14}\cdot(-\frac{3}{5}\log(\frac{3}{5})-\frac{2}{5}\log(\frac{2}{5})) = 0.246
$$

- `Temperature: {Hot,2+,2-}, {Mild,4+,2-}, {Cool,3+,1-}`

$$
Gain(S, Wind) = 0.048
$$

- **选信息增益高的，因为这样子可以减少数据集的不确定性，使分类效果更好**
- **Root Node是 Outlook**，用同样的方式选出接下来的 node 

<img src="./assets/截屏2024-10-31 10.09.42.png" alt="截屏2024-10-31 10.09.42" style="zoom: 33%;" />

### Summary

- **Recursive partitioning**
    - a top-down, greedy algorithm to fit the decision tree for the data.
- **Top-down**
    - Starting at the root node, split the data into subgroups that are as homogeneous as possible with respect to the output.
- **Greedy method**
    - Always make **a locally optimal choice** in the hope that this will lead to a globally optimal solution.

## Three Steps in Building Decision Tree

**Three Steps**

- **Selection of the best split**
    - Which feature could give the “best” split information gain?
- **Stop-splitting rule**
    - When should the splitting stop?
- **Assignment of each leaf node to a class**
    - Predict the value of the output at each leaf node.

### Selection of Best Splits

- Exhaustively **examining all possible** splits is time consuming.
- By default, algorithms will use exhaustive search if no. of possible splits is less than a given number (e.g. 5000).
- Otherwise, a clustering of levels of a feature is used to limit the possible splits to consider.
- An alternative way is to consider binary splits only

### Stopping Criteria for Tree Induction

- Stop expanding a node when all the data **belong to the same class**
- Stop expanding a node when all the data **have similar feature values**
- Early termination
- A simple method:
    - Continue splitting until every node is pure or contains only one instance.
    - Fit training data perfectly but may predict poorly on new data.
- Two approaches:
    - **Top-down stopping rules (pre-pruning).**
    - **Bottom-up assessment criteria (post-pruning).**

### Assignment of Each Leaf Node to a Class

- **Classification tree**
    - Classify an input sample with **the most common label** in the leaf node (the percentage of the label is the probability).
- **Regression tree**
    - Predict an input in a node by the **sample mean of the output values** in the node.

## Evaluation

### Advantages of Trees

- **Easy to interpret**: Tree structured presentation.
- **Allow mixed input data types**: Discrete or continuous.
- Allow discrete or continuous output
- Robust to outliers in feature vectors
- No problem with missing values
- Automatically
    - Accommodates nonlinearity.
    - Selects input variables.

### Disadvantages of Trees

- **Most algorithms use univariate splits (split on only one variable)**
    - Solution: Linear combination split (a1x1+a2x2< c?).
- **Unstable fitted tree**
    - Often a small change in the data result in a very different series of splits.
- Lack of smoothness (step function) in regression tree
- Splitting turns continuous input features into discrete features
- **Spitting using a “greedy” algorithm**
    - While each split is optimal, the overall tree is not.

### Overfitting

- Overfitting results in decision trees that are more complex than necessary.
- Training error no longer provides a good estimate of how well the tree will perform on previously unseen data.
- Need new ways for estimating errors.

**Pre-Pruning**

- Stop the algorithm before it becomes a fully tree.
- Typical stopping conditions for a node
    - Stop if all samples **belong to the same class.**
    - Stop if all **the features values are the same.**
- More restrictive conditions
    - Stop if **number of samples** is less than some user-specified threshold.
    - Stop if expanding the current node **does not improve impurity measures**, e.g., information gain.

**Post-pruning**

- Grow decision tree to its entirety.
- Trim the nodes of the decision tree in a bottom-up fashion.
- If generalization error improves after trimming, replace sub-tree by a leaf node.
- Class label of leaf node is determined from majority class of samples in the sub-tree.

> **预剪枝（Top-down Stopping Rules / Pre-pruning）**
>
> 预剪枝是指在构建决策树的过程中，提前设置停止条件，以防止树的深度或结构变得过于复杂。这些规则在构建树的“自顶向下”过程中逐步应用。常见的预剪枝规则包括：
>
> - **最大深度限制**：设置树的最大深度，如果达到该深度，则停止分裂。
> - **最小样本数限制**：如果一个节点中的样本数低于某个阈值，则不再分裂。
> - **信息增益阈值**：若一个分裂带来的信息增益（或纯度改善）低于某一设定阈值，则停止分裂。
> - **叶节点最小样本数**：一个节点在分裂后若产生的叶节点样本数低于阈值，则不允许分裂。
>
> **后剪枝（Bottom-up Assessment Criteria / Post-pruning）**
>
> 后剪枝是在**整个决策树构建完成后，从叶节点向上评估每个节点是否真的必要**。如果某些分支或节点对于整体泛化效果的贡献较小或无显著提升，就将其剪掉，最终形成一个更简洁的树。后剪枝的常用方法包括：
>
> - **成本复杂度剪枝（Cost Complexity Pruning）**：计算每个节点的误差和复杂度成本，根据这两个因素的加权来确定是否保留某分支。
> - **交叉验证剪枝**：通过交叉验证评估分支对模型性能的影响，若剪掉某分支后性能无显著下降，则去掉该分支。
> - **误差剪枝**：对叶节点的误差进行评估，如果将某节点转化为叶节点能减少误差，则剪枝。
