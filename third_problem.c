#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxSum(void)
{

}


int main()
{
    FILE *f = fopen("candy_collection_input.txt", "r");
    int *buffer;
    fread(buffer, sizeof(int*), 1, f);
    printf("%d ", *buffer);
    
    fclose(f);
}