#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printfmat(int **m, int rows, int cols)
{
    int i,j;
    for (int i = 0; i < rows; i++)
    {
        printf("\n");
        for (int j = 0; j < cols; j++)
        {
            printf("\t%d", m[i][j]);
        }
        
    }
    printf("\n");
    
}

int main()
{
    int **mat;

    mat = malloc(ROWS*sizeof(int *)); //Tamaño de apuntadors en (int *);

    for (int ren = 0; ren < ROWS; ren++)
    {
        mat[ren] = malloc(COLS * sizeof(int));
    }

    for (int ren = 0; ren < ROWS; ren++)
    {
        for (int col = 0; col < COLS; col++)
        {
            //Se aplica sobre el contenido
            mat[ren][col] = 10*(ren+1)+col+1;
        }
        
    }
    
    printfmat(mat, ROWS, COLS);
    
}