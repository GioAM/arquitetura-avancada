#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#define NUM_THREADS 4

int endThreads, endThreadsBLOCKED,porThread;;

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
void *Thread(void *id){
    int comeco, fim, threadID;
    threadID = (int) id;
    comeco = porThread * threadID;
    fim = porThread * (threadID + 1);
    int i;
    threadID == NUM_THREADS-1 ? fim = fim + (50 % NUM_THREADS) : NULL;
    for(i = comeco; i < fim; i++){
        Calculo(i);
    }
    while(endThreadsBLOCKED);
    endThreadsBLOCKED = 1;
    endThreads++;
    endThreadsBLOCKED = 0;

    pthread_exit(NULL);

}
int main()
{
    time_t t_init, t_end;
    porThread = 50 / NUM_THREADS;
    pthread_t thread[NUM_THREADS];
    float tempo;
    int k;

    t_init = time(NULL);
    endThreads = endThreadsBLOCKED = 0;
    for(k = 0; k < NUM_THREADS; k++)
    {
        pthread_create(&thread[k],NULL,*Thread,(void *)k);
    }

    while(endThreads < NUM_THREADS); // fica aqui ate acabar todas as threads

    t_end = time(NULL);
    tempo = difftime(t_end, t_init);

    printf("\nTempo de execucao: %f\n", tempo);
    return 0;
}


