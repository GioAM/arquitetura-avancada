#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#define NUM_THREADS 4

int endThreads, endThreadsBLOCKED;
int porThread;
typedef struct
{
    int valorAsc;
    int frequencia;
} DADOS;

char arrayOne[][50] = { "AAABCBC", "AAABERBRFGCBC", "AAABBEDSCBC", "AAABCBSDVVXVSC","AA8416SDABCBC", "AAABCSDVDSVBC", "AAAS87ABCBC", "AAABASC56SCBC", "AABC", "AAA45VCBCBC",
                        "AAABCBC", "AAABERBRFGCBC", "AAABBEDSCBC", "AAABCBSDVVXVSC","AA8416SDABCBC", "AAABCSDVDSVBC", "AAAS87ABCBC", "AAABASC56SCBC", "AABC", "AAA45VCBCBC",
                        "AAABCBC", "AAABERBRFGCBC", "AAABBEDSCBC", "AAABCBSDVVXVSC","AA8416SDABCBC", "AAABCSDVDSVBC", "AAAS87ABCBC", "AAABASC56SCBC", "AABC", "AAA45VCBCBC",
                        "AAABCBC", "AAABERBRFGCBC", "AAABBEDSCBC", "AAABCBSDVVXVSC","AA8416SDABCBC", "AAABCSDVDSVBC", "AAAS87ABCBC", "AAABASC56SCBC", "AABC", "AAA45VCBCBC",
                        "AAABCBC", "AAABERBRFGCBC", "AAABBEDSCBC", "AAABCBSDVVXVSC","AA8416SDABCBC", "AAABCSDVDSVBC", "AAAS87ABCBC", "AAABASC56SCBC", "AABC", "AAA45VCBCBC"
                     };
boolean ordena (DADOS A, DADOS B){
    if (A.frequencia == B.frequencia){
        return A.valorAsc > B.valorAsc;
    }

    return A.frequencia < B.frequencia;
}
void frequencia(int location){
    char* linha = arrayOne[location];
    char letras[128];
    DADOS vet[100];
    int i;
    int cont = 0;
    for (i=32; i<128; i++){
        letras[i] = 0;
    }
    for (i=0; i<strlen(linha); i++){
        letras[linha[i]]++;
    }
    for (i=32; i< 128; i++){
        if (letras[i] != 0)
        {
            vet[cont].valorAsc = i;
            vet[cont].frequencia = letras[i];
            cont = cont+1;
        }
    }
    qsort(vet, 0, sizeof(vet), ordena);
    for (i=0; i<cont; i++){
        printf("Valor[%d] = %d : %d \n", location, vet[i].valorAsc, vet[i].frequencia);
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
        frequencia(i);
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


