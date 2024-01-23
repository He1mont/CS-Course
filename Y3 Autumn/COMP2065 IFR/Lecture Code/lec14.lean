/-

Lecture 14 : Lists

-/

namespace l14
set_option pp.structure_projections false

#check [1,2,3]
#check [tt, ff]
#check [[0, 1], [2], []]

#check []   -- nil
#check 1 :: [2, 3]  -- cons
#check 1 :: 2 :: 3 :: []

/-
inductive list (A : Type)
| nil : list
| cons : A → list → list

[] := nil
a :: as := cons a as
[1,2,3] := 1 :: 2 :: 3 :: []

inductive ℕ : Type
| zero : ℕ
| succ : ℕ → ℕ 
-/

open list 

variables {A B C : Type}


-- basic contradiction, just like succ n ≠ 0, tt ≠ ff
example : ∀ a : A, ∀ as : list A, a :: as ≠ [] :=
begin
  assume a as h,
  contradiction,
end

-- succ is **injective**
example : ∀ a b : A, ∀ as bs : list A,
  a :: as = b :: bs → a = b ∧ as = bs :=
begin
  assume a b as bs h,
  constructor,
    injection h,
    ----------
    injection h,
end

variables P Q R : Prop 

example : P → Q ∧ R ↔ (P → Q) ∧ (P → R) :=
begin
  constructor,
    assume pqr,
    constructor,
      assume p,
      have qr : Q ∧ R,
        apply pqr,
        assumption,
      cases qr with q r,
      assumption,
      ------------
      assume p,
      have qr : Q ∧ R,
        apply pqr,
        assumption,
      cases qr with q r,
      assumption,
    -------------
    assume pqpr p,
    cases pqpr with pq pr,
    constructor,
      apply pq,
      assumption,
      ------------
      apply pr,
      assumption,
end

/-
Instead of using `injection` tactics, 
we could prove the theorem in a different way. 
Since `P → Q ∧ R ↔ (P → Q) ∧ (P → R)`,
we need to prove both 
- `a :: as = b :: bs → a = b`
- `a :: as = b :: bs → as = bs`,

-/


def tail : list A → list A  
| [] := []
| (a :: as) := as 

example : ∀ a b : A, ∀ as bs : list A,
  a :: as = b :: bs → as = bs :=
begin
  assume a b as bs h,
  change (tail (a :: as) = tail (b :: bs)),
  rewrite h,
end


def head : list A → A 
| [] := sorry
| (a :: as) := a

example : ∀ a b : A, ∀ as bs : list A,
  a :: as = b :: bs → a = b :=
begin
  assume a b as bs h,
  sorry,  -- the technique is not covered in this lecture
end

def append : list A → list A → list A 
| [] bs := bs 
| (a :: as) bs := a :: (append as bs)

local notation (name := cons) as ++ bs := append as bs

#eval [1,2,3] ++ [4,5,6]

def append' : list A → list A → list A 
| as [] := as 
| as (b :: bs) := b :: (append' as bs) 

open nat 

def length : list A → ℕ 
| [] := 0
| (a :: as) := succ (length as)

#eval (length [1,2,3])


example : ∀ as bs : list A,
  length (as ++ bs) = length as + length bs :=
begin
  sorry,
end

theorem lneutr : ∀ as : list A, [] ++ as = as :=
begin
  assume as,
  dsimp [(++)],
  refl,
end

theorem rneutr : ∀ as : list A, as ++ [] = as :=
begin
  assume as,
  induction as with a as' ih,
    dsimp [(++)],
    refl,
    ------------
    dsimp [(++)],
    rewrite ih,
end

-- a :: as' ++ bs ++ cs = (a :: as' ++ bs) ++ cs == (a :: (as' ++ bs)) ++ cs

theorem assoc : ∀ as bs cs : list A,
  (as ++ bs) ++ cs = as ++ (bs ++ cs) :=
begin
  assume as bs cs,
  induction as with a as' ih,
    dsimp [(++)],
    refl,
    ----------
    dsimp [(++)],
    sorry,
end

   




end l14