#include <windows.h>
#include <time.h>
#include <math.h>

int arrayOne[] = {4,0,0,0,0,2,3,1,0,1,2,3,4,5,6,5,7,8,4,7,2,4,1,9,2,2,2,3,4,4,2,3,1,0,1,2,3,4,5,6,5,7,8,4,7,2,4,1,9,2};
int arrayTwo[] = {4,0,2,4,4,2,3,1,0,1,2,3,4,5,6,5,7,8,4,7,2,4,1,9,2,2,2,3,4,4,2,3,1,0,1,2,3,4,5,6,5,7,8,4,7,2,4,1,9,2};

void Calculo(int location){
    int F1,F2,i,j;
    long long int fat1=1, fat2=1,total=0;
    F1 = arrayOne[location];
    F2 = arrayTwo[location];
    for(i = F1; i > 0; i--){
        fat1 = fat1 * i;
    }
    for(j = F2; j > 0; j--){
        fat2 = fat2 * j;
    }
    total = fat1 + fat2;
    printf("Total : %d\n",total);
    Sleep(1000);
    total=0;
    fat1=1;
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
