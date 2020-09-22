/*
- Problema: https://moj.naquadah.com.br/contests/bcrFSO20201-exerciciofork/multiplica-matriz-fork.html#fnref1
- Codigo por: Erick Giffoni e Geise Saunier
- Universidade de Brasilia
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define item int

pid_t filho1, filho2, idPai;
item matResultado[2000][2000];
item mat1[2000][2000];
item mat2[2000][2000];
int dimensao;

void imprimeResultado(int signal){
    printf("alguem chamou imprimeResultado\n");
    if(signal == SIGTERM){ //sinal recebido do filho 1
        //pid_t filho1 = getpid(); //aqui esta dando errado : tinha que pegar o ID do filho
        printf("SIGTERM - sou %d e quem me chamou foi %d\n", getpid(), filho1);
        kill(filho1, SIGPIPE); //filho, imprime a matriz
    }
    else if(signal == SIGALRM){ //sinal recebido do filho 2
        //pid_t filho2 = getpid();
        printf("SIGALRM - sou %d e quem me chamou foi %d\n", getpid(), filho2);
        kill(filho2, SIGSYS); //filho, imprime a matriz
    }
    else if(signal == SIGPIPE){ // filho 1 imprime
        printf("SIGPIPE sou %d\n", getpid());
        for (int i = 0; i < dimensao; i++){
            if (i > (dimensao / 2) - 1)
                break;
            for (int j = 0; j < dimensao; j++){
                printf("%d ", matResultado[i][j]);
            }
            puts("\n");
        }
        //avisar o pai que acabou e morrer
        kill(idPai, SIGSEGV);
        exit(0); // ou kill(filho1, SIGKILL)
    }
    else if (signal == SIGSYS){ // filho 2 imprime
        printf("SIGSYS sou %d\n", getpid());
        for (int i = (dimensao/2); i < dimensao; i++){
            for (int j = 0; j < dimensao; j++){
                printf("%d ", matResultado[i][j]);
            }
            puts("\n");
        }
        //avisar o pai que acabou e morrer
        kill(idPai, SIGBUS);
        exit(0); // ou kill(filho2, SIGKILL)
    }
    else if(signal == SIGSEGV){ //filho 1 imprimiu e morreu
        //int num;
        //wait(&num);
        signal(SIGALRM, imprimeResultado); //quando filho 2 termina a conta
    }
    else if(signal == SIGBUS){ //filho 2 imprimiu e morreu
        //pai espera
        int num;
        wait(&num);
    }
}

int main(){

    scanf(" %d", &dimensao);
    //ler mat1
    for(int i=0; i<dimensao;i++)
        for(int j=0; j<dimensao; j++)
            scanf(" %d", &mat1[i][j]);
    //ler mat2
    for (int i = 0; i < dimensao; i++)
        for (int j = 0; j < dimensao; j++)
            scanf(" %d", &mat2[i][j]);

    idPai = getpid();

    //criar 2 filhos: cada um calcula o produto de um pedaco da matriz
    filho1 = fork();

    if(filho1==0){ // filho 1 calcula da linha 0 ate a dimensao/2 -1
        printf("sou o filho 1 : %d\n e meu pai e : %d\n", getpid(), getppid());
        for (int linha = 0; linha < dimensao; linha++){
            if(linha > (dimensao/2)-1 )
                break;
            for (int coluna = 0; coluna < dimensao; coluna++){
                for (int var = 0; var < dimensao; var++){
                    matResultado[linha][coluna] += mat1[linha][var] * mat2[var][coluna];
                }
            }
        }
        //enviar o sinal para papai
        kill(idPai, SIGTERM); //papai, terminei de calcular a matriz
        int num;
        //wait(&num);
        // receber o sinal do pai para print da matriz
        signal(SIGPIPE, imprimeResultado);
        wait(&num);
        //signal();

    }//end filho 1

    else{ //pai

        filho2 = fork();
        if(filho2==0){ //filho 2 calcula de dimensao/2 ate dimensao -1
            printf("sou o filho 2 : %d\ne meu pai e : %d\n", getpid(), getppid());
            //mat[0][1] * mat2[1][0] += res[0][0]
            //mat[1][1] * mat2[1][1]
            //mat[2][1] * mat2[1][2]
            for (int linha = (dimensao/2); linha < dimensao; linha++){
                for (int coluna = 0; coluna < dimensao; coluna++){
                    for (int var = 0; var < dimensao; var++){
                        matResultado[linha][coluna] += mat1[linha][var] * mat2[var][coluna];
                    }
                }
            }
            //enviar o sinal para papai
            kill(idPai, SIGALRM); //papai, terminei de calcular a matriz
            int num;
            wait(&num);
            // receber o sinal do pai para print da matriz
            signal(SIGSYS, imprimeResultado);

        }//end filho 2

        else{//pai fica aqui
            int num;
            printf("sou o pai : %d\n", getpid());
            signal(SIGTERM, imprimeResultado); //quando filho 1 avisa que terminou a conta
            signal(SIGSEGV, imprimeResultado); //quando filho 1 imprime e morre
            //wait(&num);
            //signal(SIGALRM, imprimeResultado); //quando filho 2 termina a conta
            wait(&num);
            signal(SIGBUS, imprimeResultado); //quando filho 2 imprime e morre

        }//end pai
    }//end geral

    return 0;
}