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

/-
    P    |    Q    |   P → Q  
------------------------------
  true   |  true   |   true  
  true   |  false  |   false
  false  |  true   |   true
  false  |  false  |   true
-/
example : P → Q :=
begin 
  sorry, -- counterexample: P=true Q=false
end
example : ¬(true → false) :=
begin
  assume tf,
  apply tf,
  constructor,
end

/-
    P    |    Q    |  (P → Q) | (P → Q) → Q | 
---------------------------------------------
  true   |  true   |   true   |    true     |
  true   |  false  |   false  |    true     |
  false  |  true   |   true   |    false    |
  false  |  false  |   true   |    false    |
-/
example : P → (P → Q) → Q :=
begin 
  assume p pq,
  apply pq,
  exact p,
end 

/-
   P   |   Q   |   R   |  Q → R  | P → (Q → R) → R
---------------------------------------------------
 true    false   false    true         false
-/
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
  IMPORTANT: Truth table reasoning will only tell you if something
  is provable or not. It WON'T tell you whether it can be proved
  intuitionistically or if classical reasoning is required
-/

/-
## Classical Reasoning
-/
open classical

/-
    P    |   ¬P    |   P ∨ ¬P 
------------------------------
  true   |  false  |   true  
  false  |  true   |   true
-/


-- Excluded middle: for any proposition P, (P ∨ ¬P).
#check em (P ∨ Q → R)

theorem em_to_raa : (P ∨ ¬ P) →  ¬¬P → P :=
begin
  assume pnp nnp,
  cases pnp with p np,
  exact p,
  have f : false,
  apply nnp,
  exact np,
  cases f,
end
-- Notice: This proof doesn't use any classical reasoning itself

theorem raa : ¬¬P → P :=
begin 
  apply em_to_raa,
  exact (em P),
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

-- Provable intuitionistically
theorem example0 : ¬ P ∨ ¬ Q → ¬ (P ∧ Q) :=
begin 
  assume npnq pq,
  cases pq with p q,
  cases npnq with np nq,
  apply np,
  exact p,
  apply nq,
  exact q,
end 
-- Requires classical logic
theorem example1 : ¬ (P ∧ Q) → ¬ P ∨ ¬ Q :=
begin 
  assume npq,
  cases (em P) with p np,
  right,
  assume q,
  apply npq,
  constructor,
  exact p,
  exact q,
  left,
  exact np,
end 

/- How classification will be formatted on the exercises: -/
inductive PokerAnswer : Type
| UNANSWERED : PokerAnswer 
| NotProvable : PokerAnswer
| Intuition : PokerAnswer
| Classical : PokerAnswer
open PokerAnswer

def answer0 : PokerAnswer := Intuition
def answer1 : PokerAnswer := Classical

/- ## Try it yourself! -/

def answer2 : PokerAnswer := Intuition 
theorem example2 : ¬(P ∧ ¬P) :=
begin 
  assume pnp,
  cases pnp with p np,
  apply np,
  exact p,
end

def answer3 : PokerAnswer := NotProvable
theorem example3 : (¬ P → P) → ¬P :=
begin
  sorry,
end -- counterexample: P=true

def answer4 : PokerAnswer := Classical 
theorem example4 : (¬ P → P) → P :=
begin 
  assume pnp,
  cases (em P) with p np,
  exact p,
  apply pnp,
  exact np,

end 

def answer5 : PokerAnswer := Intuition
theorem example5 : (P → Q) → ¬ Q → ¬ P :=
begin
  assume machine nq p,
  apply nq,
  apply machine,
  exact p,
end 

def answer6 : PokerAnswer := Classical 
theorem example6 : (¬ Q → ¬ P) → P → Q :=
begin
  assume h p,
  cases (em Q) with q nq,
  exact q,
  have f : false,
  apply h,
  exact nq,
  exact p,
  cases f,
end 

def answer7 : PokerAnswer := NotProvable
theorem example7 : (P → ¬P) → R :=
begin
  sorry,
end -- counterexample: P=false, R=false

def answer8 : PokerAnswer := Intuition
theorem example8 : (P → ¬P) → P → R :=
begin
  assume p_to_np p,
  have f : false,
  apply p_to_np,
  exact p,
  exact p,
  cases f,
end

def answer9 : PokerAnswer := Intuition
theorem example9 : P ∨ Q → ¬ (¬ P ∧ ¬ Q) := 
begin 
  assume porq npnq,
  cases npnq with np nq,
  cases porq with p q,
  apply np,
  exact p,
  apply nq,
  exact q,
end 

def answer10 : PokerAnswer := Classical
theorem example10 : ¬ (¬ P ∧ ¬ Q) → P ∨ Q := 
begin 
  assume h,
  cases (em P) with p np,
  left,
  exact p,
  cases (em Q) with q nq,
  right,
  exact q,
  have f : false,
  apply h,
  constructor,
  exact np,
  exact nq,
  cases f,
end 