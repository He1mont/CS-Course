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
    dsimp [bnot, band, bor],
    reflexivity,
    -------------
    dsimp [bnot, band, bor],
    reflexivity,
end

example : ¬ ∃ b: bool, b || tt = ff :=
begin
  assume h,
  cases h with b hb,
  cases b,
    dsimp [bor] at hb,
    cases hb,
    ------------
    dsimp [bor] at hb,
    cases hb,
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
    assume h,
    cases b,
      cases h,
      -----------
      constructor,
    ---------------
    assume h,
    rewrite h,
    constructor,
end

variable P : Prop 
example : P ∨ ¬ P := sorry -- can't do it! (plain Lean is intuitionistic)

example : ∀ b : bool, is_tt(b || !b) :=
begin
  assume b,
  cases b,
    dsimp [bnot, bor],
    constructor,
    -------------
    dsimp [bnot, bor],
    constructor,
end


theorem band_sound : ∀ x y : bool, is_tt (x && y) →  is_tt x ∧ is_tt y :=
begin
  assume x y,
  cases x,
    dsimp [band],
    assume f,
    cases f,
    -------------------
    dsimp [band],
    assume h,
    constructor,
      constructor,
      --------------
      assumption,
end 


theorem band_complete : ∀ x y : bool, is_tt x ∧ is_tt y → is_tt (x && y) :=
begin -- Can be done in six lines!
  assume x y h,
  cases h with hx hy,
  cases x,
    cases hx,
    --------------
    dsimp [band],
    assumption,
end 

-- def band : bool → bool → bool 
-- | tt b := b
-- | ff b := ff

-- def band' : bool → bool → bool


-- theorem band'_complete : ∀ x y : bool, is_tt x ∧ is_tt y → is_tt (band' x y) :=
-- begin 
--   sorry,
-- end

/-
  Moral: Lean needs to be able to compute!
-/

theorem and_ok : ∀ x y : bool, is_tt (x && y) ↔ is_tt x ∧ is_tt y :=
begin
  assume x y,
  constructor,
  apply band_sound,
  apply band_complete,
end

def allb (f : bool → bool) : bool := f tt && f ff

theorem allb_sound : ∀ f : bool → bool, 
  is_tt (allb f) →  ∀ b : bool, is_tt(f b) :=
begin 
  sorry,
end 

theorem allb_complete : ∀ f : bool → bool, 
  (∀ b : bool, is_tt(f b)) → is_tt (allb f) :=
begin 
  sorry,
end 

theorem allb_ok : ∀ f : bool → bool, 
  is_tt (allb f) ↔ ∀ b : bool, is_tt(f b) :=
begin
  sorry,
end


end tutorial04