/-
## Lecture 11: Natural Numbers
-/

namespace lec11
set_option pp.structure_projections false
open nat


/-
def add(n, (m + 1)):
  if m+1 == 0:
    return n
  else
    return 1 + add(n, m)
-/

/- 2 + 3 = 1 + (2 + 2) -/
def add : ℕ → ℕ → ℕ
| n zero := n
| n (succ m) := succ (add n m)

local notation (name := add) m + n := add m n 

#eval 3 + 5
#eval 2 + 100


/- 3 * 5 = 3 + (3 * 4) -/
def mult : ℕ → ℕ → ℕ
| n zero := zero 
| n (succ m) := add n (mult n m)

local notation (name := mult) m * n := mult m n 

theorem lneutr : ∀ n : ℕ, 0 + n = n := 
begin
  assume n,
  induction n with n' nh,
    dsimp [add],
    reflexivity,
    ------------
    dsimp [add],
    rewrite nh,
end 

theorem rneutr : ∀ n : ℕ, n + 0 = n := 
begin
  assume n,
  dsimp [add],
  reflexivity,
end 

theorem assoc : ∀ l m n : ℕ, (l + m) + n = l + (m + n) :=
begin
  assume l m n,
  induction n with n' nh,
    dsimp [add],
    reflexivity,
    ----------------
    dsimp [add],
    rewrite nh,
end

lemma add_succ : ∀ m n : ℕ,
  (succ m) + n = succ (m + n) :=
begin
  assume m n,
  induction n with n' nh,
  dsimp [(+),add],
  reflexivity,
  ----------------
  dsimp [(+),add],
  rewrite nh,
end

theorem comm : ∀ m n : ℕ , m + n = n + m :=
begin
  assume m n,
  induction n with n' nh,
    dsimp [(+),add],
    rewrite lneutr,
    ----------------
    dsimp [(+),add],
    rewrite add_succ,
    rewrite nh,
end

end lec11