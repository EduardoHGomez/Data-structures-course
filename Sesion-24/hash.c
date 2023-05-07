#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct STRMLNODE {
	char key[60];
	char data[80];
	struct STRMLNODE *next;
	struct STRMLNODE *prev;
};

struct STRMAPLIST {
	struct STRMLNODE *first;
	struct STRMLNODE *last;
};

#define M 12

struct STRMAPLIST table[M];

unsigned long long hash(char *s);


int main()
{
	char key[60];
	char nombre[80];
	unsigned long long hashcode;
	int p;

	setbuf(stdout,NULL);

	while(1)
	{
		printf("Dame una llave, FIN para terminar :");
		scanf("%s",key);
		if(strcmp(key,"FIN")==0)
			break;
		printf("Nombre completo :");
		scanf("%s",nombre);

		hashcode = hash(key);
		printf("El código es %016llX\n",hashcode);
		p = (int) (hashcode % M);
		printf("Posición en la tabla(p) es %d\n",p);

		/* Insertar un nodo en la lista p correspondiente
		 * que contenga la llave y el nombre
		 */
	}
}

unsigned long long hash(char *s)
{
	int len = strlen(s);
	int i=0;
	unsigned long long retcode = 0;
	char c;

	if(len>12)
		len = 12;

	while(i<len && s[i]!='\0')
	{
		c = toupper(s[i]);
		if(c>='A' && c<='Z')
		{
			retcode = retcode << 5;
			retcode = retcode | (c & 0x1F);
		}
		i++;
	}

	return retcode;
}