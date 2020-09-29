/*
- Problema: https://moj.naquadah.com.br/contests/bcrFSO20201-exerciciofork/multiplica-matriz-fork.html#fnref1
- Codigo por: Erick Giffoni e Geise Saunier
- Universidade de Brasilia
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define item int

int main(){

    item mat1[2000][2000];
    item mat2[2000][2000];
    int dimensao = 0;
    scanf(" %d", &dimensao);
    //ler mat1
    for(int i=0; i<dimensao;i++)
        for(int j=0; j<dimensao; j++)
            scanf(" %d", &mat1[i][j]);
    //ler mat2
    for (int i = 0; i < dimensao; i++)
        for (int j = 0; j < dimensao; j++)
            scanf(" %d", &mat2[i][j]);
    
    item matResultado[dimensao][dimensao];

    //criar 2 filhos: cada um calcula o produto de um pedaco da matriz
    pid_t filho1 = fork();

    if(filho1==0){ // filho 1 calcula da linha 0 ate a dimensao/2 -1
        printf("sou o filho 1 : %d\n e meu pai e : %d\n", getpid(), getppid());
        
    }//end filho 1

    else{ //pai

        pid_t filho2 = fork();
        if(filho2==0){ //filho 2 calcula de dimensao/2 ate dimensao -1
            printf("sou o filho 2 : %d\ne meu pai e : %d\n", getpid(), getppid());
        }//end filho 2

        else{//pai fica aqui
            printf("sou o pai : %d\n", getpid());

        }//end pai
    }//end geral

    return 0;
}