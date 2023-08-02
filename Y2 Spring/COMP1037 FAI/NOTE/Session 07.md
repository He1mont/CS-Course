## Session 7: Machine Learning & Data Mining



>   ### Outline
>
>   -   Machine learning overview
>       -   Regression and classification
>       -   Training set and test set
>   -   Supervised learning
>       -   **Classification**
>       -   Regression
>   -   Unsupervised learning
>       -   **Clustering**
>       -   Dimensional reduction
>   -   Classification
>       -   Linear Learner: $$a\cdot x_{1} + b \cdot x_{2} + c = y$$
>       -   Decision Tree
>       -   Neural Networks
>       -   KNN
>       -   Naive Bayes
>   -   Clustering
>       -   Partition-based clustering
>           -   **K-means clustering**
>           -   K-medoids clustering
>       -   Density-based clustering
>   -   Applications:
>       -   Classification: Target marketing
>       -   Clustering: Market Segmentation







[**Here is a youtube tutorial from the original author.**](https://www.youtube.com/watch?v=Ye018rCVvOo&list=PLJV_el3uVTsMhtt7_Y6sgTHGHp1Vb2P2J)

#### 1. What is Machine Learning

-   Looking for Functions

<img src="assets/Screenshot 2023-04-09 at 22.21.25.png" alt="Screenshot 2023-04-09 at 22.21.25" style="zoom:40%;" />



#### 2. Different types of functions

-   **<u>Regression:</u>**
    -   The function outputs a scalar
    -   输出一个数值

<img src="assets/Screenshot 2023-04-09 at 22.22.20.png" alt="Screenshot 2023-04-09 at 22.22.20" style="zoom:40%;" />

-   **<u>Classification:</u>**
    -   Given options, the function outputs the correct one
    -   做出一个选择

<img src="assets/Screenshot 2023-04-09 at 22.23.33.png" alt="Screenshot 2023-04-09 at 22.23.33" style="zoom:33%;" />



#### 3. Machine Learning vs. Traditional Programming

-   Traditional Programming

<img src="assets/Screenshot 2023-04-09 at 22.25.58.png" alt="Screenshot 2023-04-09 at 22.25.58" style="zoom:40%;" />

-   Machine Learning

<img src="assets/Screenshot 2023-04-09 at 22.26.13.png" alt="Screenshot 2023-04-09 at 22.26.13" style="zoom:40%;" />



#### 4. How Machine Learning Works

-   Partition the total dataset into two subsets
    -   **<u>Training set</u>**: Learning the parameters of the model
    -   <u>**Test set**</u>: How the results will generalize to an independent data set

<img src="assets/Screenshot 2023-04-09 at 22.34.39.png" alt="Screenshot 2023-04-09 at 22.34.39" style="zoom:40%;" />



#### 5. Machine Learning Tasks

-   **<u>Supervised Learning</u>**
    -   The agent observes some example input-output pairs and learns a function that ==**maps** from input to output==
    -   Given input samples (`x`) and labeled outputs (`y`) of a function $y = f(x)$, learn `f` and evaluate it on new data
-   **Classification**:
    -   to predict a ==categorical or **discrete** output== variable. 
    -   to assign input data to different classes
-   **Regression**:
    -   to predict a ==**continuous** output variable==
    -   to predict a numerical value based on input features



-   **<u>Unsupervised Learning</u>**
    -   Given only samples x of the data, infers a function f such that  $y = f(x)$ describes the ==hidden structure== of the ==unlabeled data==
    -   more of an ==exploratory/descriptive data analysis==
-   **Clustering**
    -   y is **discrete**
    -   <u>process</u>: group similar data points together based on their attributes, ==without any prior knowledge==
    -   <u>goal</u>: learn any ==intrinsic structure== that is present in the data
-   **Dimensional Reduction**
    -   y is **continuous**
    -   <u>process</u>: reduce the number of input features or variables in a dataset, while preserving the most important information or relationships in the data
    -   <u>goal</u>: ==simplify the data==do and make it easier to visualize, analyze, or process



-   **<u>Reinforcement Learning</u>**
    -   The agent learns from a series of reinforcements - rewards or punishments



-   Supervised learning vs. Unsupervised learningw


| Supervised                                                | Unsupervised             |
| --------------------------------------------------------- | ------------------------ |
| y = F(x): function                                        | y = ? : no function      |
| Data: labeled training set                                | Data: unlabeled data set |
| Learn: G(x): model trained to predict labels of new cases | Learn: ?                 |
| Goal: $E[(F(x)-G(x))^2] \approx 0$                        | Goal: ?                  |

<div style="display:flex;">
  <img src="assets/Screenshot 2023-05-14 at 16.31.38.png" style="zoom:30%;">
  <img src="assets/Screenshot 2023-05-14 at 16.31.45.png" style="zoom:30%;">
</div>



#### 6. Classification

-   Learn a method to predict the instance class from pre-labeled instances

-   **Data**: a collection of records
    -   each record contains a set of attributes
    -   one of the attributes is the class attribute
    
-   Find a **model** for `class attribute` as a function of the other attributes

-   Goal: assign a class to unseen records correctly

-   Process:

    -   Divide the given data set into ==<u>training</u> & <u>test sets</u>==
    -   Use <u>training set</u> to build the model
    -   Use <u>test set</u> to validate the model



#### 7. Other Supervised Learning

-   **Regression**: (linear or any other polynomial)
    -   $a\cdot x_{1} + b \cdot x_{2} + c = y$
    -   To find the best line (**linear function** $y=f(x)$) to explain the data
    -   Linear Regression: $w_{0}+w_{1}x=y$
    

<img src="assets/Screenshot 2023-04-09 at 22.55.04.png" alt="Screenshot 2023-04-09 at 22.55.04" style="zoom:40%;" />

-   **Decision Trees**
    -   <u>Internal Node</u>: decision rule on one or more attributes
    -   <u>Leaf Node</u>: a predicted class label

<img src="assets/Screenshot 2023-04-09 at 22.57.32.png" alt="Screenshot 2023-04-09 at 22.57.32" style="zoom:40%;" />

<img src="assets/Screenshot 2023-05-14 at 16.53.31.png" alt="Screenshot 2023-05-14 at 16.53.31" style="zoom:40%;" />

| Pros                                  | Cons                                            |
| ------------------------------------- | ----------------------------------------------- |
| Reasonable training time              | Simple decision boundaries                      |
| Can handle large number of attributes | Problems with lots of missing data              |
| Easy to implement                     | Cannot handle complicated relationships between |
| Easy to implement                     |                                                 |



-   Neural Networks
    -   Useful for learning complex data like speech, image and handwriting recognition

| Pros                                        | Cons                                                         |
| ------------------------------------------- | ------------------------------------------------------------ |
| Can learn more complicated class boundaries | Hard to implement: trial and error for choosing parameters and network structure |
| Can be more accurate                        | Slow training time                                           |
| Can handle large number of features         | Can over-fit the data: find patterns in random noise         |
|                                             | Hard to interpret                                            |

-   Conclusion
    -   <u>Regression</u>: use of linear or any other polynomial
    -   <u>Decision Trees</u>: divide decision space into ==piecewise== regions
    -   <u>Neural Networks</u>: partition by ==nonlinear boundaries==

<img src="assets/Screenshot 2023-04-09 at 23.01.16.png" alt="Screenshot 2023-04-09 at 23.01.16" style="zoom:40%;" />



-   **K-Nearest Neighbour (KNN)**

    -   One of the first choices for a classification study when there is **little or no prior knowledge** about the distribution of the data

    -   A new data point is assigned ==the class of the plurality== of its nearest neighbors in the training set, considering the nearest k neighbors

    -   k = 3: Purple

    -   k = 5: Yellow

<img src="assets/Screenshot 2023-04-09 at 23.14.11.png" alt="Screenshot 2023-04-09 at 23.14.11" style="zoom:40%;" />



#### 8. Clustering (unsupervised learning)

-   What we have
    -   a set of ==un-labeled data points==, each with a set of attributes
    -   a ==similarity measures==
-   What we need
    -   find =="natural" partitioning of data==, or groups of similar/close items
-   The task of `clustering` is to ==partition the data== so the instances are grouped in similar items by using **distance/similarity** measure

<img src="assets/Screenshot 2023-04-09 at 23.17.56.png" alt="Screenshot 2023-04-09 at 23.17.56" style="zoom:40%;" />

-   Key: ==measure the **similarity** between instances==
    -   Euclidean or Manhattan distance
    -   Hamming distance
    -   Other

<img src="assets/Screenshot 2023-04-09 at 23.19.36.png" alt="Screenshot 2023-04-09 at 23.19.36" style="zoom:40%;" />



#### 9. Clustering: Methods

-   Partitioning-based clustering
    -   **K-means clustering**
    -   K-medoids clustering
-   Density-based clustering
    -   Separate regions of dense points by sparser regions of relatively low density



#### 10. K-Means clustering

-   Goal: minimize ==sum of square of distance==
    -   between each point and centers of the cluster
    -   between each pair of points in the cluster
-   **Algorithm:**
    -   Initialize K cluster centers
        -   random, first K, K separated points
    -   Repeat until stabilization
        -   Assign each point to closest cluster center
        -   Generate new cluster centers
        -   Adjust clusters by merging or splitting



#### 11. Density-Based Clustering

-   A cluster: a connected dense component
-   Density: the number of neighborws of a point
-   Can find clusters of arbitrary shape



#### 12. Applications

-   **Classification: Target Marketing**

-   **Goal**: 
    -   reduce the cost of mailing by targeting consumers who are likely to buy a new cell-phone product
-   **Approach**:
    -   Find the old data for a similar product
    -   Collect info. of all customers
    -   This {buy, don't buy} decision forms the ==class attribute==
    -   Use this info to learn a classifier model



-   **Clustering: Market Segm∑entation**
-   **Goal:**
    -   divide a market into distinct subsets of customers,
        any subset may be a market target
-   **Approach:**
    -   Collect different attributes of customers, based on their related information
    -   Find clusters of similar customers
    -   Evaluate buying patterns in the same cluster vs. those from different clusters









