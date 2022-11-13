//stress testing a loop

#include <stdio.h>

int main()
{
    int a = 1;
    printf("Printing 1 to 9:\n");                       // this loop works fine
    for(double i = 0.000000000000001; i < 0.000000000000010; i=i+0.000000000000001)
    {
        printf("%d ", a);
        a++;
    }
    printf("\n");
    
    int b = 11;                                         // this loop is stressed by the nu,mber of decimals
    printf("Printing 11 onwards:\n");
    for(float i = 0.00000000000000000000000000000000000000000000000000000000000000001; i < 0.00000000000000000000000000000000000000000000000000000000000000010; i=i+0.00000000000000000000000000000000000000000000000000000000000000001)
    {
        printf("%d ", b);
        b++;
    }                                           
}