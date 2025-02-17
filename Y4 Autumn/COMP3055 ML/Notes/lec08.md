# lec08: Data Clustering

[toc]

## Supervised vs. Unsupervised Learning

- **Supervised learning**
    - Learns a function that maps an input to an output based on example input-output pairs.
    - Training data is **labeled.**
- **Unsupervised learning**
    - Learns from test data that has not been labeled.
    - Learns relationships between elements in a data set and classify the raw data without "help.”
    - Typical application includes **data clustering.**

## Motivating Problem

<img src="./assets/截屏2024-10-24 09.26.36.png" alt="截屏2024-10-24 09.26.36" style="zoom:50%;" />

<img src="./assets/截屏2024-10-24 09.29.20.png" alt="截屏2024-10-24 09.29.20" style="zoom:50%;" />

### Motivation of Clustering 物以类聚

- Patterns within a valid cluster are more similar to each other than they are to **a pattern belonging to a different cluster**.
- In clustering, the problem is to group a given collection of **unlabeled patterns** into meaningful clusters. Clustering is **data driven** method, the clusters are obtained solely from the data.
- Clustering could be used in the field of pattern-analysis, grouping, decision-making, and machine-learning situations, including data mining, document retrieval, image segmentation

## K-Means

- An algorithm for partitioning (or clustering) **N data points** into **K disjoint subsets Sj** containing Nj data points

    - Define, $X(i) = [x_1(i), x_2(i), \dots, x_n(i)]$, i = 1, 2, …N, as N data points

    - n 是feature vector的维度，N是训练集的大小

    - We want to cluster these N points into K subsets, or K clusters, where K is pre-set

    - For **each cluster**, we define $M(j) = [m_1(j), m_2(j),\dots, m_n(j)]$, j=1, 2, …K, as its **prototype** or cluster centroids 

    - Define the **distance** between **data point** $X(i)$ and **cluster prototype** $M(j)$ as

$$
D(X(i), M(j)) = \|X(i)-M(j)\| = \sqrt{\sum_{l=1}^{n}(x_l(i)-m_l(j))^2}
$$

- A data point $X(i)$ is assigned to the jth cluster, $C(j)$
    - Minimum distance classifier

$$
D(X(i),M(j))\le D(X(i),M(l)), \mathrm{for \ all\ } l =1,2,\dots,k
$$

### Step 1

- Arbitrarily choose from the given sample set k initial cluster centres
- 随机选取k个点作为每个聚类的群心，t 表示迭代的次数

$$
M^{(0)}(j) = [m^{(0)}_1(j), m^{(0)}_2(j), \dots, m^{(0)}_n(j)], \ j = 1, 2, \dots, K
$$

### Step 2

- 根据每个点和聚类群心的距离，初始化聚类
- $X(i) = [x_1(i), x_2(i), \dots, x_n(i)]\in M^{(t)}(j)$ if

$$
D(X(i),M^{(t)}(j)) \le D(X(i),M^{(t)}(l)) \textrm{\ for all\ } l = 1,2,\dots,k
$$

### Step 3

- 根据现有的聚类，更新群心的位置

$$
M^{(t+1)}(j) = \frac{1}{N^{(t)}_j}\sum_{X(i)\in M^{(t)}(j)}
$$

### Step 4

- Calculate the error of approximation

$$
E(t) = \sum^K_{j=1} \sum_{X(i)\in M^{(t)}(j))}\| X(i)-M^{(t)}(j) \|
$$

### Step 5

- If the **terminating criterion** is met, then stop, **otherwise go to step 2**

- **Stopping criteria**

    - The errors do not change significantly in two consecutive epochs

        $|E(t)-E(t-1)|<\epsilon$

    - No further change in the assignment of the data points to clusters in two consecutive epochs.

    - It can also stop after **a fixed number of epochs** regardless of the error

### Remarks

- Is a **gradient descent** algorithm, trying to **minimize a cost function** E
- In general, the algorithm does not achieve a global minimum of E over the assignments
- Sensitive to **initial choice of cluster centers**. Different starting cluster centroids may lead to different solution
- Is a popular method, many more advanced methods derived from this simple algorithm







