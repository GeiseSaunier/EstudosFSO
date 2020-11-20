#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

char s[10];

void trata_sinal(int signum){


    if (signum == SIGUSR1){

         if (scanf(" %s", s) != EOF){

            if (strcmp(s, "Igor3k") == 0){
                printf("Certo\n");
            } else {
                printf("Erro\n");       
            }
        } else {

            exit(0);
        }

    }

    else if (signum == SIGUSR2){

         if (scanf(" %s", s) != EOF){

            if (strcmp(s, "Monark") == 0) {
                printf("Certo\n");
            } else {
                printf("Erro\n");
            }
        } else {

            exit(0);
        }
    }     

    else if (signum == SIGINT){
      
         if (scanf(" %s", s) != EOF){

            if (strcmp(s, "Con1") ==0 ){
                printf("Certo\n");
            } else {
                printf("Erro\n");
            }
        } else {

            exit(0);
        }
    }      

    else if (signum == SIGTERM){

         if (scanf(" %s", s) != EOF){

            if (strcmp(s, "Con2") == 0){
                printf("Certo\n");
            } else {
                printf("Erro\n");
            }
        } else {

            exit(0);
        } 
    }     

    else if (signum == SIGALRM){

        if (scanf(" %s", s) != EOF){

            if (strcmp(s, "Silencio") == 0){
                printf("Certo\n");
            } else {
                printf("Erro\n");
            }
        } else {

            exit(0);
        }
    }
}

int main(void) {

    signal(SIGUSR1, trata_sinal);
    signal(SIGUSR2, trata_sinal);
    signal(SIGINT, trata_sinal);
    signal(SIGTERM, trata_sinal);
    signal(SIGALRM, trata_sinal);

    while (1)
        pause();

    return 0;
}