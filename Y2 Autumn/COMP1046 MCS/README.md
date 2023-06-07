# COMP1046 MCS

>   写于2023年6月6日
>



### 1. Basic Info

| Title       | Content                             | Remark       |
| ----------- | ----------------------------------- | ------------ |
| Module Code | COMP1046                            |              |
| Name        | Mathematics for Computer Scientists | MCS in short |
| Credits     | 20                                  |              |
| Lecture     | 2 per week                          | 3h           |
| Tutorial    | 1 per week                          | 2h           |
| CW1         | 10%                                 | covers pt.1  |
| CW2         | 15%                                 | covers pt.2  |
| Final Exam  | 75%                                 |              |



### 2. Lecture

这门课一共有10个Session，分为2个part。pt.1是Session1-Session5，主要涉及到Blind SearchHeuristic Search的一些算法；pt.2是Session6-Session10，内容比较杂乱，涉及到MDP，Machine Learning的介绍和一点点Neural Network

Session1是intro，跳过；Session2主要介绍了Problem Formulation的一些性质还有Search Tree；Session3-4介绍了了Blind Search和Heuristic Search的几个算法；Session5介绍了Minimax算法和Alpha-Beta剪纸。（Session3-5有ppt的动画演示，所以也顺带上传了.pptx文件）

Session6是Stanford CS221里的内容，简单介绍了马尔可夫决策过程(Markov Decision Process)。课件几乎是照搬，[原课程网站链接](https://stanford-cs221.github.io/autumn2022/modules/)在这里， Youtube上也能找到相对应的[视频课程](https://www.youtube.com/watch?v=9g32v7bK3Co&t=4047s)。CS221的原原课件我也有下载，放在[Textbook](./Textbook)文件夹里。

Session7是Machine Learning的简介，给了一个比较明晰的框架，具体的有涉及K-NN Classification和K-means Clustering两个算法，算是为数不多的优质课件吧。

Session8主要在介绍神经网络，其中有具体给出训练一个Perceptron的过程；Session9在介绍Machine Learning训练的大致过程，课件是完全照搬的NTU的李宏毅老师，[原课件](https://speech.ee.ntu.edu.tw/~hylee/ml/ml2021-course-data/regression%20(v16).pdf)在这里，也有配套的Youtube[视频课程](https://www.youtube.com/playlist?list=PLJV_el3uVTsMhtt7_Y6sgTHGHp1Vb2P2J)，讲的很细致。

Session10我真的不知道在干什么，课件乱的要死，最后考试也只考了贝叶斯的基本应用，不过Naive Bayes还是可以了解一下的。

总体来说pt.1的架构还是相对清晰一点的，属于看ppt能看懂，pt.2则很需要一些课外资源的帮助了



### 3. Lecture Code

pt.1的lecture有提供ipynb的文件，主要就是通过python实现一些game，我当时没仔细看，和lab的内容到也没有差特别多



### 4. Lab

FAI lab的文件主要是.ipynb，前期需要用anaconda配置好jupyter，具体教程在[GetStart文件](./LAB/FAI-GetStart.pdf)里，[lab01](./LAB/lab01)里面还有ipynb和python的基本使用教程。

由于之前没有系统性的上过python，当时PGP也还没讲到OOP，所以lab的源代码我看的一头雾水，所以lab几乎都没做，都是在写CW的时候临时抱佛脚的看的，所以lab部分我提供不了什么有效的说明，搞明白lab的内容需要一些基础和自学能力

pt.1的lab (lab01-lab03)相对来说也是比较organized的，lab01是jupyter notebook和python的basic tutorial，lab02在讲OOP，lab03是课件里Search Problem的代码实现

pt.2的lab就比较难评了，和CW2的相关性很高。lab04是MDP，印象比较深的比如policy evaluation和value iteration；lab05是Machine Learning的一些基本的概念，还有KNN，Perceptron和Linear Learner之类的算法；lab06讲了点Naive Bayes的算法

很惭愧，我lab的时候真一点都没写，我是写CW2的时候一个一个看过去的，但写完一遍之后真的很难说我真正学到了什么，借用朋友的一句话

>   “我对这个cw的理解就是，代码跑起来了，但是本质并不理解。”



### 5. Note

FAI的Note应该是我大二下四门课里做的最认真的一门笔记了，后来复习周的时候又整理了一遍，虽然笔记认真和最后学成什么样没有必然联系

文件形式都是.md，可以用Typora之类支持markdown的软件打开



### 6. Textbook

FAI的教材是Artificial Intelligence A Modern Approach (4th edition)

