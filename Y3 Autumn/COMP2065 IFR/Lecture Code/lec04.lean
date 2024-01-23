/-

## lec04: Algebra and logic

**NO reference from the book**

- = ==> ↔
- + ==> ∨
- * ==> ∧
- ^ ==> →       *index could be seen as implication in logics*
 - 2 ^ 3 ==> 3 → 2 

**law of commutativity**
**law of associativity**
**law of distributivity**

**laws of indices**
- `x^y * x^z = x^(y+z)`
- `x^z * y^z = (x*y)^z`
- `(x^y)^z = x^(y*z)`
-/

variables P Q R: Prop


-- `x^z * y^z = (x*y)^z`
-- let x be Q, y be R, z be P
example : (P → Q) ∧ (P → R) ↔ P → (Q ∧ R) := 
begin
  constructor,
    assume pqpr p,
    cases pqpr with pq pr,
    constructor,
      apply pq,
      assumption,
      ---------------
      apply pr,
      assumption,
    ------------------
    assume pqr,
    constructor,
      assume p,
      have simpQ : Q ∧ R → Q,
        assume qr,
        cases qr with q r,
        assumption,
      apply simpQ,
      apply pqr,
      assumption,
      -----------------
      assume p,
      have simpR : Q ∧ R → R,
        assume qr,
        cases qr with q r,
        assumption,
      apply simpR,
      apply pqr,
      assumption,
end

-- `x^y * x^z = x^(y+z)`
-- let x be R, y be P and z be Q
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

-- `x^(y*z) = (x^y)^z`
-- let x be R, y be Q, z be P
-- This is the `Curry` theorem 
example : (P ∧ Q) → R ↔ P → Q → R := 
begin
  constructor,
    assume pqr p q,
    apply pqr,
    constructor,
    assumption,
    assumption,
    ------------------
    assume pqr pq,
    cases pq with p q,
    apply pqr,
    assumption,
    assumption,
end



