
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define item int

item matResultado[2000][2000];
item mat1[2000][2000];
item mat2[2000][2000];
int dimensao;

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

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, multThread1, NULL);
    pthread_create(&thread2, NULL, multThread2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    for (int i = 0; i < dimensao; i++){
        for (int j = 0; j < dimensao; j++){
            printf(" %d", matResultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}