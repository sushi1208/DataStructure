// Sorting a linked list(int) using Insertion Sort technique
#include <stdio.h>
#include <stdlib.h>
  
struct node         // defining a node for the linked list
{
    int data;
    struct node* next;
};
  
struct node* head = NULL;       //creating node head and setting it to NULL
struct node* isort = NULL;     //creating node isort and setting it to NULL
  
void insert(int a)           // insert function is used to add user-inputted elements into the linked list
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));   // allocating memory for the linked list through malloc
    newnode->data = a;        
    newnode->next = head;       
    head = newnode;
}
  
void sort(struct node* newnode)
{
    if (isort == NULL || isort->data >= newnode->data)
    {
        newnode->next = isort;
        isort = newnode;
    }

    else
    {
        struct node* current = isort;

        while (current->next != NULL && current->next->data < newnode->data)
        {
            current = current->next;            // iterating over all the members of the linked list
        }

        newnode->next = current->next;
        current->next = newnode;
    }
}
  
void finalsort()                            // this function is used to implement the insertion sort technique
{
  
    struct node* current = head;
  
    while (current != NULL)                 // traversing the entire linked list
    {
  
        struct node* next = current->next;
  
        sort(current);                      // inserting current in the sorted linked list through the sort function
  
        current = next;                     // update the value of current for the next iteration
    }
    head = isort;                           //update head to isort
}
  
void print(struct node* head)       // function to print the sorted linked list
{
    while (head)                    // loop iterates until head != NULL
    {
        printf("%d->", head->data);
        head = head->next;          // moves head to next element in the sorted list to be printed
    }
    printf("NULL");                 // prints NULL to indicate NULL value of element in linked list(usually, the final element of the linked list)
}
  
int main()
{
  
    int length, a = 0;

    printf("Please enter the number of elements in your linked list:\n");

    scanf("%d", &length);
    
    printf("Please enter the elements of your linked list:\n");
    
    for(int i = 0; i < length; ++i)
    {
        scanf("%d", &a);
        insert(a);
    }
  
    finalsort(head);
  
    printf("Linked List after sorting:\n");
    print(head);
    printf("\n");
}
