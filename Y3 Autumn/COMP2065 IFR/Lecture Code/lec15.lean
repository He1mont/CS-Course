/-
lec15
-/

namespace l15
set_option pp.structure_projections false
variables {A B C D : Type}

open list 

/-
This theorem cannot be proved since if there's a type `unit` that has only one element,
then this theorem is true
-/

theorem comm :¬ (∀ A : Type, ∀ as bs : list A, as ++ bs = bs ++ as) :=
begin
  assume h,
  have hh : [0] ++ [1] = [1] ++ [0],
    apply h,
  have hhh : 0 = 1,
    dsimp [(++)] at hh,
    injection hh,
  contradiction,
end
  
-- rev : list A → list A
-- rev [1,2,3] = [3,2,1]
-- rev [1,2,3] = rev (1 :: [2,3])
-- snoc as b = as ++ [b]


def snoc : list A → A → list A
| [] b := [b]
| (a :: as) b := a :: (snoc as b)

#eval (snoc [3,2] 1)

def rev : list A → list A 
| [] := []
| (a :: as) := snoc (rev as) a 

#eval (rev [1,2,3])
#eval (rev (rev [1,2,3]))

open list 

-- snoc [1,2] 3 = [1,2,3]
-- rev [1,2,3] = 3 :: rev [1,2]
-- rev (snoc [1,2,3] 4) = rev ([1,2,3,4]) = 4 :: rev [1,2,3]

lemma revsnoc : ∀ a : A, ∀ as : list A, rev (snoc as a) = a :: (rev as) :=
begin
  assume a as,
  induction as with a' as' ih,
    dsimp [snoc, rev],
    refl,
    -------------
    dsimp [snoc, rev],
    rewrite ih,
    dsimp [snoc],
    refl,
end

theorem revrev : ∀ as : list A, rev (rev as ) = as :=
begin
  assume as,
  induction as with a as' ih,
    dsimp [rev],
    refl,
    ------------
    dsimp [rev],
    rewrite revsnoc,
    rewrite ih,
end

/-
list is a functor
list : Type → Type
rev is natural
-/

def map_list : (A → B) → list A → list B
| f [] := []
| f (a :: as) := (f a) :: (map_list f as)

/- 
id : A → A
comp : (B → C) → (A → B) → A → C

id ∘ f = f
f ∘ id = f
(f ∘ g) ∘ h = f ∘ (g ∘ h)

It is a **category** rather than a **monoid**
-/

def id : A → A | a := a 

def comp : (B → C) → (A → B) → A → C
| g f a := g (f a)

-- notation (name := comp) f ∘ g := comp f g 

theorem idl : ∀ f : A → B, id ∘ f = f :=
begin
  assume f,
  apply funext,
  assume x,
  dsimp [id],
  reflexivity,
end

theorem idr : ∀ f : A → B, f ∘ id = f :=
begin
  assume f,
  apply funext,
  assume x,
  dsimp [id],
  reflexivity
end

theorem assoc : ∀ h : C → D, ∀ g : B → C,
  ∀ f : A → B, (h ∘ g) ∘ f = h ∘ (g ∘ f) := 
begin
  assume h g f,
  apply funext,
  assume x,
  dsimp [comp],
  reflexivity,
end

/-
`map_list id = id`
`map_list (g ∘ f) = map g ∘ map f`
-/

lemma map_id_lem : ∀ as : list A,
  map_list id as = as :=
begin
  assume as,
  induction as with a as' ih,
    dsimp [map_list, id],
    refl,
    -----------
    dsimp [map_list, id],
    rewrite ih,
end

/-
f g : A → B
∀ a : A, f a = g a → f = 
-/

theorem map_id : map_list (@id A) = (@id (list A)) :=
begin
  apply funext,
  apply map_id_lem,
end






end l15