# lec04: Probability Theory

[toc]

## Sample Space and Experiment

**Sample Space**

- The set of all possible outcomes of **an experiment.**
- A sample space can be finite or infinite, & discrete or continuous.

**Experiment**

- Something capable of replication under stable conditions.

### Example: discrete, finite sample space

- **Experiment**: Flipping a coin once.
- **Sample space**: `{Head, Tail}`.

### Example: continuous, infinite sample space

- **Experiment**: Burning a light bulb until it burns out.

    Suppose there is a theoretical maximum number of hours that a bulb can burn and that is 10,000 hours.

- **Sample space**: The set of all real numbers between 0 & 10,000.

- **All continuous sample spaces are infinite.**

## Assigning Probabilities

$$
0 \le P(E_i) \le 1, \ \text{for all} \ i \\
P(E_1) + P(E_2) + \dots + P(E_n) = 1
$$

- **Classical Method**
    - Assigning probabilities based on the assumption of **equally likely outcomes**
- **Relative Frequency Method**
    - Assigning probabilities based on experimental or historical data
- **Subjective Method** 
    - Assigning probabilities based on judgment

> **应用场景**
>
> **Classical Method** 多用于如掷骰子、抽卡片等简单的随机实验，假定所有可能结果是等概率的。
>
> **Relative Frequency Method** 通常在大量数据或实验的背景下使用，比如统计某种疾病的发生率。
>
> **Subjective Method** 则适用于那些无法基于实验数据得出概率的领域，如股票市场预测、经济走势等不确定性较高的领域。

### Classical Method

- Example: **Roll a die**
- If an experiment has n possible outcomes, the classical method would assign a probability of 1/n to each outcome.

### Relative Frequency Method

- Example: **Lucas Tool Rental**
- Each probability assignment is given by **dividing the frequency (number of days) by the total frequency** (total number of days).



> 如果在 100 次掷硬币实验中，得到了 48 次正面，则可以估计正面朝上的概率为 
> $$
> P(正面)=\frac{48}{100}=0.48
> $$

### Subjective Method

- We can use any data available as well as our **experience and intuition**, but ultimately a probability value should express our **degree of belief** that the experimental outcome will occur.
- The best probability estimates often are obtained by combining the estimates from the classical or relative frequency approach with the subjective estimate.

> **例子**：一个医生可能根据以往经验和知识，主观地判断某种新治疗对特定患者有效的概率为 80%。

- Example: **Bradley Investments**
- An analyst made the following probability estimates.

## Math part

- **Multiplication Rule**: 分类累加，分步累乘
- **Set Operation**: Complement, Intersection, Union

$$
P(E \cup F ) = P(E) + P(F) - P(E\cap F)
$$

- **Conditional Probability** of A given B

$$
P(A|B) = \frac{P(A\cap B)}{P(B)}
$$

- **Joint Probability Distributions**
    - 用来描述两个或多个随机变量同时发生的概率，**联合概率分布**
- **Marginal Distribution**
    - 从联合概率分布中，可以通过对另一个变量求和或积分，得到其中一个变量的概率分布。这称为**边缘分布**

<img src="./assets/截屏2024-10-14 16.35.31.png" alt="截屏2024-10-14 16.35.31" style="zoom:33%;" />

> **Example**
>
> - 上图中，第一行第二列表示：这个公司的员工既是 Male 又在 Department 2 的概率是 30%
> - 最右边那一列：marginal distribution of gender
> - 最底下那一行：marginal distribution of department

- **Independence**
    - A and B are independent iff. （AB 之间相互不影响）

$$
P(A|B) = P(A) \Rightarrow P(A\cap B) = P(A)\cdot P(B)
$$

- **Mutually Exclusive 互斥** 
    - 如果事件 A 和事件 B 是互斥的，那么它们没有共同的结果，事件 A 发生时，事件 B 必定不发生，反之亦然

$$
P(A \cap B) = 0
$$

## The Birthday Problem

> **问题描述**：
>
> 假设一年有365天，每个人的生日是随机且均匀分布的，那么在一个 nn 个人的群体中，至少有两个人生日相同的概率是多少
>
> **解法**：
>
> 这个问题的计算思路是通过求解“所有人的生日都不同”的概率，再用 1 减去这个概率，得到至少有两个人生日相同的概率
>
> - 先计算"都不相同"的概率
>
> $$
> P(\text{all different}) = \frac{365}{365} \cdot \frac{364}{365}\cdot \frac{363}{365} \cdots \frac{365 -n+1}{365}
> $$
>
> - 至少两人相同生日的概率
>
> $$
> P(\text{at least 2 ppl sharing b-day}) = 1 - P(\text{all different})
> $$



