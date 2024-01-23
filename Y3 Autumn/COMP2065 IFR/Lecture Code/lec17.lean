/-
Lecture 17 : rev and map
-/

namespace l17
set_option pp.structure_projections false
variables {A B C : Type}

open nat
def leb : ℕ → ℕ → bool 
| 0 n := tt
| (succ m) 0 := ff
| (succ m) (succ n) := leb m n

lemma Le2leb : ∀ m n : ℕ, m ≤ n → leb m n = tt := sorry
lemma leb2Le : ∀ m n : ℕ, leb m n = tt → m ≤ n := sorry


open list

def ite : bool → A → A → A
| tt a b := a
| ff a b := b

local notation (name := ite) 
  if x then a else b := ite x a b


def insert : ℕ → list ℕ → list ℕ 
| n [] := [ n ]
| n (m :: ns) := 
    if (leb n m) then n :: m :: ns
                 else m :: (insert n ns)

#eval insert 6 [2,3,3,8]


def sort : list ℕ → list ℕ 
| [] := []
| (n :: ns) := insert n (sort ns)

#eval sort [4,3,2,1]


inductive Le_list : ℕ → list ℕ → Prop 
| le_nil : ∀ n : ℕ , Le_list n []
| le_cons : ∀ m n : ℕ, ∀ ms : list ℕ,
    n ≤ m → Le_list n (m :: ms)

inductive Sorted : list ℕ → Prop
| sorted_nil : Sorted []
| sorted_cons : ∀ n : ℕ, ∀ ns : list ℕ, 
    Sorted ns → Le_list n ns → Sorted (n :: ns)

open Le_list Sorted


/-
Insert a ms ns means: 
insert a at any place of ms to obtain ns

The base case is:
insert a at the head of ms to obtain ns

if we wannna prove `Insert 3 [1,1,2,2] [1,1,2,3,2]`
we should trace back to
`Insert 3 [1,2,2] [1,2,3,2]`
`Insert 3 [2,2] [2,3,2]`
`Insert 3 [2] [3,2]`

And by `insert_hd` we know `Insert 3 [2] [3,2]` is Valid
Therefore we stop at the base case

-/

inductive Insert : A → list A → list A → Prop 
| insert_hd : ∀ a : A, ∀ as : list A, 
    Insert a as (a :: as)
| insert_tl : ∀ a b : A, ∀ bs abs : list A, 
    Insert a bs abs → Insert a (b::bs) (b::abs)


/-
Perm as bs basically means bs is one permutation of as
the other way around

`bs'` is `bs` inserted with `a`

If we wanna prove `Perm [1,2,3] [3,2,1]`
we should trace back to 
`Perm [2,3] [3,2]`, `Insert 1 [2,3] [3,2,1]`
`Perm [3] [3]`, `Insert 3 [2] [3,2]`
`Perm [] []`, `Insert 3 [] [3]`

-/

inductive Perm : list A → list A → Prop 
| perm_nil : Perm [] []
| perm_cons : ∀ a : A, ∀ as bs bs' : list A,
    Perm as bs → Insert a bs bs' → Perm (a :: as) bs' 


open Insert Perm

theorem refl_perm : ∀ as : list A, Perm as as :=
begin
  assume as,
  induction as with a as' ih,
    apply perm_nil,
    ------------
    apply perm_cons,
      assumption,
      -------------
      apply insert_hd,
end

lemma perm_sort_lem : ∀ ns : list ℕ, ∀ a : ℕ,
  Insert a ns (insert a ns) :=
begin
  assume ns,
  induction ns with n ns' ih,
    assume a,
    dsimp [insert],
    apply insert_hd,
    -----------
    assume a,
    dsimp [insert],
    cases hh : (leb a n),
      dsimp [ite],
      apply insert_tl,
      apply ih,
      ------------
      dsimp [ite],
      apply insert_hd,
end


theorem perm_sort : ∀ l : list ℕ, Perm l (sort l) :=
begin
  assume l,
  induction l with a as ih,
    dsimp [sort],
    apply perm_nil,
    -----------
    dsimp [sort],
    apply perm_cons,
      assumption,
      ------------
      apply perm_sort_lem,
end




end l17