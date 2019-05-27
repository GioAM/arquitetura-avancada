#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>

int arrayOne[] = {      110, 120, 130, 410, 150, 160, 170, 180, 190, 919,
                        140, 240, 350, 407, 550, 460, 170, 845, 290, 199,
                        150, 240, 350, 450, 570, 690, 720, 580, 930, 299,
                        160, 240, 350, 405, 580, 607, 730, 806, 940, 997,
                        170, 240, 350, 460, 550, 690, 704, 480, 950, 969
                     };

int arrayTwo[] = {      310, 120, 190, 412, 160, 260, 70, 10, 19,   219,
                        440, 220, 300, 402, 570, 260, 70, 84, 20,   299,
                        550, 220, 300, 420, 580, 590, 70, 80, 30,   399,
                        150, 230, 354, 234, 540, 407, 73, 86, 1940, 697,
                        190, 200, 334, 442, 510, 290, 74, 48, 1950, 569
                     };

void Calculo(int location){
    int total = arrayOne[location] + arrayTwo[location];
    printf("\nX[%d] = %d",location,total);
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


