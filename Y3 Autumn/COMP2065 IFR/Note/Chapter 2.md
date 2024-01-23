# Chapter 2: Propositional Logic

## 2.1 What is a proposition

> A **proposition** is a statement which may be able to prove.

In Lean, we declare propositional variables below:

```Lean
variables P Q R : Prop
```

We introduce a number of connectives and logical constants to construct propositions:
- Implication, `P → Q`
- Conjunction, `P ∧ Q`
- Disjuction, `P ∨ Q `
- Negation, `¬ P`
- Equivalence, `P ↔ Q`
- `true`
- `false`

To save **parentheses**, there are a number of conventions:
- `not` stronger than any connectives
- `and` stronger than `or`
- `and` and `or` stronger than `imply`
- `imply` stronger than `iff`
- **Implication is right associative**

> A tautology is a statement that is true in all cases.

**Tautology** is important because they exhibit the basic figures of reasoning.


## 2.2 Out first proof

```Lean
theorem I : P → P := 
begin
  assume h, 
  exact h,
end 
```

- `assume h` means we are going to prove an implication by assuming the premise, and using the assumption to prove the conclusion.
- `exact h`, we complete the proof by telling Lean that there is an assumption that *exactly* matches the current goal.
- `tactics`, each line of proof is a tactic


## 2.3 Using assumptions

Next, we are going to prove a more complicated tautology.
- There are 3 assumptions.
- The proof process is the way of tracing back.

```Lean
theorem C : (P → Q) → (Q → R) → (P → R) :=
begin
  assume pq,
  assume qr,
  assume p,
  apply qr,
  apply pq,
  exact p,
end
```

Here is an example of a **repeated implications.**
- In a mathematical way
  - P and Q are both conditions to make R happen
  - So the order of P and Q doesn't affect the actual results
  - $P \to Q \to R \equiv (P \land Q) \to R$
- In a programming way
  - It's kinda like **currying in Haskell**
  - The program waits for P and then waits for Q
  - Therefore the waiting order doesn't affect the actual results

```Lean
theorem swap: (P → Q → R) → (Q → P → R) :=
begin
  assume pqr q p,
  apply pqr,
  exact p,
  exact q,
end
```


## 2.4 Proof terms

The tactics are actually more like editor commands which is a program. This explains why `p : P` is kinda similar to `3 :: int` in **Haskell**.

> Proofs are functional programs.

Lean exploits *the propositions as types translation* and associates to every proposition the type of evidence for this proposition.

The Haskell type system is expressive enough for propositional logic but doesn't cover predicate logic.

> The functional language on which Lean relies is called *dependent type theory*, or more specifically *The Calculus of Inductive Constructions.*


## 2.5 Conjunctions

In order to prove (P and Q), we need to prove both P and Q. This is achieved by `constructor` tactic.

Here is an example.
- We use `example` here since we don't wanna give `theorem` a name.
- The `constructor` kinda spilt the original goal `P and Q` into `P` and `Q`
- The `cases` however, spilt the condition `P and Q` into `P is True` and `Q is True`, by the *simplification rule*. 

```Lean
example : P → Q → P ∧ Q :=
begin
  assume p q,
  constructor,
  exact p,
  exact q,
end
```
```Lean
example : P ∧ Q → P :=
begin
  assume pq,
  cases pq with p q,
  exact p,
end
```

Now we prove that conjunction is *commutative*.

```Lean
theorem comAnd : P ∧ Q → Q ∧ P :=
begin
  assume pq,
  cases pq with p q,
    constructor,
    exact q,
    exact p
end 
```
- Here we use `constructor` to break `iff` into two `implies`.

```Lean
theorem comAndIff : P ∧ Q ↔ Q ∧ P :=
begin 
  constructor,
  apply comAnd,
  apply comAnd,
end    
```


## 2.6 The Currying Equivalence

