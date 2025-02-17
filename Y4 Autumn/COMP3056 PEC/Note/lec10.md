# lec10: Trustworthy AI

## AI Risks

### 5 categories

- **Data related**: Data is an important resource for AI; poor quality or misuse can create problems.
    - Poor Data Quality
    - Data Bias
    - Misuse of Data
    - Poor Security
- **Performance**: Whether AI performs to benefit all its stakeholders, or not.
    - Poor Aggregate Performance
    - Sub - population Performance Bias
    - Machine learning
    - Unfairness
- **Human/AI interaction**: How humans interact with the AI presents a risk.
    - Human - Computer Interface Design
    - Opaque System
    - Over - or Under - reliance
    - Misuse of AI 
- **Objective**: How we code up the objective for the AI can be problematic, with unintended consequences.
    - Ethical misalignment
    - Misaligned objective
    - Gaming the objectives
- **Social risks**: Broad social impact of AI, in general.

### Principles of AI Assurance

**Board Principles to mitigate AI Risk**

- Society will benefit from regulation and governance of AI. 
- Training and professional accreditation of AI professionals.
- Well - established methods for AI development, validation and deployment.
- Validation and monitoring of AI systems. 
- Understanding the conditions when we should not use AI. 
- Clear responsibility, accountability and governance of AI.

## Autonomous Agents & Encoded Ethics

### Autonomous Vehicles & Ethics

### Autonomous Agents & Embedded Ethics

**General Ethical Principles**

- **Human-focused**. The AI’s only objective is to maximize the realization of human values.
- **Humility**. The AI is initially uncertain about what those values are.
- **Learning**. Human behaviour provides information about human values.

## Fairness and Bias

> ### Two Examples
>
> A mother gives her two children some sweets: 5 for Timmy and 2 for Sammy. Sammy complains he gets less and this is unfair . But his mother explains that Timmy did his homework but Sammy didn’t, so Timmy gets an extra reward and that is fair .
>
> A husband and wife are the same age, live in the same home, drive the same family car, have been driving for the same time, and neither have had a car accident. They both pay the same insurance premium. However, statistically men are more risky than women, in general, and if this were taken into account in the pricing, men should pay 10% more than women. The wife is unhappy with this and thinks it is unfair that women are “subsidizing” men’s riskiness. However, her husband is happy with it the way it is.

### Fairness Definitions

In computer science, we have some definitions of fairness:

- **Independence**. The AI decision should be independent of any individual characteristic.
- **Separation**. Same as Independence but the independence is within each outcome type being modelled.
- **Sufficiency**. The AI decision should be sufficient to account for all features and characteristics,

<img src="./assets/截屏2025-01-01 19.06.02.png" alt="截屏2025-01-01 19.06.02" style="zoom:50%;" />

### 1. Independence

$$
R \perp A
$$

- Similar to 

$$
P(R=r\mid A=a) = P(R=r \mid A=b)
$$

- 无论 A 取何值，模型的决策分布 R 都是相同的

### 2. Separation

$$
R \perp A \mid Y
$$

- Similar to

$$
P(R=r \mid A=a, Y=0) = P(R=r\mid A=b, Y=0)\\
P(R=r \mid A=a, Y=1) = P(R=r\mid A=b, Y=1)
$$

- 对于每一种 Y 的取值，AI 的决策 R 的分布应该与 A 无关。

### 3. Sufficiency

$$
P(Y=1 \mid R=r) = P(Y=1 \mid R= r, A=a)
$$

- 在给定预测 R 的条件下，敏感属性 A 不影响对实际结果 Y 的预测。
- 模型的预测 R 已经包含了所有必要的信息，可以独立于 A 准确预测 Y

### Example

<img src="./assets/截屏2025-01-01 19.45.27.png" alt="截屏2025-01-01 19.45.27" style="zoom:50%;" />

## Explainable AI

### Black Box

<img src="./assets/截屏2025-01-01 19.18.15.png" alt="截屏2025-01-01 19.18.15" style="zoom:50%;" />

### Metrics

- **LIME**. Local Interpretable Model-agnostic Explanations 
- **SHAP**. SHapley Additive exPlanation
- **PDP**. Partial Dependency Plots