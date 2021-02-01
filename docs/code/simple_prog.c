#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void hello()
{
    printf("Hello from Hello!\n");
}

int buf_copy(char* string)
{
	char buffer[50];
	int dummy=200;
	strcpy(buffer, string);
	printf("%d - %s\n", dummy, buffer);
	return 0;
}

int main(int argc, char **argv)
{
	char name[]="World!";
	hello();
	printf("Hello %s\n",name);
	buf_copy(argv[1]);
	return 0;
}

