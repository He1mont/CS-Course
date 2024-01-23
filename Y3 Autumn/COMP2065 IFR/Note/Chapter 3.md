# Chapter 3. Classical Logic

## 3.0 Algebra and Logic (from `lec04`)
There are some relations between algebra and logic:
- `=` ==> ↔
- `+` ==> ∨
- `*` ==> ∧
- `^` ==> →       
  - *index could be seen as implication in logics*
  - x ^ y ==> y → x

Here we skip *law of commutativity*, *law of associativity* and *law of distributivity*. We only focus on the three ***law of indices***.
- `x^y * x^z = x^(y+z)`
- `x^z * y^z = (x*y)^z`
- `(x^y)^z = x^(y*z)`

| Algebra             | Logical | Logic |
| ------------------- | ------- | ----- |
|`x^y * x^z = x^(y+z)`|`(P → R) ∧ (Q → R) ↔ (P ∨ Q) → R`|Intuitional |
|variation            |`(P → R) ∨ (Q → R) ↔ (P ∧ Q) → R`| Classical |
|`x^z * y^z = (x*y)^z`|`(P → Q) ∧ (P → R) ↔ P → (Q ∧ R)`|Intuitional |
|variation            |`(P → Q) ∨ (P → R) ↔ P → (Q ∨ R)`|Classical|

<details>
<summary>Here are the Proofs. </summary>

### `x^y * x^z = x^(y+z)`
```Lean
-- let x be R, y be P and z be Q
theorem index : (P → R) ∧ (Q → R) ↔ (P ∨ Q) → R :=
begin
  constructor,
    assume prqr pq,
    cases prqr with pr qr,
    cases pq with p q,
      apply pr,
      assumption,
      ----------------
      apply qr,
      assumption,
    ---------------------
    assume pqr,
    constructor,
      assume p,
      apply pqr,
      left,
      assumption,
      ---------------
      assume q,
      apply pqr,
      right,
      assumption,
end
```

### `x^z * y^z = (x*y)^z`
```Lean
-- let x be Q, y be R, z be P
example : (P → Q) ∧ (P → R) ↔ P → (Q ∧ R) := 
begin
  constructor,
    assume pqpr p,
    cases pqpr with pq pr,
    constructor,
      apply pq,
      exact p,
      apply pr,
      exact p,
    -----------
    assume pqr,
    constructor,
      assume p,
      have qr : Q ∧ R,
        apply pqr,
        exact p,
      cases qr with q r,
      exact q,
      ----------
      assume p,
      have qr : Q ∧ R,
        apply pqr,
        exact p,
      cases qr with q r,
      exact r,
end
```

### `x^(y*z) = (x^y)^z`
- This is the **Curry** theorem we proved in Chapter 2.6
```Lean
-- let x be R, y be Q, z be P
example : (P ∧ Q) → R ↔ P → Q → R := 
begin
  constructor,
    assume pqr p q,
    apply pqr,
    constructor,
    assumption,
    assumption,
    ------------------
    assume pqr pq,
    cases pq with p q,
    apply pqr,
    assumption,
    assumption,
end
```

</details>

## 3.1 The de Morgran laws
**De Morgan Laws**
- `¬ (P ∨ Q) ↔ ¬ P ∧ ¬ Q`
- `¬ (P ∧ Q) ↔ ¬ P ∨ ¬ Q`

Notice that `¬ P = P → false`, we can re-write the De Morgan's laws into the *law of indices*
- `(P ∨ Q) → false ↔ (P → false) ∧ (Q → false)`
- `(P ∧ Q) → false ↔ (P → false) ∨ (Q → false)`

The proofs are as follows.

### `¬ (P ∨ Q) ↔ ¬ P ∧ ¬ Q`
- Here we apply the `index` theorem proved in *Chapter 3.0*
- Please note that if we wanna prove `dm1`
and we directly apply theorem `index`, it's not working.\
Although `↔` satisfies commutative law,
but `Lean` is too dumb to know that

```Lean
theorem dm1: ¬ P ∧ ¬ Q ↔ ¬ (P ∨ Q) :=
begin
  apply index,
end
```

### `¬ (P ∧ Q) ↔ ¬ P ∨ ¬ Q`
This proof would be a litte bit more complicated, so we have to introduce some powerful **lemmas** in `Lean`.

## 3.2 The law of the excluded middle

In Discrete Mathematics, the excluded middle is written as follows:
$$P \vee \neg P \equiv True $$

In `Lean`, we have to include a library to use it.
```Lean
open classical
#check em P
```

```Lean
-- Note that if we wanna prove `P`,
-- we are proving `P → True`
example : P ∨ ¬ P :=
begin
  apply em,
end
```

```Lean
theorem dm2: ¬ (P ∧ Q) ↔ ¬ P ∨ ¬ Q :=
begin
  constructor,
    assume npq,
    cases (em P) with p np,
      right,
      assume q,
      apply npq,
      constructor,
      assumption,
      assumption,
      ----------------
      left,
      assumption,
    ----------------            
    assume npnq,
    assume pq,
    cases pq with p q,
    cases npnq with np nq,
      apply np,
      assumption,
      -------------------
      apply nq,
      assumption,
end
```

### Indirect proof
In this proof, we prove P by showing that `not(P)` is impossible, kinda like **Proof by Contradiction**, and this is called *reduction ad absurdo* in *Latin*.

```Lean
theorem efq : false → P :=
begin
  assume f,
  cases f,
end
```

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

```Lean
theorem nnem : ¬ ¬ (P ∨ ¬ P) :=  
begin
  assume npnp,
  apply npnp,
  right,        -- **important step**
  assume p,
  apply npnp,
  left,
  assumption,
end
```
Now we can prove `em`:
```Lean
theorem em : P ∨ ¬ P :=
begin
  apply raa,
  apply nnem,
end 
```

## 3.4 Intuitionistic vs. classical logic
There are two types of logic.
- classical logic: 
  - truth based
  - need `em` and `raa` in proof
- intuitionisitic logic
  - evidence based

> Anything you can prove using intuitionisically, you can also prove it classically.

`em` and `raa` could be proved **recursively**.
- `em → raa`
- `raa → em`
