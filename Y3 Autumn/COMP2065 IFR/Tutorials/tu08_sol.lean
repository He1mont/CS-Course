/-
COMP2065 Tutorial 8
-/

namespace predicates

open nat list
set_option pp.structure_projections false
variables {A B C : Type}

------------------------------------------------------------
-- Part I: Inductive predicates

-- `Insert a as bs` means `bs` can be obtained from `as` by
-- inserting `a` somewhere
inductive Insert : A → list A → list A → Prop
| ins_hd : ∀ a : A, ∀ as : list A, Insert a as (a :: as)
| ins_tl : ∀ a b : A, ∀ as as': list A, Insert a as as' → 
           Insert a (b :: as) (b :: as')

open Insert

--#check Insert 4 [2, 8, 0] [2, 8, 4, 0] -- provable
--#check Insert 0 [2,3] [2,3,4]          -- its negation is provable

-- `Perm as bs` means `as` is a permutation of `bs`
inductive Perm : list A → list A → Prop 
| perm_nil : Perm [] []
| perm_cons : ∀ a : A, ∀ as bs bs' : list A, Perm as bs → 
              Insert a bs bs' → Perm (a :: as) bs'

open Perm

example : Insert 'x' ['y', 'z'] ['x', 'y', 'z'] :=
begin
  apply ins_hd 'x' ['y', 'z'],
end

example : Insert 4 [2, 8, 0] [2, 8, 4, 0] :=
begin
  apply ins_tl,
  apply ins_tl,
  apply ins_hd,
end

example : Perm [3, 9, 1] [9, 1, 3] :=
begin
  apply perm_cons 3 [9, 1] [9,1] [9, 1, 3],
  apply perm_cons 9 [1] [1] [9, 1],
  apply perm_cons 1 [] [] [1],
  apply perm_nil,
  apply ins_hd,
  apply ins_hd,
  apply ins_tl,
  apply ins_tl,
  apply ins_hd,
end

theorem cons_perm : ∀ as bs : list A, ∀ a : A, 
                    Perm as bs → Perm (a :: as) (a :: bs) :=
begin
  assume as bs a p,
  apply perm_cons,
  exact p,
  apply ins_hd,
end

theorem self_perm : ∀ l : list A, Perm l l :=
begin
  assume l,
  induction l with a as ih,
  apply perm_nil,
  apply perm_cons,
  exact ih,
  apply ins_hd,
end

------------------------------------------------------------
-- Part II: Sort outputs a permutation of its input

def ite {A : Type} : bool → A → A → A
| tt t e := t
| ff t e := e

--local notation ` if ` b ` then ` t ` else ` e := ite b t e
local notation (name := ite) ` if ` b ` then ` t ` else ` e := ite b t e

def ble : ℕ → ℕ → bool
| 0        n        := tt
| (succ m) 0        := ff
| (succ m) (succ n) := ble m n

def ins : ℕ → list ℕ → list ℕ
| a [] := [a]
| a (b :: bs) := 
    if (ble a b) then (a :: b :: bs) else (b :: (ins a bs))

--#eval ins 9 [4, 8, 12]

def sort : list ℕ → list ℕ
| [] := []
| (a :: as) := ins a (sort as)

--#eval sort [9, 2, 23, 0]

lemma perm_sort_lem : ∀ as : list ℕ, ∀ a : ℕ, Insert a as (ins a as) :=
begin
  assume as,
  induction as with b bs ih,
  assume a,
  dsimp [ins],
  apply ins_hd,
  assume a,
  dsimp [ins],
  cases (ble a b),
  dsimp [ite],
  apply ins_tl,
  apply ih,
  dsimp [ite],
  apply ins_hd,
end

theorem perm_sort : ∀ ns : list ℕ , Perm ns (sort ns) :=
begin
  assume ns,
  induction ns with a as ih,
  dsimp [sort],
  apply perm_nil,
  dsimp [sort],
  apply perm_cons,
  exact ih,
  apply perm_sort_lem,
end

------------------------------------------------------------
-- Part III: Inducting on defined relations

-- Using `cases`

example : Insert 0 [2,3] [2,3,4] → false :=
begin
  assume i,
  cases i with _ _ _ _ _ _ i',
  cases i' with _ _ _ _ _ _ i'',
  cases i'',
end

-- Definition of append 

def my_append : list A → list A → list A
| []       l := l
| (h :: s) t := h :: (my_append s t)

--local notation l₁ ` ++ ` l₂ := my_append l₁ l₂
local notation (name := my_append) l₁ ` ++ ` l₂ := my_append l₁ l₂

-- Using `induction`

theorem perm_append : ∀ l1 l1' l2 l2' : list A, 
  Perm l1 l1' → Perm l2 l2' → Perm (l1 ++ l2) (l1' ++ l2') :=
begin
  assume l1 l1' l2 l2' p1 p2,
  induction p1 with a as bs bs' i p ih,
  dsimp [(++)],
  exact p2,
  dsimp [(++)],
  apply perm_cons,
  exact ih,
  sorry, --challenge!
end

end predicates
