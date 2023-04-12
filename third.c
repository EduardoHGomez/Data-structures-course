#include <stdio.h>

int maxSum(void)
{
    
}

int main()
{
    int amount_of_tests;
    scanf("%d", amount_of_tests);

    int * results[amount_of_tests];

    for (int i = 0; i < amount_of_tests; i++)
    {
        results[i] = maxSum();
    }
    
}