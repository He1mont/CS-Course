/- COMP2065 Autumn 2023
# Tutorial 4: Booleans

  + Boolean Review & Practice
  + Proving is_tt Stuff
-/

namespace tutorial04

/-
## Boolean Review & Practice
-/
def bnot : bool → bool 
| tt := ff
| ff := tt 

def band : bool → bool → bool 
| tt b := b
| ff b := ff

def bor : bool → bool → bool 
| tt b := tt
| ff b := b


local notation (name := band) x && y := band x y 
local notation (name := bor) x || y := bor x y
/-
If you get an error update your lean or use:
local notation x && y := band x y 
local notation x || y := bor x y
-/

prefix `!`:90 := bnot

example : ∀ x y : bool, ! (x || y) =  !x && !y :=
begin
  assume x y,
  cases x,
  reflexivity,
  reflexivity,
end
example : ∃ b : bool, b && b = b :=
begin
  existsi tt,
  dsimp[(&&)],
  refl,
end

example : ¬ ∃ b: bool, b || tt  = ff :=
begin
  assume h,
  cases h with santa claus,
  cases santa,
  dsimp[bor] at claus,
  contradiction,
  dsimp[bor] at claus,
  contradiction,
end

example : ¬ ∀ x y : bool, x && y = ff :=
begin
  -- counterexample: x=tt y=tt
  assume h,
  have absurd : tt && tt = ff,
  apply h,
  dsimp[band] at absurd,
  contradiction,
end

/- Exercises: -/
example : ¬ ∀ x y z : bool, x && y = !z :=
begin
  sorry,
end
example : ¬ ∃ x y : bool, x = y ∧ x = !y :=
begin
  sorry,
end


/-
## Proving is_tt Stuff
-/

def is_tt : bool → Prop 
| tt := true
| ff := false

example : ∀ b : bool, is_tt b ↔ b = tt :=
begin
  assume b,
  constructor,
  assume is_ttb,
  cases b,
  -- dsimp[is_tt] at is_ttb,
  cases is_ttb,
  refl,
  assume eqtt,
  rewrite eqtt,
  -- dsimp[is_tt],
  constructor,
end

variable P : Prop 
example : P ∨ ¬ P := sorry -- can't do it! (plain Lean is intuitionistic)

example : ∀ b : bool, is_tt(b || !b) :=
begin
  assume b,
  cases b,
  dsimp[bnot,bor,is_tt],
  constructor,
  dsimp[bnot,bor,is_tt],
  constructor,
end



theorem band_sound : ∀ x y : bool,
  is_tt (x && y) →  is_tt x ∧ is_tt y :=
begin
  assume x y,
  cases x,
  assume h,
  dsimp [band,is_tt] at h,
  cases h,
  assume h,
  dsimp [band] at h,
  constructor,
  dsimp [is_tt],
  constructor,
  exact h,
end 


theorem band_complete : ∀ x y : bool, is_tt x ∧ is_tt y → is_tt (x && y) :=
begin -- Can be done in six lines!
  assume x y h,
  cases h with hx hy,
  cases x,
  cases hx,
  exact hy,
end 

-- def band : bool → bool → bool 
-- | tt b := b
-- | ff b := ff

def band' : bool → bool → bool
| tt tt := tt
| _ _ := ff

theorem band'_complete : ∀ x y : bool, is_tt x ∧ is_tt y → is_tt (band' x y) :=
begin -- Takes (slightly) more work
  assume x y h,
  cases h with hx hy,
  cases x,
  cases hx,
  cases y,
  cases hy,
  constructor,
end

/-
  Moral: Lean needs to be able to compute!
-/

theorem and_ok : ∀ x y : bool,
  is_tt (x && y)
  ↔ is_tt x ∧ is_tt y :=
begin
  assume x y,
  constructor,
  apply band_sound,
  apply band_complete,
end

def allb (f : bool → bool) : bool :=
  f tt && f ff

theorem allb_sound : ∀ f : bool → bool, 
  is_tt (allb f) →  ∀ b : bool, is_tt(f b) :=
begin 
  assume f h,
  have applied : is_tt(f tt) ∧ is_tt(f ff),
  apply band_sound,
  exact h,
  cases applied with ttftt ttfff,
  assume b,
  cases b,
  exact ttfff,
  exact ttftt,
end 

theorem allb_complete : ∀ f : bool → bool, 
  (∀ b : bool, is_tt(f b)) → is_tt (allb f) :=
begin -- Can be done in 5 lines!
  assume f h,
  apply band_complete,
  constructor,
  apply h,
  apply h,
end 

theorem allb_ok : ∀ f : bool → bool, 
  is_tt (allb f) ↔ ∀ b : bool, is_tt(f b) :=
begin
  assume f,
  constructor,
  apply allb_sound,
  apply allb_complete,
end


end tutorial04