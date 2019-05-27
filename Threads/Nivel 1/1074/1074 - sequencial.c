#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>

int array[] = {-1,2,-2,0,-9,8,7,-8,0,-23,-1,2,-2,0,-9,8,7,-8,0,-23,-1,2,-2,0,-9,8,7,-8,0,-23,-1,2,-2,0,-9,8,7,-8,0,-23,-1,2,-2,0,-9,8,7,-8,0,-23};
void Calculo(int location){
    int B = array[location];
    printf("[%d] ", location);
    if(B%2==0 && B>0) {
        printf("EVEN POSITIVE\n");
    } else if(B%2==0 && B<0) {
        printf("EVEN NEGATIVE\n");
    } else if(B%2==1 && B>0) {
        printf("ODD POSITIVE\n");
    } else if(B%2==-1 && B<0) {
        printf("ODD NEGATIVE\n");
    } else if(B==0) {
        printf("NULL\n");
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


