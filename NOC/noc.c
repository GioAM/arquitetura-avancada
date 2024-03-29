#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#define NUM_THREADS 5

int endThreads, endThreadsBLOCKED;
int porThread;
char mensagem;
pthread_t thread[NUM_THREADS];
pthread_t threadMessage[NUM_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexMessage = PTHREAD_MUTEX_INITIALIZER;

int nextId(int id){
    id ++;
    if(id >= NUM_THREADS){
        return 0;
    }
    return id;
}
void *doMensagem(void *id){
    pthread_mutex_lock(&mutexMessage);
    printf("Roteador %d recebendo mensagem = %c\n", id, mensagem);
    Sleep(1000);
    pick();
    printf("Roteador %d enviando mensagem = %c\n", id, mensagem);
    Sleep(1000);
    pthread_mutex_unlock(&mutexMessage);
    pthread_exit(NULL);
}
void pick() {
    char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    time_t t;
    srand((unsigned) time(&t));
    mensagem = abc[rand() % 26]; // 3
    return;
}
void *Thread(void *id){
    pthread_mutex_lock(&mutex);
    int idRoteador = (int) id;
    pthread_create(&threadMessage[idRoteador], NULL, *doMensagem, (void *) idRoteador);
    pthread_create(&thread[nextId(idRoteador)], NULL, *Thread, (void *) nextId(idRoteador));
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
int main()
{
    pthread_create(&thread[0],NULL,*Thread,(void *)0);
    while(1); // fica aqui ate acabar todas as threads
    return 0;
}
