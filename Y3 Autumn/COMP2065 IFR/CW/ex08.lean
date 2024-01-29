/-
COMP2065-IFR Exercise 08
(permutation)

Our goal is to prove that reverse outputs a permutation of its input.

-/
namespace ex08

open list
set_option pp.structure_projections false
variables {A B C : Type}

/-
In the lecture we have introduced the function reverse
(and the auxilliary function snoc)
-/

def snoc : list A → A → list A
| [] a := [a]
| (a :: as) b := a :: (snoc as b)

def rev : list A → list A
| [] := []
| (a :: as) := snoc (rev as) a

/-
Show that rev (or fastrev) does actually outputs a permutation
of its input. 

I include the definition of Perm (and the auxilliary Insert)
here. 

Hint : You will need to state and prove a lemma about snoc.
-/

inductive Insert : A → list A → list A → Prop
| ins_hd : ∀ a:A, ∀ as : list A,Insert a as (a :: as)
| ins_tl : ∀ a b:A, ∀ as as': list A, Insert a as as' 
        → Insert a (b :: as) (b :: as')

inductive Perm : list A → list A → Prop 
| perm_nil : Perm [] []
| perm_cons : ∀ a : A, ∀ as bs bs' : list A,Perm as bs 
      → Insert a bs bs' → Perm (a :: as) bs'

open Insert
open Perm
/- --- Do not add/change anything above this line --- -/


lemma perm_rev_lem: ∀ ns : list A, ∀ a : A, 
  Insert a ns (snoc ns a) :=
begin
  assume ns,
  induction ns with n ns' ih,
    assume a,
    dsimp [snoc],
    apply ins_hd,
    -------------
    assume a,
    dsimp [snoc],
    apply ins_tl,
    apply ih,
end

theorem perm_rev : ∀ as : list A, Perm as (rev as) :=
begin
  assume as,
  induction as with a as' ih,
    dsimp [rev],
    apply perm_nil,
    ---------
    apply perm_cons,
      assumption,
      -----------
      dsimp [rev],
      apply perm_rev_lem,
end


variables as bs cs  : list A

theorem refl_perm : ∀ as : list A, Perm as as :=
begin
  assume as,
  induction as with a as' ih,
    apply perm_nil,
    ---------
    apply perm_cons a as' as' (a :: as'),
    assumption,
    apply ins_hd,
end

lemma sym_perm_lem1 : ∀ a : A, ∀ as : list A, Perm as bs →   → false :=
begin
  sorry,
end 

lemma sym_perm_lem2 : ∀ a : A, ∀ as : list A, Perm (a :: as) [] → false :=
begin
  sorry,
end 

theorem sym_perm : ∀ as bs : list A, Perm as bs → Perm bs as :=
begin
  assume as,
  induction as with a as' ih,
    assume bs h,
    cases bs,
      assumption,
      ---------
      have f : false,
        apply sym_perm_lem1,
        assumption,
      cases f,
    -------------
    assume bs h,
    cases bs,
      have f : false,
        apply sym_perm_lem2,
        assumption,
      cases f,
      -------------
      apply perm_cons,
      apply ih,
      




end



theorem trans_perm : Perm as bs → Perm bs cs → Perm as cs := sorry


/-
Extra Challenge (NOT REQUIRED - NOT WORTH ANY MARKS)
If you are looking for a challenge try to prove that Perm is
an equivalence relation, that is 

The first one is quite easy (I'll do it in the lecture) but the other 
two are very difficult and require some lemmas.
-/


--- Do not add/change anything below this line ---
end ex08
