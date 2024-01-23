# Chapter 6: The Natural Numbers

We use *Peano Arithmetic* to define natural numbers in Lean. This is kinda like the *Mathematical Induction*.

```lean
inductive ℕ : Type
| zero : ℕ 
| succ : ℕ → ℕ  

ℕ = {0, 1, 2, ...}
  = {zero, succ zero, succ (succ zero), ...}
```

This declaration means:
- There is a new type `ℕ`
- There are two elements `zero : ℕ` and given `n : ℕ` we have `succ n : ℕ`.

**Peano Arithmetic**
- `zero ≠ succ`
- `succ` is injective

## 6.1 Basic properties of `ℕ`

Firstly we want verify `zero ≠ succ n`, it's kinda like `tt ≠ ff` for bool. We can use `contradiction` when we have an assumption of the form `0 = succ n`

```lean
example : ∀ n : ℕ, zero ≠ succ n :=
begin
  assume n h,
  contradiction,
end
```

Next, let's show `succ` is injective. To do this we have to define a predecessor
```lean
def pred : ℕ → ℕ
| zero := zero
| (succ n) := n

theorem inj_succ : ∀ m n : ℕ, succ m = succ n → m = n :=
begin
  assume m n h,
  change pred (succ m) = n,
  rewrite h,
  dsimp [pred],
  reflexivity,
end 
```

### Injection & `apply congr_arg`

When we have `succ m = succ n` in our condition, we could use `injection` to deal with it.
```lean
example : ∀ m n : ℕ, succ m = succ n → m = n :=
begin
  assume m n h,
  injection h,
end 
```

When we have `succ m = succ n` in our goal, we could `apply congr_arg succ` since `succ` is an injective function.
```Lean
theorem congr_succ : ∀ m n : ℕ, m = n → succ m = succ n :=
begin
  assume m n h,
  -- rewrite h,
  apply congr_arg succ,
  assumption,
end
```

We could also use **lamba expression** to create our own function

>   From [tu05](../Tutorials/tu05.lean)

```lean
theorem congr_add : ∀ l m n : ℕ, m = n → (l + m = l + n) :=
begin
  assume l m n,
  assume h,
  apply congr_arg (λ x, l + x),
  exact h,
end
```

```lean
theorem cancel_add_r : ∀ (l m n : ℕ), l + n = m + n → l = m :=
begin
  assume l m n,
  induction n with n' ih,
    dsimp [add],
    assume h,
    assumption,
    -----------
    dsimp [add],
    assume hh,
    apply ih,
    injection hh,
end
```

## 6.2 Structural recursion

A very classical example of *structural recursion* is `double`.

```lean
def double : ℕ → ℕ
| zero := zero 
| (succ m) :=  succ (succ (double m))
```

Another example is the reverse version, `half`.
- Here we have two base cases, `zero`, `succ zero`
- One for even numbers and the other for odd numbers

```lean
def half : ℕ → ℕ
| zero := zero
| succ (zero) := zero
| succ (succ n) = succ (half n)
```

## 6.3 Induction

**Mathematical induction**
- Here we use `induction` tactics to separate `∀ i : ℕ` into two cases
- Case one is the base cases `P(0)`
- Case two is the inductive step `P(k) → P(k+1)`

```lean
example : P zero → (∀ n : ℕ, P n → P (succ n)) → ∀ i : ℕ, P i :=
begin
  assume p0 pn i,
  induction i with i' pi,
  assumption,
  apply pn,
  assumption,
end
```

Based on this, now we can prove:
```lean
example : ∀ n : ℕ, half (double n) = n :=
begin
  assume n,
  induction n with n' ih,
    dsimp [double, half],
    reflexivity,
    -------------
    dsimp [double],
    dsimp [half],
    rewrite ih,
end
```

## 6.4 Addition and its properties

Here is the definition of add.
```lean
/- 2 + 3 = 1 + (2 + 2) -/
def add : ℕ → ℕ → ℕ
| n zero := n
| n (succ m) := succ (add n m)

local notation (name := add) m + n := add m n 
```

Here we take a very classic theorem as an example.
- **left neutral element**
- Due to the def of `add`, lean don't know whose successor `n` is, so we cannot directly use `dsimp [(+), add]`
- So we use induction to break it into *base case* and *inductive step*. Base case is very easy to prove
- For *inductive step*, we assume `P(k)` and need to prove `P(k+1)`. Lean could consider it as `P(succ k)`, therefore we could use `dsimp` to finish the rest of the proof

```lean
theorem lneutr : ∀ n : ℕ, 0 + n = n := 
begin
  assume n,
  induction n with n' ih,
    dsimp [add],
    reflexivity,
    ------------
    dsimp [add],
    rewrite ih,
end 
```

