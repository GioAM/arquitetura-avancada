#include <windows.h>
#include <time.h>
#include <math.h>

int array[] = {4,12,11,10,8,2,3,1,9,1,2,3,4,5,6,5,7,8,4,7,2,4,1,9,2,2,2,3,4,4,2,3,1,2,1,2,3,4,5,6,5,7,8,4,7,2,4,1,9,2};

void Calculo(int location){
    int casos = array[location];
    printf("[%d]",location);
    int y;
    for(y = 1; y <= casos; y++)
    {
        printf("Ho");
        if(y != casos){
            printf(" ");
        }
        else if(y == casos){
            printf("!\n");
        }
    }
    Sleep(1000);
}
int main(){

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
