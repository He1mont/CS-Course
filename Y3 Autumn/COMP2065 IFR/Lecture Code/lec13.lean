namespace l13
set_option pp.structure_projections false
open nat

-- equality on natural numbers is decidable

def Eq_nat (m n : ℕ) : Prop := m = n  

def eq_nat : ℕ → ℕ → bool 
| zero zero := tt 
| (succ m) zero := ff
| zero (succ n) := ff
| (succ m) (succ n) := eq_nat m n 

-- show that `eq_nat` returns `tt` for equal numbers
lemma eq_nat_ok_1 : ∀ n : ℕ, eq_nat n n = tt :=
begin
  assume n,
  induction n with n' ih,
    dsimp [eq_nat],
    constructor,
    ---------------
    dsimp [eq_nat],
    assumption,
end 

-- if `eq_nat` returns `tt` then its arguments must be equal

-- Wrong Proof
lemma eq_nat_ok_2' : ∀ m n : ℕ, eq_nat m n = tt → m = n :=
begin
  assume m n h,
  induction m with m' ih,
    cases n with n',
      reflexivity,
      ------------
      dsimp [eq_nat] at h,
      contradiction,
    ---------------
    cases n with n',
      dsimp [eq_nat] at h,
      contradiction,
      -----------
      apply congr_arg succ,
      sorry,
end


lemma eq_nat_ok_2 : ∀ m n : ℕ, eq_nat m n = tt → m = n :=
begin
  assume m,
  induction m with m' ih,
    assume n h,
    cases n with n',
      constructor,
      ------------
      dsimp [eq_nat] at h,
      contradiction,
    -------------
    assume n h,
    cases n with n',
      dsimp [eq_nat] at h,
      contradiction,
      ------------
      apply congr_arg succ,
      dsimp [eq_nat] at h,
      apply ih,
      assumption,
end 

theorem eq_nat_ok : ∀ m n : ℕ, m = n ↔ eq_nat m n = tt :=
begin
  assume m n,
  constructor,
    assume h,
    rewrite h,
    apply eq_nat_ok_1,
    ------------
    apply eq_nat_ok_2,
end

/-
`eq_nat` decides `Eq_nat`, i.e. the equality,
equality on natural numbers is **decidable**

A predicat PP : A → Prop is decidable,
if there is a function p : A → bool s.t. ∀ a : A, PP a ↔ p a = tt

Prime : ℕ → Prop is decidable
≤ : ℕ → ℕ → Prop is decidable


Halt :Program → Prop
Halt p = program will stops


-/

def Tricky (f : ℕ → bool) : Prop :=
  ∀ n : ℕ, f n = tt




end l13