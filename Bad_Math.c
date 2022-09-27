//program to show how computers are bad at math.

#include <stdio.h>

int main()
{
    int i;
    i = 0.1 + 0.2 + 0.3;
    //The sum of these three decimals stored in 'i' should be 0.6
    
    printf("The result: ");

    if (i == 0.6)
        printf("Computers are good at Math. The result is 0.6\n");
    else
        printf("Computers are bad at Math. The result is not equal to 0.6\n");
}


    
