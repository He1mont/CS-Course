/-
COMP2065-IFR Exercise 02
-/

namespace poker

variables P Q R : Prop

inductive PokerAnswer : Type
| UNANSWERED : PokerAnswer 
| NotProvable : PokerAnswer
| Intuition : PokerAnswer
| Classical : PokerAnswer
open PokerAnswer

open classical

theorem raa : ¬ ¬ P → P := 
begin
  assume nnp,
  cases (em P) with p np,
    exact p,
    have f : false,
      apply nnp,
      exact np,
    cases f,
end

/- --- Do not add/change anything above this line --- -/

/-
We play the game of logic poker :-)

  You have to classify each proposition as either
  a) provable intuitionistically (i.e. in plain lean)
  b) provable classically (using em : P ∨ ¬ P or raa : ¬¬ P → P).
  c) not provable classically.
  and then you have to prove the propositions in a) and b) accordingly.

  You will start with a score of 10 points, and then 1 point will be deducted
  for each incorrect classification and 1 point will be deducted for each
  incorrect proof. We stop deducting at zero, so you cannot earn negative points.
  So, for instance, if you do every proof correctly but do not classify anything,
  you will earn 0/10.
-/

/-
CLASSIFICATION: For each proposition, replace UNANSWERED with
  Intuition     if the proposition is provable intuitionistically (i.e. in plain lean)
  Classical     if the proposition is provable classically (using em : P ∨ ¬ P or raa : ¬¬ P → P)
  NotProvable   if the proposition is not provable classically

**Important**: Every classification should be one of these three, or UNANSWERED. 
DO NOT put anything else on the right-hand side or leave it totally blank.

Examples:                                  -/
-- q00 : P → P
def answer00 : PokerAnswer := Intuition

-- q00' : ¬¬P → P
def answer00' : PokerAnswer := Classical

-- q00'' : false
def answer00'' : PokerAnswer := NotProvable

/-
PROOFS: 
  Then, prove the propositions you classified as 'Intuition' or 'Classical'. 
  For the 'Classical' ones, you may use em or raa, as discussed in lecture.
  For propositions classified as 'NotProvable' just keep "sorry," as the proof.

  You are only allowed to use the tactics introduced in the lecture
  (e.g. assume, exact, apply, constructor, cases, left, right, have),

  Please only use the tactics in the way indicated in the lecture notes,
  otherwise we may deduct points.
-/


-- q01 : (P → Q) → (R → P) → (R → Q)
def answer01 : PokerAnswer  := Intuition
theorem q01 : (P → Q) → (R → P) → (R → Q) := 
begin
  assume pq rp r,
  apply pq,
  apply rp,
  assumption,
end

-- q02 : (P → Q) → (P → R) → (Q → R)
def answer02 : PokerAnswer  := NotProvable
theorem q02 : (P → Q) → (P → R) → (Q → R) :=
begin
  sorry,
end

-- q03 : (P → Q) → (Q → R) → (P → R)
def answer03 : PokerAnswer  := Intuition
theorem q03 : (P → Q) → (Q → R) → (P → R) :=
begin
  assume pq qr p,
  apply qr,
  apply pq,
  assumption,
end

-- q04 : P → (P → Q) → P ∧ Q
def answer04 : PokerAnswer  := Intuition
theorem q04 : P → (P → Q) → P ∧ Q :=
begin
  assume p pq,
  constructor,
  assumption,
  apply pq,
  assumption,
end

-- q05 : P ∨ Q → (P → Q) → Q
def answer05 : PokerAnswer  := Intuition
theorem q05 : P ∨ Q → (P → Q) → Q :=
begin
  assume pq p2q,
  cases pq with p q,
  apply p2q,
  assumption,
  assumption,
end

-- q06 : (P → Q) → ¬ P ∨ Q
def answer06 : PokerAnswer  := Classical
theorem q06 : (P → Q) → ¬ P ∨ Q :=
begin
  assume pq,
  cases em Q with q nq,
    right,
    assumption,
    ------------------
    left,
    assume p,
    apply nq,
    apply pq,
    assumption,
end

-- q07 : (¬ P ∨ Q) → P → Q
def answer07 : PokerAnswer  := Intuition
theorem q07 : (¬ P ∨ Q) → P → Q :=
begin
  assume npq p,
  cases npq with np q,
    have efq : false -> Q,
      assume f,
      cases f,
    apply efq,
    apply np,
    assumption,
    ----------------
    assumption,
end

-- q08 : ¬ (P ↔ ¬ P)
def answer08 : PokerAnswer  := Intuition
theorem q08 : ¬ (P ↔ ¬ P) :=
begin
  assume pnp,
  cases pnp with p2np np2p,
    apply p2np,
    apply np2p,
    assume p,
    apply p2np,
    assumption,
    assumption,
    -------------------------
    apply np2p,
    assume p,
    apply p2np,
    assumption,
    assumption,
end

-- q09 : ¬ P ↔ ¬ ¬ ¬ P
def answer09 : PokerAnswer  := Intuition
theorem q09 : ¬ P ↔ ¬ ¬ ¬ P :=
begin
  constructor,
    assume np nnp,
    apply nnp,
    assumption,
    -------------------
    assume nnnp p,
    apply nnnp,
    assume np,
    apply np,
    assumption,
end

-- q10 : ((P → Q) → P) → P
def answer10 : PokerAnswer  := Classical
theorem q10 : ((P → Q) → P) → P :=
begin
  assume pqp,
  cases em P with p np,
  assumption,
  apply pqp,
  assume p,
  have efq : false → Q,
    assume f,
    cases f,
  apply efq,
  apply np,
  assumption,
end


--- Do not add/change anything below this line ---
end poker