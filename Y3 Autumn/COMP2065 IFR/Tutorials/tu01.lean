/- COMP2065 Autumn 2023
# Tutorial 1: Intro to Lean ─ Propositional Reasoning

## Today:
+ Introductions
+ Lean setups
+ Review of basic proof tactics
+ Do more proofs


## Getting started with Lean

I'll be using Lean 3 in this course; Lean 4 is under active development. Feel free to use it, but note it's not backward-compatible and I
can only help with anything Lean 4-specific if there's spare time.

### Some useful links

+ [Lean community website](https://leanprover-community.github.io)
  -- Good first port of call for info on installation, links to tutorials, documentation...

+ [Lean Zulip](https://leanprover.zulipchat.com)
  -- Great for beginner (and advanced) questions!

+ [Lean - main website](https://leanprover.github.io/)
  -- More focused on Lean 4, but good for learning about the Lean project as a whole

+ [Lean reference manual](https://leanprover.github.io/reference)
  -- A bit older but has lots of good info about features, internals, advanced usage etc.

-/

variables P Q R S T U V W X: Prop

/-
## Quick recap of tactics for propositional reasoning
-/

-- KEY IDEA: A proposition/claim is a **type** of data
    -- Data of type P are **proofs** or **witnesses** to the truth of P
    -- A false proposition is one which doesn't have any data of that type

-- KEY IDEA: Build more complex propositions using **connectives** like ∧, →, and ¬ 

-- KEY IDEA: Lean creates proof "environments" we can interact with using **tactics**

theorem C : (P → Q) → (Q → R) → (P → R) :=
begin
  assume h h1 h2,
  apply h1,
  apply h,
  exact h2,
end

#reduce C


-- `assume` the hypothesis to *prove* an implication.
-- `exact` fulfills a goal

example : P → Q → R → S → T → U → V → W → X → S :=
begin
  assume p q r s t u v w x,
  exact s,
end


-- To *use* an implication, `apply` it.
-- KEY IDEA: Work backwards! Use what you have to make your goals simpler

lemma apply_tactic : (P → Q) → (Q → R) → (R → S) → (S → T) → P → T :=
begin
  assume pq qr rs st p,
  apply st,
  apply rs,
  apply qr,
  apply pq,
  exact p,
end

-- We *construct* a conjunction by giving proofs of each conjunct.
-- KEY IDEA: "Follow your nose" 
  -- sometimes you can construct a proof by just doing the automatic thing, no thought required

lemma constructor_tactic : P → Q → P ∧ Q :=
begin
  assume p q,
  constructor,
  exact p,
  exact q,
end

-- Canonical proofs of disjunctions are constructed in one of two ways. By
-- proving the left disjunct...

lemma left_tactic : P →  P ∨ Q :=
begin
  assume p,
  left,
  exact p,
end

--- ...or the right one.

lemma right_tactic : Q → P ∨ Q :=
begin
  assume q,
  right,
  exact q,
end

-- In fact, `constructor` works more generally for any type with ...
-- "constructors". One important example is `true`

lemma constructor_for_true : true :=
begin
  constructor,
end


-- `cases` splits a conjunction into its conjuncts, ...

lemma and_comm1 : P ∧ Q → Q ∧ P :=
begin
  assume pq,
  cases pq with p q,
  constructor,
  exact q,
  exact p,
end

#check (and_comm P Q)

-- ...splitting a disjunct into its cases, ...

lemma or_comm1 : P ∨ Q → Q ∨ P :=
begin
  assume pq,
  cases pq with p q,
  right,
  exact p,
  left,
  exact q,
end

#check or_comm

-- ...and "eliminating `false` into" any statement at all 
-- (i.e. using ex-falso: the principle that from falsehood, anything follows).

lemma ex_falso : false → P :=
begin
  assume p,
  cases p,
end

-- Negation is defined as "implying false": ¬P is shorthand for P → false
lemma modus_tollens : (P → Q) → ¬Q → ¬P :=
begin
  assume pq nq p,
  apply nq,
  apply pq,
  exact p,
end

-- Bi-implication is the conjunction of two implications: P ↔ Q is shorthand for (P → Q)∧(Q → P)
lemma obvious : P ↔ P :=
begin
  constructor,
  assume p,
  exact p,
  assume p, 
  exact p,
end

-- `have` allows you to set your own goals
example : (P ∨ Q) → ¬ Q → P :=
begin
  assume pq nq,
  cases pq with p q,
  exact p,
  have f : false,
    apply nq,
    exact q,
  cases f,
end

lemma better_obvious : P ↔ P :=
begin
  have id : P → P,
    assume p,
    exact p,
  constructor,
  exact id,
  exact id,
end

/-
## More practice
-/
-- Try these!

example : ¬(P ∨ Q) → ¬ P :=
begin
  assume npq p,
  apply npq,
  left,
  exact p,
end

example : ¬P → (P → Q) :=
begin
  assume np p,
  have f : false,
    apply np,
    exact p,
  cases f,
end

example : P → true :=
begin
  assume p,
  constructor,
end

example : P ∧ (Q ∨ R) ↔ (P ∧ Q) ∨ (P ∧ R) :=
begin
  constructor,
    assume pqr,
    cases pqr with p qr,
    cases qr with q r,
      left,
      constructor,
      exact p,
      exact q,
       -------------------
      right,
      constructor,
      exact p,
      exact r,
    -----------------------
    assume pqpr,
    cases pqpr with pq pr,
      cases pq with p q,
      constructor,
      exact p,
      left,
      exact q,
      ------------------------
      cases pr with p r,
      constructor,
      exact p,
      right,
      exact r,
end

example : ¬¬¬P ↔ ¬P :=
begin
  constructor,
    assume nnnp p,
    apply nnnp,
    assume np,
    apply np,
    exact p,
    ------------
    assume np nnp,
    apply nnp,
    exact np,
end

example : (P → Q) ↔ (P ∧ P → Q) :=
begin
  constructor,
    assume pq pp,
    apply pq,
    cases pp with p p,
    exact p,
    ---------------
    assume ppq p,
    apply ppq,
    constructor,
    exact p,
    exact p,
end