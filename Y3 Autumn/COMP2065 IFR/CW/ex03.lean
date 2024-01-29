/-
COMP2065-IFR Exercise 03
(Predicate logic) (20)

    This exercise has 2 parts. 
    
    The first part is multiple choice and your task is to 
    translate english to predicate logic.
    
    In the 2nd part we play logic poker again :-) but this time for
    predicate logic. 

-/

-- part 1 (10)
namespace family

-- Given the following type, predicates and relations:

constant People : Type
constants Male Female : People → Prop
-- Male x means x is male
-- Female x means x is female
constant Parent : People → People → Prop
-- Parent x y means x is a parent of y
constant Married : People → People → Prop
-- Married x y means x is married to y

/- --- Do not add/change anything above this line --- -/

/-
The following questions are all mutiple choice and there is 
exactly one correct answer. You get 2 points for each correct answer.

To answer, replace 'sorry' by the number of the correct definition (1-5).

DO NOT modify any of the provided definitions.

For example:

Q0 : How do we translate
"Everybody is equal to themself"
into predicate logic?
-/
def Self_Equal_1 : Prop := false
def Self_Equal_2 : Prop := false
def Self_Equal_3 : Prop := ∀ x : People, x = x
def Self_Equal_4 : Prop := false
def Self_Equal_5 : Prop := false

def answer0 : ℕ := 3


/- Q1 : How do we translate
"x is the grandmother of y"
into predicate logic -/

def Grandmother_1 (x y z : People) : Prop
:= Female x ∧ Parent x z ∧ Parent z y
def Grandmother_2 (x y z : People) : Prop
:= Female x ∧ Parent x z → Parent z y
def Grandmother_3 (x y : People) : Prop
:= Female x ∧ ∃ z : People , Parent x z ∧ Parent z y
def Grandmother_4 (x y : People) : Prop
:= Female x ∧ ∀ z : People , Parent x z → Parent z y
def Grandmother_5 (x y : People) : Prop
:= ∀ z : People , Female z ∧ Parent x z → Parent z y

def answer1 : ℕ := 3


/- Q2 : How do we translate
"Everybody has got a mother."
into predicate logic ?
-/
def every_mother_1 : Prop
:= ∀ x : People , ∃ y : People , Female y ∧ Parent y x 
def every_mother_2 : Prop
:= ∀ x y : People , Female y → Parent y x 
def every_mother_3 : Prop
:= ∃ x : People , ∀ y : People , Female y → Parent y x 
def every_mother_4 : Prop
:= ∀ x : People , ∃ y : People , Parent y x → Female y 
def every_mother_5 : Prop
:= ∀ x : People , ∀ y : People , Female y ∧ Parent y x 

def answer2 : ℕ := 1


/- Q3 : How do we translate
"Nobody is married to themselves."
into predicate logic ?
-/

def self_married_1 : Prop
:= ¬ ∀ x : People , Married x x
def self_married_2 : Prop
:= ∃  x : People , ¬ Married x x
def self_married_3 : Prop
:= ∀ x : People , Married x x ∧ x ≠ x
def self_married_4 : Prop
:= ∀ x : People , ¬ Married x x
def self_married_5 : Prop
:= ∀ x y : People , x≠y → Married x y

def answer3 : ℕ := 4


/- Q4 : How do we translate
"Everybody is married at most to one other person."
into predicate logic ?
-/
def no_bigamy_1 : Prop
:= ∀ x : People , ∀ y z : People, Married x y ∧ Married x z ∧ x ≠ z  
def no_bigamy_2 : Prop
:= ∀ x : People , ∀ y z : People, Married x y → Married x z → y = z  
def no_bigamy_3 : Prop
:= ∀ x : People , ∃ y : People, Married x y ∧ y = y  
def no_bigamy_4 : Prop
:= ∀ x : People , ∀ y : People, Married x y → x ≠ y  
def no_bigamy_5 : Prop
:= ∀ x : People , ∃ y z : People, x ≠ y ∧ Married x y ∧ Married x z  

def answer4 : ℕ := 2


/- Q5 : How do we translate
"x is the sibling of y"
into predicate logic ?
-/
def Sibling_1 (x y : People) : Prop
  := x ≠ y ∧ ∀ z : People , Parent z x ∧ Parent z y 
def Sibling_2 (x y : People) : Prop
  := x ≠ y ∧ ∃ z : People , Parent z x ↔ Parent z y 
def Sibling_3 (x y z : People) : Prop
  := x ≠ y ∧ Parent z x ↔ Parent z y 
def Sibling_4 (x y z : People) : Prop
  := x ≠ y ∧ Parent z x ∧ Parent z y 
def Sibling_5 (x y : People) : Prop
  := x ≠ y ∧ ∀ z : People , Parent z x ↔ Parent z y 

def answer5 : ℕ := 5




