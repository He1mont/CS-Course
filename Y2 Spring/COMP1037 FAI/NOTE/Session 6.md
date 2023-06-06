## Session 6: Markov Decision Process (MDP)

>   ### Outline
>
>   -   Modeling
>       -   What is MDP
>       -   Some definitions
>       -   Difference between MDP and Search Problems
>   -   Policy evaluation
>       -   Policy
>       -   Discounting
>       -   Utility
>       -   Value of a policy
>       -   Q-Value of a policy
>       -   Algorithm of policy evaluation
>       -   Policy evaluation of `Dice Game`
>   -   Value iteration
>       -   Optimal value
>       -   Optimal Q-value
>       -   Optimal policy
>       -   Algorithm of value iteration



#### 1. Example 1: Dice Game

>   For each round r= 1, 2, ..., you choose **stay** or **quit**
>
>   -   if **quit**, you get $10 and we end the game
>   -   if **stay**, you get $4 and then I roll a 6-sided dice
>       -   if the dice results in 1 or 2, we end the game
>       -   otherwise, continue to the next round

<img src="assets/Screenshot 2023-03-28 at 12.01.42.png" alt="Screenshot 2023-03-28 at 12.01.42" style="zoom:50%;" />



#### 2. Policy

-   A policy is a choice of what action to choose at each state.
-   If follow policy "stay"
    -   expected utility: $\frac{1}{3}\cdot4+ \frac{2}{3}\cdot\frac{1}{3}\cdot 8+\frac{2}{3}\cdot\frac{2}{3}\cdot\frac{1}{3}\cdot 12+ \dots = \sum_{1}^{\infty}(\frac{2}{3})^{n-1}\cdot \frac{1}{3}\cdot (4n) = 12$

-   If follow policy "quit"
    -   expected utility: $1\cdot 10 = 10$
-   In expectation, **the "stay" strategy is preferred**



#### 3. Markov Decision Process

-   An MDP can be represented as a graph
    -   **<u>nodes</u>**: both states and chance nodes
    -   **<u>edges coming out of states</u>**: possible actions from that state
    -   **<u>edges coming out of a chance node</u>**: possible random outcomes of that action



