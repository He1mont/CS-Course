# COMP2007 OSC

>   写于 2024 年 2 月 1 日 

## 1. Basic Info

| Title       | Content                         | Remark           |
| ----------- | ------------------------------- | ---------------- |
| Module Code | COMP2007                        |                  |
| Name        | Operating Systems & Concurrency | **OSC** in short |
| Credits     | 20                              |                  |
| Lecture     | 3 per week                      | 3h               |
| Lab         | 1 per week                      | 1h               |
| CW          | 50%                             |                  |
| Final Exam  | 50%                             | Exam System      |

## 2. Lecture

这门课由 [Dan](https://www.nottingham.ac.uk/research/groups/fp-lab/people/dan.marsden) 和 [Geert](https://www.nottingham.ac.uk/computerscience/people/geert.de_maere) 负责，前者是有着丰富业界工作经验的顶级程序员，后者是同时负责 **GRP** 的老师。

OSC 是相对比较中规中矩的一个 lecture 一个 ppt，一个学期下来一共有 24 个 ppt，分为四大块知识点

-   lec01-03: Intro
-   lec04-07: **进程**，包括线程和调度算法、内存管理和文件系统管理，复习起来还是比较吃力的。
-   lec08-13: **并发**，细讲了信号量和互斥锁，以及一些经典的理论模型
-   lec14-19: **内存管理**，从最原始的管理算法讲到页表，同时引出虚拟内存的概念和各种页表置换算法
-   lec20-24: **文件管理系统**，HDD和SSD的工作原理，由低级到高级的文件系统实现等

## 3. NOTE

这门课我对每一个 Lecture PPT 都写了相应的笔记。

但说来惭愧，对我来说，这些知识点在初次接触的时候都显得太过抽象，加上课上走神，我基本没有在 Lecture 上有效的吸收过知识，倒是考试逼近的时候，在室友和 GPT 的帮助下囫囵吞枣地学了一遍，算是对操作系统有了一个很粗浅的了解。因此我的笔记很多时候都是大段的复制 PPT 上的内容，然后再附上一个 GPT 给的和蔼可亲的例子助于理解。

所以很难说我的笔记有什么参考价值，看着图一乐吧

## 4. Lab

OSC 的 [lab 文档](./Labs/labs.pdf)写的很漂亮，一共 15 道题，都在一个文档里一开始就发给大家了，涵盖 Lecture 里的四块知识点。

前 8 道题主要关于进程、并发和信号量，和 CW 关联度较大。后面就是内存和文件那两块的题，题干比较抽象，后面复习时间紧迫我就战略性放弃了，我只写到 task09。

所有的 lab 和 CW 都需要在学校服务器上运行和测试。

## 5. Textbook

OSC 课件上的官方教材有三本，其中引用频率最高的是 **Tanenbaum**，其次是 **Stalling**，剩余那本很少提及。Lecture 当中所涉及的章节，基本在**Tanenbaum**（也就是 *Modern Operating System*）里都有对应，教材当中的内容会丰富很多，这本书也有 [中译本](https://book.douban.com/subject/27096665/)。

