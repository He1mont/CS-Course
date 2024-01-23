/-
lec16: rev and map
-/

namespace l16
set_option pp.structure_projections false
variables {A B C : Type}



def snoc : list A → A → list A
| []  a := [a]
| (a :: as) b := a :: (snoc as b)

#eval (snoc [3,2] 1)

def rev : list A → list A
| [] := []
| (a :: as) := snoc (rev as) a

def map_list : (A → B) → list A → list B 
| f [] := []
| f (a :: as) := f a :: map_list f as

theorem nat_rev : ∀ f : A → B, ∀ l : list A,
  map_list f (rev l) = rev (map_list f l) :=
begin
  assume f l,
  induction l with a as ih,
    dsimp [map_list, rev],
    refl,
    ---------
    sorry,
end

open nat 

def leb : ℕ → ℕ → bool
| 0 n := tt 
| (succ m) 0 := ff 
| (succ m) (succ n) := leb m n 


lemma Le2leb : ∀ m n : ℕ, m ≤ n → leb m n = tt := sorry
lemma leb2Le : ∀ m n : ℕ, leb m n = tt → m ≤ n := sorry
lemma leb_inverse : ∀ m n : ℕ, leb m n = ff → leb n m = tt := sorry

/-
sort : list ℕ → list ℕ 

sort [5,4,3,2,1] = [1,2,3,4,5]
-/

open list

def ite : bool → A → A → A 
| tt a b := a 
| ff a b := b

local notation (name := ite) 
  if x then a else b := ite x a b

def insert : ℕ → list ℕ → list ℕ
| n [] := [n]
| n (m :: ns) :=
  if (leb n m) then n :: (m :: ns)
               else m :: (insert n ns)

#eval insert 6 [2,3,4,8]

def sort : list ℕ → list ℕ 
| [] := []
| (n :: ns) := insert n (sort ns)

#eval sort [6,4,3,2,1]

-- we wanna prove that sort sorts, 
-- what do we mean by sorting? 
-- sorted: list ℕ → Prop

inductive Le_list : ℕ → list ℕ → Prop 
| le_nil : ∀ n : ℕ , Le_list n []
| le_cons : ∀ m n : ℕ, ∀ ms : list ℕ,
  n ≤ m → Le_list n (m :: ms)

#check Le_list 3 [6,8]
#check Le_list 10 [6,8]


lemma le_cons_inv : ∀ m n : ℕ, ∀ ns : list ℕ,
  Le_list m (n :: ns) → m ≤ n :=
begin
  assume m n ns h,
  cases h with _ _ _ _ mn,
  exact mn
end


inductive Sorted : list ℕ → Prop 
| sorted_nil : Sorted [] 
| sorted_cons : ∀ n : ℕ, ∀ ns : list ℕ,
    Sorted ns → Le_list n ns → Sorted (n :: ns)  

open Le_list Sorted


lemma sorted_sgl : ∀ n : ℕ, Sorted [n] :=
begin
  assume n,
  apply sorted_cons,
    apply sorted_nil,
    ---------
    apply le_nil,
end

lemma insert_lem_le_list : ∀ m n : ℕ, ∀ ns : list ℕ, 
  n ≤ m → Le_list n ns → Le_list n (insert m ns) :=
begin
  assume m n ns h1 h2,
  cases ns with hd tl,
    dsimp [insert],
    apply le_cons,
    assumption,
    ----------
    dsimp [insert],
    cases hh: (leb m hd),
      dsimp [ite],
      apply le_cons,
      cases h2 with _ _ _ _ nhd,
      assumption,
      ----------
      dsimp [ite],
      apply le_cons,
      assumption,
end

lemma insert_lem : ∀ ns : list ℕ, ∀ n : ℕ,
  Sorted ns → Sorted (insert n ns) :=
begin
  assume ns,
  induction ns with n' ns' ih,
    assume n h,
    dsimp [insert],
    apply sorted_sgl,
    -----------
    assume n h,
    dsimp [insert],
    cases hh : (leb n n'),
      dsimp [ite],
      apply sorted_cons,
        apply ih,
        cases h with _ _ h1 h2,
        assumption,
        ----------
        apply insert_lem_le_list,
          apply leb2Le,
          apply leb_inverse,
          assumption,
          --------
          cases h with _ _ h1 h2,
          assumption,
      --------
      dsimp [ite],
      apply sorted_cons,
        assumption,
        ----------
        apply le_cons,
        apply leb2Le,
        assumption,
end


theorem sort_sorts : ∀ ns : list ℕ, Sorted (sort ns) :=
begin
  assume ns,
  induction ns with n ns' ih,
    dsimp [sort],
    apply sorted_nil,
    --------
    dsimp [sort],
    apply insert_lem,
    assumption,
end
    




end l16