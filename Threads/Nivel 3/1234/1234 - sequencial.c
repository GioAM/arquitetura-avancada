#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

String arrayOne[] = {   "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avançada","Amalia","Ciência da Computação","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avançada","Amalia","Ciência da Computação","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avançada","Amalia","Ciência da Computação","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avançada","Amalia","Ciência da Computação","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avançada","Amalia","Ciência da Computação","Threads","Uri Online Judge"
                     };
void Calculo(int location){
    frase = arrayOne[location];
    int j;
    char acesso='N';
    for(j = 0; j< frase.size(); j++)
    {
        if(frase[j]>='a' and frase[j]<='z' and acesso=='N' or frase[j]>='A' and frase[j]<='Z' and acesso=='N')
        {
            frase[j]= toupper(frase[j]);
            acesso='H';
        }
        else if(frase[j]>='a' and frase[j]<='z' and acesso=='H' or frase[j]>='A' and frase[j]<='Z' and acesso=='H')
        {
            frase[j]= tolower(frase[j]);
            acesso='N';
        }
    }
    acesso='N';
    printf("\nFrase [%d] = " + frase , location);
    Sleep(1000);
}
int main()
{
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


