/*
- Problema: https://moj.naquadah.com.br/contests/bcrFSO20201-exerciciothread/multiplica-matriz-fork.html
- Codigo por: Erick Giffoni
- Universidade de Brasilia, 2020
*/

#include <stdio.h>
#include <pthread.h> // compile with -pthread

int matResultado[2000][2000];
int mat1[2000][2000];
int mat2[2000][2000];
int dimensao;
int option;

void read_matrix(){
    scanf(" %d", &dimensao);
    //ler mat1
    for (int i = 0; i < dimensao; i++)
        for (int j = 0; j < dimensao; j++)
            scanf(" %d", &mat1[i][j]);
    //ler mat2
    for (int i = 0; i < dimensao; i++)
        for (int j = 0; j < dimensao; j++)
            scanf(" %d", &mat2[i][j]);
}

void * compute_result(void * option){
    switch ( * ( (int *)option ) ){
    case 0: //computes and prints first half
        for (int linha = 0; linha < dimensao; linha++){
            if (linha > (dimensao / 2) - 1)
                break;
            for (int coluna = 0; coluna < dimensao; coluna++){
                for (int var = 0; var < dimensao; var++){
                    matResultado[linha][coluna] += mat1[linha][var] * mat2[var][coluna];
                }//end for mult
            }//end for column
        }//end for line
        // print
        for (int i = 0; i < dimensao; i++){
            if (i > (dimensao / 2) - 1)
                break;
            for (int j = 0; j < dimensao; j++){
                printf("%d ", matResultado[i][j]);
            }
            puts("");
        }//end for print
        break;

    case 1: //computes and prints last half
        for (int linha = (dimensao / 2); linha < dimensao; linha++){
            for (int coluna = 0; coluna < dimensao; coluna++){
                for (int var = 0; var < dimensao; var++){
                    matResultado[linha][coluna] += mat1[linha][var] * mat2[var][coluna];
                }//end for mult
            }//end for column
        }//end for line
        // print
        for (int i = (dimensao / 2); i < dimensao; i++){
            for (int j = 0; j < dimensao; j++){
                printf("%d ", matResultado[i][j]);
            }
            puts("");
        }//end for print
        break;
    
    default:
        break;
    }//end switch
    return 0;
}

int main(){

    read_matrix();
    pthread_t pth1, pth2;
    option = 0;
    pthread_create(&pth1, NULL, &compute_result, (void *)&option);
    pthread_join(pth1, NULL);
    option = 1;
    pthread_create(&pth2, NULL, &compute_result, (void *)&option);
    pthread_join(pth2, NULL);

    return 0;
}
