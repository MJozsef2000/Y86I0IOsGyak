#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (!system("dir")){
        for (int i=0; i<3;i++)
            printf("MEGY!\n");
    }
    system("color a"); //�rdekess�g, a sz�n megv�ltozott a dir command el�tt!
    system("Ilyen nincs"); //Itt hib�t jelez a rendszer, nem l�tez� parancs!
    return 0;
}
