// Sorting an array(int) using Insertion Sort technique

#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *x;    // stores the value of pointer *x in temp, this allows for pointer *x to be overwritten while its previous value is stored
  *x = *y;          // stores the value of pointer *y in temp
  *y = temp;        // stores the previous value of pointer *x (which was stored in temp) in *y
}


void ascend_insertionSort(int array1[], int size1)
{
    for (int i = 1; i < size1; i++)
    {
        int temp = array1[i];
        int j = i - 1;
        
        while (temp < array1[j] && j >= 0)
        {
            array1[j + 1] = array1[j];
            j--;
        }

    array1[j + 1] = temp;
    }
}

void descend_insertionSort(int array1[], int size1)
{
    for (int i = 1; i < size1; i++)
    {
        int temp = array1[i];
        int j = i - 1;
        
        while (temp > array1[j] && j >= 0)
        {
            array1[j + 1] = array1[j];
            j--;
        }

    array1[j + 1] = temp;
    }
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
    ascend_insertionSort(array_input, length);
    printf("Sorted array in Ascending Order:\n");
    printArray(array_input, length);
    descend_insertionSort(array_input, length);
    printf("Sorted array in Descending Order:\n");
    printArray(array_input, length);
}
