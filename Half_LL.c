// Finding the first half of a linked list without knowing the length of the list

#include <stdio.h>
#include <stdlib.h>
  
struct node         // defining a node for the linked list
{
    int data;
    struct node* next;
};

struct node* head = NULL;       //creating node head and setting it to NULL


void insert(int a)           // insert function is used to add user-inputted elements into the linked list
{ 
    struct node* newnode = (struct node*)malloc(sizeof(struct node));   // allocating memory for the linked list through malloc
    newnode->data = a;        
    newnode->next = head;       //Setting the next pointer of the new node to point to the current first node of the list
    head = newnode;             //Changing the head pointer to point to the new node - now it is the first node in the list.
}

struct node *half(struct node* head)
{
    struct node* hare = head;       //creating node pointer hare and setting it to head pointer
    struct node* tortoise = head;   //creating node pointer tortoise and setting it to head pointer

    while(hare && hare->next)
    {
        hare  = hare -> next -> next;
        tortoise  = tortoise -> next;
    }
    return tortoise;
}

void print(struct node* head)       // function to print the linked list
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
    
    for(int i = 0; i < length; ++i)     //sending user-inputs to be added into the linked list
    {
        scanf("%d", &a);
        insert(a);
    }
      
    printf("Original Linked List:\n");
    print(head);
    printf("\n");

    print(half(head));
    printf("\n");
}