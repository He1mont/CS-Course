# Chapter 4: Predicate Logic

## 4.1 Predicates, relations and quantifiers

The objects are organized in *types*, for example
- `ℕ : Type`, for natural numbers
- `bool : Type`, for boolean values

We can introduce some type variables:
```Lean
variables A B C : Type
```

> **What is Predicate?**
> 
> The statement “x is greater than 3” has two parts. 
> - The variable x, is the subject of the statement. 
> - The ***predicate***, “is greater than 3”, refers to <u>a property that the subject of the statement can have.</u>

A **predicate** is just another word for **property**. Predicates may have several inputs, and we usually call them **relations**. For example:
- `≤ : ℕ → ℕ → Prop`
- `occurs : A → list A → Prop`
  - occurs 1 [1,2,3] is true
  - occurs 7 [1,2,3] is false

We will use some generic predicates for example:
```Lean
variables PP QQ : A → Prop 
```

### Quantifiers
**Both quantifiers bind *weaker* than any other propositional operator.**
- `∀ x : A, PP x`
- `∃ x : A, PP x`

Consider the two examples below, they are not equivalent. Since when A is an ***empty set***, `∀ x:A` would be a *vacuous proof*, the first example would be `true` while the second one would be `false`.
```Lean
 ∀ x : A, (PP x ∧ Q)
 (∀ x : A, PP x) ∧ Q
```


## 4.2 The universal quantifier

**An example**

We can treat universal quantifier as an implication since:
$$\forall x \in A, P(x) \equiv \forall x \in A \to P(x)$$

Assume `A` stands for the typs of students in the class
`PP x` means x is clever, and `QQ x` means x is funny

```Lean
example : (∀ x : A, PP x) → (∀ x : A, PP x → QQ x) → (∀ x : A, QQ x) :=
begin 
  assume pp ppqq,
  assume a,         -- instantiation
  apply ppqq,
  apply pp,         -- generalization
end
```

```Lean
example : P → (P → Q) → Q :=
begin
  assume p pq,
  apply pq,
  assumption,
end
```

Another example including intersection
```Lean
example : (∀ x:A, PP x ∧ QQ x) ↔ (∀ x:A, PP x) ∧ (∀ x:A, QQ x ) :=
begin
  constructor,
    assume ppqq,
    constructor,
      assume a,
      have stone : PP a ∧ QQ a,
        apply ppqq,
      cases stone with ppa qqa,
      assumption,
      --------------
      assume a,
      have stone : PP a ∧ QQ a,
        apply ppqq,
      cases stone with ppa qqa,
      assumption,
    ----------------
    assume ppqq,
    cases ppqq with pp qq,
    assume a,
    constructor,
      apply pp,
      apply qq,
end
```

## 4.3 The existential quantifier

We can treat existential quantifier as an conjunction since:
$$\exist x \in A, P(x) \equiv \exist x \in A \land P(x)$$

Therefore, we can use `cases` if we have `∃ x:A, PP x` in our conditions.

However, if we have prove `∃ x:A, PP x`, `constructor` does not work well. Instead, we have a tool called `existsi a` to change our goal into `PP a`.

**An example**

```Lean
example : (∃ x:A, PP x) → (∀ x:A, PP x → QQ x) → (∃ x:A, QQ x) :=
begin
  assume pp ppqq,
  cases pp with a pa,
  existsi a,
  apply ppqq,
  assumption,
end
```

```Lean
example : (∃ x:A, PP x ∨ QQ x) ↔ (∃ x:A, PP x) ∨ (∃ x:A, QQ x) :=
begin
  constructor,
    assume ppqq,
    cases ppqq with a ppaqqa,
      cases ppaqqa with ppa qqa,
      left,
      existsi a,
      assumption,
      ------------------
      right,
      existsi a,
      assumption,
    ------------------
    assume ppqq,
    cases ppqq with pp qq,
      cases pp with a ppa,
      existsi a,
      left,
      assumption,
      --------------------
      cases qq with a qqa,
      existsi a,
      right,
      assumption,
end
```

## 4.4 Another Currying equivalence

In the previous **Curry theorem**, we know that:

```Lean
P ∧ Q → R ↔ P → Q → R
```

We can now turn it into :

```Lean
`(∃ x:A, QQ x) → R ↔ (∀ x:A, QQ x → R)`
```

Let `QQ x` be x is clever and R mean the professor is happy, then the equivalence is:
```
If there's a student who is clever then the professor is happy 
is equivalent to saying 
if any student is clever then the professor is happy
```
Here is the proof:
```Lean
example : (∃ x:A, QQ x) → R ↔ (∀ x:A, QQ x → R) :=
begin
  constructor,
    assume qqr a qqa,
    apply qqr,
    existsi a,
    assumption,
    -----------------
    assume qqr qq,
    cases qq with a qqa,
    have qqar : QQ a → R,
      apply qqr,
    apply qqar,
    assumption,
end
```

## 4.5 Equality
Now we consider a relation `equality` and its three properties `reflexive`, `symmetric`, `transitive` one by one.

- To prove **reflexivity**, we just write it down
- if we know `a = b` and we have to prove `PP a`, we can use `rewrite`
- if we know `a = b` and we have to prove `PP b`, we can use `rewrite←` 

