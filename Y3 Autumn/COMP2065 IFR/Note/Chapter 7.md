# Chapter 7: Lists

**All elements of a list must have the same type**

All lists can be created from nil and cons hence lists

```lean
 inductive list (A : Type)
| nil  : list
| cons : A → list → list
```

Similar as *Peano Arithmetics* in natural numbers, we have
- `nil ≠ cons a`
- `cons` is injective

Therefore, we could also use `contradiction` to prove `nil ≠ a :: as`

## 7.1 Basic properties

As we mentioned above, we first need to prove `nil ≠ a :: as`
```lean
example : ∀ a : A, ∀ as : list A, a :: as ≠ [] :=
begin
  assume a as h,
  contradiction,
end
```

Then we need to prove that `cons` is *injective*
```lean
example : ∀ a b : A, ∀ as bs : list A,
  a :: as = b :: bs → a = b ∧ as = bs :=
begin
  assume a b as bs h,
  constructor,
  injection h,
  injection h,
end
```

Instead of using `injection` tactics, we could prove the theorem in **a different way**. Since `P → Q ∧ R ↔ (P → Q) ∧ (P → R)`, we need to prove both 
- `a :: as = b :: bs → a = b`
- `a :: as = b :: bs → as = bs`,

```lean
def tail : list A → list A  
| [] := []
| (a :: as) := as 

example : ∀ a b : A, ∀ as bs : list A,
  a :: as = b :: bs → as = bs :=
begin
  assume a b as bs h,
  change (tail (a :: as) = tail (b :: bs)),
  rewrite h,
end
```

```lean
def head : list A → A 
| [] := sorry
| (a :: as) := a

example : ∀ a b : A, ∀ as bs : list A,
  a :: as = b :: bs → a = b :=
begin
  assume a b as bs h,
  sorry,  -- the technique is not covered in this lecture
end
```

## 7.2 The free monoid
In natural numbers we encountered a *monoid* using `+` and `0` on `ℕ`. There is a very similar *monoid* for lists using `++` and `[]`.

```lean
def append : list A → list A → list A 
| [] bs := bs 
| (a :: as) bs := a :: (append as bs)

local notation l₁ ++ l₂ := append l₁ l₂
```

Now let's try to prove some properties of `++`:

- Left neutral
```lean
theorem lneutr : ∀ as : list A, [] ++ as = as :=
begin
  assume as,
  dsimp [(++)],
  refl,
end
```

- Right neutral
- We could also use ***induction*** to deal with list, i.e. **separate it into `nil` and `as' → (a' :: as')`**
```lean
theorem rneutr : ∀ as : list A, as ++ [] = as :=
begin
  assume as,
  induction as with a as' ih,
    dsimp [(++)],
    refl,
    ------------
    dsimp [(++)],
    rewrite ih,
end
```

- Associative
```lean
theorem assoc : ∀ as bs cs : list A,
  (as ++ bs) ++ cs = as ++ (bs ++ cs) :=
begin
  assume as bs cs,
  induction as with a as' ih,
    dsimp [(++)],
    refl,
    ----------
    dsimp [(++)],
    sorry,
end
```

- Non-commutative
- This can *not* be proved since *commutativity* holds for a single element type called `unit`.
```lean
theorem comm :¬ (∀ as bs : list A, as ++ bs = bs ++ as) :=
begin
  sorry,
end
```

But we could prove the following theorem instead, using **counter-example**
```lean
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
```


## 7.3 Reverse

Now we introduce a function *reverse* that:
`rev [1,2,3] = 3 :: rev [1,2] = [3,2,1]`

But before we define `reverse`, we need to know how to obtain the last element in a list, i.e. how to obtain `3` from [1,2,3]. Therefore we have to define:

```lean
def snoc : list A → A → list A
| [] b := [b]
| (a :: as) b := a :: (snoc as b)

def rev : list A → list A 
| [] := []
| (a :: as) := snoc (rev as) a 
```

