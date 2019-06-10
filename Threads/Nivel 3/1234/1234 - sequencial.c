#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

char arrayOne[][50] = {   "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avançada","Amalia","Ciência da Computação","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avançada","Amalia","Ciência da Computação","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avançada","Amalia","Ciência da Computação","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avançada","Amalia","Ciência da Computação","Threads","Uri Online Judge",
                        "Frase legal", "Frase Dois", "FRASE TRES","TESTE 123 TESTE","EXERCICIOS", "arquitetura avançada","Amalia","Ciência da Computação","Threads","Uri Online Judge"
                     };
void Calculo(int location){
    char frase[] = "";
    int j;
    char acesso='N';
    for(j = 0; j  < sizeof(arrayOne[location]); j++)
    {
        if(arrayOne[location][j]>='a' && arrayOne[location][j]<='z' && acesso=='N' || arrayOne[location][j]>='A' && arrayOne[location][j]<='Z' && acesso=='N')
        {
            frase[j]= toupper(frase[j]);
            acesso='H';
            printf("pvknm" + arrayOne[location][j] );
        }
        else if(arrayOne[location][j]>='a' && arrayOne[location][j]<='z' && acesso=='H' || arrayOne[location][j]>='A' && arrayOne[location][j]<='Z' && acesso=='H')
        {
            frase[j]= tolower(frase[j]);
            acesso='N';
        }
    }
    acesso='N';
    printf("\nFrase [] = %s\n", frase);
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


