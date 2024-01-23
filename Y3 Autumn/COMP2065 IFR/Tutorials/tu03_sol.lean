/- COMP2065 Autumn 2023
# Tutorial 3: Predicate Logic 

+ Making definitions
  + Family properties
+ Proving with quantifiers
+ Equality and rewriting
-/

/- 
## Family properties
-/

constant People : Type
constants Male Female : People → Prop
-- Male x means x is male
-- Female x means x is fmeale
constant Parent : People → People → Prop
-- Parent x y means x is a parent of y
constant Married : People → People → Prop
-- Married x y means x is married to y
constant Older : People → People → Prop
-- Older x y means x is older than y


-- Father x y means x is the father of y -/
def Father (x y : People) : Prop
  := Parent x y ∧ Male x


-- isMarried x = x is a married
def isMarried (x : People) : Prop 
  := ∃ y : People, Married x y

-- isBachelor x = is a bachelor (unmarried male)
def isBachelor (x : People) : Prop 
  := Male x ∧ ¬ ∃ y : People, Married x y
def isBachelor' (x : People) : Prop 
  := Male x ∧  ∀ y : People, ¬ Married x y


-- Siblings x y means x and y are Siblings (have the same parents)
def Siblings (x y : People) : Prop 
  := sorry -- exercise!

-- middleChild x means that x is a middle child
--  (has an older and younger sibling)
def middleChild (x : People) : Prop
  :=  (∃ y : People, Siblings x y ∧ Older x y)
    ∧ (∃ z : People, Siblings x z ∧ Older z x)

constant UniqueFathers :  
   ∀ x : People, ∃ p : People, Father p x ∧ 
     (∀ p' : People, Father p' x → p' = p ) 

/- 
## Quantifiers
-/

variables A B C : Type
variables P Q : A → Prop
variable RR : A → A → Prop 
variables R : Prop

-- ### Universals

-- To *prove* a universally-quantified statement,
-- `assume` a fixed but arbitrary fresh variable.

-- all bachelors are unmarried
example : ∀ x : People, isBachelor x → ¬(isMarried x) :=
begin 
  assume x hh,
  cases hh with h₀ h₁,
  exact h₁,
end 

/-
Using a universally quantified statement S = (∀ x: A, P x) involves
instantiating it to a *specific* (a: A). We can `apply` S to get Lean to infer
the particular element of A to instantiate to.
-/
example (S : ∀ x, P x) (a : A) : P a :=
begin
  apply S,
end


-- ### Existentials

/-
*Proving* an existential statement (∃ x: A, P x) involves two steps:
  1. Exhibiting a specific a: A, and
  2. Showing that P holds for that specific a.
In Lean, use `existsi a` to do Step 1. You'll then get a new goal
  ... ⊢ P a
corresponding to Step 2.
-/
example (a : A) (Pa : P a) : ∃ x, P x :=
begin
  existsi a,
  exact Pa,
end

/-
You can think of the statement (∃ x: A, P x) as a "generalized conjunction"
stating "there is an element a of A, and P a holds". From this point of view
it's unsurprising that to *use* an existential we do the same thing as for
propositional conjunctions and use `cases`:
-/
example : (∃ x : A, P x) → ∃ x : A, true :=
begin
  assume h,
  cases h with x px,
  existsi x,
  constructor,
end


-- ### Exercises with quantifiers

-- def isBachelor (x : People) : Prop 
--   := Male x ∧ ¬ ∃ y : People, Married x y
-- def isBachelor' (x : People) : Prop 
--   := Male x ∧  ∀ y : People, ¬ Married x y
example : ∀ x : People, isBachelor x ↔ isBachelor' x :=
begin
  assume x,
  constructor,
  assume isB,
  cases isB with isM noSpouse,
  constructor,
  exact isM,
  assume spouse wedding,
  apply noSpouse,
  existsi spouse,
  exact wedding,
  assume isB',
  cases isB' with isM nobodyMarried,
  constructor,
  exact isM,
  assume existsSpouse,
  cases existsSpouse with spouse wedding,
  apply nobodyMarried,
  exact wedding,
end

lemma forall_commute : (∀ x : A, ∀ y : A, RR x y) 
      ↔ (∀ y : A, ∀ x : A, RR x y) :=
begin
  constructor,
  assume h y x,
  apply h,
  assume h x y,
  apply h,
end 
lemma exists_commute : (∃ x : A, ∃ y : A, RR x y) ↔ (∃ y : A, ∃ x : A, RR x y) :=
begin
  constructor,
  assume h,
  cases h with x yr,
  cases yr with y r,
  existsi y,
  existsi x,
  exact r,
  assume h,
  cases h with y xr,
  cases xr with x r,
  existsi x,
  existsi y,
  exact r,
end 


/- 
## Equality and Rewriting
-/

-- Equality is a predicate on two terms of the same type:

-- Prove equality using refl
lemma reflexivity: ∀ x: A, x = x :=
begin
  assume x,
  refl,
end

-- `rewrite` and `rewrite←` use an equality to change **the goal**
example : ∀ x y z : A, x=y → y=z → x=z :=
begin
  assume x y z xy yz,
  rewrite xy,
  exact yz,
end
example : ∀ x y z : A, x=y → y=z → x=z :=
begin
  assume x y z xy yz,
  rewrite← yz,
  exact xy,
end

-- `rewrite...at` uses an equality to change **the premises**
example : ∀ x y z : A, x=y → y=z → x=z :=
begin
  assume x y z xy yz,
  rewrite yz at xy,
  exact xy,
end
example : ∀ x y z : A, x=y → y=z → x=z :=
begin
  assume x y z xy yz,
  rewrite← xy at yz,
  exact yz,
end


open classical
lemma raa : ¬¬R → R :=
begin
  assume nnr,
  cases (em R) with r nr,
  exact r,
  have f : false,
  apply nnr,
  exact nr,
  cases f,
end 

-- Which of these is intuitionistically provable?
example : ∀ x y z : A, ¬(x=y ∧ x=z) → (x≠y ∨ x≠z) :=
-- NOT this one!
begin
    assume x y z h,
    cases em (x=y) with xy nxy,
    -----------
      right,
      assume xz,
      apply h,
      constructor,
      exact xy,
      exact xz,
    -----------
      left,
      exact nxy,
end
example : ∀ x y z : A, ¬(x=y ∨ x=z) → (x≠y ∧ x≠z) :=
-- THIS ONE!
begin
  assume x y z h,
  constructor,
  -------------
    assume xy,
    apply h,
    left,
    exact xy,
  -------------
    assume xz,
    apply h,
    right,
    exact xz,
end
example : ∀ x y z : A, ¬(x≠y ∨ x≠z) → (x=y ∧ x=z) :=
-- NOT this one!
begin
  assume x y z h,
  constructor,
  ------------
    apply raa,
    assume nxy,
    apply h,
    left,
    exact nxy,
  ------------
    apply raa,
    assume nxz,
    apply h,
    right,
    exact nxz,
end