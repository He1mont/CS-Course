# lec08: Trees

## What is a (Rooted) Tree

-   A tree consists of nodes with a parent-child relation (**at most one parent**!)
-   As data structures
    -   Heaps
    -   Seach trees

**Terminology**

-   **Root**: node without parent (A)
-   **Internal node**: node with at **least one child** (A, B, C, F)
-   **External node** (a.k.a. **leaf** ): node without children (E, I, J, K, G, H, D)
-   **Ancestors** of a node: parent, grandparent, grand-grandparent, etc.
-   **Depth** of a node: number of ancestors (**not counting itself**)
-   **Height** of a tree: **maximum depth** of any node
-   **Descendant** of a node: child, grandchild, grand-grandchild, etc.
-   **Subtree**: tree consisting of a node and its descendants

<img src="assets/Screenshot 2024-02-26 at 14.23.06.png" alt="Screenshot 2024-02-26 at 14.23.06" style="zoom:50%;" />

## Traversal

>   下面的 Pre-Post-In Order 遍历，指的就是根节点在被遍历时的顺序

### Preorder Traversal 根左右

-   In a preorder traversal, a node is visited **before** its descendants
-   **Application**: print a structured document

```pseudocode
Algorithm preOrder(v) 
	visit(v)
	for each child w of v
		preorder(w)
```

<img src="assets/Screenshot 2024-02-26 at 12.16.51.png" alt="Screenshot 2024-02-26 at 12.16.51" style="zoom:50%;" />

### Postorder Traversal 左右根

-   In a postorder traversal, a node is visited **after** its descendants
-   **Application**: compute **space used by files** in a directory and its subdirectories

```pseudocode
Algorithm postOrder(v) 
	for each child w of v 
		postOrder (w) 
	visit(v)
```



<img src="assets/Screenshot 2024-02-26 at 12.17.13.png" alt="Screenshot 2024-02-26 at 12.17.13" style="zoom:50%;" />

### Inorder Traversal 左根右

-   In an inorder traversal a node is visited after its left subtree and **before its right subtree**

```pseudocode
Algorithm inOrder(v)
	if hasLeft (v) 
		inOrder (left (v)) 
	visit(v) 
	if hasRight (v)
		inOrder (right (v))
```



<img src="assets/Screenshot 2024-02-26 at 12.26.44.png" alt="Screenshot 2024-02-26 at 12.26.44" style="zoom:50%;" />

## Binary Trees

-   A binary tree is a tree with the following **properties**:
    -   Each internal node has **at most two children**
    -   The children of a node are **an ordered pair** - though one might be “missing”
-   We call the children of an internal node **left child** and **right child**
-   Alternative **recursive definition**: a binary tree is either
    -   a tree consisting of a single node, or
    -   a tree whose root has an ordered pair of “children”, each of which is missing (a null) or is the root of a binary tree
-   **Applications**: searching

### **Proper Binary Trees**

-   A proper binary tree is a tree with the following **properties**:
    -   Each internal node has **either two children or no children**
    -   The children of a node are an **ordered pair**
-   We call the children of an internal node left child and right child
-   Alternative recursive definition:
    -   a tree consisting of a single node, or
    -   a tree whose root has an ordered pair of children, each of which is a root of a binary tree
-   **Applications:**
    -   arithmetic expressions
    -   decision processes

**Arithmetic Expression Tree** 

-   **internal nodes**: (binary) operators
-   **external nodes**: operands
-   Example: `(2 * (a - 1) + (3 * b))`

<img src="assets/Screenshot 2024-02-26 at 12.20.46.png" alt="Screenshot 2024-02-26 at 12.20.46" style="zoom:50%;" />

**Decision Tree**

-   **internal nodes**: questions with yes/no answer
-   **external nodes**: decisions
-   Example: dining decision

<img src="assets/Screenshot 2024-02-26 at 12.21.07.png" alt="Screenshot 2024-02-26 at 12.21.07" style="zoom: 33%;" />

**Print Arithmetic Expressions**

-   Specialization of an **inorder traversal**

