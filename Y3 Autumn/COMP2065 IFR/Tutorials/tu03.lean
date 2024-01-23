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
  := Male x ∧ Parent x y


-- isMarried x = x is a married
def isMarried (x : People) : Prop 
  := ∃ y : People, Married x y

-- isBachelor x = is a bachelor (unmarried male)
def isBachelor (x : People) : Prop 
  := Male x ∧ ¬ isMarried x 

def isBachelor' (x : People) : Prop 
  := Male x ∧ ∀ y, ¬ Married x y  


-- Siblings x y means x and y are Siblings (have the same parents)
def Siblings (x y : People) : Prop 
  := ∃ z : People, Parent z x ∧ Parent z y

-- middleChild x means that x is a middle child
--  (has an older and younger sibling)
def middleChild (x : People) : Prop
  :=  ∃ y z : People, Siblings x y ∧ Siblings x z ∧ Older x y ∧ Older z x

constant UniqueFathers :  sorry 

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
  assume x isB,
  cases isB with isM isUnmarried,
  assumption,
end 

/-
Using a universally quantified statement S = (∀ x: A, P x) involves
instantiating it to a *specific* (a: A). We can `apply` S to get Lean to infer
the particular element of A to instantiate to.
-/
example (S : ∀ x, P x) (a : A) : P a :=
begin
  sorry,
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
  sorry,
end

/-
You can think of the statement (∃ x: A, P x) as a "generalized conjunction"
stating "there is an element a of A, and P a holds". From this point of view
it's unsurprising that to *use* an existential we do the same thing as for
propositional conjunctions and use `cases`:
-/
example : (∃ x : A, P x) → ∃ x : A, true :=
begin
  sorry,
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
    ------------------
    assume isB,
    cases isB with male notmarried,
    constructor,
      assumption,
      ----------------
      assume y married,
      apply notmarried,
      existsi y,
      assumption,
    assume isB',
    cases isB' with male notmarried,
    constructor,
      assumption,
      --------------
      assume married,
      cases married with spouse wedding,
      apply notmarried,
      assumption,
end

lemma forall_commute : (∀ x : A, ∀ y : A, RR x y) 
      ↔ (∀ y : A, ∀ x : A, RR x y) :=
begin
  sorry,
end 
lemma exists_commute : (∃ x : A, ∃ y : A, RR x y) ↔ (∃ y : A, ∃ x : A, RR x y) :=
begin
  sorry,
end 


/- 
## Equality and Rewriting
-/

-- Equality is a predicate on two terms of the same type:

-- Prove equality using refl
lemma reflexivity: ∀ x: A, x = x :=
begin
  assume a,
  reflexivity,
end

-- `rewrite` and `rewrite←` use an equality to change **the goal**
example : ∀ x y z : A, x=y → y=z → x=z :=
begin
  assume x y z xy yz,
  rewrite xy,
  assumption,
end
example : ∀ x y z : A, x=y → y=z → x=z :=
begin
  assume x y z xy yz,
  rewrite← yz,
  assumption,
end

-- `rewrite...at` uses an equality to change **the premises**
example : ∀ x y z : A, x=y → y=z → x=z :=
begin
  assume x y z xy yz,
  rewrite yz at xy,
  assumption,
end

example : ∀ x y z : A, x=y → y=z → x=z :=
begin
  assume x y z xy yz,
  rewrite← xy at yz,
  assumption,
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
begin
  assume x y z nxyxz,
  apply raa,
  assume xyxz,
  apply nxyxz,
    

end
example : ∀ x y z : A, ¬(x=y ∨ x=z) → (x≠y ∧ x≠z) :=
begin
  sorry,
end
example : ∀ x y z : A, ¬(x≠y ∨ x≠z) → (x=y ∧ x=z) :=
begin
  sorry,
end