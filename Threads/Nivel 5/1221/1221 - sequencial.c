#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int arrayOne[] = {   12,56416,654,5214,21,465,23,65,54,31,22,
                        12,56416,654,5214,21,465,23,65,54,31,22,
                        12,56416,654,5214,21,465,23,65,54,31,22,
                        12,56416,654,5214,21,465,23,65,54,31,22,
                        12,56416,654,5214,21,465,23,65,54,31,22
                     };
bool eh_primo(int num){
    int  limite = sqrt(num) + 1;
    for (int i=2; i<limite; i++){
        if(num%i==0){
             return false;
        }
    }
    return true;
}
void Calculo(int location){
    int num = arrayOne[location];
    if (eh_primo(num)){
        printf("Prime\n");
    }
    else{
        printf("Not Prime\n");
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


