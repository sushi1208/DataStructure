#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node* next;
};
 
void insert(struct Node** head, int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node != NULL)
    {
        node->data = value;
        node->next = NULL;
        if (*head == NULL)
        {
            *head = node;
        }
        else
        {
            struct Node* temp = *head;
 
            // finding last node
            while (temp->next != NULL) {
                temp = temp->next;
            }
 
            // adding node at last position
            temp->next = node;
        }
    }
}
 
void display(struct Node* head)
{
    if (head == NULL) {
        printf("Empty linked list");
        return;
    }
    struct Node* temp = head;
    printf("\n Linked List :");
    while (temp != NULL) {
        printf("  %d", temp->data);
        temp = temp->next;
    }
}
 
struct Node* last_node(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}
 
// We are Setting the given last node position to its proper
// position
struct Node* parition(struct Node* first, struct Node* last)
{
    // Get first node of given linked list
    struct Node* pivot = first;
    struct Node* front = first;
    int temp = 0;
    while (front != NULL && front != last) {
        if (front->data < last->data) {
            pivot = first;
 
            // Swapping  node values
            temp = first->data;
            first->data = front->data;
            front->data = temp;
 
            // Visiting the next node
            first = first->next;
        }
 
        // Visiting the next node
        front = front->next;
    }
 
    // Change last node value to current node
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}
 
// Performing quick sort in  the given linked list
void quick_sort(struct Node* first, struct Node* last)
{
    if (first == last)
    {
        return;
    }
    struct Node* pivot = parition(first, last);
 
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort(pivot->next, last);
    }
 
    if (pivot != NULL && first != pivot) {
        quick_sort(first, pivot);
    }
}
 
// Driver's code
int main()
{
    struct Node* head = NULL;
 
    // Create linked list
    int length, a = 0;

    printf("Please enter the number of elements in your linked list:\n");

    scanf("%d", &length);
    
    printf("Please enter the elements of your linked list:\n");
    
    for(int i = 0; i < length; ++i)
    {
        scanf("%d", &a);
        insert(&head, a);
    }
  
    quick_sort(head, last_node(head));
    printf("After Sort\n");
    display(head);
    printf("\n");
}