#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int v1[10000000], v2[10000000], TAM, i=0;

  void le_tamvetores() {
    scanf("%d", &TAM);
    if (TAM < 2){
      exit(0); 
  }
}

  void le_v1() {

    for (i=0; i<TAM; i++) {
      scanf("%d", &v1[i]);

    }

  }

   void le_v2() {

      for (i=0; i<TAM; i++) {
      scanf("%d", &v2[i]);

    }

  }

   
int Compara(void *v1, void *v2) {
   if (*(int*)v1 > *(int*)v2) {
      return 1;
   } else if (*(int*)v1 < *(int*)v2) {
      return -1;
   } else {
      return 0;
   }
}

  void Ordena1(void *a) {
    
  qsort (v1, TAM, sizeof(int), (void*)Compara);
  pthread_exit(NULL);
  }

  void Ordena2(void*a){

  qsort (v2, TAM, sizeof(int), (void*)Compara);
  pthread_exit(NULL);
  }
 

pthread_t t1, t2;

int main() {

  le_tamvetores();
  le_v1();
  le_v2();
 

  pthread_create(&t1, NULL, (void*)Ordena1, NULL);
  pthread_create(&t2, NULL, (void*)Ordena2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  int cont=0;
  for (i=0; i<TAM; i++){
    if(v1[i]==v2[i]){
      cont++;
    }
  }
  if (cont == TAM){
        printf("Mesmos elementos\n");
    } else {
       printf("Diferentes\n");
      }
  pthread_exit(NULL);
    return 0;
}