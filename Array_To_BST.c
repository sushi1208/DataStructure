#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int key;
    struct node *left, *right;      // nodes initialized for left and right subtrees
};
 
struct node* newNode(int a)      // function to create a binary search tree
{
    struct node* bst = (struct node*)malloc(sizeof(struct node));      // allocating memory for node
    bst->key = a;
    bst->left = bst->right = NULL;
    return bst;                         // returning bst node to the main function
}
 
void traverse(struct node* root)        // function to traverse and print the BST
{
    if (root != NULL)
    {
        traverse(root->left);
        printf("%d \n", root->key);
        traverse(root->right);
    }
}
 
struct node* insert(struct node* a, int b)
{
    if (a == NULL)           // condition when tree is empty
        return newNode(b);
 
    if (b < a->key)
    {
        a->left = insert(a->left, b);
    }
    else if (b > a->key)
    {
        a->right = insert(a->right, b);
    }
 
    return a;           // returning original pointer
}
 
int main()
{
    
    int length = 0;

    printf("Please enter the number of elements in your array:\n");

    scanf("%d", &length);
    
    printf("Please enter the elements of your array:\n");

    int array_input[length];

    
    for(int i = 0; i < length; ++i)
    {
        scanf("%d", &array_input[i]);
    }
    
    struct node* root = NULL;
    
    root = insert(root, array_input[0]);                // inserting the root first
    for(int i = 1; i < length; ++i)                     
    {
        insert(root, array_input[i]);                   // inserting the elements of the array into the BST
    } 

    traverse(root);                                     // printing the BST
 
}