In [Chapter 2.3](#23-using-assumptions), the *swap* example shows that P and Q are all conditions to R. 
- We don't have to worry about the *orders* of the conditions. 
- The last propostion is our `goal`, and the others are all `conditions`. 
- Do not consider `→` as *imply*, rather than all the conditions are *conjunction*, and here comes the idea of **currying**.

So now let's prove:

```Lean
-- a lemma for the curry theorem
example : (P → Q → R) → P → Q → R :=
begin
  assume pqr p q,
  apply pqr,
  exact p,
  exact q
end
```

```Lean
theorem curry : (P → Q → R) ↔ (P ∧ Q → R) :=
begin
  constructor,
  assume pqr pq,
  cases pq with p q,
  apply pqr,
  exact p,
  exact q,

  assume pqr p q,
  apply pqr,
  constructor,
  exact p,
  exact q,
end 
```
> A function with several parameters can be reduced to a function which returns a function.
>
> In Haksell: `Int -> Int -> Int`


## 2.7 Disjunction

To prove a disjunction, we can either prove P or prove Q. This is achieved by the tactics `left` and `right`.

```Lean
example : P → P ∨ Q :=
begin
  assume p,
  left,
  exact p
end 

example : Q → P ∨ Q :=
begin
  assume q,
  right,
  exact q
end 
```

```Lean
theorem case_lem : (P → R) → (Q → R) → P ∨ Q → R :=
begin
  assume pr qr pq,
  cases pq with p q,
  apply pr,
  exact p,
  apply qr,
  exact q
end  
```


## 2.8 Logic and algebra

Consider the **distributivitiy** in propositional logic:
- In Lean, you can type `sorry` to omit the proof

```Lean
example : P ∧ (Q ∨ R) ↔ (P ∧ Q) ∨ (P ∧ R) :=
begin
  sorry
end
```

```Lean
example : P ∧ (Q ∨ R) ↔ (P ∧ Q) ∨ (P ∧ R) :=
begin
  constructor,
  assume pqr,   -- left to right
  cases pqr with p qr,
  cases qr with q r,
  left,
  constructor,
  exact p,
  exact q,
  right,
  constructor,
  exact p,
  exact r,
  assume pqpr,  -- right to left
  constructor,
  cases pqpr with pq pr,
  cases pq with p,
  exact p,
  cases pr with p,
  exact p,
  cases pqpr with pq pr,
  cases pq with p q,
  left,
  exact q,
  cases pr with p r,
  right,
  exact r,
end
```


## 2.9 True, false, and negation

There are two logical constants:
- `true` is like an empty conjunction
- `false` is like an empty disjunction

```Lean
example : true :=
begin 
  constructor,
end 

theorem efq : false → P :=
begin
  assume pigs_can_fly,
  cases pigs_can_fly,
end 
```

*Law of contradiction*:
```Lean
theorem contr: ¬ (P ∧ ¬ P) :=
begin
  assume pnp,
  cases pnp with p np,
  apply np,
  exact p,
end
```

When dealing with *negation*, remember that
$$ \neg \  P \equiv  P \to False $$
Therefore, if the goal has many negations, we can assume another variable to simpilify the goal into `false`.



An example from [`q06 ex01`](../CW/ex01.lean):

```Lean
-- equiv to `P → (P → false) → false`
theorem q06 : P → ¬ ¬ P :=
begin
  assume p pf,
  apply pf,
  exact p,
end
```

The following theorem is a very **important tautology** in logic. However, it would be a lot more complicated to prove the reverse, which is called `raa` and will be discussed in **Chapter 3**.
```Lean
theorem raa : ¬ ¬ P → P :=
begin
  assume nnp,
  cases em P with p np,
    assumption,
    -------------------
    apply efq,
    apply nnp,
    assumption,
end 
```

Another interesting fact that a noticed is that it would be a lot more easier to prove the following to examples, so I think if the goal contains $\neg P$, it might be a nice thing.
```Lean
example : ¬ ¬ ¬ P → ¬ P 
example : ¬ P → ¬ ¬ ¬ P
```


## 2.10 Summary of tactics

|      | How to prove | How to use |
| ---- | ------------ | ---------- |
| →    | assume h     | apply h    |
| ∧    | constructor  | cases h with p q |
| ∨    | left right   | cases h with p q |
| true | constructor  |            |
| false |             | cases hc   |