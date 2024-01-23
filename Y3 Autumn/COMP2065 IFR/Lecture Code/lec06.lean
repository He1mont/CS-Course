/-
## lec06: Predicate Logic

- ℕ : Type
- bool : Type
- A: Type
-/

variables P Q R : Prop

-- Types (Sets)

#check bool -- {tt, ff}
#check ℕ -- {0, 1, 2, ...}
#check list ℕ
#check ℕ → bool

variables A B C : Type

/- Predicats and relations -/

/-
Even : ℕ → Prop
Even 2
Even 3

Prime : ℕ → Prop

### relations: n-ary predicates 
≤ : ℕ → ℕ → Prop

Holds : Program → Prop 

occurs : A → list A → Prop

occurs 1 [1,2,3] is true
occurs 7 [1,2,3] is false

= : A → A → Prop
-- equality, part of predicate logic

-/

variables PP QQ : A → Prop 
variables RR : A → B → Prop 

-- Quantifiers: ∀, ∃ 

-- A = "Students", PP x = "x is clever"
#check ∀ x : A, PP x    -- all students are clever
#check ∃ x : A, PP x    -- there is a clever student

#check ∀ x : A, PP x = ∀ y : A, PP y
#check ∃ x : A, PP x = ∃ y : A, PP y

-- ### how to prove ∀

/-
assume `A` stands for the typs of students in the class
`PP x` means x is clever, and `QQ x` means x is funny
-/

example : P → (P → Q) → Q :=
begin
  assume p pq,
  apply pq,
  assumption,
end

example : (∀ x : A, PP x) → (∀ x : A, PP x → QQ x) → (∀ x : A, QQ x) :=
begin 
  assume pp ppqq,
  assume a,         -- instantiation
  apply ppqq,
  apply pp,         -- generalization
end

example : (∀ x:A, PP x ∧ QQ x) ↔ (∀ x:A, PP x) ∧ (∀ x:A, QQ x ) :=
begin
  constructor,
    assume ppqq,
    constructor,
      assume a,       -- instantiation
      have stone : PP a ∧ QQ a,
        apply ppqq,   -- instantiation
      cases stone with ppa qqa,
      assumption,
      --------------
      assume a,       -- instantiation
      have stone : PP a ∧ QQ a,
        apply ppqq,   -- instantiation
      cases stone with ppa qqa,
      assumption,
    ----------------
    assume ppqq,
    cases ppqq with pp qq,
    assume a,         -- instantiation
    constructor,
      apply pp,
      apply qq,
end




