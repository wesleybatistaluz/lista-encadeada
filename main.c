#include <stdio.h>
#include <sys/time.h>


#define MAX 10

#include "listasentinela.h"


int main(void) {

 
 /*
  Como criar um item 
  TipoItem *t;
  t = CriaItem(20);*/

  struct timeval t;
  gettimeofday(&t,NULL);
  unsigned int s = (unsigned int)t.tv_usec;
  srand(674434);
  printf("S: %d\n",s);
  int vetor[MAX];


  TipoLista *lista = NULL;
  lista = CriaLista();


   /*Insere cada chave na lista */
  for (int i = 0; i < MAX; i++)
  { 
    
    int k  = (int) (100.0 * rand()/(RAND_MAX + 1.0));
    vetor[i] = k;

    InsereOrdenado(lista, k);
  }
  ImprimeLista(lista);

  
 /*escolhe uma chave aleatoriamente */
  int k = (int) ( rand() % MAX);
  printf("Retirou: %d %d\n",  k, vetor[k]);
      /*retira chave apontada */
  Retira(lista, vetor[k]);

  ImprimeLista(lista);






  return 0;
}