The proofs of some basic properties of addition are as follow.
- **right neutral element**
```lean
theorem rneutr : ∀ n : ℕ, n + 0 = n := 
begin
  assume n,
  dsimp [add],
  reflexivity,
end 
```

- associativity
- addition is by default **left associative**
```lean
theorem assoc : ∀ l m n : ℕ, (l + m) + n = l + (m + n) :=
begin
  assume l m n,
  induction n with n' ih,
    dsimp [add],
    reflexivity,
    ----------------
    dsimp [add],
    rewrite ih,
end
```

>   Now we have shown the following facts about `+` and `0`
>
>   -   `0` is right neutral: `n + 0 = n`
>   -   `0` is left neutral: `0 + n = n`
>   -   `+` is associative: `(l + m) + n = l + (m + n)`
>
>   Such a structure is called a **monoid**

- **commutativity**
```lean
lemma add_succ : ∀ m n : ℕ,
  (succ m) + n = succ (m + n) :=
begin
  assume m n,
  induction n with n' ih,
    dsimp [(+),add],
    reflexivity,
    -------------
    dsimp [(+),add],
    rewrite ih,
end

theorem comm : ∀ m n : ℕ , m + n = n + m :=
begin
  assume m n,
  induction n with n' ih,
    dsimp [(+),add],
    rewrite lneutr,
    --------------
    dsimp [(+),add],
    rewrite add_succ,
    rewrite ih,
end
```

**Note that:**
- In order to use lemma `add_succ` in `comm`, they should be in the same **namespace**.
- The reason why we should use a `lemma` is that, we get stuck in proving `(succ m) + n' = succ (m + n')`.
- Since we are in the *inductive step* of `n`, we cannot use `induction` **again** on `n'`.
- So we take it out as a lemma, and we can prove it using induction.

A more complicated example is to prove `mult_comm` in [ex05](../CW/ex05.lean).
```lean
lemma mult_succ : ∀ m n : ℕ, n * m + m = succ n * m :=
begin
  assume m n,
  induction m with m' ih,
    dsimp [add, mul],
    reflexivity,
    ---------------
    dsimp [mul],
    dsimp [add],
    rewrite← ih,
    rewrite add_assoc (n*m') n m',
    rewrite add_comm n m',
    rewrite add_assoc (n*m') m' n,
end

theorem mult_comm :  ∀ m n : ℕ , m * n = n * m :=
begin
  assume m n,
  induction n with n' ih,
    dsimp [mul],
    rewrite mult_zero_l,
    -------------
    dsimp [mul],
    rewrite ih,
    rewrite mult_succ,
end
```

>   **Conclusion**:
>
>   - ℕ with `+` and `0` form a *commutative monoid*
>   - If we have **inverse** where for every integer `i` there is `-i` s.t. `i + (-i) = 0`, then this structure is called a *group*.

## 6.5 Multiplication and its properties

First of all lets define multiplication:
```lean
def mul : ℕ → ℕ → ℕ
| m 0     := 0
| m (succ n) := (mul m n) + m

local notation (name := mul) m * n := mul m n 
```

> `ex05` is all about basic properties of **multiplication**, where you can find [here](../CW/ex05.lean)

In `ex05`, a theorem of *distributivity* is a very nice example of how to use `rewrite` with *parameters*.

- In this example, we need to prove:
- `(m*l')+(n*l')+(m+n)=m*l'+m+(n*l'+n)`
- Since there are many components in the equation, we have to give `rewrite` some specific variables to let Lean know which component i wanna apply `add_comm` or `add_assoc`
```lean
theorem mult_distr_l :  ∀ l m n : ℕ , (m + n) * l = m * l + n * l :=
begin
  assume l m n,
  induction l with l' lh,
    dsimp [(*), mul],
    dsimp [(+), add],
    reflexivity,
    ------------
    dsimp [(*), mul],
    rewrite lh,
    rewrite← add_assoc,
    rewrite add_assoc (m*l') (n*l') (m),
    rewrite add_comm (n*l') (m),
    rewrite add_assoc,
    rewrite add_assoc (m) (n*l') (n),
    rewrite← add_assoc,
end
```

>   **Conclusion**
>
>   Now we have a ***semiring***
>
>   - **Closure**: when you perform operations on two elements within the semiring, the result is still an element of the semiring.
>   - **Addition**: associative and commutative with identity element 0
>   - **Multiplication**: associative and commutative over addition with identity element 1
>   - **Distributivity**: Multiplication is distributive over addition


## 6.6 Some Algebra
Here we define the *exponentiatoin*.

