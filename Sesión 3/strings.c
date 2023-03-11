#include <stdio.h>

int main()
{
    char names[][10] = {"Alex", "Carlos", "Lando", "Massa", "Juan"};

    char *word = (char *) (names+2); //names+2
    printf("%s\n", word);

    printf("%c\n", names[0][0]); //*((char*) names

    char name1[10] = {"Thomas"};
    printf("%s\n", name1);

    word = *(names + 4);
    printf("%s", word);


}