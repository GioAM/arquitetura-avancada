#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

String arrayOne[] = {   "<..><.<..>>", "<><<..><.<..>>>", "<>","><","<.>", ">.<","<<<<>><>><><<><><>",">><><><><><><>><<>","<<<..<......<<<<....>","<<<..<......<<<<..<<..>>>>",
                        "<..><.<..>>", "<><<..><.<..>>>", "<>","><","<.>", ">.<","<<<<>><>><><<><><>",">><><><><><><>><<>","<<<..<......<<<<....>","<<<..<......<<<<..<<..>>>>",
                        "<..><.<..>>", "<><<..><.<..>>>", "<>","><","<.>", ">.<","<<<<>><>><><<><><>",">><><><><><><>><<>","<<<..<......<<<<....>","<<<..<......<<<<..<<..>>>>",
                        "<..><.<..>>", "<><<..><.<..>>>", "<>","><","<.>", ">.<","<<<<>><>><><<><><>",">><><><><><><>><<>","<<<..<......<<<<....>","<<<..<......<<<<..<<..>>>>",
                        "<..><.<..>>", "<><<..><.<..>>>", "<>","><","<.>", ">.<","<<<<>><>><><<><><>",">><><><><><><>><<>","<<<..<......<<<<....>","<<<..<......<<<<..<<..>>>>"
                     };
void Diamantes(int location){
    string frase = arrayOne[location];
    int count=0;
    stack<char> diamante;

    cin>>frase;

    for(int i = 0; i < frase.size(); i++){
        if(frase[i] == '<'){
            diamante.push('<');
        }else if(frase[i] == '>' and !diamante.empty()){
            diamante.pop();
            count++;
        }
    }
    cout<<count<<endl;
    count=0;
    while(!diamante.empty()){
        diamante.pop();
    }
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
        Diamantes(k);
    }
    t_end = time(NULL);
    tempo = difftime(t_end, t_init);

    printf("\nTempo de execucao: %f\n", tempo);
    return 0;
}


