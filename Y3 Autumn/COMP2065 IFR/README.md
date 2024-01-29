# COMP2065 IFR

>   写于 2024 年 1 月 28 日 

## 1. Basic Info

| Title       | Content                          | Remark            |
| ----------- | -------------------------------- | ----------------- |
| Module Code | COMP2065                         |                   |
| Name        | Introduction to Formal Reasoning | **IFR** in short  |
| Credits     | 10                               |                   |
| Lecture     | 2 per week                       | 2h                |
| Tutorial    | 1 per week                       | 1h                |
| Lab         | 1 per week                       | 2h                |
| CW          | 8 exercises, 12.5% in total      |                   |
| In-lab Test | 12.5%                            | 1h, **open-book** |
| Final Exam  | 75%                              | Written Exam      |

## 2. Lecture

这门课由 [Thorsten](http://www.cs.nott.ac.uk/~psztxa/) 负责，水平很高的德国老师，上课时不时会穿插他的德式幽默。

IFR 教的也是函数式编程，用的语言的是 **Lean**，和 **Haskell** 的感觉挺像。数学知识其实就是 **MCS** 当中离散数学那一部分，只是用代码又实现了一遍。

这是我个人认为大三上 UNUK 体验最好的一门课，Textbook 是由 Thorsten 教授自己编写的，Lecture 基本按照 Textbook 的章节来走，内容也大差不差（Lecture 当然会更细致一点），上课没有 ppt，Thorsten 会开一个空的 `.lean` 文件边手打边讲（个人认为的最好的 CS 编程教学模式），相比 DMS 那种插一个代码截图在 ppt 里字小的要命上课也不放大给你看的教学模式，我只能说狠狠地爆杀了。

因为没有 Lecture ppt，所以我上传的是我上课跟着老师手打的代码

## 3. Lab & CW

这部分和 **DBI** 有点像，**IFR** 的 **CW** 被拆分成 8 个练习，基本上每周会发一个，可以在 lab 上找助教解答。由于这个 8 道练习题不算是严格意义上的 **CW**，所以我上传了供参考。另外还有一个 **bonus exercise**，知识点是 **lec18** 里 `Expr` 那一部分，不算分，当时我期末复习来不及了就略过了。

虽然 **Lean** 目前已经更新到 Lean4 了，但是 **IFR** 用的仍然是 Lean3，加上 Apple Silicon 的兼容问题，下载的时候确实费了我一点心思。图方便的话，Lean 有一个 [网页版](https://leanprover-community.github.io/lean-web-editor/#code=--%20start%20your%20code%20below!%0A)，可以直接把 `.lean` 文件导入进去

## 4. Tutorial

这门课的 Tutorial 很有意思，有四个助教，分别负责不同的时间段。他们的内容不完全相同，但是涵盖的知识点是一样的，有些 Tutorial 会讲当周练习的提示。

我上传的基本是 [Stefania](https://stefaniatadama.com) 的版本，配有相应的解答。她是讲的最好并且文档编写最清楚的，人美心善能力强，个人认为是 **IFR** 的最佳助教。

## 5. NOTE

**IFR** 的 Note 我记得很认真，是按 Textbook 的章节来整理的，同时涵盖了 Lecture 以及部分 Exercise 的难题。笔记我写的都是 markdown，Lean 的代码都是放在 code block里的，由于 Typora 的 code block 并不支持 Lean 代码的高亮，所以用 VS Code 打开可能会看得更清楚一点。

**Chapter 8** 由于我当时误以为 `Expr` 那一章节不考试，就大意没整理（但后来居然考到了，我狠狠痛心💔）

## 6. Textbook

**IFR** 的 **Textbook** 是我目前为止见过最牛的，由 Thorsten 本人编写。他有两个版本，一个是 pdf 版，我放在文件夹里，另一个是[网页版](http://www.cs.nott.ac.uk/~psztxa/comp2065.23-24.ifr-notes/_build/html/index.html)，会根据教学内容进行些许的调整。网页版的教材编写的极其清楚漂亮，和 Lecture 也配合的很好，是体验相当流畅的一门课
