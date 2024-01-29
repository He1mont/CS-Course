/-
COMP2065-IFR Exercise 05 (100)
(Natural numbers) 

Exercise 05 (Natural numbers)

The goal is to complete the proof that the natural 
numbers with addition and multiplication form a
semiring. I include the proof that addition forms a 
commutative monoid (which we have done in the lecture).

It may be advisable not to prove the theorems in 
the order I list them! Also you will need to prove 
some lemmas (auxilliary theorems).

There are 8 theorems to prove, each counts 12.5 points 
adding up to 100 if you prove them all. Don't use classical 
logic (I don't think it even helps). 

-/

set_option pp.structure_projections false

namespace mult_monoid

open nat

--we have defined +

def add : ℕ → ℕ → ℕ 
| n zero     := n
| n (succ m) := succ (add n m)


local notation (name := add) m + n := add m n
/-
If you get an error update your lean or use:
local notation m + n := add m n 
-/


-- and have shown that it is a commutative monoid

theorem add_rneutr : ∀ n : ℕ, n + 0 = n :=
begin
  assume n,
  refl,
end

theorem add_lneutr : ∀ n : ℕ, 0 + n  = n :=
begin
  assume n,
  induction n with n' ih,
  refl,
  dsimp [(+),add],
  rewrite ih,
end

theorem add_assoc : ∀ l m n : ℕ , (l + m) + n = l + (m + n) :=
begin
  assume l m n,
  induction n with n' ih,
  refl,
  dsimp [(+),add],
  rewrite ih,
end

lemma add_succ_lem : ∀ m n : ℕ, succ m + n = succ (m + n) :=
begin
  assume m n,
  induction n with n' ih,
  refl,
  apply congr_arg succ,
  exact ih,
end

theorem add_comm : ∀ m n : ℕ , m + n = n + m :=
begin
  assume m n,
  induction m with m' ih,
  apply add_lneutr,
  calc 
    succ m' + n = succ (m' + n) : by apply add_succ_lem
    ... = succ (n + m') : by apply congr_arg succ; exact ih
    ... = n + succ m' : by reflexivity,
end

-- now we define multiplication

def mul : ℕ → ℕ → ℕ
| m 0     := 0
| m (succ n) := (mul m n) + m

local notation (name := mul) m * n := mul m n
/-
If you get an error update your lean or use:
local notation m * n := mul m n 
-/

/- --- Do not add/change anything above this line (except the local notation syntax, if necessary) --- -/


-- and your task is to show that it is a commutative semiring, i.e.


-- multiplication forms a monoid
theorem mult_rneutr : ∀ n : ℕ, n * 1 = n :=
begin
  assume n,
  dsimp [(*), mul],
  rewrite add_lneutr,
end

theorem mult_lneutr : ∀ n : ℕ, 1 * n = n :=
begin
  assume n,
  induction n with n' nh,
    dsimp [mul],
    reflexivity,
    --------------
    dsimp [(*), mul],
    rewrite nh,
    dsimp [(+), add],
    reflexivity,
end

theorem mult_zero_l : ∀ n : ℕ , 0 * n = 0 :=
begin
  assume n,
  induction n with n' nh,
    dsimp [(*), mul],
    reflexivity,
    ---------------
    dsimp [(*), mul],
    rewrite nh,
    dsimp [(+), add],
    reflexivity,
end 

theorem mult_zero_r : ∀ n : ℕ , n * 0 = 0 :=
begin
  assume n,
  dsimp [(*), mul],
  reflexivity,
end

theorem mult_distr_l :  ∀ l m n : ℕ , (m + n) * l = m * l + n * l :=
begin
  assume l m n,
  induction l with l' lh,
    dsimp [(*), mul],
    dsimp [(+), add],
    reflexivity,
    ------------
    dsimp [(*), mul],
    rewrite lh,
    rewrite← add_assoc,
    rewrite add_assoc (m*l') (n*l') (m),
    rewrite add_comm (n*l') (m),
    rewrite add_assoc,
    rewrite add_assoc (m) (n*l') (n),
    rewrite← add_assoc,
end

theorem mult_distr_r :  ∀ l m n : ℕ , l * (m + n) = l * m + l * n :=
begin
  assume l m n,
  induction n with n' nh,
    dsimp [add, mul],
    reflexivity,
    -------------
    dsimp [add, mul],
    rewrite← add_assoc,
    rewrite nh,
end

-- distributivity laws
theorem mult_assoc : ∀ l m n : ℕ , (l * m) * n = l * (m * n) :=
begin
  assume l m n,
  induction n with n' nh,
    dsimp [(*), mul],
    reflexivity,
    ----------
    dsimp [(*), mul],
    rewrite nh,
    rewrite← mult_distr_r,
end

-- commutativity
lemma mult_succ : ∀ m n : ℕ, n * m + m = succ n * m :=
begin
  assume m n,
  induction m with m' mh,
    dsimp [add, mul],
    reflexivity,
    ---------------
    dsimp [mul],
    dsimp [add],
    rewrite← mh,
    rewrite add_assoc (n*m') n m',
    rewrite add_comm n m',
    rewrite add_assoc (n*m') m' n,
end

theorem mult_comm :  ∀ m n : ℕ , m * n = n * m :=
begin
  assume m n,
  induction n with n' nh,
    dsimp [mul],
    rewrite mult_zero_l,
    -------------
    dsimp [mul],
    rewrite nh,
    rewrite mult_succ,
end


/- --- Do not add/change anything below this line --- -/
end mult_monoid
