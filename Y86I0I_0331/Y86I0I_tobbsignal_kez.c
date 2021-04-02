#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void handleSignal();

int main(){
signal(SIGINT, handleSignal); //Az Interrupt Signal-t átadom a handleSignal-nak, hogy kezelje le ha ilyen jelet kap a process
signal(SIGQUIT, handleSignal); //A Quit Signal-t átadom ugyan úgy a handleSignal-nak
for (int i=0; i<10; i++){ //10x várunk jelet a felhasználótól
	printf("Varunk...\n");
	pause();
}
return 0;
}

void handleSignal(int sig){
char desc[50];
switch(sig){// A kapott jelet megvizsgáljuk, most felkészítettem a handleSignal-t mind a 6 jel vizsgálatára, de ebből csak a Quit és Interrupt fog menni
	case 1: {
	strcpy(desc, "Hangup Signal");
	break;
	}

	case 2: {//Interrupt Signal 2-essek tér ide, ezért az üzenetet átírjuk erre
	strcpy(desc, "Interrupt Signal");
	signal(SIGINT, SIG_DFL);//A C feladatnak megfelelően átállítjuk az interruptot az eredeti állapotára
	printf("\nA CTRL + C most már ki fogja léptetni a programból!");
	break;
	}

	case 3: {//A Quit 3-as kóddal tér ide, ezért ezt itt kezeljük
	strcpy(desc, "Quit Signal");
	break;
	}

	case 4: {
	strcpy(desc, "Illegal Instruction Signal");
	break;
	}

	case 5: {
	strcpy(desc, "Trace Trap Signal");
	break;
	}

	case 6: {
	strcpy(desc, "Abort Signal");
	break;
	}
}//Switch
printf("\nAz elkapott jel: %s\n", desc); //Ez a B feladat megvalósítása, csak már a kódot átírtam emberi szövegre
}
