/- COMP2065 Autumn 2023
# Tutorial 2: Propositional logic ─ Constructive and classical reasoning

+ Provable or not?
+ Classical logic principles: excluded middle (`em`), double-negation
  elimination ("DNE"/"RAA")
+ Practice with constructive and classical proofs
-/


variables P Q R : Prop

/-
## Is this provable?

IDEA: Truth table reasoning
-/

example : P → Q :=
begin 
  sorry, -- P=true Q=false
end

-- example : ¬( ? → ? ) :=
-- begin
-- end


example : P → (P → Q) → Q :=
begin 
  assume p pq,
  apply pq,
  assumption,
end 


example : P → (Q → R) → R :=
begin 
  sorry,
end 
example : ¬(true → (false → false) → false) :=
begin
  assume g,
  apply g,
  constructor,
  assume f,
  exact f,
end


/-
    P    |   ¬P    |   P ∨ ¬P 
------------------------------
  true   |  false  |   true  
  false  |  true   |   true
-/
example : P ∨ ¬ P :=
begin
  sorry,
end

/-
  IMPORTANT: Truth table reasoning will only tell you if something
  is provable or not. It WON'T tell you whether it can be proved
  intuitionistically or if classical reasoning is required
-/

/-
## Classical Reasoning
-/
open classical



-- Excluded middle: for any proposition P, (P ∨ ¬P).
#check em (P ∨ Q → R)

theorem em_to_raa : (P ∨ ¬ P) →  ¬¬P → P :=
begin
  assume pnp nnp,
  cases pnp with p np,
    assumption,
    ------------------
    have efq : false → P,
      assume f,
      cases f,
    apply efq,
    apply nnp,
    assumption, 
end
-- Notice: This proof doesn't use any classical reasoning itself

-- This one does though
theorem raa : ¬¬P → P :=
begin 
  assume nnp,
  cases em P with p np,
    assumption,
    ------------
    have efq : false → P,
      assume f,
      cases f,
    apply efq,
    apply nnp,
    assumption,
end

/-
  KEY IDEA: A theorem is intuitionistically/constructively provable
  if we're not "getting information from nowhere"

  ¬ P ∨ ¬ Q → ¬ (P ∧ Q) -- Intuitionistic 
  ¬ (P ∧ Q) → ¬ P ∨ ¬ Q -- Classical

  Intuitionistic logic (the "BHK Interpretation")
  - Proof of P ∧ Q : 
      a proof of P and a proof of Q
  - Proof of P ∨ Q : 
      one bit of info (left or right), and a proof of that side
  - Proof of P → Q : 
      an algorithm that turns proofs of P into proofs of Q
  - Proof of ¬ P : 
      an algorithm that turns proofs of P into proofs of absurdity
-/

-- Provable intuitionistically ?or? Requires classical logic
theorem example0 : ¬ P ∨ ¬ Q → ¬ (P ∧ Q) :=
begin 
  assume npnq pq,
  cases pq with p q,
  cases npnq with np nq,
    apply np,
    assumption,
    --------------------
    apply nq,
    assumption,
end 

-- Provable intuitionistically ?or? Requires classical logic
theorem example1 : ¬ (P ∧ Q) → ¬ P ∨ ¬ Q :=
begin 
  assume npq,
  cases em P with p np,
    right,
    assume q,
    apply npq,
    constructor,
    assumption,
    assumption,
    ------------------
    left,
    assumption,
end 

/- How classification will be formatted on the exercises: -/
inductive PokerAnswer : Type
| UNANSWERED : PokerAnswer 
| NotProvable : PokerAnswer
| Intuition : PokerAnswer
| Classical : PokerAnswer
open PokerAnswer

def answer0 : PokerAnswer := UNANSWERED
def answer1 : PokerAnswer := UNANSWERED


/- ## Try it yourself! -/

def answer2 : PokerAnswer := Intuition
theorem example2 : ¬(P ∧ ¬P) :=
begin
  assume pnp,
  cases pnp with p np,
  apply np,
  assumption,
end

def answer3 : PokerAnswer := NotProvable
theorem example3 : (¬ P → P) → ¬P :=
begin
  sorry,
end 

def answer4 : PokerAnswer := Classical
theorem example4 : (¬ P → P) → P :=
begin
  assume npp,
  cases em P with p np,
    assumption,
    --------------
    apply npp,
    assumption,
end 

def answer5 : PokerAnswer := Intuition
theorem example5 : (P → Q) → ¬ Q → ¬ P :=
begin
  assume pq nq p,
  apply nq,
  apply pq,
  assumption,
end 

def answer6 : PokerAnswer := Classical
theorem example6 : (¬ Q → ¬ P) → P → Q :=
begin
  assume nqnp p,
  apply raa,
  assume nq,
  apply nqnp,
    assumption,
    --------------
    assumption,
end 

def answer7 : PokerAnswer := NotProvable
theorem example7 : (P → ¬P) → R :=
begin
  sorry,
end

def answer8 : PokerAnswer := Intuition
theorem example8 : (P → ¬P) → P → R :=
begin
  assume pnp p,
  have efq : false → R,
    assume f,
    cases f,
  apply efq,
  apply pnp,
    assumption,
    -------------------
    assumption,
end

def answer9 : PokerAnswer := Intuition
theorem example9 : P ∨ Q → ¬ (¬ P ∧ ¬ Q) := 
begin
  assume pq npnq,
  cases npnq with np nq,
  cases pq with p q,
    apply np,
    assumption,
    -----------------
    apply nq,
    assumption,
end 

def answer10 : PokerAnswer := UNANSWERED
theorem example10 : ¬ (¬ P ∧ ¬ Q) → P ∨ Q := 
begin
  assume nnpnq,
  apply raa,
  assume npq,
  apply nnpnq,
  constructor,
    assume p,
    apply npq,
    left,
    assumption,
    ----------------
    assume q,
    apply npq,
    right,
    assumption,
end 