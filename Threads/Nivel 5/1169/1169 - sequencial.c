#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

int arrayOne[] = {   1,2,3,4,5,6,7,8,9,10,
                        11,12,13,14,15,16,17,18,19,20,
                        21,22,23,24,25,27,28,30,31,32,
                        33,35,36,37,39,40,41,42,44,45,
                        46,48,50,55,60,61,62,63,64,54
                     };
void Calculo(int location){
    int quadrados = arrayOne[location];
    unsigned long long int total=0;
    unsigned long long int dobro = 1;

    if(quadrados<=64){
        for(int j=1; j<=quadrados; j++){
            total = dobro + total;
            dobro = dobro * 2;
        }
        total = total / 12;
        total = total/ 1000;
        printf("Array[%d] = %d kg\n", location, total);
    }
    else{
        printf("Fora das especificacoes\n");
    }

    Sleep(1000);
}
int main()
{
    time_t t_init, t_end;
    float tempo;
    int k;

    t_init = time(NULL);
    for(k = 0; k < 50; k++)
    {
        Calculo(k);
    }
    t_end = time(NULL);
    tempo = difftime(t_end, t_init);

    printf("\nTempo de execucao: %f\n", tempo);
    return 0;
}


