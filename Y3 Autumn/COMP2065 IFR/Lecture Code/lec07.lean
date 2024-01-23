/-
lec07: 
-/

variables P Q R : Prop 
variables A B C : Type
variables PP QQ : A → Prop 
variables RR : A → A → Prop 

-- example : (∀ x:A, PP x) ∨ (∀ x:A, QQ x) → (∀ x:A, PP x ∨ QQ x) :=
-- begin
--   assume ppqq,

-- end

/-
to prove `∃ x:A, PP x`
we say `existsi a`, where a : A, 
and we have to prove `PP a`

to use condition `∃ x:A, PP x`, we say
cases h with a ppa,
and we have two assumptions
since `∃ x:A, PP x = ∃ x:A ∧ PP x`
-/

example : (∃ x:A, PP x) → (∀ x:A, PP x → QQ x) → (∃ x:A, QQ x) :=
begin
  assume pp ppqq,
  cases pp with a pa,
  existsi a,
  apply ppqq,
  assumption,
end

example : (∃ x:A, PP x ∨ QQ x) ↔ (∃ x:A, PP x) ∨ (∃ x:A, QQ x) :=
begin
  constructor,
    assume ppqq,
    cases ppqq with a ppaqqa,
      cases ppaqqa with ppa qqa,
      left,
      existsi a,
      assumption,
      ------------------
      right,
      existsi a,
      assumption,
    ------------------
    assume ppqq,
    cases ppqq with pp qq,
      cases pp with a ppa,
      existsi a,
      left,
      assumption,
      --------------------
      cases qq with a qqa,
      existsi a,
      right,
      assumption,
end

/-
**Curry theorem**
`P ∧ Q → R ↔ P → Q → R`

**Another version**
`(∃ x:A, QQ x) → R ↔ (∀ x:A, QQ x → R)`
-/

example : (∃ x:A, QQ x) → R ↔ (∀ x:A, QQ x → R) :=
begin
  constructor,
    assume qqr a qqa,
    apply qqr,
    existsi a,
    assumption,
    -----------------
    assume qqr qq,
    cases qq with a qqa,
    have qqar : QQ a → R,
      apply qqr,
    apply qqar,
    assumption,
end



/-
`= : A → A → Prop `
**how to prove an equality**
we can prove a = a using *reflexivity*

**how to use an assumed equality**
if we know a = b and we have to prove PP a,
we can use rewrite
if we know a = b and we have to prove PP b,
we can use rewrite← 
-/

-- equality is reflexive
example : ∀ x : A, x = x :=
begin
  assume a,
  reflexivity,
end

example : ∀ x y : A, x = y → PP y → PP x :=
begin
  assume a b,
  assume ab ppb,
  rewrite ab,
  assumption,
end  

example : ∀ x y : A, x = y → PP x → PP y :=
begin
  assume a b,
  assume ab ppa,
  rewrite← ab,
  assumption,
end  

-- equality is symmetric
example : ∀ x y : A, x = y → y = x :=
begin
  assume a b,
  assume ab,
  rewrite ab,   -- automatically applies reflexivity
end

-- equality is transitive
example : ∀ x y z : A, x = y → y = z → x = z :=
begin
  assume a b c,
  assume ab bc,
  rewrite ab,
  assumption,
end

-- since equality is reflexive, symmetric and transitive,
-- it is a equivalence relation

-- built-in tools
example : ∀ x y : A, x = y → y = x :=
begin
  assume a b ab,
  symmetry,
  assumption,
end

-- equality is transitive
example : ∀ x y z : A, x = y → y = z → x = z :=
begin
  assume x y z xy yz,
  transitivity,
  assumption,
  assumption,
end

/- 
### De Morgan's Law
-/

open classical

theorem dm1_pred : ¬ (∃ x:A, PP x) ↔ (∀ x:A, ¬ PP x) :=
begin
  constructor,
    assume npp a ppa,
    apply npp,
    existsi a,
    assumption,
    ---------------
    assume npp pp,
    cases pp with a ppa,
    have nppa : ¬ PP a,
      apply npp,
    apply nppa,
    assumption,
end

theorem raa : ¬ ¬ P → P :=
begin
  assume nnp,
  cases em P with p np,
    assumption,
    ---------------
    have efq : false → P,
      assume f,
      cases f,
    apply efq,
    apply nnp,
    assumption,
end  

theorem dm2_pred : ¬ (∀ x:A, PP x) ↔ (∃ x:A, ¬ PP x) :=
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
    ---------------
    assume npp pp,
    cases npp with a nppa,
    apply nppa,
    apply pp,
end