### Self-Inverse

**Now we prove `rev` is *self-inverse*.**

```lean
theorem revrev : ∀ as : list A, rev (rev as ) = as := sorry
```

- We got stuck in the following situation:
```lean
ih : rev (rev as') = as'
⊢ rev (snoc (rev as') a) = a :: as'
```

I cannot `rewrite ih`, but by intuition we know that:
```lean
rev (snoc (rev as') a)
= a :: rev (rev as')    -- rev from the other direction
= a :: as'
```

Replace `rev as'` with `as`,  we need to prove a *lemma* below. And with the help of this lemma, we would be able to prove the theorem easily:
```lean
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
```

### Fast Reverse

However, the solution above is in-efficient: it has $O(n^2)$ complexity. The definition below, called `fastrev` is efficient, with only $O(n)$ complexity.

> [ex07](../CW/ex07.lean) is all about `fastrev`

```lean
def revaux : list A → list A → list A
| [] bs := bs
| (a :: as) bs := revaux as (a :: bs)

def fastrev (l : list A) : list A := revaux l []
```

**Now we need to prove that `rev` and `fastrev` does the same thing.**

```lean
theorem fastrev_thm : ∀ as : list A , fastrev as = rev as := sorry
```

- As always, we do `induction` on `as`
- The *base case* is easy to prove
- The *inductive step*, after `rewrite ih`, we have need to prove

```lean
⊢ revaux as' [a] = snoc (revaux as' nil) a
```

So now we should focus on proving this lemma:

```lean
lemma snoc_revaux_lem1 : ∀ as : list A, ∀ a : A, 
  revaux as [a] = snoc (revaux as []) a := sorry
```

>   **Notice**
>
>   We need to write `∀ as : list A` before `∀ a : A`, in order to do `induction` and keep `ih` with `∀ a : A`

- The *base case* is easy to prove
- In *inductive step*, after `rewrite ih`, we need to prove

```lean
⊢ snoc (revaux as' [a']) a = revaux as' [a', a]
```

- This is quite similar to the **lemma itself**. So we could find a more **general version** of this lemma, which would be the following. This is much more easier to prove, so I skip the steps here.
```lean
lemma snoc_revaux_lem2 : ∀ as bs : list A, ∀ a : A, 
  snoc (revaux as bs) a = revaux as (snoc bs a) := sorry,
```

Here are the full proof of mine.
```lean
lemma snoc_revaux_lem2 : ∀ as bs : list A, ∀ a : A, 
						 snoc (revaux as bs) a = revaux as (snoc bs a) :=
begin
  assume as,
  induction as with a' as' ih,
    assume bs a,
    dsimp [revaux, snoc],
    refl,
    -------------
    assume bs a,
    dsimp [revaux, snoc],
    rewrite ih,
    refl,
end

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
    rewrite snoc_revaux_lem2,
    dsimp [snoc],
    refl,
end
```

Here are two chanllenging exercises in [tu07](../Tutorials/tu07.lean)

```lean
theorem rev_append : 
  ∀ l m : list A, rev l ++ rev m = rev (m ++ l) :=
```

*The key point is which list to use `induction` on*.

- If we use `induction m`, in the inductive step we would get the following
- We could not `rewrite ih` since `a :: as` is on the RHS of `rev`

```lean
ih: rev as ++ rev m = rev (m ++ as)
⊢ snoc (rev as) a ++ rev m = rev (m ++ a :: as)
```

- But if we do `induction l`, the inductive step would be the following
- So we only need to `rewrite ih` and prove the goal as a new *lemma*
```lean
ih: rev l ++ rev as = rev (as ++ l)
⊢ rev l ++ snoc (rev as) a = snoc (rev (as ++ l)) a
```

