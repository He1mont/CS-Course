/-
lec02: Propositional logic in lean
  from chapter 1.1-2.3

What is a proposition?
- classical interpretation
- evidence view (intuitionistic)
- tautology: a proposition that is always True

-/

-- how to declare propositional variables
variables P Q R : Prop 

-- connectives
#check P → Q
#check P → Q → R    -- right associative
#check P ∧ Q
#check P ∧ Q → R
#check P ∨ Q
#check ¬ P 
#check P ↔ Q
#check true
#check false

/--------------Chapter 2-------------------/

-- first tautology
theorem I : P → P := 
begin
  assume h, 
  exact h,
end 

-- a more complicated tautology
-- there are three assumptions
theorem C : (P → Q) → (Q → R) → (P → R) :=
begin
  assume pq,
  assume qr,
  assume p,
  apply qr,
  apply pq,
  exact p,
end
