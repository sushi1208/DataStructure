// Sorting an array(int) using Selection Sort technique

#include <stdio.h>

// function 'swap' to swap the the position of two elements using pointers and 'temp' variable
void swap(int *x, int *y)
{
  int temp = *x;    // stores the value of pointer *x in temp, this allows for pointer *x to be overwritten while its previous value is stored
  *x = *y;          // stores the value of pointer *y in temp
  *y = temp;        // stores the previous value of pointer *x (which was stored in temp) in *y
}

// function to perform the selection sort technique(ascending order) on the given array
void ascend_selectionSort(int array1[], int size1)
{
  // The loops below allow us to find the element with the minimum value in the array
  for (int  i = 0; i < size1 - 1; i++)
  {
    int min = i;

    for (int j = i + 1; j < size1; j++)
    {
        if (array1[j] < array1[min])
        min = j;
    }

    // swapping the elements with the help of the swap function
    swap(&array1[min], &array1[i]);
  }
}

// function to perform the selection sort technique(ascending order) on the given array
void descend_selectionSort(int array2[], int size2)
{
  // The loops below allow us to find the element with the maximum value in the array
  for (int  i = 0; i < size2 - 1; i++)
  {
    int max = i;

    for (int j = i + 1; j < size2; j++)
    {
        if (array2[j] > array2[max])
        max = j;
    }

    // swapping the necessary elements with the help of the swap function
    swap(&array2[max], &array2[i]);
  }
}


// function to print an array when called from main
void printArray(int array3[], int size3)
{
  for (int i = 0; i < size3; ++i) {
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

    ascend_insertionSort(array_input, length);
    printf("Sorted array in Ascending Order:\n");
    printArray(array_input, length);
    descend_insertionSort(array_input, length);
    printf("Sorted array in Descending Order:\n");
    printArray(array_input, length);
}
