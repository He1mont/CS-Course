/-
## Lecture 05: Classical vs Intuitionistic Logic
-/

/-
- classical logic: truth based
- intuitionisitic logic: evidence based

**De Morgan Laws**
- `¬ (P ∨ Q) ↔ ¬ P ∧ ¬ Q`
- `¬ (P ∧ Q) ↔ ¬ P ∨ ¬ Q`

since `¬ P = P → false`
we can re-write the De Morgan's law into 
- `(P ∨ Q) → false ↔ (P → false) ∧ (Q → false)`
- `(P ∧ Q) → false ↔ (P → false) ∨ (Q → false)`
-/

variables P Q R: Prop 

-- in lec04, we got a theorem called index
theorem index : (P → R) ∧ (Q → R) ↔ (P ∨ Q) → R :=
begin
  constructor,
    assume prqr pq,
    cases prqr with pr qr,
    cases pq with p q,
      apply pr,
      assumption,
      ----------------
      apply qr,
      assumption,
    ---------------------
    assume pqr,
    constructor,
      assume p,
      apply pqr,
      left,
      assumption,
      ---------------
      assume q,
      apply pqr,
      right,
      assumption,
end

/-
Please **note that** 
if we wanna prove `¬ (P ∨ Q) ↔ ¬ P ∧ ¬ Q`
and we apply theorem index, it's not working
Although `↔` satisfies commutative law,
but `Lean` is too dumb to know that
-/

theorem dm1: ¬ P ∧ ¬ Q ↔ ¬ (P ∨ Q) :=
begin
  apply index,
end


open classical
#check em P       -- law of excluded middle

-- Note that if we wanna prove `P`,
-- we are proving `P → True`
example : P ∨ ¬ P :=
begin
  apply em,
end

theorem dm2: ¬ (P ∧ Q) ↔ ¬ P ∨ ¬ Q :=
begin
  constructor,
    assume npq,
    cases (em P) with p np,     -- we add another variable `em P`
      right,                    -- since `P ↔ P ∧ true`
      assume q,
      apply npq,
      constructor,
      assumption,
      assumption,
      ----------------
      left,
      assumption,
    ----------------            
    assume npnq,
    assume pq,
    cases pq with p q,
    cases npnq with np nq,
      apply np,
      assumption,
      -------------------
      apply nq,
      assumption,
end

/-
reduction ad absurdo, indirect proof
we wanna prove `P`,
we assume ¬ P and derive a contradiction
¬ P → false
-/

theorem efq : false → P :=
begin
  assume f,
  cases f,
end

theorem raa : ¬ ¬ P → P :=
begin
  assume nnp,
  cases em P with p np,
    assumption,
    -------------------
    apply efq,
    apply nnp,
    assumption,
end 

theorem nnem : ¬ ¬ (P ∨ ¬ P) :=  
begin
  assume npnp,
  apply npnp,
  right,        -- **important step**
  assume p,
  apply npnp,
  left,
  assumption,
end

/-
em : `P ∨ ¬ P`
raa : `¬ ¬ P → P`
they are **equivalent**.
- `em → raa`
- `raa → em`
-/

theorem em : P ∨ ¬ P :=
begin
  apply raa,
  apply nnem,
end 