#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

int n, num, a, b, i, resultado_a, resultado_b;

int calcule_sequaseprimo_maluco(int n)
{

    if (n == 1 || n % 2 == 0)
        return 0;

    int count = 0;

    for (int i = 3, f = floor(sqrt(n)); i < f; i += 2)
        if (n % i == 0 && i < 11)
            return 0;
        else if (n % i == 0 && i > 10)
            count++;

    if (count >= 10)
        return 1;
    return 0;
}

void *thread1(void *parametro)
{
    while (calcule_sequaseprimo_maluco(a) == 0)
    {
        a++;
    }
    resultado_a = a;
}

void *thread2(void *parametro)
{
    while (calcule_sequaseprimo_maluco(b) == 0)
    {
        b++;
    }
    resultado_b = b;
}

int main(void)
{
    pthread_t t1, t2;
    scanf("%d", &num);

    while (1)
    {
        if (scanf("%d", &a) != 1)
        {
            break;
        }

            pthread_create(&t1, NULL, &thread1, NULL);

        if (scanf("%d", &b) != 1)
        {
            pthread_join(t1, NULL);
            printf("%d\n", resultado_a);
            break;
        }

       
            pthread_create(&t2, NULL, &thread2, NULL);

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        printf("%d\n", resultado_a);
        printf("%d\n", resultado_b);
    }

    return 0;
}