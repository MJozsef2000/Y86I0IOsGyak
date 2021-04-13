#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void displayValues(double input[]);
int calculate(double input[], double output[]);
void displayResults(double output[], int solutions);
void documentResults(double input[], double output[], int solutions);
int main()
{
    int buf, solutions;
    double input[3]; //a, b, c
    double output[2]; //x és y
    FILE *fp;
    fp = fopen("Output.txt", "w"); //Létrehozzuk és kitisztítjuk az Output.txt-t
    fp = fopen("Input.txt", "r");
    if (fp < 0) {
     perror("File nyitas hiba!\n");
     exit(-1);
    }
    fscanf(fp, "%d", &buf);
    printf("Ennyi szamitast fogok elvegezni: %d\n", buf);
    printf("A kapott adatok:\n");
    for (int i=0; i<buf; i++){
        for (int j=0; j<3; j++){//Beolvassuk a 3 számot
            fscanf(fp, "%lf", &input[j]);
        }
        displayValues(input);
        solutions = calculate(input, output);
        displayResults(output, solutions);
        documentResults(input, output, solutions);
    }
    fclose(fp);
    return 0;
}


void displayValues(double input[]){
    static int task = 1;
    printf("%d. Feladat: a=%.2lf b=%.2lf c=%.2lf\n",task++, input[0], input[1], input[2]);
    return;
}

int calculate(double input[], double output[]){
    /*
    input[0] = a;
    input[1] = b;
    input[2] = c;
    */
    double negyzet = pow(input[1], 2.0);
    double ac = 4*input[0]*input[2];
    double disc = sqrt(negyzet - ac);
    if (disc > 0){
        output[0] = -((input[1]+disc)/(2*input[0]));
        output[1] = -((input[1]-disc)/(2*input[0]));
        return 2;
    } else if(disc == 0)
    {
        output[0] = -(input[1]/2*input[0]);
        return 1;
    }
    return 0;
}

void displayResults(double output[], int solutions){
    switch(solutions){
            case 2: {
                printf("A megoldasok: %.2lf, %.2lf\n", output[0], output[1]);
                break;
            }
            case 1: {
                printf("A megoldas: %.2lf\n", output[0]);
                break;
            }
            case 0: {
                printf("Erre a masodfoku egyenletre nincs megoldas! (Diszkriminans < 0)\n");
                break;
            }
        }
    return;
}

void documentResults(double input[], double output[], int solutions){
    FILE * fp = fopen("Output.txt", "a");
    if (fp < 0) {
     perror("File nyitas hiba!\n");
     exit(-1);
    }
    switch(solutions){
            case 2: {
                    fprintf(fp, "a=%.2lf b=%.2lf c=%.2lf x1=%.2lf x2=%.2lf\n", input[0], input[1], input[2], output[0], output[1]);
                break;
            }
            case 1: {
                    fprintf(fp, "a=%.2lf b=%.2lf c=%.2lf x1=%.2lf\n", input[0], input[1], input[2], output[0]);
                break;
            }
            case 0: {
                    fprintf(fp, "a=%.2lf b=%.2lf c=%.2lf Nincs megoldás!", input[0], input[1], input[2]);
                break;
            }
        }
    fclose(fp);
    return;
}