```lean
def exp : ℕ → ℕ → ℕ 
| n zero := 1
| n (succ m) := (exp n m) * n 

local notation (name := exp) m ^ n := exp m n 
```

Now we can use a very useful tactic `ring` to make our life much easier.
```lean
import tactic

theorem binom : ∀ x y : ℕ, (x + y)^ 2 = x^2 + 2*x*y + y^2 :=
begin
  assume x y,
  ring,
end
```
Note that in order to use `import tactic`, we need to install mathlib globally using command `leanproject global-install`. 

*A sad story is that macOS with ARM does not support mathlib package :(*


There are different algebraic structures:
|**Example**|**Algebraic structure**|
|-----------|-----------------------|
| Natural numbers (ℕ) | Semiring    |
| Integers (ℤ)        | Ring        |
| Rational numbers (ℚ)| Field       |
| Real numbers (ℝ)    | Complete Field |
| Complex numbers (ℂ) | Algebraically complete Field |

- A *ring* is a semiring with *additive inverses*
  - $x + (-x) = 0$
- A field also has multiplicative inverses
  - $p * p^{-1} = 1$

## 6.7 Ordering the numbers

In this section, we look at *relations* `≤`, which defines a *partial order* on numbers.

```lean
def le (m n : ℕ) : Prop :=
  ∃ k : ℕ, k + m = n

local notation (name := le) m ≤ n := le m n
```

A *partial order* is a relation which is:
- reflexive: `∀ x : A, x ≤ x`
- transitive: `∀ x y z : A, x ≤ y → y ≤ z → x ≤ z`
- anti-symmetric: `∀ x y : A, x ≤ y → y ≤ x → x = y`

Now let's prove the first two properties.

```lean
-- Reflexivity
theorem le_refl: ∀ n : ℕ, n ≤ n :=
begin
  assume n,
  dsimp [(≤)],
  existsi 0,
  ring,
end

-- Transitivity
theorem le_trans: ∀ l m n : ℕ, l ≤ m → m ≤ n → l ≤ n :=
begin
  dsimp [(≤)],
  assume l m n lm mn,
  cases lm with k h,
  cases mn with k' hh,
  rewrite← hh,
  rewrite← h,
  existsi (k + k'),
  ring,
end
```

> which is also a question in [ex06](../CW/ex06.lean)

Anti-symmetric is a lot harder to prove, let's break it into pices:

```lean
theorem le_anti_sym : ∀ x y : ℕ , x ≤ y → y ≤ x → x = y := sorry
```

- By def of `le`, we know we have `k1+m=n`, `k2+n=m`, which by intuition we know that both `k1` and `k2` are `0`, but how to prove that?
- We first replace `n` in the second equation and have `k2+(k1+m)=m`.
- In order to prove this, we need *two lemmas*
  - `x+m=m → x=0` to imply `k2+k1=0`
  - `k2+k1=0 → k1=0 ∧ k2=0`
- Therefore, we could have `m=n`.
- The proof of two lemmas could be found in [ex06](../CW/ex06.lean).

```lean
lemma pos_neg : ∀ x y : ℕ, x + y = 0 → (x = 0) ∧ (y = 0) :=
begin
  sorry,
end

lemma pos_neg' : ∀ x y : ℕ, x + y = y → x = 0 :=
begin
  sorry,
end

-- Anti-symmetric
theorem le_anti_sym : ∀ x y : ℕ , x ≤ y → y ≤ x → x = y :=
begin
  assume x y,
  dsimp [le],
  assume h1 h2,
  cases h1 with k1 h1',
  cases h2 with k2 h2',
  rewrite← h2' at h1',
  rewrite← assoc at h1',
  have lem : k1 + k2 = 0,
    apply pos_neg',
    assumption,
  have lem' : (k1 = 0) ∧ (k2 = 0),
    apply pos_neg,
    assumption,
  cases lem' with lem1 lem2,
  rewrite lem2 at h2',
  rewrite lneutr at h2',
  rewrite h2',
end
```

We can also define `<` by saying:
```lean
def lt (m n : ℕ) : Prop := m + 1 ≤ n

local notation (name := lt) x < y := lt x y
```

It has the following properties:
- antireflexive: `∀ x : A, ¬ (x < x)`
- anti-symmetric: `∀ x y : A, x < y → y < x → false`
- *transitive*
- *well-founded*: `10 > 5 > 3 > 0` will eventually terminate
- *trichotomy*: the proof below

```lean
-- trichotomy
theorem trich : ∀ m n : ℕ, m < n ∨ m = n ∨ n < m :=
begin
  sorry,
end 
```

Since `<` is transitive, trichotomous and well-founded, it is called a `well-order`.


## 6.8 Decidability
A predicate `PP : A → Prop` is *decidable*, if there is a function `p : A → bool` s.t. `∀ a : A, PP a ↔ p a = tt`

Decidable examples:
- `Prime : ℕ → Prop`
- `≤ : ℕ → ℕ → Prop`

Un-decidable examples:


Equality for natural numbers is decidable, that is we can actually **implement it as a function into bool**:

```lean
def eq_nat : ℕ → ℕ → bool 
| zero zero := tt 
| (succ m) zero := ff
| zero (succ n) := ff
| (succ m) (succ n) := eq_nat m n 
```

We need to show that `eq_nat` indeed decides equality, first of all we show that `eq_nat` returns `tt` for equal numbers:

```lean
lemma eq_nat_ok_1 : ∀ n : ℕ, eq_nat n n = tt :=
begin
  assume n,
  induction n with n' ih,
    dsimp [eq_nat],
    constructor,
    ---------------
    dsimp [eq_nat],
    assumption,
end 
```

On the other hand we also show that if `eq_nat` returns `tt` then its arguments must be equal:
- Firstly, we do `induction` on `m`, which is a very natural way to deal with natural numbers
- But after `m` we need to deal with `n`. 
- Since we could not use `induction` inside a induction step, we simply use `cases` to separate `n` into *base case* and *inductive step*.
- *Also importantly*, we `assume n` after `induction` on `m`. 
- By doing this, we could have a **more flexible `ih` with `∀ n : ℕ`**, which is better than an *assumed `n`*.
- If we `assume m n` together and then do `cases n`, the `n` in `ih` would be affected by the `cases n`, therefore being

```lean
lemma eq_nat_ok_2 : ∀ m n : ℕ, eq_nat m n = tt → m = n :=
begin
  assume m,
  induction m with m' ih,
    assume n h,
    cases n with n',
      constructor,
      ------------
      dsimp [eq_nat] at h,
      contradiction,
    -------------
    assume n h,
    cases n with n',
      dsimp [eq_nat] at h,
      contradiction,
      ------------
      apply congr_arg succ,
      dsimp [eq_nat] at h,
      apply ih,
      assumption,
end 
```

Notice that, the proof above may go into a wrong way:
```lean
-- Wrong Proof
lemma eq_nat_ok_2' : ∀ m n : ℕ, eq_nat m n = tt → m = n :=
begin
  assume m n h,
  induction m with m' ih,
    cases n with n',
      reflexivity,
      ------------
      dsimp [eq_nat] at h,
      contradiction,
    ---------------
    cases n with n',
      dsimp [eq_nat] at h,
      contradiction,
      -----------
      apply congr_arg succ,
      sorry,
end
```

Now we could show that `eq_nat` decides equality:

```lean
theorem eq_nat_ok : ∀ m n : ℕ, m = n ↔ eq_nat m n = tt :=
begin
  assume m n,
  constructor,
  apply eq_nat_ok_1,
  apply eq_nat_ok_2,
end
```

Here we show that `≤` is also *decidable*, which also appears in [ex06](../CW/ex06.lean).
> For more exercises about `≤` and `min`, please go to [tu06](../Tutorials/tu06.lean).

```lean
def leb : ℕ → ℕ → bool
| zero n := tt 
| (succ m) zero := ff
| (succ m) (succ n) := leb m n 

theorem leb_ok : ∀ m n : ℕ, m ≤ n ↔ leb m n = tt := sorry
```

Like what we did for `eq_nat`, we separate the proof into two lemmas:
- The proof logics are quite similar
- Firstly, we *only* assume m, which makes `ih` more flexible with `∀ n : ℕ`
- Then we use `h` to rewrite our goal so that our goal could fit the goal of `ih`
- So we apply `ih` to our goal, there are only few steps left.

```lean
lemma lem1: ∀ m n : ℕ, m ≤ n → leb m n = tt :=
begin
  assume m,
  induction m with m' ih,
    assume n h,
    dsimp [leb],
    refl,
    --------
    assume n h,
    cases n,
    cases h with k h',
    contradiction,
    dsimp [le, add] at h,
    cases h with k h',
    dsimp [leb],
    apply ih,
    dsimp [le],
    existsi k,
    injection h',
end

lemma lem2: ∀ m n : ℕ, leb m n = tt → m ≤ n :=
begin
  assume m,
  induction m with m' ih,
    assume n h,
    dsimp [le],
    existsi n,
    dsimp [add],
    refl,
    ---------
    assume n h,
    cases n,
    dsimp [leb] at h,
    contradiction,
    dsimp [leb] at h,
    have mn : m' ≤ n,
      apply ih,
      exact h,
    cases mn with k mn',
    dsimp [le, add],
    existsi k,
    apply congr_arg succ,
    exact mn',
end
```





