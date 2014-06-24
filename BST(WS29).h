/*  Group 15
    Worksheet 29
    BST.h - Definitions for binary search tree */

#ifndef BST
#define TYPE int 
#define EQ(a, b) (a == b)
#define LT(a, b) (a < b)
#define GT(a, b) (a > b)    //Note necessary, but the videos imply that we should add them
#endif

struct Node {
    TYPE value;
    struct Node * left;
    struct Node * right;
};

struct BinarySearchTree {
    struct Node *root;
    int size;
};

void initBST(struct BinarySearchTree *tree);
void addBST(struct BinarySearchTree *tree, TYPE newValue);
int sizeBST (struct BinarySearchTree *tree);
struct Node * _nodeAddBST (struct Node *current, TYPE newValue);
int containsBST (struct BinarySearchTree *tree, TYPE d);
void removeBST (struct BinarySearchTree *tree, TYPE d);
TYPE _leftMostChild (struct Node * current);
struct Node * _removeLeftmostChild (struct Node *current);
struct Node * _nodeRemoveBST (struct Node * current, TYPE d);
void freeBST(struct BinarySearchTree *tree);
TYPE getFirst(struct BinarySearchTree *tree);
void removeFirst(struct BinarySearchTree *tree);
void outputPriorityQueue(struct BinarySearchTree *tree);
int equalsBST(struct BinarySearchTree *tree1, struct BinarySearchTree *tree2);