```Lean
example : ∀ x y : A, x = y → PP y → PP x :=
begin
  assume a b,
  assume ab ppb,
  rewrite ab,
  assumption,
end  

example : ∀ x y : A, x = y → PP x → PP y :=
begin
  assume a b,
  assume ab ppa,
  rewrite← ab,
  assumption,
end  
```

> From ex03 q05
- we could also do `rewrite at` to modify our condition
```Lean
theorem q05 : ∀ x y z : A, x = y → x ≠ z → y ≠ z :=
begin 
  assume x y z xy xz,
  rewrite← xy,
  assumption,
end
```

### Reflexivity
```Lean
example : ∀ x : A, x = x :=
begin
  assume a,
  reflexivity,
end
```

### Symmetry
```Lean
example : ∀ x y : A, x = y → y = x :=
begin
  assume a b,
  assume ab,
  rewrite ab,   -- automatically applies reflexivity
end
```

### Transitivity
```Lean
example : ∀ x y z : A, x = y → y = z → x = z :=
begin
  assume a b c,
  assume ab bc,
  rewrite ab,
  assumption,
end
```

Actually Lean already has built-in tactics to deal with **symmetry** and **transitivity**
```Lean
example : ∀ x y : A, x = y → y = x :=
begin
  assume a b ab,
  symmetry,
  assumption,
end

example : ∀ x y z : A, x = y → y = z → x = z :=
begin
  assume x y z xy yz,
  transitivity,
  assumption,
  assumption,
end
```

## 4.6 Classical Predicate Logic
Before we step into De Morgan's Law, let's reconsider the [Curry Equivalence](#44-another-currying-equivalence) in predicate logic.
```Lean
example : (∃ x:A, PP x) → R ↔ ∀ x:A, PP x → R := sorry
```
If we let `R` be `false` then we get `dm1_pred`.

Now we consider De Morgan's Law in predicate logics.

```Lean
theorem dm1_pred : ¬ (∃ x:A, PP x) ↔ (∀ x:A, ¬ PP x) :=
begin
  constructor,
    assume npp a ppa,
    apply npp,
    existsi a,
    assumption,
    ---------------
    assume npp pp,
    cases pp with a ppa,
    have nppa : ¬ PP a,
      apply npp,
    apply nppa,
    assumption,
end
```

**This theorem is much harder to prove**, we `apply raa` twice.
```Lean
-- raa : ¬ ¬ P → P

theorem dm2_pred : ¬ (∀ x:A, PP x) ↔ (∃ x:A, ¬ PP x) :=
begin
  constructor,
    assume npp,
    apply raa,
    assume nnpp,
    apply npp,
    assume a,
    apply raa,
    assume nppa,
    apply nnpp,
    existsi a,
    assumption,
    ---------------
    assume npp pp,
    cases npp with a nppa,
    apply nppa,
    apply pp,
end
```

## 4.6* Drinkers Paradox
> From ex03 q10

> The drinkers paradox is as follows: 
> 
> There is a non-empty pub and there exists a person such that if this person is drinking, then everyone is drinking.

It can be written in Predicate Logic as follows:
```Lean
(∃ x : A, true) → (∃ x:A, (PP x → ∀ x : A,PP x))
```
Notice that the theorem above is **Provable**, while the example below is **NotProvable**
```Lean
(∃ x : A, true) → (∃ x:A, PP x) → ∀ x : A,PP x
```

Now let's first try to prove this theorem in logic:
- There are only two cases in the non-empty pub: everyone in the pub is drinking, and there exists at one person who is not drinking
- Case 1: `PP x = True` and `∀ x : A,PP x = True`
- Case 2: Let x be the person who is not drinking, therefore we could use *vacuous proof* by `PP x = false`

Now let's analyse the proof step by step.
- First and foremost, we use `em (∀ x : A,PP x)` to sepate into two cases
- Case 1 is quite simple
- In case 2, we apply De Morgan's Law to the case and turn it into `∃ x:A, ¬ PP x` and do `cases with` to generate a person `b` who is not drinking
- Then we could let the `∃ x:A` be the one who is not drinking by using `existsi` and then assume `PP b` which means `b` is drinking
- This generates a contradiction and therefore we could use *vacuous proof*

Here is the proof
```Lean
theorem q10 : (∃ x : A, true) → (∃ x:A, (PP x → ∀ x : A,PP x)) :=
begin
  assume t,
  cases t with a tt,
  cases em (∀ x:A, PP x) with h nh,
    existsi a,
    assume ppa,
    assumption,
    -------------
    have dm : ∃ x:A, ¬ PP x,
      apply raa,
      assume npp,
      apply nh,
      assume b,
      apply raa,
      assume ppb,
      apply npp,
      existsi b,
      assumption,
    cases dm with b nppb,
    existsi b,
    assume ppb,
    have efq : false → (∀ x:A, PP x),
      assume f,
      cases f,
    apply efq,
    apply nppb,
    assumption,
end
```

## 4.7 Summary of tactics
|   | How to prove | How to use |
| - | ------------ | ---------- |
| ∀ | assume h     | apply h    |
| ∃ | exisrsi a    | cases h with a ppa |
| = | reflexivity  | rewrite h, rewrite← h|



