# Splay Trees

A Splay Tree is an efficient implementation of a balanced binary search tree that takes advantage of locality in the keys used in upcoming lookup requests.

### Splay Trees are self-balancing BSTs

A self-balancing BST is any node-based BST that automatically keeps its height (maximum number of levels below the root) small in the face of arbitrary item insertions and deletions. Non-balanced BSTs are referred to as being skewed. Depending on which side of the root has a greater depth, the tree may be either right-skewed or left-skewed.

To be specific, splay trees are **roughly balanced**. By nature of the tree's splaying property, splay trees can balance themselves through random access. However, there is no guarantee that the final tree structure will be balanced.

### Purpose of a Splay Tree

_The main idea of a splay tree is to bring the most recently accessed key and its associated node to the root of the tree, making the node easily accessible in case it needs to be used again._

This principle refers to Locality of Reference, in which a program has the tendency to access instructions whose addresses are near to each other. In the case of splay trees, the program looks for elements that are accessed at a higher frequency.

By accessing the same elements frequently, they will be found further up (close to the root) on the tree, thus decreasing the time needed to search for those elements again. As a result, splay trees offer better performace compared to AVL and Red-Black trees when implemented in _practical situations_. Such situations involve implementing cache memory and mapping network routers.

### Time Complexity

Splay trees can perform operations such as search and insert in O(log n) time.

### Operations

The search and insert operations follow the standard binary tree operations, but every step is followed by a splaying operation.

To splay a tree is to perform a tree rotation that moves the key and its associated node to the root. There are several types of rotations depending on where the key is positioned in the tree.

#### Zig Rotation

If the key is to the left of a parent node, perform a right rotation.

#### Zag Rotation

If the key is to the right of a parent node, perform a left rotation.

#### Zig-zig Rotation

If the key is to the left of both a parent node and a grandparent node, perform two zig rotations.

#### Zag-zag Rotation

If the key is to the right of both a parent node and a grandparent node, perform two zag rotations.

#### Zig-zag Rotation

If the key is to the left of a parent node and to the right of a grandparent node, perform a zig rotation then a zag rotation.

#### Zag-zig Rotation

If the key is to the right of a parent node and to the left of a grandparent node, perform a zag rotation then a zig rotation.


### Cases

The type of rotation to use when splaying depends on different cases:

#### Case 1: The key is in the root node

No rotations required; the key can be accesssed in O(1) time.

#### Case 2: The key is the child of the root node
######      - Subcase 1: Left child

Use zig rotation.

######      - Subcase 2: Right child

Use zag rotation.

#### Case 3: The key has a grandparent that is a root

######      - Subcase 1: Left of parent, left of grandparent

Use zig-zig rotation.

######      - Subcase 2: Left of parent, right of grandparent

Use zig-zag rotation.

######      - Subcase 3: Right of parent, right of grandparent

Use zag-zag rotation.

######      - Subcase 4: Right of parent, left of grandparent

Use zag-zig rotation.

# References

Splay Tree Search: https://www.geeksforgeeks.org/splay-tree-set-1-insert/

Splay Tree Insertion: https://www.geeksforgeeks.org/insertion-in-splay-tree/?ref=rp

Splay Tree Cornell CS: https://www.cs.cornell.edu/courses/cs3110/2013sp/recitations/rec08-splay/rec08.html

Locality of Reference: https://www.geeksforgeeks.org/locality-of-reference-and-cache-operation-in-cache-memory/#:~:text=Locality%20of%20reference%20refers%20to,addresses%20are%20near%20one%20another.

Intro to Splay Trees [Video]: https://youtu.be/qMmqOHr75b8

Splay Tree Insertion [Video]: https://youtu.be/1HeIZNP3w4A

Amortized Analysis: https://en.wikipedia.org/wiki/Amortized_analysis

Scaler Topics: https://www.scaler.com/topics/data-structures/splay-tree/
