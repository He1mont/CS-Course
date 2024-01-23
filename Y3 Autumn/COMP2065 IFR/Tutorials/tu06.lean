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


theorem min_assoc : 
  ∀ l m n : ℕ, min (min l m) n = min l (min m n) :=
begin
  assume l,
  induction l with l' ih,
    dsimp [min],
    assume m n,
    refl,
    -------------
    assume m,
    cases m,
      dsimp [min],
      assume n,
      refl,
      ------------
      assume n,
      cases n,
        dsimp [min],
        refl,
        --------------
        dsimp [min],
        apply congr_arg succ,
        apply ih,

/-
如果一开始都assume掉，那么后面的cases m n 会影响ih
但如果放到后面再assume，就不会影响到ih，
因此我们说带有any的ih是stronger的
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
-- local notation m ` + ` n := add m n

-- definition of ≤ 
def le (m n : ℕ) : Prop :=
  ∃ k : ℕ , k + m = n

local notation (name := le) x ` ≤ ` y := le x y
-- If you get an error, replace with:
-- local notation x ` ≤ ` y := le x y

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
  assume h,
  cases h with k kh,
  existsi k,
  dsimp [add] at kh,
  injection kh,
end

lemma add_lem : ∀ x y : ℕ, x + y = y → x = 0 :=
begin
  assume x y,
  induction y with y' ih,
    dsimp [add],
    assume h,
    assumption,
    ------------
    assume h,
    dsimp [add] at h,
    apply ih,
    injection h,
end


lemma le_min_lem : ∀ k m : ℕ, min m (k + m) = m :=
begin
  assume k m,
  induction m with m' ih,
    dsimp [add, min],
    refl,
    ------------
    dsimp [add, min],
    apply congr_arg succ,
    assumption,
end

theorem le_min : ∀ m n : ℕ, m ≤ n → min m n = m :=
begin
  assume m n,
  assume h,
  dsimp [le] at h,
  cases h with k kh,
  rewrite← kh,
  apply le_min_lem,
end

lemma lower_bound_lem : ∀ m n : ℕ, m ≤ n → succ m ≤ succ n :=
begin
  assume m n,
  dsimp [le],
  assume h,
  cases h with k kh,
  existsi k,
  dsimp [add],
  apply congr_arg succ,
  assumption,
end

theorem lower_bound : ∀ m n : ℕ, min m n ≤ m :=
begin
  assume m,
  induction m with m' ih,
    assume n,
    dsimp [min],
    dsimp [le],
    existsi zero,
    dsimp [add],
    refl,
    --------------
    assume n,
    cases n,
      dsimp [min],
      dsimp [le],
      existsi (succ m'),
      dsimp [add],
      refl,
      --------------
      dsimp [min],
      apply lower_bound_lem,
      apply ih,
end

end morenaturals