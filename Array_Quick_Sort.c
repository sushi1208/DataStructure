// Sorting an array(int) using Quick Sort technique

#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *x;    // stores the value of pointer *x in temp, this allows for pointer *x to be overwritten while its previous value is stored
  *x = *y;          // stores the value of pointer *y in temp
  *y = temp;        // stores the previous value of pointer *x (which was stored in temp) in *y
}


// function to find the partition position
int partition(int array1[], int low, int high)
{
    int right = array1[high];   //storing the value of the rightmost element in int variable 'right
    int i = (low - 1);      // traverse each element of the array
        
    for (int j = low; j < high; j++)
    {
        if (array1[j] <= right)
        {
            i++;
            swap(&array1[i], &array1[j]);
        }
    }
    
    swap(&array1[i + 1], &array1[high]);
    
    return (i + 1);
}


void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        
        quickSort(array, low, pi - 1);
        
        quickSort(array, pi + 1, high);
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

  // perform quicksort on data
  quickSort(array_input, 0, (length - 1));
  
  printf("Sorted array in ascending order: \n");
  printArray(array_input, length);
}