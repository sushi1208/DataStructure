#include <stdio.h>
#include <stdlib.h>

struct nodeType
{
  int data;
  struct nodeType *next;
};

typedef struct nodeType* NodeAddress;
NodeAddress head = NULL;                        // initializing global head pointer to NULL
NodeAddress temp = NULL;                        // initializing global temp pointer to NULL



NodeAddress createLL(int *a, int n)           // this function is used to add user-inputted elements into a circular linked list
{	
    if(n > 0)                                                 // special case for head
    {
		head = malloc( sizeof(struct nodeType));              // allocating memory
		head->data  = a[0];
		head->next = NULL;
        temp = head;
        
    }

    for(int i = 1; i < n; i++)
    {
		temp->next = malloc(sizeof(struct nodeType));       // allocating memory
		temp = temp->next;
		temp->data = a[i];
		temp->next = NULL;
    }

    temp->next = head;                              // making the linked list circular
    
    return head;
}


NodeAddress josephus_problem(int k)
{
    struct nodeType *t1, *t2;

    int counter = 0;                                        // counter variable to keep track of the elimination number of the josephus problem

    t2 = t1 = head;
    
    while (t1->next != t1)
    {
        counter++;                                                  // increments counter variable at every elimination 

        for (int i = 0; i < k - 1; i++)
        {
            t2 = t1;
            t1 = t1->next;
        }
        
        t2->next = t1->next;
       
        printf("Elimination Number %d: %d has been eliminated.\n", counter, t1->data);
        
        free(t1);                                                           // freeing up of memory allocating to the now-deleted node in the linked list
       
        t1 = t2->next;
    }

    printf("The person to survive, post the completion of the original Josephus game, will be : %d\n", t1->data);

    return 0;                           // as this is a non-void function, we have to return some value
    
}


NodeAddress hybrid_josephus_problem(int k)
{
    struct nodeType *t1, *t2;

    int counter = 0;                                        // counter variable to keep track of the elimination number of the josephus problem

    t2 = t1 = head;
            
    while (t1->next != t1)
    {
        counter++;                                                  // increments counter variable at every elimination 

        for (int i = 0; i < k - 1; i++)
        {
            t2 = t1;
            t1 = t1->next;
        }
        
        t2->next = t1->next;
       
        printf("Elimination Number %d: %d has been eliminated.\n", counter, t1->data);
        
        free(t1);                                                           // freeing up of memory allocating to the now-deleted node in the linked list
       
        t1 = t2->next;

        NodeAddress prev = NULL;            // reversing the linked list - from GitHub repo
        NodeAddress current = t1;
        NodeAddress nextnode = NULL;
        while (current != NULL)         // while loop to traverse linked list
        {
            nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }
        t1 = prev;                    // update head pointer to beginning of reversed linked list
    }

    printf("The person to survive, post the completion of the hybrid Josephus game, will be : %d\n", t1->data);

    return 0;                           // as this is a non-void function, we have to return some value

}


int main()
{
    
    int length;

    printf("Please enter the number of individuals in your circle: \n");

    scanf("%d", &length);
    
    printf("Please enter the individuals in your circle:\n");
    
    int *a1;                    // initializing dynamic array

    a1 = (int*)malloc(length * sizeof(int));        // allocating memory
    
    for(int i = 0; i < length; ++i)
    {
        scanf("%d", &a1[i]);
    }

    head = createLL(a1, length);

    int skip_count, input1;
     
    printf("Enter the number of persons to be skipped: \n");
    scanf("%d", &skip_count);

    if(skip_count < 1)
    {
    printf("Skip Value is less than one. Incorrect Input \n");
    return 0;
    }

    printf("If you want to use the original Jopehus method enter 1, else we will use the hybrid version: ");
    scanf("%d", &input1);
    
    if(input1 == 1)
    {
        josephus_problem(skip_count);
    }
    else
    {
        hybrid_josephus_problem(skip_count);
    }
}
