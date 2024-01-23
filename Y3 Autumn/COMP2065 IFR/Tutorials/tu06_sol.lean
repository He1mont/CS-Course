/-
COMP2065 Tutorial 6
-/

set_option pp.structure_projections false

namespace morenaturals

open nat

------------------------------------------------------------
-- PART I: Minimum

-- definition of minimum
def min : ℕ → ℕ → ℕ 
| 0 n := 0
| (succ n) 0 := 0
| (succ n) (succ m) := succ (min n m)

/-
min 0        0        = 0
min 0        (succ n) = 0
min (succ n) 0        = 0
min (succ n) (succ m) = succ (min n m)
-/

/-
min 3 2 =
min (succ (succ (succ 0))) (succ (succ 0)) =
succ (min (succ (succ 0)) (succ 0)) =
succ (succ (min (succ 0) 0)) =
succ (succ 0) =
2
-/

theorem min_assoc : 
  ∀ l m n : ℕ, min (min l m) n = min l (min m n) :=
begin
  assume l,
  induction l with l' ih,
  assume m n,
  dsimp [min],
  refl,
  assume m n,
  cases m,
  dsimp [min],
  refl,
  dsimp [min],
  cases n,
  dsimp [min],
  refl,
  dsimp [min],
  apply congr_arg succ,
  apply ih,

  /-
  assume l m n,
  induction l with l' ih,
  dsimp [min],
  refl,
  cases m,
  dsimp [min],
  refl,
  dsimp [min],
  cases n,
  dsimp [min],
  refl,
  dsimp [min],
  apply congr_arg succ,
  -/
end

------------------------------------------------------------
-- PART II: Less than or equal to

-- definition of +
def add : ℕ → ℕ → ℕ 
| n zero := n 
| n (succ m) := succ (add n m)

local notation (name := add) m ` + ` n := add m n
-- If you get an error, replace with:
--local notation m ` + ` n := add m n

-- definition of ≤ 
def le (m n : ℕ) : Prop :=
  ∃ k : ℕ , k + m = n

-- e.g. 2 ≤ 8 i.e. le 2 8 because ∃ 6 : ℕ, 6 + 2 = 8  

local notation (name := le) x ` ≤ ` y := le x y
-- If you get an error, replace with:
--local notation x ` ≤ ` y := le x y

/-
-- Properties of + 
lemma add_rneutr : ∀ a : ℕ, a + 0 = a := sorry
lemma add_lneutr : ∀ a : ℕ, 0 + a = a := sorry 
lemma add_assoc : ∀ a b c : ℕ, (a + b) + c = a + (b + c) := sorry
lemma add_comm : ∀ a b : ℕ , a + b = b + a := sorry
-/

theorem le_cancel_succ : ∀ m n : ℕ, succ m ≤ succ n → m ≤ n :=
begin
  assume m n,
  dsimp [le],
  assume ex,
  cases ex with k pfk,
  existsi k,
  dsimp [add] at pfk,
  injection pfk,
end

lemma add_lem : ∀ x y : ℕ, x + y = y → x = 0 :=
begin
  assume x y,
  induction y with y' ih,
  assume eq,
  dsimp [add] at eq,
  exact eq,
  assume eq,
  dsimp [add] at eq,
  apply ih,
  injection eq,
end

lemma le_min_lem : ∀ k m : ℕ, min m (k + m) = m :=
begin
  assume k m,
  induction m with m' ih,
  dsimp [add, min],
  refl,
  dsimp [add, min],
  apply congr_arg succ,
  exact ih,
end

theorem le_min : ∀ m n : ℕ, m ≤ n → min m n = m :=
begin
  assume m n,
  assume l,
  dsimp [le] at l,
  cases l with k eqk,
  rewrite← eqk,
  apply le_min_lem,
end

theorem lower_bound : ∀ m n : ℕ, min m n ≤ m :=
begin
  assume m,
  induction m with m' ih,
  assume n,
  dsimp [min],
  dsimp [le],
  existsi 0,
  dsimp [add],
  refl,
  assume n,
  cases n,
  dsimp [min],
  dsimp [le],
  existsi (succ m'),
  dsimp [add],
  refl,
  dsimp [min],
  dsimp [le] at ih,
  dsimp [le, add],
  have h : ∃ (k : ℕ), k + min m' n = m',
  apply ih,
  cases h with k eqk,
  existsi k,
  rewrite eqk,
end

end morenaturals