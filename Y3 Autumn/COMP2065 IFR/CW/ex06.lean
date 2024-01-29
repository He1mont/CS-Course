/-
COMP2065-IFR Exercise 06 (100)
(Less or equal (≤)) 

Exercise 06

The goal is to prove some properties of ≤ on the natural numbers:

6a) ≤ is antisymmetric (50%)
6b) ≤ is decidable (50%)

-/
set_option pp.structure_projections false

namespace ex06 
 
open nat

/- from the lecture: 
  defn of + and proof that it is a commutative monoid.
-/

def add : ℕ → ℕ → ℕ 
| n zero := n
| n (succ m) := succ (add n m)

local notation (name := add) m + n := add m n
/-
If you get an error update your lean or use:
local notation m + n := add m n 
-/

theorem lneutr : ∀ n : ℕ, 0 + n = n :=
begin
 assume n,
 induction n with n' ih,
 reflexivity,
 dsimp [(+)],
 rewrite ih,
end

theorem rneutr : ∀ n : ℕ, n + 0 = n :=
begin
  assume n,
  dsimp [(+),add],
  reflexivity
end

theorem assoc : ∀ l m n : ℕ, 
    (l + m) + n = l + (m + n) :=
begin
  assume l m n,
  induction n with n' ih,
  dsimp [(+),add],
  reflexivity,
  dsimp [(+),add],
  rewrite ih,
end   

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

theorem comm : ∀ m n : ℕ , m + n = n + m :=
begin
  assume m n,
  induction n with n' ih,
  dsimp [(+),add],
  rewrite lneutr,
  dsimp [(+),add],
  rewrite add_succ,
  rewrite ih,
end

-- from the lecture : definition of ≤ .

def le(m n : ℕ) : Prop :=
  ∃ k : ℕ , k + m = n

local notation (name := le) x ≤ y := le x y
/-
If you get an error update your lean or use:
local notation x ≤ y := le x y 
-/

-- end of lecture material

/- --- Do not add/change anything above this line (except the `local notation` syntax, if necessary) --- -/


/- 6a) Prove that ≤ is antisymmetric. (50%)
  Hint: it may be a good idea to prove some lemmas.-/

lemma pos_neg : ∀ x y : ℕ, x + y = 0 → (x = 0) ∧ (y = 0) :=
begin
  assume x,
  induction x with x' ih,
    assume y h,
    rewrite lneutr at h,
    constructor,
    refl,
    assumption,
    -----------
    assume y,
    assume h,
    rewrite comm at h,
    dsimp [add] at h,
    contradiction,
end

lemma pos_neg' : ∀ x y : ℕ, x + y = y → x = 0 :=
begin
  assume x y,
  induction y with y' ih,
    assume h,
    rewrite rneutr at h,
    assumption,
    -----------
    assume h,
    apply ih,
    dsimp [add] at h,
    injection h,
end

theorem anti_sym : ∀ x y : ℕ , x ≤ y → y ≤ x → x = y :=
begin
  assume x y,
  dsimp [le],
  assume h1 h2,
  cases h1 with k1 h1',
  cases h2 with k2 h2',
  rewrite← h2' at h1',
  rewrite← assoc at h1',
  have lem : k1 + k2 = 0,
    apply pos_neg',
    assumption,
  have lem' : (k1 = 0) ∧ (k2 = 0),
    apply pos_neg,
    assumption,
  cases lem' with lem1 lem2,
  rewrite lem2 at h2',
  rewrite lneutr at h2',
  rewrite h2',
end


/-
6b) Show that ≤ is decidable, by defining a function returning 
a boolean (10%).

You should define leb in such a way that you can prove
  ∀ m n : ℕ, m ≤ n ↔ leb m n = tt
-/

def leb : ℕ → ℕ → bool
| zero n := tt 
| (succ m) zero := ff
| (succ m) (succ n) := leb m n 


/- Now, show that leb computes ≤, i.e. that
 your definition of leb satisfies its specification. (40%) -/


lemma lem1: ∀ m n : ℕ, m ≤ n → leb m n = tt :=
begin
  assume m,
  induction m with m' ih,
    assume n h,
    dsimp [leb],
    refl,
    --------
    assume n h,
    cases n,
    cases h with k h',
    contradiction,
    dsimp [le, add] at h,
    cases h with k h',
    dsimp [leb],
    apply ih,
    dsimp [le],
    existsi k,
    injection h',
end

lemma lem2: ∀ m n : ℕ, leb m n = tt → m ≤ n :=
begin
  assume m,
  induction m with m' ih,
    assume n h,
    dsimp [le],
    existsi n,
    dsimp [add],
    refl,
    ---------
    assume n h,
    cases n,
    dsimp [leb] at h,
    contradiction,
    dsimp [leb] at h,
    have mn : m' ≤ n,
      apply ih,
      exact h,
    cases mn with k mn',
    dsimp [le, add],
    existsi k,
    apply congr_arg succ,
    exact mn',
end

theorem leb_ok : ∀ m n : ℕ, m ≤ n ↔ leb m n = tt :=
begin
  assume m n,
  constructor,
  apply lem1,
  apply lem2,
end


/- --- Do not add/change anything below this line --- -/
end ex06