# COMP2005 IIP

>   写于 2024 年 10 月 4 日 

## 1. Basic Info

| Title       | Content                          | Remark                      |
| ----------- | -------------------------------- | --------------------------- |
| Module Code | COMP2005                         |                             |
| Name        | Introduction to Image Processing | **IIP** in short            |
| Credits     | 10                               |                             |
| Lecture     | 2 per week                       | 2h                          |
| Lab         | 1 per week                       | 1h                          |
| CW          | 50%                              | Teamwork, Random Allocation |
| Final Exam  | 50%                              | Exam-sys                    |

## 2. Lecture

这门课由 [Magan](https://www.nottingham.ac.uk/computerscience/people/armaghan.moemeni) 负责。IIP 的课程编排还是挺清晰的，基本每一个 Slides 负责一个主题，内容不算太多、难度也没有很大，循序渐进，都有涉猎，直方图、降噪、Thresholding，Morphology，到后面大头 Segmentation。最后一节蜻蜓点水般介绍 CNN，考试也只是考了非常基本的五个 Stage（由于考试那天早上还和朋友背过，所以印象深刻）。

顺带提一嘴 IIP 的考试，50% final，并且是 Exam Sys，为了改卷方便所以填空题和选择题居多，这意味着所有的空和选项都在 Slides 里出现过。所以对 Slides 的掌握很重要，要能精确回答出 Slide 里的原词，期末复习基本就变成了高中文科背资料。考试难度并不大， 但有些空出的相当刁钻，我由于记忆不佳考试交卷后才幡然醒悟痛失好几分！

## 3. NOTE

Slides 质量挺好的，我的笔记依旧只照着 slides 顺了一遍，没什么参考价值。

## 4. Lab

Lab 的设置非常好。文档漂亮，代码规整，难度适中，感谢 TA Wu Ziling。

一共 9 个 lab，用的是 python，基本和 Lecture 的内容都对应上了。前面几个 lab 我写的还比较认真，特意写了一个 Jupyter Notebook，可以同时兼顾文字和 python 代码。Lab 和 CW 关联性很高，因为我们这届 CW 要求写一个 Pipeline 实现花卉分割，需要囊括 Noise Reduction, Thresholding, Morphology 和 Segmentation，基本把 lab 里实现的大头都用上了。只是最后 Code 部分只占 30%，倒是 Report 占了大头，我有点没懂。

最后面的 lab 和 CW 还有考试关联都不多，我都偷懒没写。特别是 `lab09`，教我们用 Pytorch 和 CNN 跑最基本的深度学习模型，数据集用的 MNIST。非常基础且新手友好的深度学习入门文档，辛苦 TA Wu Ziling。

## 5. Textbook

推荐的教科书有中译本，[数字图像处理](https://book.douban.com/subject/35075811/)。不过书里涉及到很多非常专业的理论知识，还是看 Slides 就好。
