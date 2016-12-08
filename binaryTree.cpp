#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <queue>

typedef struct BinaryTreeNode {
    int data;
    BinaryTreeNode * left;
    BinaryTreeNode * right;
} BinaryTreeNode;

void PreOrder(BinaryTreeNode *root) {
    
    if(root) {
        printf("%d ", root -> data);
        PreOrder(root -> left);
        PreOrder(root -> right);
    }
}

void InOrder(BinaryTreeNode *root) {
    if(root) {
        InOrder(root -> left);
        printf("%d ", root -> data);
        InOrder(root -> right);
    }
}

void PostOrder(BinaryTreeNode *root) {
    if(root) {
        PostOrder(root -> left);
        PostOrder(root -> right);
        printf("%d ", root -> data);
    }
}


int FindMax(BinaryTreeNode *root) {
    static int max = INT_MIN;
    if(root) {
        if(root -> data > max) max = root -> data;
        FindMax(root -> left);
        FindMax(root -> right);
    }
    
    return max;
    
}



int isElementInBinaryTree(BinaryTreeNode *root, int search_item) {
   
		if(root != nullptr)	{
		if(search_item == root->data)
			return search_item;
		else if(search_item > root->data)
			return isElementInBinaryTree(root->left,search_item);
		else 
			return isElementInBinaryTree(root->right, search_item);
			}
		
		 return 0;
}


int main() {
    BinaryTreeNode one = {1, NULL, NULL}; // root of the binary tree
    BinaryTreeNode two = {2, NULL, NULL};
    BinaryTreeNode three = {3, NULL, NULL};
    BinaryTreeNode four = {4, NULL, NULL};
    BinaryTreeNode five = {5, NULL, NULL};
    BinaryTreeNode six = {6, NULL, NULL};
    BinaryTreeNode seven = {7, NULL, NULL};
    
    one.left = &two;
    one.right = &three;
    
    two.left = &four;
    two.right = &five;
    
    three.left = &six;
    three.right = &seven;
    //Prints Inorder
    InOrder(&one);
    //Prints in PreOrder
    printf("\n");
    PreOrder(&one);
    //Prints in PostOrder
    printf("\n");
    PostOrder(&one);
    printf("\n");
    //Finds the Max value
    printf("%d ", FindMax(&one));
    
    printf("\n");
    //Checks if the element is in the binary tree
    printf("%d", isElementInBinaryTree(&one,1));
    
    printf("\n");
    
    return 0;
}