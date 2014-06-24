/*  Group 15
    Worksheet 29
    BST.c - Definitions for binary search tree */

#include "BST.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void initBST(struct BinarySearchTree *tree){ 
    tree->size = 0; 
    tree->root = 0;
}

void addBST(struct BinarySearchTree *tree, TYPE newValue){
    tree->root = _nodeAddBST(tree->root, newValue); 
    tree->size++; 
}

int sizeBST (struct BinarySearchTree *tree){ 
    return tree->size; 
}

struct Node * _nodeAddBST (struct Node *current, TYPE newValue){
    struct Node * newNode;

    if(current == 0){        //If current node is empty
        //Create Node (in memory) and assert
        newNode = (struct Node *) malloc(sizeof(struct Node));
        assert(newNode != 0);
        
        //Initialize newNode
        newNode->value = newValue;
        newNode->left = 0;
        newNode->right = 0;
        
        return newNode;
    }
    else if(LT(newValue, current->value))
        current->left = _nodeAddBST(current->left, newValue);   //Set left node to newValue
    else
        current->right = _nodeAddBST(current->right, newValue); //Set right node to newValue

    return current;     //Return reference to location of newNode
}

int containsBST (struct BinarySearchTree *tree, TYPE d){
    struct Node * current = tree->root;

    while(current != 0){    //Continue searching until node is set to Null
        if(current->value == d)
            return 1;
        else if(LT(d, current->value))
            current = current->left;    //Move to left child (less than)
        else
            current = current->right;   //Move to right child (greater than)
    }

    return 0;
}

void removeBST (struct BinarySearchTree *tree, TYPE d){
    if (containsBST(tree, d)){
        tree->root = _nodeRemoveBST(tree->root, d);
        tree->size--;
    }
}

/* return value of leftmost child of current node */
TYPE _leftMostChild (struct Node * current){
    while(current->left != 0)       //Continue searching until leftmost child
        current = current->left;

    return current->value;      //Value of leftmost child
}

/*  Return tree with leftmost child removed */
struct Node * _removeLeftmostChild (struct Node *current){
    struct Node * lastNode = 0,   //This will be the parent of the currNode
                * currNode = current;
    
    assert(current != 0);

    /* Locate leftmost node to current */
    while(currNode->left != 0){     
        lastNode = current;         //Parent of currNode
        currNode = currNode->left;  //Leftmost node of current
    }
    
    /*  The leftmost child may have children to the right - save them by 
        pointing parent of leftmost's left-pointer to the right child of 
        the leftmost child. */
    if(currNode->right != 0){
        if(lastNode != 0)
            lastNode->left = currNode->right;    //Save children to the right
        else
            lastNode = currNode->right;     //Save children to the right
        
        return lastNode;
    }
    else if(current != currNode){
        /* Clear Node values and free memory */
        currNode->value = 0;
        currNode->left = 0;
        currNode->right = 0;
        free(currNode);
        current->left = 0;

        return current;
    }
    
    return 0;
}

/*  Locates and returns node with value d using recursion 
    When node is located, it moves the value of the 
    leftmost child (of right or left child, depending on 
    comparison) to replace the node containing value d 
    and removes the leftmost child from the subtree 
    of the node containing value d. */
struct Node * _nodeRemoveBST (struct Node * current, TYPE d){
    if(current->value == d){            //Base Case
        if(current->right == 0)
            return current->left;
        else{
            /* Copy lowest child to current */
            current->value = _leftMostChild(current->right);    
            /* Set right child to subtree with lowest child removed */
            current->right = _removeLeftmostChild(current->right);  
        }
    }
    else if(LT(d, current->value))
        current->left = _nodeRemoveBST(current->left, d);   //Less than == left
    else
        current->right = _nodeRemoveBST(current->right, d); //Greater than == right

    return current;
}

/* Free all nodes in BST, including root node */
void freeBST(struct BinarySearchTree *tree){
    while(tree->root != 0)
		removeFirst(tree);

    assert(tree->size == 0);     //Confirm no more elements in BST
}

/* Returns the lowest element in tree */
TYPE getFirst(struct BinarySearchTree *tree){
    struct Node * current = tree->root;

    while(current->left != 0)
    current = current->left;

    return current->value;
}

/* Removes the lowest element in tree */
void removeFirst(struct BinarySearchTree *tree){
    removeBST(tree, getFirst(tree));
}

/*  Outputs BST elements in order from lowest to highest.
    NOTE: This function removes all elements in tree. */
void outputPriorityQueue(struct BinarySearchTree *tree){
	while(tree->root != 0){
		printf("%d\n", getFirst(tree));
		removeFirst(tree);
	}

    assert(tree->size == 0);
}

/* Boolean return on the equivalency of two BST's */
int equalsBST(struct BinarySearchTree *tree1, struct BinarySearchTree *tree2){
    TYPE tree1curr, tree2curr;
    
    if(tree1->size != tree2->size)      //If size !=, then BST's are not equal
        return 0;

    /*  The getFirst function fails when size == 0.  However, two BST's with
        size zero are equal. */
    if((tree1->size == 0) && (tree2->size == 0))
        return 1;
    else{
        tree1curr = getFirst(tree1);
        tree2curr = getFirst(tree2);
    }

    /*  Destructive comparison of values in each BST.  Returns true when all
        values have been compared (i.e, size == 0)  */
    while(tree1curr == tree2curr){
	    if((tree1->size == 0) && (tree2->size == 0))
            return 1;
        else{
            removeFirst(tree1);
            removeFirst(tree2);
            
            /* getFirst fails when size == 0 */
            if((tree1->size != 0) && (tree2->size != 0)){
                tree1curr = getFirst(tree1);
                tree2curr = getFirst(tree2);
            }
        }
    }

    return 0;
}