// Solution to Question 3-a of the Midterm Exam (Take-Home)
// Read https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/ once; however wrote code on my own

#include <stdio.h>
#include <stdlib.h>

struct nodeType
{
	int val;
	struct nodeType* left; 
	struct nodeType* right;
};

typedef struct nodeType* NodeAddress;

NodeAddress createnode(int a)
{
    struct nodeType* node = malloc(sizeof(struct nodeType));                // allocating memory using malloc
    node->left = NULL;
    node->right = NULL;
    node->val = a;
 
    return node;
}

NodeAddress insert(NodeAddress root, int val)
{
	if(root == NULL)
    {
        return createnode(val);
    }

    if (val > root->val)                                   
    {
        root->right = insert(root->right, val);
    }
	else if (val < root->val)                              
    {
        root->left = insert(root->left, val);
    }

	return root;
}


NodeAddress arrayToBST(int *a, int n)
{
    int midpoint = (n)/2;                                  // finding the midpoint of the sorted array
    
    struct nodeType *root = createnode(a[midpoint]);       // creating the root of the BST 
 
    for(int i = 0; i < n; i++)
    {
        if (root == NULL)
        {
            return createnode(a[i]);
        }
        
        else if(a[i] < root->val) 
        {
            root->left  = insert(root->left , a[i]);         // which tree the element goes into for the BST
        }
	
        else if (a[i] > root->val )
        {
            root->right = insert(root->right, a[i]);         // which tree the element goes into for the BST
        }
    }

    return root;
}

void prefixPrint(NodeAddress root)        // function to print the BST using prefix order
{
    if (root != NULL)
    {
        prefixPrint(root->left);
        printf("%d ", root->val);
        prefixPrint(root->right);
    }
}



int main()
{
  
    int length;

    printf("Please enter the number of elements in your array:\n");

    scanf("%d", &length);
    
    printf("Please enter the elements of your array:\n");
    
    int *a1;                                                // creating a dynamic array

    a1 = (int*)malloc(length * sizeof(int));
    
    for(int i = 0; i < length; ++i)
    {
        scanf("%d", &a1[i]);
    }

    for (int  i = 0; i < length - 1; i++)               // sorting the array inputted using selection sort
    {
        int min = i;

        for (int j = i + 1; j < length; j++)
        {
            if (a1[j] < a1[min])
            {
                int temp = a1[min];    
                a1[min] = a1[j];          
                a1[j] = temp;
            }
        }
    }
    
    printf("BST:  \n");

    prefixPrint(arrayToBST(a1, length));

}