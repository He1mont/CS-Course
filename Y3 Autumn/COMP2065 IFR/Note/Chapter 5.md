# Chapter 5: The Booleans

We look at a very simple type in this Chapter `bool`, which has just two elements `tt` for *true* and `ff` for *false*.

In the Lean prelude `bool` is defined as an inductive type, and this means:
- There is a new type `bool : Type`
- There are two elements `tt ff : bool`
- These are the only elements of `bool`
- `tt` and `ff` are different elements of `bool`

```Lean
inductive bool : Type
| ff : bool
| tt : bool
```

> `tt` and `ff` are a type of `bool` while `true` and `false` are propositions.

## 5.1 Functions on bool

Let's define logic relation functions for booleans.

- **Not**

```Lean
def bnot : bool → bool
| tt := ff 
| ff := tt  
```

- **And**
```Lean
def band : bool → bool → bool
| tt b := b 
| ff b := ff

local notation (name := band) x && y := band x y 

-- we could also write
def band2 : bool → bool → bool
| b tt := b 
| b ff := ff
```

>   In order to figure our the difference of `band` and `band2`, let's take `orb_ok` in `ex04` as an example.
>
>   ```Lean
>   example : ∀ x y : bool, is_tt x ∨ is_tt y → is_tt (x || y) :=
>   begin
>     assume x y h,
>     sorry,
>   end
>   ```
>
>   After this, we could have two options:
>
>   - `cases h with hx hy`
>   - `cases x`
>
>   If we choose `cases h with hx hy`, then we may have to use `cases y`. However, if we do `cases y`, then we have to deal with `is_tt (x || ff)`, which can be solved by `dsimp [band2]` rather than `dsimp [band]`.
>
>   **So we have to go for `cases x`.**

- **Or**
```Lean
def bor : bool → bool → bool 
| ff x := x
| tt x := tt

local notation (name := bor) x || y := bor x y
```


The lean prelude also introduces the standard infix notation for operations on `bool`
```Lean
x && y := band x y
x || y := bor x y
```

We can also evaluate boolean expressions using `#reduce`
```Lean
#reduce ff && (tt || ff)    -- ff
#reduce tt && (tt || ff)    -- tt
#reduce band tt x           -- x
#reduce band x tt           -- x && tt 
```

## 5.2 Proving some basic properties
We can use `cases x` to analyse a variable `x : bool` which there are two possibilities `tt` and `ff`. 

We can also prove in predicate logic that every element of `bool` is either `tt` or `ff`

```Lean
example : ∀ x : bool, x = tt ∨ x = ff :=
begin
  assume x,
  cases x, 
    right,
    refl,
    -----------
    left,
    refl,
end
```

- `is_tt`

```Lean
def is_tt : bool → Prop 
| ff := false
| tt := true 
```

**Now we have two ways to show that `tt` and `ff` cannot be equal.**

### Using `is_tt`

- Note that after `tf`, we use `change` to change the goal from `false` into `is_tt ff`.
- And use *trivial proof* since if the results are correct, the whole proof is correct.

```Lean
theorem cons : tt ≠ ff :=
begin
  assume tf,
  change is_tt ff,
  rewrite← tf,
  trivial,
end
```
- Instead of writing `trivial`, we could simply just write `dsimp: `
- `dsimp` could be directly used in goals, to apply functions like `band`, `is_tt`
- if you wanna apply functions to our conditions, we could use `dsimp at`
```Lean
example : tt ≠ ff :=    -- (tt = ff) → false 
begin
  assume h,
  change is_tt ff,      -- is_tt ff = false
  rewrite← h,
  dsimp [is_tt],
  constructor,
end
```

### Using `Contradiction`


- However, since this is a common situation, Lean provides the tactic `contradict` which we can use to prove goals like this:

```Lean
example : tt ≠ ff :=
begin
  assume h,
  contradiction,
end
```

## 5.3 Proving equations about bool

Here we list three examples, respectively a *distributive law* and two *De Morgan's laws*. 

As you could see below, **proving equations about bool mostly relies on `dsimp`**, so we just take a very quick glance.

