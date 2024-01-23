-- start your code below!
/-
## Lecture 12: Algebra and Order
-/

-- import tactic   -- need to install mathlib globally
-- leanproject global-install

namespace lec12
set_option pp.structure_projections false
open nat

def exp : ℕ → ℕ → ℕ 
| n zero := 1
| n (succ m) := (exp n m) * n 

local notation (name := exp) m ^ n := exp m n 

-- theorem binom : ∀ x y : ℕ, (x + y)^ 2 = x^2 + 2*x*y + y^2 :=
-- begin
--   assume x y,
--   ring,
-- end

-- #print binom

def le (m n : ℕ) : Prop :=
  ∃ k : ℕ, k + m = n

local notation (name := le) m ≤ n := le m n

example : 2 ≤ 3 :=
begin
  dsimp [(≤), le],
  existsi 1,
  reflexivity,
end

example : ¬ (3 ≤ 2) :=
begin
  assume h,
  dsimp [(≤)] at h,
  cases h with k hh,
  have h2 : k + 2 = 1,
    injection hh,   -- since add k (succ 2) = succ 1
  have h3 : k + 1 = 0,
    injection h2,
  contradiction,    -- 0 is not a succ of any natural number
end

-- Properties of order theory, partial order
 

-- Reflexivity
theorem le_refl: ∀ n : ℕ, n ≤ n :=
begin
  assume n,
  dsimp [(≤)],
  existsi 0,
  -- ring,
  sorry,
end

-- Transitivity
theorem le_trans: ∀ l m n : ℕ,
  l ≤ m → m ≤ n → l ≤ n :=
begin
  dsimp [(≤)],
  assume l m n lm mn,
  cases lm with k h,
  cases mn with k' hh,
  rewrite← hh,
  rewrite← h,
  existsi (k + k'),
  -- ring,
  sorry,
end


-- Anti-symmetric
theorem le_anti_sym : ∀ m n : ℕ, m ≤ n → n ≤ m → m = n :=
begin
  sorry,
end


def lt (m n : ℕ) : Prop := m + 1 ≤ n

local notation (name := lt) x < y := lt x y

/-
not reflexive, transitive, not anti-symmetric
∀ n : ℕ, ¬ (n < n)
∀ l m n : ℕ, l < m → m < n → l < n
∀ m n : ℕ, m < n → n < m → false

< is well founded, since it goes back to the base case `zero`

a relation which is transitive and well founded is called good order
-/

-- trichotomy
theorem trich : ∀ m n : ℕ, m < n ∨ m = n ∨ n < m :=
begin
  sorry,
end 






end lec12