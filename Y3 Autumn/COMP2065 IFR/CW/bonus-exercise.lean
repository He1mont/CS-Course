namespace dnf
set_option pp.structure_projections false
/-
The goal of this exercise is to compute
the disjunctive normal form (dnf) of a boolean
expression and then prove that the dnf has 
the same semantics (i.e. evaluates to the 
same boolean in all environments).
-/


def band : bool → bool → bool 
| tt b := b
| ff b := ff

def bor : bool → bool → bool 
| tt b := tt
| ff b := b

def bnot : bool → bool
| tt := ff
| ff := tt
prefix `!`:90 := bnot
/- --- Do not add/change anything above this line --- -/


local notation (name := band) x && y := band x y 
local notation (name := bor) x || y := bor x y
/-
If you get an error update your lean or use:
local notation x && y := band x y 
local notation x || y := bor x y
-/

-- we define boolean expressions 

inductive Expr : Type
| var : string → Expr
| and : Expr → Expr → Expr  
| or : Expr → Expr → Expr
| not : Expr → Expr 
| tt : Expr 
open Expr
/- 
`string` is the built-in type of strings, e.g
"" or "Hello world!"
-/

/- 
For example, the expression 
p && ! (q || p)
would be represented as
-/
def e1 : Expr :=
  and (var "p") (not (or (var "q") (var "p")))

/- we define environments, i.e. 
 assignments of booleans to variables
-/
def Env : Type := string → bool

/-
as an example we assign tt to "p" and ff to "q"
since we have to assign all variables (i.e. all strings), 
we just default to ff otherwise
-/
def env1 : Env 
| "p" := tt
| "q" := ff
| _ := ff

/- We specify the meaning of expr by 
defining an evaluator (its semantics)-/

def eval : Expr → Env → bool 
| (var x) env := env x 
| (and e₁ e₂) env := eval e₁ env && eval e₂ env
| (or e₁ e₂) env := eval e₁ env || eval e₂ env
| (not e) env := ! (eval e env)
| tt env := tt

/- so for example evaluating e1 with env1 
gives ff -/

#eval (eval e1 env1)

/- 
Now we define DNFs. A boolean expression
is said to be in *disjunctive normal form*
when it is composed of a disjunction of several boolean expressions
  C_1 || C_2 || C_3 || ... || C_n
where each C_i is of the form
  L_1 && L_2 && ... && L_m
and where each L_j is either a variable p, or the negation
of a variable, !p. In short: a DNF is a *disjunction*
of *conjunctions* of *literals* (where "literal" means
"variable or negated variable").

e1 := p && ! (q || p)  *is not* in disjunctive normal
form, because it contains the negation of a disjunction, which
isn't allowed in the above description.
e2 := (p && !q) || r   *is* in disjunctive normal form, because
it is the disjunction of two expressions, `(p && !q)`  with `r`,
where both are conjunctions of literals: `p` and `!q` are literals,
so `(p && !q)` is a conjunction of literals. `r` is a literal,
and therefore also the conjunction of 1 literal.

Note that `tt` and `ff` are both in DNF, because tt is the 
"empty conjunction", i.e. the conjunction together of *zero*
literals. `ff` is in DNF because it is the "empty disjunction",
the disjunction of *zero* boolean expressions.

We now define DNF boolean expressions as an inductive type in Lean.
Start with literals "Lit" which are variables and negated variables 
-/


inductive Lit : Type 
| lit : bool → string → Lit
/-
`lit tt "p"` represents the expression p
`lit ff "p"` represents the expression !p
-/

/- Con are conjunctions of literals -/
inductive Con : Type 
| TT : Con 
| And : Lit → Con → Con
/- The TT here is the boolean expression 
   representing tt:bool, which is the "empty conjunction",
   the disjunction of _zero_ Lit's.
-/ 

/- DNFs are disjuctions of conjunctions-/
inductive DNF : Type 
| FF : DNF 
| Or : Con → DNF → DNF
/- The FF here is the boolean expression 
   representing ff:bool, which is the "empty disjunction",
   the disjunction of _zero_ Con's.
-/ 

open Lit Con DNF 

/- e1 is not in disjunctive normal form
but we can convert it to one which is equivalent
  p && ! q && ! q
This is a conjunction of literals, i.e. it'll be
represented by a expression of type Con. 
-/
def d1' : Con
:= And (lit tt "p") 
      (And (lit ff "q")
      (And (lit ff "p") TT))
/- To view any Con as a DNF, we can just
   "or" it with the empty disjunction, FF.
 -/
def d1 : DNF 
:= Or d1' FF

/-
we also need an evaluator for 
DNF using evaluators for literals and 
conjunctions.
-/

def eval_lit : Lit → Env → bool
| (lit tt x) env := env x 
| (lit ff x) env := ! (env x)

def eval_con : Con → Env → bool 
| TT env := tt 
| (And l c) env := eval_lit l env && eval_con c env 

def eval_dnf : DNF → Env → bool 
| FF env := ff 
| (Or c d) env := eval_con c env || eval_dnf d env 

/- Now evaluating c1 gives the same result
as evaluating eq -/
#eval (eval_dnf d1 env1)


/- 
Here's our claim: for *any* boolean expression e : Expr, it's possible
to convert it into an expression  d:DNF which is equivalent.
"Equivalent" here means that, given any env:Env, the two expressions
have the same truth value according to their respective evaluators:
      `eval e env  =  eval_dnf d env`

Our goal is to write a function that performs this conversion: -/
def dnf : Expr → DNF 
:= sorry

/- and to prove it correct-/
theorem dnf_ok : ∀ e : Expr , ∀ env : Env,
  eval e env = eval_dnf (dnf e) env :=
begin
  sorry
end 


end dnf