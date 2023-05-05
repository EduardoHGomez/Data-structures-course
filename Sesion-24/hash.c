#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define 12

struct STRMLNODE {
    char key[60];
    char data[80];

    struct STRLNODE *next;
    struct STRLNODE *prev;
};

struct STRLIST {
    struct STRMLNODE *first;
    struct STRMLNODE *last;
};

unsigned long long hash(char *s);

int main()
{
    struct STRLIST l1;

    char key[60];
    unsigned long long hashcode;
    char c;
    int p;
    
    while (1)
    {
        printf("Dame una llave, FIN para terminar : ");
        scanf("%s", key);
        if(strcmp(key, "fin") == 0)
            break;
        p = hash(key); 
        printf("El codigo es %016llx\n", hashcode);
        
    }
    
}

unsigned long long hash(char *s)
{
    int len = strlen(s);
    unsigned long long retcode = 0;
    char c;

    if (len > 12)
        len = 12;

    int i = 0;
    while (i<len && s[i] != '\0')
    {
        c = toupper(s[i]);
        if (c >= 'A' && c<= 'Z')
        {
            retcode = retcode << 5;
            retcode = retcode | (c & 0x1F);
        }
        i++;   
    }
    
    
}