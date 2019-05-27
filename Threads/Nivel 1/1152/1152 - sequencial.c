#include <windows.h>
#include <time.h>
#include <math.h>

int array[] = {4,12,11,10,8,2,3,1,9,1,2,3,4,5,6,5,7,8,4,7,2,4,1,9,2,2,2,3,4,4,2,3,1,2,1,2,3,4,5,6,5,7,8,4,7,2,4,1,9,2};

void Calculo(int location){
    int mes = array[location];
    printf("[%d]",location);
    if (mes == 1){
        printf("January\n");
    }
    else if (mes == 2){
        printf("February\n");
    }
    else if (mes == 3){
        printf("March\n");
    }
    else if (mes == 4){
        printf("April\n");
    }
    else if (mes == 5){
        printf("May\n");
    }
    else if (mes == 6){
        printf( "June\n");
    }
    else if (mes == 7){
        printf("July\n");
    }
    else if (mes == 8){
        printf("August\n");
    }
    else if (mes == 9){
        printf("September\n");
    }
    else if (mes == 10){
        printf("October\n");
    }
    else if (mes == 11){
        printf( "November\n");
    }
    else if (mes == 12){
        printf("December\n");
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