Here is the full proof:
```lean
lemma rev_append_lem : ∀ as bs : list A, ∀ a : A, 
  as ++ snoc bs a = snoc (as ++ bs) a :=
begin
  assume as bs a,
  induction as with a' as' ih,
    dsimp [rev, snoc, (++)],
    refl,
    ----------
    dsimp [rev, snoc, (++)],
    rewrite ih,
end

theorem rev_append : 
  ∀ l m : list A, rev l ++ rev m = rev (m ++ l) :=
begin
  assume l m,
  induction m with a as ih,
    dsimp [rev, (++)],
    rewrite app_rneutr,
    -------------
    dsimp [rev, (++)],
    rewrite← ih,
    apply rev_append_lem,
end
```

---
The second one is here. Since it is more complicated, I'll just leave it empty here. plz refer to [tu07](../Tutorials/tu07.lean)
```lean
theorem rev_app : ∀ as bs : list A, rev as ++ bs = rev (rev bs ++ as) :=
begin
  sorry,
end
```

## 7.4 Functors and Naturality

We could apply a function to every element of the list

```lean
def map_list : (A → B) → list A → list B
| f [] := []
| f (a :: as) := (f a) :: (map_list f as)
```

There are two basic ingredients of the function type:
```lean
def id : A → A | a := a 

def comp : (B → C) → (A → B) → A → C
| g f a := g (f a)
```

Notably, we write `f ∘ g` for the composition of f and g
```lean
notation (name := comp) f ∘ g := comp f g 
```

There are some basic equations involving `id` and `circ` namely:
```lean
theorem idl : ∀ f : A → B, id ∘ f = f := sorry

theorem idr : ∀ f : A → B, f ∘ id = f := sorry

theorem assoc : ∀ h : C → D, ∀ g : B → C,
  ∀ f : A → B, (h ∘ g) ∘ f = h ∘ (g ∘ f) := sorry
```

It's like a *monoid*, it is NOT really a monoid since there isn’t one fixed type on which the operations are defined, like `0` for addition and `1` for multiplication. This structure is called a *category*.

But how to prove *functions*? There is a given tactic in lean called `funext`. If we wanna prove `f g : A → B, f = g`, and we `apply funext`, then we need to prove `∀ a : A, f a = g a`

And here are the proofs.

```lean
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
```

Now we look back to `map_list`

```lean
theorem map_id : map_list (@id A) = id := sorry

theorem map_comp : ∀ g : B → C, ∀ f : A → B,
  map_list (g ∘ f) = (map_list g) ∘ (map_list f) := sorry
```

## 7.5 Insertion sort

Now we going to look at a easily-implement sort algorithm: *insertion sort*. We only discuss about lists of natural numbers here.

We assume the following is decidable:
```lean
lemma Le2leb : ∀ m n : ℕ, m ≤ n → leb m n = tt := sorry
lemma leb2Le : ∀ m n : ℕ, leb m n = tt → m ≤ n := sorry
lemma leb_inverse : ∀ m n : ℕ, leb m n = ff → leb n m = tt := sorry
```

### 7.5.1 Implementing sort

Our goal is to implement function `sort`, but before that, we need to implement a function `insert`

```lean
def insert : ℕ → list ℕ → list ℕ
| m [] := [m]
| m (n :: ns) := if (leb m n) then m :: (n :: ns)
               				  else n :: (insert m ns)
```

We could rewrite a function `ite` to implement `if-then-else`:

```lean
def ite : bool → A → A → A
| tt a b := a
| ff a b := b

local notation (name := ite) 
  if x then a else b := ite x a b
```

Now we could implement function `sort` recursively
```lean
def sort : list ℕ → list ℕ 
| [] := []
| (n :: ns) := insert n (sort ns)
```

### 7.5.2 Specifying sort
To verify that the algorithm indeed sorts we need to define a predicate `Sorted : list ℕ → Prop`. 

To define this, we also need an auxiliary predicate which tells us that **an element we want to add to a sorted list is smaller than the first element of the list** `Le_list : ℕ → list ℕ → Prop`.

