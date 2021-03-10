#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (!system("dir")){
        for (int i=0; i<3;i++)
            printf("MEGY!\n");
    }
    system("color a"); //Érdekesség, a szín megváltozott a dir command elõtt!
    system("Ilyen nincs"); //Itt hibát jelez a rendszer, nem létezõ parancs!
    return 0;
}
