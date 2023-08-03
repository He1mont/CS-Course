# COMP1037 FAI

>   写于 2023 年 5 月 28 日
>



### 1. Basic Info

| Title       | Content                                 | Remark           |
| ----------- | --------------------------------------- | ---------------- |
| Module Code | COMP1037                                |                  |
| Name        | Fundamentals of Artificial Intelligence | **FAI** in short |
| Credits     | 10                                      |                  |
| Lecture     | 1 per week                              | 2h               |
| Lab         | 1 per week                              | 2h               |
| CW1         | 10%                                     | covers pt.1      |
| CW2         | 15%                                     | covers pt.2      |
| Final Exam  | 75%                                     |                  |



### 2. Lecture

这门课一共有 10 个 Session，分为 2 个 part，分别由 [Qian Zhang](https://research.nottingham.edu.cn/en/persons/qian-zhang) 和 [Huan Jin](https://research.nottingham.edu.cn/en/persons/huan-jin) 负责。

Part 1 是 Session 1 - Session 5，主要涉及到 Blind Search 和 Heuristic Search 的一些算法；Part 2 是 Session 6 - Session 10，内容比较杂乱，涉及到 MDP，Machine Learning 的介绍和一点点 Neural Network。

-   Session 1 是 intro，跳过；
-   Session 2 主要介绍了 Problem Formulation 的一些性质还有 Search Tree；
-   Session 3 - 4 介绍了 Blind Search 和 Heuristic Search 的几个算法；
-   Session 5 介绍了 Minimax 算法和 Alpha-Beta 剪枝。（Session 3 - 5 有 ppt 的动画演示，所以也顺带上传了`.pptx`文件）
-   Session 6 是 **Stanford CS221** 里的内容，简单介绍了马尔可夫决策过程(Markov Decision Process)。课件几乎是照搬，原课程网站链接在 [这里](https://stanford-cs221.github.io/autumn2022/modules/)， Youtube 上也能找到相对应的 [视频课程](https://www.youtube.com/watch?v=9g32v7bK3Co&t=4047s)。**CS221** 的原课件我也有下载，放在 [Textbook](./Textbook) 文件夹里。
-   Session 7 是 Machine Learning 的简介，给了一个比较明晰的框架，具体的有涉及 K-NN Classification 和 K-means Clustering 两个算法，算是为数不多的优质课件吧。
-   Session 8 主要在介绍神经网络，其中有具体给出训练一个 Perceptron 的过程；
-   Session 9 在介绍 Machine Learning 训练的大致过程，课件是完全照搬的**NTU的李宏毅老师**，原课件在 [这里](https://speech.ee.ntu.edu.tw/~hylee/ml/ml2021-course-data/regression%20(v16).pdf)，也有配套的 Youtube [视频课程](https://www.youtube.com/playlist?list=PLJV_el3uVTsMhtt7_Y6sgTHGHp1Vb2P2J)，讲的很细致。
-   Session 10 我真的不知道在干什么，课件乱的要死，最后考试也只考了贝叶斯的基本应用，不过 Naive Bayes 还是可以了解一下的。

总体来说 Part 1 的架构还是相对清晰一点的，属于看 PPT 能看懂，Part 2 则很需要一些课外资源的帮助了。



### 3. Lecture Code

Part 1 的 lecture 有提供 `.ipynb` 的文件，主要就是通过 python 实现一些小游戏，我当时没仔细看，和 lab 的内容到也没有差特别多



### 4. Lab

FAI lab 的文件主要是 `.ipynb`，前期需要用 `anaconda` 配置好 `jupyter`，具体教程在 [GetStart文件](./LAB/FAI-GetStart.pdf) 里，[lab01](./LAB/lab01) 里面还有 ipynb 和 python 的基本使用教程。

由于之前没有系统性的上过 python，当时 PGP 也还没讲到 OOP，所以 lab 的源代码我看的一头雾水，lab 几乎都没做，都是在写 CW 的时候临时抱佛脚的看的，所以 lab 部分我提供不了什么有效的说明，搞明白 lab 的内容需要一些基础和自学能力

-   Part 1 的 lab (lab01-lab03) 相对来说也是比较清楚的，lab01 是 jupyter notebook 和 python 的基本教程，lab02 在讲 OOP，lab03 是课件里 Search Problem 的代码实现
-   Part 2 的 lab 就比较难评了，和 CW2 的相关性很高。lab04 是 MDP，印象比较深的比如 policy evaluation 和 value iteration；lab05 是 Machine Learning 的一些基本的概念，还有 KNN，Perceptron 和 Linear Learner 之类的算法；lab06 讲了点 Naive Bayes 的算法

很惭愧，我 lab 的时候真一点都没写，是写 CW2 的时候一个一个看过去的，但写完一遍之后真的很难说我真正学到了什么，借用朋友的一句话

>   “我对这个 CW 的理解就是，代码跑起来了，但是本质并不理解。”



### 5. Note

FAI 的 Note 应该是我大二下四门课里做的最认真的一门笔记了，后来复习周的时候又整理了一遍，虽然笔记认真和最后学成什么样没有必然联系

文件形式都是 `.md`，可以用 `Typora` 之类支持 `markdown` 的软件打开



### 6. Textbook

FAI 的教材是 [Artificial Intelligence A Modern Approach (4th edition)](<./Textbook/Artificial Intelligence A Modern Approach.pdf>)，Lecture 没有太多提到教材，只在 Part 2 的 lab 里有用到书里对应的数据库，行有余力的话可以看看

