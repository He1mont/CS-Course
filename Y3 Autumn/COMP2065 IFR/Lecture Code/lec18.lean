/-
Lecture 18 : expression trees & compiler
-/

namespace l18
set_option pp.structure_projections false


inductive Expr : Type
| const : ℕ → Expr 
| var : string → Expr  
| plus : Expr → Expr → Expr
| times : Expr → Expr → Expr

open Expr 

-- x * (y + 2)
def e1 : Expr
:= times (var "x") (plus (var "y") (const 2))

-- (x * y) + 2
def e2 : Expr
:= plus (times (var "x") (var "y")) (const 2)

def Env : Type := string → ℕ

def eval : Expr → Env → ℕ
| (const n) env := n   
| (var x) env := env x 
| (plus e1 e2) env := (eval e1 env) + (eval e2 env)
| (times e1 e2) env := (eval e1 env) * (eval e2 env)

def env0 : Env
| "x" := 3
| "y" := 5
| _ := 0

-- eval把表达式转化成可处理的数学公式
-- env就是给变量赋值

#eval (eval e1 env0)
#eval (eval e2 env0)

-- example : eval e1 env0 = 21 :=
-- begin
--   dsimp [e1],
--   dsimp [eval],
-- end


-- assembly language

inductive Instr : Type 
| pushC : ℕ → Instr
| pushV : string → Instr
| add : Instr
| mult : Instr

open Instr

@[reducible]
def Code : Type := list Instr

def Stack : Type := list ℕ 

def run : Code → Stack → Env → ℕ
| [] [n] env := n
| (pushC n :: c) s env :=
    run c (n :: s) env 
| (pushV x :: c) s env :=
    run c (env x :: s) env 
| (add :: c) (m :: n :: s) env :=
    run c ((n + m) :: s) env 
| (mult :: c) (m :: n :: s) env :=
    run c ((n * m) :: s) env 
| _ _ _ := 0


def c1 : Code 
:= [pushV "x", pushV "y", pushC 2, add, mult]

-- example : run c1 [] env0 = 21 :=
-- begin
--   dsimp [c1],

-- end

#eval (run c1 [] env0)


-- translate high programming language expressions
-- to assembly language

-- def compile : Expr → Code
-- | (const n) := [pushC n]
-- | (var x) := [pushV x]
-- | (plus l r) :=
--     (compile l) ++ (compile r) ++ [add]
-- | (times l r) :=
--     (compile l) ++ (compile r) ++ [mult]

-- continuation based compiler
-- it's like fast_rev to rev

def compile_aux : Expr → Code → Code 
| (const n) c := pushC n :: c
| (var x) c := pushV x :: c 
| (plus l r) c :=
    (compile_aux l (compile_aux r (add :: c)))
| (times l r) c :=
    (compile_aux l (compile_aux r (mult :: c)))

def compile : Expr → Code 
| e := compile_aux e []

#eval (run (compile e1) [] env0)
#eval (run (compile e2) [] env0)

open list 



-- a more generalised version
lemma compile_aux_ok : 
  ∀ e : Expr, ∀ env : Env, ∀ c : Code, ∀ s : Stack,
  run (compile_aux e c) s env = run c (eval e env :: s) env :=
begin
  assume e env,
  induction e,
  case const: n {
    assume c s,
    dsimp [compile_aux, run, eval],
    refl,
  },
  case var : v {
    assume c s,
    dsimp [compile_aux, run, eval],
    refl,
  },
  case plus : a b {
    assume c s,
    dsimp [compile_aux, run, eval],
    rewrite e_ih_ᾰ,
    
  }

end

theorem compile_ok : ∀ e : Expr, ∀ env : Env,
  eval e env = run (compile e) [] env := 
begin
  assume e env,
  dsimp [compile],
  rewrite compile_aux_ok,
  dsimp [run],
  refl,
end



end l18