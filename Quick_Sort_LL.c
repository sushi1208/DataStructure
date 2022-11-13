//quick sort code -need to meet TAs

#include <stdio.h>
#include <stdlib.h>
 
struct node         // defining a node for the linked list
{
    int data;
    struct node* next;
};
 
void insert(struct node* head, int value)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if (node != NULL)
    {
        node->data = value;
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            struct node* temp = head;
 
            while (temp->next != NULL)          // finding final node in the list
            {
                temp = temp->next;
            }
             temp->next = node;                 // pushing node at last position
        }
    }
}
 
void display(struct node* head)
{
    if (head == NULL)                        // checks if head is empty, in effect, list is empty
    {
        printf("Empty linked list");         
        return;                             // function exit statement if condition in loop is satisfied
    }
    struct node* temp = head;
    printf("\n Linked List :");
    while (temp != NULL)
    {
        printf("  %d", temp->data);         // printing the linked list
        temp = temp->next;
    }
}
 
struct node* last_node(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}
 
struct node* parition(struct node* first, struct node* last)            // function to partition the list
{
    struct node* pivot = first;                                         // assigning the value of node pivot to the value stored in first
    struct node* front = first;                                         // assigning the value of node pivot to the value stored in first
    
    int temp = 0;

    while (front != NULL && front != last)
    {
        if (front->data < last->data)
        {
            pivot = first;
 
            temp = first->data;                                         // swapping value procedure; similar to previous programs
            first->data = front->data;
            front->data = temp;
 
            first = first->next;
        }
         front = front->next;
    }
 
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}
 
void quick_sort(struct node* first, struct node* last)          // function applying the quick sort technique
{
    if (first == last)
    {
        return;
    }
    struct node* pivot = parition(first, last);
 
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort(pivot->next, last);
    }
 
    if (pivot != NULL && first != pivot) {
        quick_sort(first, pivot);
    }
}
 
int main()
{
    struct node* head = NULL;
     int length, a = 0;

    printf("Please enter the number of elements in your linked list:\n");

    scanf("%d", &length);
    
    printf("Please enter the elements of your linked list:\n");
    
    for(int i = 0; i < length; ++i)
    {
        scanf("%d", &a);
        insert(head, a);
    }
  
    quick_sort(head, last_node(head));
    printf("After Sort\n");
    display(head);
    printf("\n");
}