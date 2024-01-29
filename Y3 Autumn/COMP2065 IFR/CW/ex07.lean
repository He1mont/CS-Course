/-
COMP2065-IFR Exercise 07
(fast reverse) 

Our goal is to prove that fast reverse computes the same function
as reverse.

-/

open list
set_option pp.structure_projections false
variables {A B C : Type}
namespace revDefn

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
Our implementation of rev is inefficient: it has O(n^2) complexity.
The definition below (called fastrev) is efficient, having only O(n) complexity.
It uses an auxillary function revaux which accumulates the reversed 
list in a 2nd variable.
-/

def revaux : list A → list A → list A
| [] bs := bs
| (a :: as) bs := revaux as (a :: bs)

def fastrev (l : list A) : list A
  := revaux l []

#reduce fastrev [1,2,3]


end revDefn

namespace ex07
open revDefn
/- --- Do not add/change anything above this line --- -/

/-
However we would like to show that fast rev and rev do the same thing.

You'll need to establish a lemma about revaux (hint: try writing
down a precise specification of what revaux does).

You may use the fact that lists with ++ form a monoid 
(just copy the proofs from the lecture).
-/

/-
rev [1,2,3]
= snoc (rev [2,3]) 1
= snoc (snoc (rev [3]) 2) 1
= snoc (snoc (snoc (rev []) 3) 2) 1
= snoc (snoc (snoc [] 3) 2) 1
= snoc (snoc [3] 2) 1
= snoc [3,2] 1
= [3,2,1]
-/


/-
fastrev [1,2,3]
= revaux [1,2,3] []
= revaux [2,3] [1]
= revaux [3] [2,1]
= revaux [] [3,2,1]
= [3,2,1]
-/


lemma snoc_revaux_lem2 : ∀ as bs : list A, ∀ a : A, revaux as (snoc bs a) = snoc (revaux as bs) a :=
begin
  assume as,
  induction as with a' as' ih,
    assume bs a,
    dsimp [revaux, snoc],
    refl,
    -------------
    assume bs a,
    dsimp [revaux, snoc],
    rewrite← ih,
    refl,
end

-- lemma snoc_revaux_lem1 : ∀ as : list A, ∀ a : A, revaux as [a] = snoc (revaux as nil) a :=
-- begin
--   assume as,
--   induction as with a' as' ih,
--     assume a,
--     dsimp [revaux, snoc],
--     refl,
--     ----------
--     assume a,
--     dsimp [revaux, snoc],
--     rewrite ih,
--     rewrite snoc_revaux_lem2,
--     rewrite snoc_revaux_lem2,
--     dsimp [snoc],
--     refl,
-- end

theorem fastrev_thm : ∀ as : list A , fastrev as = rev as :=
begin
  assume as,
  induction as with a as' ih,
    dsimp [fastrev, revaux, rev],
    refl,
    -----------
    dsimp [fastrev, revaux, rev],
    dsimp [fastrev, revaux, rev] at ih,
    rewrite← ih,
    rewrite← snoc_revaux_lem2,
    dsimp [snoc],
    refl,
end




--- Do not add/change anything below this line ---
end ex07