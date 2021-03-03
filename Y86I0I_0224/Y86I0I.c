#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char s[300];
    file = fopen("vezeteknev.txt", "r+");
    for (int i=0; i<4; i++)	
	{
    	fscanf(file, "%s", s);
    	printf("%s\n", s);
	}
    return 0;
}
