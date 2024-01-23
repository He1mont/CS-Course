/-
## Lecture 10: Natural Numbers
-/

set_option pp.structure_projections false
open nat

/-
ℕ = {0, 1, 2, ...}
  = {zero, succ zero, succ (succ zero), ...}

inductive ℕ : Type
| zero : ℕ 
| succ : ℕ → ℕ  
-/


-- kinda like true ≠ false
example : ∀ n : ℕ, zero ≠ succ n :=
begin
  assume n h,
  contradiction,
end

/-
-- the reverse version of successor called presuccessor
def pred : nat → nat
| zero := zero
| (succ n) := n
-/

--  #reduce (pred 7)

-- **succ is injective**
example : ∀ m n : ℕ, succ m = succ n → m = n :=
begin
  assume m n h,
  change pred (succ m) = n,
  rewrite h,
  dsimp [pred],
  reflexivity,
end 

example : ∀ m n : ℕ, succ m = succ n → m = n :=
begin
  assume m n h,
  injection h,
end

variable P : ℕ → Prop 

example : P zero → (∀ n : ℕ, P n → P (succ n)) → ∀ i : ℕ, P i :=
begin
  assume p0 pn i,
  induction i with i pi,    -- cases i with k
  assumption,
  apply pn,
  assumption,
end

def double : ℕ → ℕ
| zero := zero 
| (succ m) :=  succ (succ (double m))

#eval (double 3)
#reduce (double 7)

/-
double 3 = double (succ 2) = succ (succ (double 2))
2 * 3 = 2 * (1 + 2) = 1 + 1 + 2 * 2
-/

def half : ℕ → ℕ
| zero := zero 
| (succ zero) := zero
| (succ (succ m)) := succ (half m)

example : ∀ n : ℕ, half (double n) = n :=
begin
  assume n, 
  induction n with k pk,
    dsimp [double, half],
    reflexivity,
    -------------
    dsimp [double],
    dsimp [half],
    rewrite pk,
end