```pseudocode
Algorithm printExpression(v)
	if hasLeft(v) 
		print("(") 
		printExpression(left(v)) 
	print(v.element()) 
	if hasRight(v) 
		printExpression(right(v)) 
		print(")")
```

**Evaluate Arithmetic Expressions**

-   Specialization of a **postorder traversal**

```pseudocode
Algorithm evalExpr(v)
	if isExternal(v)
		return v.element()
	else
		x = eval(Expr(leftChild(v)))
		y = eval(Expr(rightChild(v)))
		return operator(x, y)
```

## Data Types

### Linked Structure for Binary Trees

-   A node is represented by an object storing
    -   Element
    -   Parent node
    -   Left child node
    -   Right child node

<img src="assets/Screenshot 2024-02-26 at 14.47.33.png" alt="Screenshot 2024-02-26 at 14.47.33" style="zoom: 33%;" />

### Abstract Data Types (ADT)

>   有点像 Java 当中的**抽象类**

-   An abstract data type (ADT) is **an abstraction** of a data structure
-   An **ADT specifies**:

    -   **Data stored**
    -   **Operations** on the data
    -   Error conditions associated with operations
-   An ADT **does not** specify the implementation itself - hence “abstract”

**Example: ADT modeling a simple stock trading system**

-   The data stored are buy/sell orders
-   The **operations** supported are
    -   `order buy(stock, shares, price)`
    -   `order sell(stock, shares, price)`
    -   `void cancel(order)

-   Error conditions:
    -   Buy/sell a nonexistent stock
    -   Cancel a nonexistent order


### Concrete Data Types (CDT)

-   The actual date structure that we use
-   An ADT might be implemented using **different choices** for the CDT
-   The choice of CDT will not be apparent from the interface: “data hiding” “encapsulation” – e.g. see ‘Object Oriented Methods’
    -   The choice of CDT will **affect the runtime and space usage**


### ADT & Efficiency

-   Often the ADT comes with **efficiency requirements**
    -   `cancel(order)` must be $O(1)$
    -   `sell(order)` must be $O(\log(|orders|))$

### Tree ADT

-   We can use “**positions**”, `p`, to abstract nodes
-   **Generic methods**
    -   `int size()`
    -   `bool isEmpty()`
    -   `Iterator iterator()`
    -   `Iterator positions()`
-   **Accessor methods**
    -   `position root()`
    -   `position parent(p)`
    -   `Iterator children(p)`
    
-   **Query methods**
    -   `bool isInternal(p)`
    -   `bool isExternal(p)`
    -   `bool isRoot(p)`
    
-   **Update method**
    -   `object replace(p, o)`
    

### Array-Based Representation of Binary Trees

-   nodes are stored in **an array**
-   Example Implementation
    -   `rank(root) = 1`
    -   **left**: `rank(n) = rank(parent) << 1`  (**left shift**)
    -   **right**: `rank(n) = rank(parent) << 1 + 1` 
    -   Going to the parent is a **right shift**
    -   **This implementation can be very fast**

-   **Advantages**
    -   Saves space as **do not have to store the pointers**
    -   Better memory **locality**


<img src="assets/Screenshot 2024-02-26 at 12.36.24.png" alt="Screenshot 2024-02-26 at 12.36.24" style="zoom:50%;" />

## Properties of perfect binary trees

-   A binary tree is said to be **proper(full)** if every internal node has **exactly 2** children
-   **height**: $h = \log_2(n+1) -1$

<img src="assets/Screenshot 2024-02-26 at 12.46.49.png" alt="Screenshot 2024-02-26 at 12.46.49" style="zoom:50%;" />

-   level (depth) `k` contains `2^k` nodes.
    -   proof by induction on `k`
-   A perfect binary tree of height `h` contains `2^(h+1) - 1`
    -   proof by induction on `h`
-   For a perfect binary tree of size `n`
    -   $n = 2^{h+1} -1$
    -   $h = \log_{2}(n+1) -1$
-   If the tree is **perfect**, the height in size of the tree
    -   $\Theta(\log n)$
-   If **imperfect**, the height is
    -   $\Omega (\log n)$ and $O(n)$