To define these, we are going to use *inductive definitions of predicates* which are similar to *inductive datatypes* like *bool*. The basic idea is that we state some rules how to prove the predicate, just like we used *constructors* for inductive types like `zero, succ` or `nil, cons`. We also presume that using those rules is the only way to prove the predicate.

```lean
inductive Le_list : ℕ → list ℕ → Prop 
| le_nil : ∀ n : ℕ , Le_list n []
| le_cons : ∀ m n : ℕ, ∀ ns : list ℕ, 
			m ≤ n → Le_list m (n :: ns)
```

>   This means, if the list is empty, then any element `n` could fit. Otherwise, if `n` is smaller than the head of the list, it is ok too.

We could also `invert` le_cons:

```lean
lemma le_cons_inv : ∀ m n : ℕ, ∀ ns : list ℕ,
  Le_list m (n :: ns) → m ≤ n :=
begin
  assume m n ns h,
  cases h with _ _ _ _ mn,
  exact mn
end
```

- We are using `cases` here.
- The idea is that using `le_nil` and `le_cons` are the *only* way to prove `Le_list`.
- The definition of `Le_list` is not recursive, hence `cases` is sufficient.

However, the definition of `Sorted` is actually recursive

```lean
inductive Sorted : list ℕ → Prop 
| sorted_nil : Sorted [] 
| sorted_cons : ∀ n : ℕ, ∀ ns : list ℕ,
    			Sorted ns → Le_list n ns → Sorted (n :: ns)
```


### 7.5.3 Verifying sort

Now we wanna prove that our function `sort` sorts.

```lean
theorem sort_sorts : ∀ ns : list ℕ, Sorted (sort ns) :=
begin
  assume ns,
  induction ns with n ns' ih,
    dsimp [sort],
    apply sorted_nil,
    --------
    dsimp [sort],
    sorry,
end
```

- The *base case* is easy to prove
- In the *inductive step*, we need to prove 
```lean
ih: Sorted (sort ns')
⊢ Sorted (insert n (sort ns'))
```

So we consider `sort ns'` as a **new list** and try to prove the following lemma:

```lean
lemma insert_lem : ∀ ns : list ℕ, ∀ n : ℕ,
  Sorted ns → Sorted (insert n ns) := sorry
```

To prove this lemma, we have two choices
- do `induction` over list `ns`
- derivation of `Sorted ns`
- The first one is easier

In the *base case*, we need to prove:

```lean
h: Sorted nil
⊢ Sorted [n]
```

It is easy to show that **singletons** are always sorted:
```lean
lemma sorted_sgl : ∀ n : ℕ, Sorted [n] :=
begin
  assume n,
  apply sorted_cons,
    apply sorted_nil,
    ---------
    apply le_nil,
end
```

The *inductive step* is more difficult:

```lean
h: Sorted (n' :: ns')
⊢ Sorted (if leb n n' then n :: n' :: ns' else n' :: insert n ns')
```

There are two cases: `n ≤ n'` or `n > n'`. So we do `cases` to split it two `leb n n' = ff` and `leb n n' tt`. Case `leb n n' tt` is quite easy to prove, so we just focus on `leb n n' ff`. 

We do `dsimp [ite]` and we would have:

```lean
ih: ∀ (n : ℕ), Sorted ns' → Sorted (insert n ns')
h: Sorted (n' :: ns')
⊢ Sorted (n' :: insert n ns')
```

Firstly we `apply sorted_cons` to split the goal into

```lean
ih: ∀ (n : ℕ), Sorted ns' → Sorted (insert n ns')
h: Sorted (n' :: ns')
hh: leb n n' = ff
⊢ Sorted (insert n ns')

ih: ∀ (n : ℕ), Sorted ns' → Sorted (insert n ns')
h: Sorted (n' :: ns')
hh: leb n n' = ff
⊢ Le_list n' (insert n ns')
```

