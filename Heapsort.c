// Given an array, building a heap and sorting it
 
#include <stdio.h>
 
// Function to swap the position of two elements
 
void swap(int* a, int* b)
{
 
    int temp = *a;          // stores the value of pointer *a in temp, this allows for pointer *a to be overwritten while its previous value is stored
    *a = *b;                // stores the value of pointer *b in *a
    *b = temp;              // stores the previous value of pointer *a (which was stored in temp) in *b
}
 

void heap(int arr[], int N, int i)
{
    int biggest = i;            // finding biggest value - becomes root
     int left = 2 * i + 1;
     int right = 2 * i + 2;
 
    if (left < N && arr[left] > arr[biggest])           // If condition for when left child is larger than root
    {
        biggest = left;                                 // updating root to the value stored in left child
    }
    if (right < N && arr[right] > arr[biggest])         // If condition for when right child is larger than root
    { 
        biggest = right;                                // updating root to the value stored in right child
    }
 
    if (biggest != i)                                   // swapping recursively
    {
         swap(&arr[i], &arr[biggest]);
         heap(arr, N, biggest);
    }
}
 

void sort_heap(int arr[], int a)
{
 
    for (int i = a / 2 - 1; i >= 0; i--)           // Building the heap
    { 
        heap(arr, a, i);
    }
 
    for (int j = a - 1; j >= 0; j--)                // Sorting the heap
    {
 
         swap(&arr[0], &arr[j]);
         heap(arr, j, 0);
    }
}
 
void print(int array3[], int size3)            // function to print an array when called from main
{
  for (int i = 0; i < size3; ++i)
  {
    printf("%d  ", array3[i]);
  }
  printf("\n");
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
    length = sizeof(array_input) / sizeof(array_input[0]);

    sort_heap(array_input, length);
    printf("Sorted heap is\n");
    print(array_input, length);
}