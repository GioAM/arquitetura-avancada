#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#define NUM_THREADS 4

int endThreads, endThreadsBLOCKED;
int porThread;
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