- To prove `Sorted (insert n ns')`
- we could `apply ih` to change the goal into `Sorted ns'`
- Since we have `h: Sorted (n' :: ns')`, by `sorted_cons` we know it's `Sorted ns' → Le_list n' ns' → Sorted (n' :: ns')`

Here we do `cases` to deal with `h`, and here is the reason
- `h: Sorted (n' :: ns')`
- If we do `cases h`, it would split into `sorted_nil` and `sorted_cons`
- Just like if we do cases `n` of Natural numbers, it would split into `zero` and `succ n`
- However, here *Lean* knows that `ns'` is not empty, so it would only display the case of `sorted_cons`
- `_` is just placeholders for variables we don't need

However, `Le_list n' (insert n ns')` is not easy to be directly proved. There are three natural numbers, `n'`, `n` and the head of `ns`. So we need another lemma:

```lean
lemma insert_lem_le_list : ∀ m n : ℕ, ∀ ns : list ℕ, 
  n ≤ m → Le_list n ns → Le_list n (insert m ns) := sorry
```

Instead of `induction ns`, this time we use `cases ns with hd tl`
- Note that, `induction` and `cases` simply do the same thing
- But `induction` gives us `ih`, therefore it is more powerful
- We should use `cases` if there's no need for `ih` to prove the problem


- The *base case* is easy to prove
- In the *inductive step*, we do `cases hh : (leb m hd)` and then `dsimp [ite]`
- And it's over

Back to prove `Le_list n' (insert n ns')`, we apply the lemma above and we have the two goals again

```lean
ih: ∀ (n : ℕ), Sorted ns' → Sorted (insert n ns')
h: Sorted (n' :: ns')
hh: leb n n' = ff
⊢ n' ≤ n

ih: ∀ (n : ℕ), Sorted ns' → Sorted (insert n ns')
h: Sorted (n' :: ns')
hh: leb n n' = ff
⊢ Le_list n' ns'
```

