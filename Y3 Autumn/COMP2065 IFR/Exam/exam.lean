set_option pp.structure_projections false

namespace exam

open nat list classical

variables P Q R : Prop

variable {A : Type}
variables PP QQ : A → Prop

/------------ Booleans --------------/

/-
inductive bool : Type
| ff : bool
| tt : bool=
-/

def band : bool → bool → bool 
| tt b := b
| ff b := ff

def bor : bool → bool → bool 
| tt b := tt
| ff b := b

def bnot : bool → bool
| tt := ff
| ff := tt 
prefix `!`:90 := bnot

def is_tt : bool → Prop 
| tt := true
| ff := false

local notation (name := band) x && y := band x y 
local notation (name := bor) x || y := bor x y

/------------ Natural Numbers --------------/
def add : ℕ → ℕ → ℕ 
| n zero := n
| n (succ m) := succ (add n m)

local notation (name := add) m + n := add m n

def double : ℕ → ℕ
| zero := 0
| (succ n) := succ (succ (double n))

lemma add_succ : ∀ m n : ℕ,
  (succ m) + n = succ (m + n) :=
begin
  assume m n,
  induction n with n' ih,
  dsimp [(+),add],
  reflexivity,
  dsimp [(+),add],
  rewrite ih,
end

/------------ Partial Order --------------/
def le (m n : ℕ) : Prop := ∃ k : ℕ, k + m = n

local notation (name := le) m ≤ n := le m n

def eq_nat: ℕ → ℕ → bool
| zero zero         := tt
| zero (succ n)     := ff
| (succ m) zero     := ff
| (succ m) (succ n) := eq_nat m n

def leb : ℕ → ℕ → bool
| zero n            := tt 
| (succ m) zero     := ff 
| (succ m) (succ n) := leb m n

/------------ List --------------/
def append : list A → list A → list A
| [] bs := bs
| (a :: as) bs := a :: (append as bs)

local notation (name := append) as ++ bs := append as bs
/-
If you get an error, please use this line instead:
local notation as ++ bs := append as bs 
-/

def snoc : list A → A → list A
| [] b        := [b]
| (a :: as) b := a :: snoc as b

def rev : list A → list A 
| []        := []
| (a :: as) := snoc (rev as) a

def revaux : list A → list A → list A 
| [] bs        := bs 
| (a :: as) bs := revaux as (a :: bs)

-- def fastrev : list A → list A
-- | l := revaux l []

def fastrev (l : list A) : list A := revaux l []

def insert : ℕ → list ℕ → list ℕ
| m []        := [m]
| m (n :: ns) := if (leb m n) then m :: (n :: ns)
                              else n :: (insert m ns)

def sort : list ℕ → list ℕ
| []        := []
| (a :: as) := insert a as

inductive Le_list : ℕ → list ℕ → Prop
| le_nil : ∀ m : ℕ, Le_list m []
| le_cons : ∀ m n : ℕ, ∀ ns : list ℕ,
            m ≤ n → Le_list m (n :: ns)

inductive Sorted : list ℕ → Prop 
| sorted_nil : Sorted []
| sorted_cons : ∀ a : ℕ, ∀ as : list ℕ,
                Sorted as → Le_list a as → Sorted (a :: as)

open Le_list Sorted 

inductive Insert : A → list A → list A → Prop 
| ins_hd : ∀ a : A, ∀ as : list A, Insert a as (a :: as)
| ins_tl : ∀ a n : A, ∀ as as' : list A,
           Insert a as as' → Insert a (n :: as) (n :: as')

inductive Perm : list A → list A → Prop 
| perm_nil : Perm [] []
| perm_cons : ∀ n : A, ∀ as bs bs' : list A,
              Perm as bs → Insert n bs bs' → Perm (n :: as) bs'

open Insert Perm

/- --- Do not change or delete anything above this line --- -/

/----------------- Q3 ------------------/

-- Q3 c
def foo : ℕ → ℕ
| zero := 1
| (succ zero) := 0
| (succ (succ n)) := succ (succ (foo n))

-- Q4 b (iv)
example : ∀ l m1 m2 : list A, l ++ m1 = l ++ m2 → m1 = m2 :=
begin
  assume l,
  induction l with a as ih,
    assume m1 m2 h,
    dsimp [(++)] at h,
    exact h,
    ----------
    assume m1 m2 h,
    dsimp [(++)] at h,
    apply ih,
    injection h,
end 

-- Q4 
inductive Tree : Type
| leaf : ℕ → Tree 
| node : Tree → Tree → Tree 

open Tree

def t1 : Tree 
:= node (node (leaf 1) (leaf 2)) (leaf 3)

def tree2list : Tree → list ℕ 
| (leaf n)     := [n]
| (node t1 t2) := tree2list t1 ++ tree2list t2

#eval tree2list t1



/- --- Do not change or delete anything below this line --- -/
end exam