```lean
theorem distr_b : ∀ x y z : bool, x && (y || z) = x && y || x && z :=
begin
  assume x y z,
  cases x,
    dsimp [band, bor],
    reflexivity,
    --------------
    dsimp [band, bor],
    reflexivity,
end
```

```Lean
theorem dm1_b : ∀ x y : bool, bnot (x || y) = bnot x && bnot y :=
begin
  assume x y,
  cases x,
    dsimp [bor, bnot],
    reflexivity,
    ---------------
    dsimp [bor, bnot],
    reflexivity,
end
```

```Lean
theorem dm2_b : ∀ x y : bool, bnot (x || y) = bnot x && bnot y :=
begin
  assume x y,
  cases x,
    dsimp [bor, bnot],
    reflexivity,
    ---------------
    dsimp [bor, bnot],
    reflexivity,
end
```

## 5.4 Relating bool and Prop
Here are three theorems about `and`, `or` and `not`.

**The basic method to solve these problems is by using `cases` and `dsimp` properly.**

```Lean
theorem andb_ok : ∀ x y : bool,
  is_tt (x && y) ↔ is_tt x ∧ is_tt y :=
begin
  assume x y,
  constructor,
    cases x,
      dsimp [band],
      assume f,
      cases f,
      --------------
      dsimp [band],
      assume h,
      constructor,
        constructor,
        assumption,
    --------------
    assume andxy,
    cases andxy with xx yy,
    cases x,
      dsimp [band],
      assumption,
      ------------
      dsimp [band],
      assumption,
end
```

```Lean
theorem orb_ok : ∀ x y : bool, 
  is_tt (x || y) ↔ is_tt x ∨ is_tt y :=
begin
  assume x y,
  constructor,
    cases x,
      dsimp [bor],
      assume h,
      right,
      assumption,
      --------------
      dsimp [bor],
      assume h,
      left,
      assumption,
    ------------
    assume h,
    cases x,
      dsimp [bor],
      cases h with f y,
      cases f,
      assumption,
      ------------
      dsimp [bor],
      cases h with t y,
      assumption,
      trivial,
end
```

```lean
theorem not_thm : ∀ x : bool, ¬ (is_tt x) ↔ is_tt (bnot x) :=
begin
  assume x,
  constructor, 
    cases x,
      dsimp [bnot],
      assume h,
      constructor,
      -------------
      dsimp [is_tt],
      assume h,
      apply h,
      constructor,
    ----------------
    cases x,
      dsimp [bnot, is_tt],
      assume t f,
      cases f,
      ------------
      dsimp [bnot, is_tt],
      assume f,
      cases f,
end
```

## 5.5 from `ex04`
We use a example to demonstrate a very interesting property of bool.
> The statement "there exists a smart student in the class" is equivalent to "student A is smart, or student B is smart, ... , or student N is smart". 
>
> In this case, the type `bool = {tt, ff}` could be replaced by a finite type `student = {A, B, ..., Z}`, and the `f : bool → bool` could be replaced by a function called `isSmart : student → bool`

And this can be translated into the following theorem.
- One key point of proving this problem is how to use a **bi-implication lemma** from `orb_ok`

```Lean
def exb (f : bool → bool) : bool := f tt || f ff

theorem exb_ok : ∀ f : bool → bool, is_tt (exb f) ↔ ∃ x : bool, is_tt (f x) :=
begin
  assume f,
  dsimp [exb],
  have lem : is_tt (f tt) ∨ is_tt (f ff) ↔ is_tt (f tt||f ff),
    apply orb_ok,
  cases lem with lem1 lem2,
  constructor,
    assume h,
    have g : is_tt (f tt) ∨ is_tt (f ff),
      apply lem2,
      assumption,
    --------------
    cases g with gtt gff,
      existsi tt,
      assumption,
      -------------
      existsi ff,
      assumption,
    --------------
    assume h,
    apply lem1,
    cases h with x hx,
    cases x,
      right,
      assumption,
      -----------
      left,
      assumption,
end
```

