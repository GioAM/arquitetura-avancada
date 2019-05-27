#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#define NUM_THREADS 4

int endThreads, endThreadsBLOCKED,porThread;;
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
    printf("Total [%d] : %d\n",location,total);
    Sleep(1000);
    total=0;
    fat1=1;
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


