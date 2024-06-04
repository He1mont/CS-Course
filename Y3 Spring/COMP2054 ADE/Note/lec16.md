# lec16: Map ADT: using lists

## Maps

-   A map models a collection of key-value entries that is searchable `by the key`
-   The main operations of a map are for searching, inserting, and deleting items
-   Multiple entries with the **same key** are not allowed
    -   (may be allowed in a ‘multi-map’)

**Map ADT over pairs `<K, V>`**

-   `V get(K k)`:
    -   if the map M has an entry with key k, return its associated value; else, return null
-   `V put(K k, V v)`: 
    -   insert entry `(k, v)` into the map M
    -   if key k is not already in M, then return **null**; 
    -   else, return old value associated with k
-   `V remove(K k)`: 
    -   if the map M has an entry with key k, remove it from M and return its associated value;
    -   else, return null
-   `int size()`, `boolean isEmpty()`
-   `{K} keys()`: return an iterable collection of the keys in M
-   `{V} values()`: return an iterable collection of the values in M
-   `{<K,V>} entries()`: return an iterable collection of the entries in M

**Comparison of MAP with Binary Tree implementations of heaps**

-   Both insert entries based on a key
-   MAP: access any key
-   PQ: access only the minimum key

## A simple list-based map

-   It is straightforward to **implement a map using a list** – either singly or doublylinked.
-   We also store separate **size counter**, `n`, so that `getSize()` is $O(1)$​, and maintain it on adding or removing elements
-   Overall: the operations are $O(n)$ because of needing to **traverse the list**.
-   The unsorted list implementation is suitable only for maps of small size
-   We could use a sorted list, but still $O(n)$
    -   It does not help as we need to be able to access any `k`, not just the **minimum**

### `get(k)` $O(n)$

-   Walk along the list looking for key `k`
-   If find it then return the currently associated value
-   Else return null (or false)

### `put(k,v)` $O(n)$

-   Walk along the list looking for key k
-   If find it then return the currently associated value, and overwrite with the new value v
-   Else insert <k,v> as a node at the end of the list

### `remove(k)` $O(n)$

-   Walk along the list looking for key k
-   If find it then return the currently associated value and remove the node.
-   Else return null/false

