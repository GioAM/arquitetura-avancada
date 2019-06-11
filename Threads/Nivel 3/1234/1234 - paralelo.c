#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#define NUM_THREADS 4

int endThreads, endThreadsBLOCKED;
int porThread;
char arrayOne[][50] = {   "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avancada","Amalia","Ciencia da Computacao","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avancada","Amalia","Ciencia da Computacao","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avancada","Amalia","Ciencia da Computacao","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avancada","Amalia","Ciencia da Computacao","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avancada","Amalia","Ciencia da Computacao","Threads","Uri Online Judge"
                     };
void setencaDancante(int location){
    char* frase;
    frase = arrayOne[location];
    int j;
    char acesso='N';
    for(j = 0; j  < sizeof(arrayOne[location]); j++)
    {
        if(arrayOne[location][j]>='a' && arrayOne[location][j]<='z' && acesso=='N' || arrayOne[location][j]>='A' && arrayOne[location][j]<='Z' && acesso=='N')
        {
            frase[j]= toupper(frase[j]);
            acesso='H';
        }
        else if(arrayOne[location][j]>='a' && arrayOne[location][j]<='z' && acesso=='H' || arrayOne[location][j]>='A' && arrayOne[location][j]<='Z' && acesso=='H')
        {
            frase[j]= tolower(frase[j]);
            acesso='N';
        }
    }
    acesso='N';
    printf("Frase [%d] = %s\n", location, frase);
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
        setencaDancante(i);
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