-   some definitions
    -   States: the set of states
    -   $s_{start} \in States$ : starting state
    -   $Actions(s)$ : possible actions from state $s$
    -   $T(s,a,s')$ : possibility of $s'$ if take action $a$ in state $s$
    -   $Reward(s,a,s')$ : reward for the transition $(s,a,s')$
    -   `IsEnd(s)` : whether at end of game
    -   $0 \le \gamma \le 1$ : discount factor (default: 1)



-   **A Markov Decision Process** has
    -   a `starting state` $s_{start}$, the `set of actions` $Actions(s)$ from each state $s$
    -   a `transition distribution` $T$, which specifies for each state $s$ and action $a$, a distribution over possible successor state $s'$
        -   specifically: $\sum_{s'}T(s,a,s') = 1$
    -   $Reward(s,a,s')$ associated with each transition, either positive or negative
    -   if `IsEnd(s) == True`, then the game is over
    -   the `discount factor` $\gamma$ is a quantity which specifies how much we value the future



#### 4. Difference between MDPs and search problems

-   **main difference**: 
    deterministic successor function $Succ(s,a)$ and transition probabilities over $s'$

    $\begin{cases}
      1, & \text{if } s' = Succ(s,a) \\
      0, & \text{otherwise}
    \end{cases}$

-   **minor difference**: we've gone from minimizing costs to maximizing rewards



#### 5. Transitions

-   The **transition probabilities** $T(s,a,s')$ specify the probability of ending up in state $s'$ if taken action $a$ in state $s$

<img src="assets/Screenshot 2023-03-28 at 15.12.21.png" alt="Screenshot 2023-03-28 at 15.12.21" style="zoom:40%;" />

-   -   For each state $s$ and action $a$: $\sum_{s'\in States} T(s,a,s') = 1$
    -   If a transition to a particular $s'$ is not possible, then $T(s,a,s') = 0$ 
    -   We refer to the $s'$ for which $T(s,a,s')>0$ as the successors



#### 6. Policy

-   A **policy** $\pi$ is a `mapping` from each state $s \in States$ to an action $a \in Actions(s)$



#### 7. Policy evaluation

-   **discounting** $\gamma$

    -   path: $s_{0}, a_{1}r_{1}s_{1}, a_{2}r_{2}s_{2}, \dots$ (action, reward, new state)

    -   if discount $\gamma$ is small, then we favor the present more

        <img src="assets/Screenshot 2023-03-28 at 15.33.32.png" alt="Screenshot 2023-03-28 at 15.33.32" style="zoom: 40%;" />



-   **utility**

    -   following a policy yields a random path

    -   the utility of a policy is the `sum of the rewards` on the path
    -   the `utility with discount` $\gamma$ is:  $u_{1} = r_{1} + \gamma \cdot r_{2} + \gamma^{2} \cdot r_{3} + \gamma^{3} \cdot r_{4} + \cdots$



-   **Value of a policy**	

    -   $V_{\pi}(s)$ be the `expected utility` received by following policy $\pi$ from state $s$
    -   labeling the state node

    

-   **Q-value of a policy**
    
    -   $Q_{\pi}(s,a)$ be the `expected utility` of taking action $a$ from state $s$ and then following policy $\pi$
    -   Now we take action $a$ from state $s$ to state $s'$

<img src="assets/Screenshot 2023-03-28 at 15.39.20.png" alt="Screenshot 2023-03-28 at 15.39.20" style="zoom:50%;" />

<img src="assets/Screenshot 2023-03-28 at 15.42.11.png" alt="Screenshot 2023-03-28 at 15.42.11" style="zoom:45%;" />

-   where
    -   Reward$(s,a,s')$ + $\gamma V_{\pi}(s')$ is the `utility` of path $s$ to $s'$
    -   $\sum_{s'}T(s,a,s')[Reward(s,a,s')+\gamma V_{\pi}(s')]$ is the `expected utility`



#### 8. Policy evaluation for `Dice Game`

-   Let $\pi$ be the "stay" pocicy: $\pi(in) = stay$
-   $V_{\pi}(end) = 0$
-   $V_{\pi}(in) = \frac{1}{3}\cdot(4+V_{\pi}(end)) + \frac{2}{3}\cdot(4+V_{\pi}(in)) = 12$



#### 9. Algorithm: policy evaluation

>Initialize $V_{\pi}^{(0)}\leftarrow 0$ for all states $s$
>
>For iteration $t = 1, \dots, t_{PE}$ : 
>
>​		For each state $s$ : 
>$$
>V_{\pi}^{(t)}(s)\leftarrow \underbrace{\sum_{s'}T(s,\pi(s),s')[Reward(s,\pi(s), s')+\gamma V_{\pi}^{(t-1)}(s')]}_{Q^{(t-1)}(s,\pi(s))}
>$$
>Repeat until:
>$$
>max_{s\in States} |V_{\pi}^{(t)}(s) - V_{\pi}^{(t-1)}(s)| \le \epsilon
>$$
>
>Don't have to store $V_{\pi}^{(t)}$ for each iteration $t$, only need last two
>
>
>
>-   Time Complexity: $O(t_{PE}SS')$



#### 10. Value iteration

-   **Optimal Value** $V_{opt}(s)$
    -   the ==maximum value== attained by any policy



<img src="assets/Screenshot 2023-05-14 at 14.44.35.png" alt="Screenshot 2023-05-14 at 14.44.35" style="zoom:40%;" />



-   Optimal value if take action $a$ in state $s$


$$
Q_{\text{opt}}(s,a) = \sum_{s'}T(s,a,s')[\text{Reward}(s,a,s')+\gamma V_{\text{opt}}(s')]
$$



-   Optimal value from state $s$:

$$
V_{\text{opt}} = 
\begin{cases}
    0 & \text{if \ IsEnd}(s)\\ 
    \text{max}_{a\in \text{Actions(s)}}Q_{\text{opt}}(s,a) & \text{otherwise} 
\end{cases}
$$



-   Optimal policies

$$
\pi_{\text{opt}}(s) = \text{arg} \ \text{max}_{a \in \text{Actions}(s)} Q_{\text{opt}}(s,a)
$$

-   -   where

    -   `argmax` is a mathematical function that returns the argument that maximizes a given function.



#### 11. Algorithm of value iteration

>Initialize $V^{(0)}_{\text{opt}}(s)\leftarrow 0$ for all states $s$
>
>For iteration $t = 1, \dots, t_{VI}$
>
>​		For each state $s$:
>$$
>V_{\text{opt}}^{(t)}(s)\leftarrow \text{max}_{a\in \text{Actions}(s)} \underbrace{\sum_{s'}T(s,a,s')[\text{Reward}(s,a, s')+\gamma V_{\text{opt}}^{(t-1)}(s')]}_{Q_{\text{opt}}^{(t-1)}(s,a)}
>$$
>
>-   Time Complexity: $O(t_{VI}SAS')$



















