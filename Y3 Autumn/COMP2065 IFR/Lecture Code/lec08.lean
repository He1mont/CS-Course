/-
Lecture 08: Predicate Logic

-/

set_option pp.structure_projections false

variables P Q R : Prop 
variables A B C : Type
variables PP QQ : A → Prop 
variable RR : A → A → Prop  

/-
A : student,
PP x = x is clever,
R = the lecturer is happy
-/

example : (∃ x:A, PP x) → R ↔ ∀ x:A, PP x → R :=
begin
  constructor,
    assume ppr a ppa,
    apply ppr,
    existsi a,
    assumption,
    ---------------
    assume ppr pp,
    cases pp with a ppa,
    apply ppr,
    apply ppa,
end

/-
Replace R with `false`, we get the De Morgan's Law
¬ (P ∨ Q) ↔ ¬ P ∧ ¬ Q 
-/

example : ¬ (∃ x:A, PP x) ↔ ∀ x:A, ¬ PP x :=
begin
  constructor,
    assume npp a ppa,
    apply npp,
    existsi a,
    assumption,
    ------------------
    assume npp pp,
    cases pp with a ppa,
    apply npp,
    apply ppa,
end

open classical

theorem raa : ¬ ¬ P → P :=
begin
  assume nnp,
  cases em (P) with p np,
    assumption,
    ------------
    have efq : false → P,
      assume f,
      cases f,
    apply efq,
    apply nnp,
    assumption,
end


example : ¬ (∀ x:A, PP x) ↔ ∃ x:A, ¬ PP x :=
begin
  constructor,
    assume npp,
    apply raa,
    assume nnpp,
    apply npp,
    assume a,
    apply raa,
    assume nppa,
    apply nnpp,
    existsi a,
    assumption,
    --------------------
    assume npp pp,
    cases npp with a nppa,
    apply nppa,
    apply pp,
end

/-

bool = { tt, ff }

inductive bool : Type
  | tt: bool
  | ff: bool

-/

variable SS : bool → Prop 

example : (∀ x : bool, SS x) ↔ SS tt ∧ SS ff :=
begin
  constructor,
    assume ss,
    constructor,
      apply ss,
      apply ss,
    --------------
    assume ssss,
    cases ssss with sst ssf,
    assume a,
    cases a,
      assumption,
      assumption,
end







