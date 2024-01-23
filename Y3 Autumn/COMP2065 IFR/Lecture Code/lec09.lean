/-
## Lecture 09 : The Booleans
-/
set_option pp.structure_projections false

/-
bool = { tt , ff }

inductive bool : Type 
| tt : bool
| ff : bool

-/

-- Two = { zero , one }
inductive Two : Type 
| zero : Two
| one : Two

#check Two.zero 

open Two

#check zero


inductive bool' : Type
| ff : bool'
| tt : bool'

def bnot' : bool → bool
| tt := ff 
| ff := tt  

def band' : bool → bool → bool
| tt b := b 
| ff b := ff

def band2 : bool → bool → bool
| b tt := b 
| b ff := ff

/-
The lean prelude also introduces the standard infix notation 
for operations on `bool`
- x && y := band x y
- x || y := bor x y

-/

-- we can evaluate boolean expressions using `#reduce`
#reduce ff && (tt || ff)
#reduce tt && (tt || ff)

variable x : bool 

#reduce band tt x
#reduce band x tt

/-
We can also prove in predicate logic that 
every element of `bool` is either `tt` or `ff`
-/

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

def is_tt : bool → Prop 
| ff := false
| tt := true 

-- we can use `is_tt` to show `tt` and `ff` are not equal
theorem cons : tt ≠ ff :=
begin
  assume tf,
  change is_tt ff,
  rewrite← tf,
  trivial,
end

-- instead of writing `trivial`, we could simply write as follows
example : tt ≠ ff :=    -- (tt = ff) → false 
begin
  assume h,
  change is_tt ff,      -- is_tt ff = false
  rewrite← h,
  dsimp [is_tt],
  constructor,
end

-- Solve it using `contradiction`
example : tt ≠ ff :=
begin
  assume h,
  contradiction,
end

prefix `!`:90 := bnot

#eval ! tt

example : ∀ x : bool, ! (! x) = x :=
begin
  assume x, 
  cases x,
  dsimp [bnot],
  reflexivity,
  dsimp [bnot],
  reflexivity,
end


theorem comm_band : ∀ x y : bool, x && y = y && x :=
begin
  assume x y,
  cases x,
    dsimp [band],
    cases y,
      dsimp [band],
      reflexivity,
      --------------
      dsimp [band],
      reflexivity,
    ---------------
    dsimp [band],
    cases y,
      dsimp [band],
      reflexivity,
      ---------------
      dsimp [band],
      reflexivity,
end

example : ∀ x y : bool, ! (x && y) = (! x) || (! y) :=
begin
  assume x y,
  cases x,
    dsimp [bnot, band, bor],
    reflexivity,
    -----------
    dsimp [bnot, band, bor],
    reflexivity,
end

example : is_tt tt :=
begin
  dsimp [is_tt],
  constructor,
end

/- ### Chaper 5.4 Relating bool and Prop -/

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


/- ### Chapter 5.3 Proving equations about bool-/

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