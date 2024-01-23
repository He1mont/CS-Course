/-
lec03: 
  from chapter 2.3-

if we assume h : P → Q
and we want to prove Q
we say apply h, and we have to prove P

- tactics
assume h: prove an implication
apply h: use an assumed implication
exact h: use an assumption as it is

-/

/--------------Chapter 2.3-------------------/

-- proofs are programs (functional programs)
-- propositions are types

variables P Q R : Prop 

theorem swap : (P → Q → R) → (Q → P → R) :=
begin
  assume pqr q p,
  apply pqr,
  exact p,
  exact q,
end

#print swap

/--------------Chapter 2.5-------------------/

-- conjuction
-- we use example here since we don't wanna give theorem a name
example : P → Q → P ∧ Q :=
begin
  assume p q,
  constructor,
  exact p,
  exact q,
end

-- to prove simplification
example : P ∧ Q → P :=
begin
  assume h,
  cases h with p q,
  exact p,
end

-- to show conjunction is commutative
theorem comAnd : P ∧ Q → Q ∧ P :=
begin
  assume pq,
  cases pq with p q,
    constructor,
    exact q,
    exact p
end 

theorem comAndIff : P ∧ Q ↔ Q ∧ P :=
begin 
  constructor,
  apply comAnd,
  apply comAnd,
end    


-- conjunction

-- a lemma for the curry theorem
example : (P → Q → R) → P → Q → R :=
begin
  assume pqr p q,
  apply pqr,
  exact p,
  exact q
end

theorem curry : (P → Q → R) ↔ (P ∧ Q → R) :=
begin
  constructor,          -- split iff

  assume pqr pq,
  cases pq with p q,    -- split condition P and Q
  apply pqr,
  exact p,
  exact q,

  assume pqr p q,
  apply pqr,
  constructor,    -- (P) ∧ (Q) → P ∧ Q
  exact p,
  exact q,
end 


-- disjunction

example : P → P ∨ Q :=
begin
  assume p,
  left,
  exact p
end 

example : Q → P ∨ Q :=
begin
  assume q,
  right,
  exact q
end 

theorem case_lem : (P → R) → (Q → R) → P ∨ Q → R :=
begin
  assume pr qr pq,
  cases pq with p q,
  apply pr,
  exact p,
  apply qr,
  exact q
end  

-- logic and algebra
example : P ∧ (Q ∨ R) ↔ (P ∧ Q) ∨ (P ∧ R) :=
begin
  constructor,
  assume pqr,   -- left to right
  cases pqr with p qr,
  cases qr with q r,
  left,
  constructor,
  exact p,
  exact q,
  right,
  constructor,
  exact p,
  exact r,
  assume pqpr,  -- right to left
  constructor,
  cases pqpr with pq pr,
  cases pq with p,
  exact p,
  cases pr with p,
  exact p,
  cases pqpr with pq pr,
  cases pq with p q,
  left,
  exact q,
  cases pr with p r,
  right,
  exact r,
end

-- True, false and negation

example : true :=
begin 
  constructor,
end 

example : false → P :=
begin
  assume pigs_can_fly,
  cases pigs_can_fly,
end 

theorem contr: ¬ (P ∧ ¬ P) :=
begin
  assume pnp,
  cases pnp with p np,
  apply np,
  exact p,
end