/- DO NOT MODIFY OR DELETE -/ 
/- -/ end family                  
/- -/ namespace poker
/- -/ variable A : Type
/- -/ variables PP QQ : A → Prop
/- -/ variables RR : A → A → Prop
/- -/ variables P Q R : Prop
/- -/ inductive PokerAnswer : Type
/- -/ | NotProvable : PokerAnswer
/- -/ | Intuition : PokerAnswer
/- -/ | Classical : PokerAnswer
/- -/ open PokerAnswer
/- -/ open classical
/- -/ theorem raa : ¬ ¬ P → P := 
/- -/ begin
/- -/   assume nnp,
/- -/   cases (em P) with p np,
/- -/     exact p,
/- -/     have f : false,
/- -/       apply nnp,
/- -/       exact np,
/- -/     cases f,
/- -/ end
/- DO NOT MODIFY OR DELETE -/


/-
PART 2 (10 points)
We play the game of logic poker - but this time with predicate logic :-)

You have to classify each proposition as either
  a) provable intuitionistically (i.e. in plain lean)
  b) provable classically (using em : P ∨ ¬ P or raa : ¬¬ P → P).
  c) not provable classically.
and then you have to prove the propositions in a) and b) accordingly.

You will start with a score of 10 points, and then 1 point will be deducted
for each incorrect classification and 1 point will be deducted for each
incorrect proof. We stop deducting at zero, so you cannot earn negative points.
So, for instance, if you do every proof correctly but do not classify anything,
you will earn 0/10.

CLASSIFICATION: For each proposition, replace sorry with
  Intuition     if the proposition is provable intuitionistically (i.e. in plain lean)
  Classical     if the proposition is provable classically (using em : P ∨ ¬ P or raa : ¬¬ P → P)
  NotProvable   if the proposition is not provable classically

**Important**: Every classification should be one of these three, or sorry. 
DO NOT put anything else on the right-hand side or leave it totally blank.

PROOFS: 
  Then, prove the propositions you classified as 'Intuition' or 'Classical'. 
  For the 'Classical' ones, you may use em or raa, as discussed in lecture.
  For propositions classified as 'NotProvable' just keep "sorry," as the proof.

  You are only allowed to use the tactics introduced in the lecture
  (e.g. assume, exact, apply, constructor, cases, left, right, have,
  existsi, reflexivity, rewrite)

  Please only use the tactics in the way indicated in the lecture notes,
  otherwise we may deduct points.
-/

def classification01 : PokerAnswer := NotProvable
theorem q01 : (∀ x : A, ∃ y : A , RR x y) → (∃ y : A, ∀ x : A, RR x y) :=
begin 
  sorry,
end

def classification02 : PokerAnswer := Intuition
theorem q02 :  (∃ y : A, ∀ x : A, RR x y) → (∀ x : A, ∃ y : A , RR x y) :=
begin 
  assume rr a,
  cases rr with b rra,
  existsi b,
  apply rra,
end

def classification03 : PokerAnswer := Intuition
theorem q03 : ∀ x y : A, x = y → RR x y → RR x x :=
begin 
  assume x y xy rr,
  rewrite← xy at rr,
  assumption,
end

def classification04 : PokerAnswer := NotProvable
theorem q04 : ∀ x y z : A, x ≠ y → x ≠ z → y ≠ z :=
begin 
  sorry,
end

def classification05 : PokerAnswer := Intuition
theorem q05 : ∀ x y z : A, x = y → x ≠ z → y ≠ z :=
begin 
  assume x y z xy xz,
  rewrite← xy,
  assumption,
end

def classification06 : PokerAnswer := Classical
theorem q06 : ∀ x y z : A, x ≠ y → (x ≠ z ∨ y ≠ z) :=
begin 
  assume x y z nxy,
  cases em (x = z) with xz nxz,
    right,
    assume yz,
    apply nxy,
    rewrite xz,
    rewrite yz,
    -------------------
    left,
    assumption,
end

def classification07 : PokerAnswer := Intuition
theorem q07 : ¬ ¬ (∀ x : A, PP x) → ∀ x : A, ¬ ¬ PP x :=
begin 
  assume nnpp x nppx,
  apply nnpp,
  assume pp,
  apply nppx,
  apply pp,
end

def classification08 : PokerAnswer := Classical
theorem q08 : (∀ x : A, ¬ ¬ PP x) → ¬ ¬ ∀ x : A, PP x :=
begin 
  assume nnpp npp,
  apply npp,
  assume x,
  apply raa,
  apply nnpp,
end

def classification09 : PokerAnswer := NotProvable
theorem q09 : (∃ x : A, true) → (∃ x:A, PP x) → ∀ x : A,PP x :=
begin 
  sorry,
end


def classification10 : PokerAnswer := Classical
theorem q10 : (∃ x : A, true) → (∃ x:A, (PP x → ∀ x : A,PP x)) :=
begin
  assume t,
  cases t with a tt,
  cases em (∀ x:A, PP x) with h nh,
    existsi a,
    assume ppa,
    assumption,
    -------------
    have dm : ∃ x:A, ¬ PP x,
      apply raa,
      assume npp,
      apply nh,
      assume b,
      apply raa,
      assume ppb,
      apply npp,
      existsi b,
      assumption,
    cases dm with b nppb,
    existsi b,
    assume ppb,
    have efq : false → (∀ x:A, PP x),
      assume f,
      cases f,
    apply efq,
    apply nppb,
    assumption,
end


--- Do not add/change anything below this line ---
end poker
