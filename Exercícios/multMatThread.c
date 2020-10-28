
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>

#define item int

pid_t filho1, filho2, idPai;
item matResultado[2000][2000];
item mat1[2000][2000];
item mat2[2000][2000];
int dimensao;

void imprimeResultado(int signal){
    //printf("alguem chamou imprimeResultado\n");
    if(signal == SIGTERM){ //sinal recebido do filho 1
        //printf("SIGTERM - sou %d e quem me chamou foi %d\n", getpid(), filho1);
        pause();
    }
    else if(signal == SIGALRM){ //sinal recebido do filho 2
        //printf("SIGALRM - sou %d e quem me chamou foi %d\n", getpid(), filho2);
        kill(filho1, SIGPIPE); //filho, imprime a matriz
        //printf("mandei o SIGPIPE pro filho 1\n");
    }
    else if(signal == SIGPIPE){ // filho 1 imprime
        //printf("SIGPIPE sou %d\n", getpid());
        for (int i = 0; i < dimensao; i++){
            if (i > (dimensao / 2) - 1)
                break;
            for (int j = 0; j < dimensao; j++){
                printf("%d ", matResultado[i][j]);
            }
            puts("");
        }
        //avisar o pai que acabou e morrer
        kill(idPai, SIGSEGV);
        //printf("FILHO 1 - MORRI\n");
        exit(0); // ou kill(filho1, SIGKILL)
    }
    else if (signal == SIGSYS){ // filho 2 imprime
        //printf("SIGSYS sou %d\n", getpid());
        for (int i = (dimensao/2); i < dimensao; i++){
            for (int j = 0; j < dimensao; j++){
                printf("%d ", matResultado[i][j]);
            }
            puts("");
        }
        //avisar o pai que acabou e morrer
        kill(idPai, SIGBUS);
        //printf("FILHO 2 - MORRI\n");
        exit(0); // ou kill(filho2, SIGKILL)
    }
    else if(signal == SIGSEGV){ //filho 1 imprimiu e morreu
        kill(filho2, SIGSYS); // filho 2, imprime aee
        pause();
    }
    else if(signal == SIGBUS){ //filho 2 imprimiu e morreu
        //pai espera
        //printf("SIGBUS - filhos morreram... pai morre\n");
        exit(0);
    }
}

void* multThread1() {
    for (int linha = 0; linha < dimensao; linha++){
        if(linha > (dimensao/2)-1 )
            break;
        for (int coluna = 0; coluna < dimensao; coluna++){
            for (int var = 0; var < dimensao; var++){
                matResultado[linha][coluna] += mat1[linha][var] * mat2[var][coluna];
            }
        }
    }
}

void* multThread2() {
    for (int linha = (dimensao/2); linha < dimensao; linha++){
        for (int coluna = 0; coluna < dimensao; coluna++){
            for (int var = 0; var < dimensao; var++){
                matResultado[linha][coluna] += mat1[linha][var] * mat2[var][coluna];
            }
        }
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
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, multThread1, NULL);
    pthread_kill(thread1, SIGTERM);
    pthread_join(thread1, NULL);
    pthread_create(&thread2, NULL, multThread2, NULL);


        else{//pai fica aqui
            //printf("sou o pai : %d\n", getpid());
            signal(SIGTERM, imprimeResultado); //quando filho 1 avisa que terminou a conta
            signal(SIGALRM, imprimeResultado); //quando filho 2 termina a conta
            signal(SIGSEGV, imprimeResultado); //quando filho 1 imprime e morre
            signal(SIGBUS, imprimeResultado); //quando filho 2 imprime e morre
            pause();
            wait(NULL);

        }//end pai
    }//end geral

    return 0;
}