#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#define NUM_THREADS 4
#include <math.h>
#include <stdbool.h>

int endThreads, endThreadsBLOCKED;
int porThread;
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