They are not difficult to prove, but to make our life easier, we may need the three lemmas [above](#75-insertion-sort).

---

And here is the whole proof, which you could find in [lec16](../Lecture%20Code/lec16.lean)

```lean
lemma sorted_sgl : ∀ n : ℕ, Sorted [n] :=
begin
  assume n,
  apply sorted_cons,
    apply sorted_nil,
    ---------
    apply le_nil,
end

lemma insert_lem_le_list : ∀ m n : ℕ, ∀ ns : list ℕ, 
  n ≤ m → Le_list n ns → Le_list n (insert m ns) :=
begin
  assume m n ns h1 h2,
  cases ns with hd tl,
    dsimp [insert],
    apply le_cons,
    assumption,
    ----------
    dsimp [insert],
    cases hh: (leb m hd),
      dsimp [ite],
      apply le_cons,
      cases h2 with _ _ _ _ nhd,
      assumption,
      ----------
      dsimp [ite],
      apply le_cons,
      assumption,
end

lemma insert_lem : ∀ ns : list ℕ, ∀ n : ℕ,
  Sorted ns → Sorted (insert n ns) :=
begin
  assume ns,
  induction ns with n' ns' ih,
    assume n h,
    dsimp [insert],
    apply sorted_sgl,
    -----------
    assume n h,
    dsimp [insert],
    cases hh : (leb n n'),
      dsimp [ite],
      apply sorted_cons,
        apply ih,
        cases h with _ _ h1 h2,
        assumption,
        ----------
        apply insert_lem_le_list,
          apply leb2Le,
          apply leb_inverse,
          assumption,
          --------
          cases h with _ _ h1 h2,
          assumption,
      --------
      dsimp [ite],
      apply sorted_cons,
        assumption,
        ----------
        apply le_cons,
        apply leb2Le,
        assumption,
end

theorem sort_sorts : ∀ ns : list ℕ, Sorted (sort ns) :=
begin
  assume ns,
  induction ns with n ns' ih,
    dsimp [sort],
    apply sorted_nil,
    --------
    dsimp [sort],
    apply insert_lem,
    assumption,
end
```

### 7.5.4 Permutations

Now we introduce the relation `Perm` which takes two lists `as bs` and returns the proposition that *`as` is a permutation of `bs` inductively*.

We do this using an auxiliary relation `Insert` which takes an element `a` and two lists `as bs` and returns the proposition that `bs` could be obtained by inserting `a` to anywhere of `as`.

```lean
inductive Insert : A → list A → list A → Prop 
| insert_hd : ∀ a : A, ∀ as : list A, Insert a as (a :: as)
| insert_tl : ∀ a b : A, ∀ bs abs : list A, 
    		  Insert a bs abs → Insert a (b::bs) (b::abs)

inductive Perm : list A → list A → Prop 
| perm_nil : Perm [] []
| perm_cons : ∀ a : A, ∀ as bs bs' : list A,
    		  Perm as bs → Insert a bs bs' → Perm (a :: as) bs' 
```

The base case of `Insert` is to insert `a` at the head of `as` to obtain `bs`. 

Here is an example:
```lean
example : Insert 4 [2, 8, 0] [2, 8, 4, 0] :=
begin
  apply ins_tl,
  apply ins_tl,
  apply ins_hd,
end
```

The base case of `Perm` is two empty lists. `bs'` is `bs` inserted with `a`, and `bs` is `bs'` without `a`.

Here is an example:

```lean
example : Perm [3, 9, 1] [9, 1, 3] :=
begin
  apply perm_cons 3 [9,1] [9,1] [9,1,3],
    apply perm_cons 9 [1] [1] [9,1],
      apply perm_cons 1 [] [] [1],
        apply perm_nil,
        ----------
        apply ins_hd,
      ----------
      apply ins_hd,
    --------
    apply ins_tl,
    apply ins_tl,
    apply ins_hd,
end
```

Now let's try to prove some theorems, but before that, **remember this:**

```lean
open Insert Perm
```

There are three properties of `Perm`, which are mentioned in [ex08](../CW/ex08.lean). The first one is easy to prove, but the rest two are difficult and I haven't try yet, so I just leave them blank here.

```lean
theorem refl_perm : ∀ as : list A, Perm as as := sorry
theorem sym_perm : ∀ as bs : list A, Perm as bs → Perm bs as := sorry
theorem trans_perm : ∀ as bs cs : list A,
  Perm as bs → Perm bs cs → Perm as cs := sorry
```

We could also prove `Perm` works for `sort` and `rev`, the proofs are much simpler compared to `sort_sorts`. 

```lean
lemma perm_sort_lem : ∀ ns : list ℕ, ∀ a : ℕ,
  Insert a ns (insert a ns) :=
begin
  assume ns,
  induction ns with n ns' ih,
    assume a,
    dsimp [insert],
    apply insert_hd,
    -----------
    assume a,
    dsimp [insert],
    cases hh : (leb a n),
      dsimp [ite],
      apply insert_tl,
      apply ih,
      ------------
      dsimp [ite],
      apply insert_hd,
end

theorem perm_sort : ∀ l : list ℕ, Perm l (sort l) :=
begin
  assume l,
  induction l with a as ih,
    dsimp [sort],
    apply perm_nil,
    -----------
    dsimp [sort],
    apply perm_cons,
      assumption,
      ------------
      apply perm_sort_lem,
end
```

```lean
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
```

Here is an interesting example from [tu08](../Tutorials/tu08.lean)

```lean
example : Insert 0 [2,3] [2,3,4] → false :=
begin
  assume h,
  cases h with _ _ _ _ _ _ h1,
  cases h1 with _ _ _ _ _ _ h2,
  cases h2,
end
```

