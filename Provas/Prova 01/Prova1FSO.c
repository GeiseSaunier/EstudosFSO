
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int i = 0;

void trata_sinal(int signum)
{

    if (signum == SIGTERM)
    {       
        printf("Recebi %d\n", signum);
        if (i == 2)
        {
            i = 3;
            printf("Senha acionada\n");
        }
        else
        {
            i = 0;
        }
    }
    else if (signum == SIGUSR1)
    {
        printf("Recebi %d\n", signum);
        if (i == 3)
        {
            i = 4;
            printf("Tchau\n");
            exit(0);
        }
        else
        {
            i = 0;
        }
    }
    else if (signum == SIGUSR2)
    {

        if (i == 1)
            i = 2;
        else
            i = 0;
        printf("Recebi %d\n", signum);
    }

    else if (signum == SIGINT)
{
    printf("Recebi %d\n", signum);
    i = 1;

    }
}


int main(void)
{

    signal(SIGUSR1, trata_sinal);
    signal(SIGUSR2, trata_sinal);
    signal(SIGTERM, trata_sinal);
    signal(SIGINT, trata_sinal);
    while (1)
        pause;

    return 0;
}