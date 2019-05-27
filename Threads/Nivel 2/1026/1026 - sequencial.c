#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>

int arrayOne[] = {      4,6,5,7,8,9,10,12,5,7,
                        4,6,5,7,8,9,10,12,5,7,
                        4,6,5,7,8,9,10,12,5,7,
                        4,6,5,7,8,9,10,12,5,7,
                        4,6,5,7,8,9,10,12,5,7
                     };

int arrayTwo[] = {      6,9,8,6,2,1,12,3,2,9,
                        6,9,8,6,2,1,12,3,2,9,
                        6,9,8,6,2,1,12,3,2,9,
                        6,9,8,6,2,1,12,3,2,9,
                        6,9,8,6,2,1,12,3,2,9,
                     };

void Calculo(int location){
    unsigned long long int valor1,valor2,soma;
    valor1 = arrayOne[location];
    valor2 = arrayTwo[location];
    soma = valor1^valor2;
    printf("\nSoma [%d] = %d",location,soma);
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


