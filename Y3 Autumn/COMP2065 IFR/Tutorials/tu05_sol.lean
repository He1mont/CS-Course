/-
COMP2065 Tutorial 5
-/

set_option pp.structure_projections false

namespace naturals

open nat

/-
inductive nat : Type
| zero : nat
| succ : nat → nat
-/

def add : ℕ → ℕ → ℕ 
| n zero     := n
| n (succ m) := succ (add n m)

local notation m ` + ` n := add m n
-- If you have newer Lean version use:
-- local notation (name := add) m ` + ` n := add m n

theorem add_rneutr : ∀ n : ℕ, n + 0 = n := sorry
theorem add_lneutr : ∀ n : ℕ, 0 + n  = n := sorry
theorem add_assoc : ∀ l m n : ℕ , (l + m) + n = l + (m + n) := sorry
theorem add_succ_lem : ∀ m n : ℕ, (succ m) + n = succ (m + n) := sorry 
theorem add_comm : ∀ m n : ℕ , m + n = n + m := sorry

------------------------------------------------------------
-- PART I: Basic Concepts

-- zero ≠ succ n 
-- We can use `contradiction` when we have an assumption
-- of the form `0 = succ n`
theorem neq : ∀ n : ℕ, zero ≠ succ n :=
begin
  assume n,
  assume eq,
  contradiction,
end  

-- In general, a function f is injective if
-- (f(x) = f(y)) → (x = y)
-- Injectivity of succ
-- (succ m = succ n) → (m = n)

-- When we want to prove `m = n` and we have 
-- `eq : succ m = succ n`, we can use `injection eq`
theorem inj_succ : ∀ m n : ℕ, succ m = succ n → m = n :=
begin
  assume m n,
  assume eq,
  injection eq,
end   

-- Congruence of equality
-- If two terms are equal, they remain equal after the 
-- same function is applied to both, i.e. 
-- If f : A → B and x, y : A, (x = y) → (f(x) = f(y))

-- When we want to prove `succ m = succ n` and we have `m = n`,
-- we can `apply congr_arg`
theorem congr_succ : ∀ m n : ℕ, m = n → succ m = succ n :=
begin
  assume m n,
  assume eq,
  apply congr_arg succ,
  exact eq,
end

theorem congr_add : ∀ l m n : ℕ, m = n → (l + m = l + n) :=
begin
  assume l m n,
  assume eq,
  apply congr_arg (λ x, l + x),
  exact eq,
end

-- Passing arguments 
-- To apply or rewrite `thm : ∀ (a b : A), R a b` on the specific
-- arguments `p` and `q`, write `apply thm p q` or 
-- `rewrite thm p q`.

-- Note: `_+_` associates to the left!
-- x + y + z means (x + y) + z 

theorem args : ∀ (a b c d : ℕ), (a + b) + c + d = a + (c + b + d) :=
begin
  assume a b c d, -- ((a + b) + c) + d = a + ((c + b) + d)
  rewrite add_assoc a b c, -- (a + (b + c)) + d = a + ((c + b) + d)
  rewrite add_comm b c, -- (a + (c + b)) + d = a + ((c + b) + d)
  rewrite add_assoc a (c+b) d,
end

------------------------------------------------------------
-- PART II: Induction

-- Principle of induction:
-- Assume `P : ℕ → Prop`.
-- To prove `∀ l : ℕ , P l` it is enough to prove
-- `P zero` and `∀ n : ℕ, (P n → P (succ n))`.

-- E.g. `P n = (succ n > n)`.
-- To prove `∀ l : ℕ, P l` i.e. `∀ l : ℕ, succ l > l`,
-- we prove `succ zero > zero` and 
-- `∀ n' : ℕ, (succ n' > n') → (succ (succ n') > succ n')`.

theorem cancel_add_r : ∀ (l m n : ℕ), l + n = m + n → l = m :=
begin
  assume l m n,
  induction n with n' ih,
  dsimp [add],
  assume eq,
  exact eq,
  dsimp [add],
  assume eq,
  apply ih,
  injection eq,
end

-- Doubling

def double : ℕ → ℕ
| zero     := zero
| (succ n) := succ (succ (double n))

--#eval (double 0)
--#eval (double 7)

theorem double_distr_add : ∀ m n : ℕ, 
                           double (m + n) = (double m) + (double n) :=
begin
  assume m n,
  induction n with n' ih,
  dsimp [add, double],
  refl,
  dsimp [add, double],
  apply congr_arg succ,
  apply congr_arg succ,
  exact ih,
end

theorem double_add : ∀ (n : ℕ), double n = n + n :=
begin
  assume n,
  induction n with n' ih,
  dsimp [add, double],
  refl,
  dsimp [double, add],
  apply congr_arg succ,
  rewrite ih,
  rewrite add_succ_lem,
end

theorem double_comm : ∀ (m n : ℕ), double (m + n) = double (n + m) :=
begin
  assume m n,
  rewrite add_comm,
end                   

-- Halving

def half : ℕ → ℕ 
| zero            := zero
| (succ zero)     := zero
| (succ (succ n)) := succ (half n)

--#eval (half 7)
--#eval (half 6)

theorem half_double : ∀ n : ℕ, half (double n) = n :=
begin 
  assume n,
  induction n with n' ih,
  dsimp [double, half],
  refl,
  dsimp [double, half],
  rewrite ih,
end 

theorem half_add : ∀ m n : ℕ, half ((double m) + n) = m + half (n) :=
begin 
  assume m n,
  induction m with m' ih,
  dsimp [double],
  rewrite add_lneutr,
  rewrite add_lneutr,
  dsimp [double],
  rewrite add_succ_lem,
  rewrite add_succ_lem,
  dsimp [half],
  rewrite ih,
  rewrite add_succ_lem,
end

end naturals 