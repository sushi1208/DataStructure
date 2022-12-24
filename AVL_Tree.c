// AVL tree implementation in C
// I didn't understand the code so I tried writing but it is still buggy

#include <stdio.h>
#include <stdlib.h>

// Define a node in the AVL tree
typedef struct AVLNode {
int key;
int height;
struct AVLNode *left;
struct AVLNode *right;
} AVLNode;

// Function prototypes
AVLNode *createNode(int key);
int max(int a, int b);
int height(AVLNode *node);
int getBalance(AVLNode *node);
AVLNode *leftRotate(AVLNode *x);
AVLNode *rightRotate(AVLNode *y);
AVLNode *insert(AVLNode *node, int key);
void preOrder(AVLNode *root);

// Create a new AVL tree node
AVLNode *createNode(int key) {
AVLNode node = (AVLNode)malloc(sizeof(AVLNode));
node->key = key;
node->height = 1;
node->left = NULL;
node->right = NULL;
return node;
}

// Find the maximum of two integers
int max(int a, int b) {
return (a > b) ? a : b;
}

// Get the height of an AVL tree node
int height(AVLNode *node) {
if (node == NULL) {
return 0;
}
return node->height;
}

// Get the balance factor of an AVL tree node
int getBalance(AVLNode *node) {
if (node == NULL) {
return 0;
}
return height(node->left) - height(node->right);
}

// Perform a left rotation on an AVL tree node
AVLNode *leftRotate(AVLNode *x) {
AVLNode *y = x->right;
AVLNode *T2 = y->left;

// Perform rotation
y->left = x;
x->right = T2;

// Update heights
x->height = max(height(x->left), height(x->right)) + 1;
y->height = max(height(y->left), height(y->right)) + 1;

// Return new root
return y;
}

// Perform a right rotation on an AVL tree node
AVLNode *rightRotate(AVLNode *y) {
AVLNode *x = y->left;
AVLNode *T2 = x->right;

// Perform rotation
x->right = y;
y->left = T2;

// Update heights
y->height = max(height(y->left), height(y->right)) + 1;
x->height = max(height(x->left), height(x->right)) + 1;

// Return new root
return x;
}

// Insert a new key into the AVL tree
AVLNode *insert(AVLNode *node, int key) {
// Perform standard BST insert
if (node == NULL) {
return createNode(key);
}
