/-
COMP2065-IFR 
Exercise 01 (10 points)

Prove all the following propositions in Lean. 1 point per exercise.
That is replace "sorry" with your proof. 

You are only allowed to use the tactics introduced in the lecture
(i.e. assume, exact, apply, constructor, cases, left, right, have)

-/
namespace proofs

variables P Q R : Prop

/- --- Do not add/change anything above this line --- -/


theorem q01 : P → Q → P :=
begin
  assume p q,
  exact p,
end

theorem q02 : (P → Q → R) → (P → Q) → P → R :=
begin
  assume pqr pq p,
  apply pqr,
  exact p,
  apply pq,
  exact p,
end

theorem q03 : (P → Q) → P ∧ R → Q ∧ R :=
begin
  assume pq pr,
  cases pr with p r,
  constructor,
  apply pq,
  exact p,
  exact r,
end

theorem q04 : (P → Q) → P ∨ R → Q ∨ R :=
begin
  assume pq pr,
  cases pr with p r,
  left,
  apply pq,
  exact p,
  right,
  exact r,
end

theorem q05 : P ∨ Q → R ↔ (P → R) ∧ (Q → R) :=
begin
  constructor,
  assume pqr,         -- left to right
  constructor,
  assume p,
  apply pqr,
  left,
  exact p,
  assume q,
  apply pqr,
  right,
  exact q,
  assume prqr pq,     -- right to left
  cases prqr with pr qr,
  cases pq with p q,
  apply pr,
  exact p,
  apply qr,
  exact q,
end

theorem q06 : P → ¬ ¬ P :=
begin
  assume p pf,
  apply pf,
  exact p,
end

theorem q07 : P ∧ true ↔ P :=
begin
  constructor,
  assume pt,          -- left to right
  cases pt with p t,
  exact p,            -- right to left
  assume p,
  constructor,
  exact p,
  constructor,
end

theorem q08 : P ∨ false ↔ P :=
begin
  constructor,
  assume pf,          -- left to right
  cases pf with p f,
  exact p,
  cases f,            -- right to left
  assume p,
  left,
  exact p,
end

theorem q09 : P ∧ false ↔ false :=
begin
  constructor,
  assume pf,
  cases pf with p f,
  exact f,
  assume f,
  cases f,
end

theorem q10 : P ∨ true ↔ true :=
begin
  constructor,
  assume pt,
  constructor,
  assume t,
  right,
  exact t,
end

/- --- Do not add/change anything below this line --- -/
end proofs