#include <stdio.h>
#include <stdlib.h>

#include "listasentinela.h"


struct TipoCelula{
  TipoItem *item;
  struct TipoCelula * prox;
};

struct TipoLista{
  struct TipoCelula *primeiro;
  struct TipoCelula *ultimo;
  int qtde;
};

TipoLista *CriaLista()
{
  TipoLista *l = (TipoLista *)malloc(sizeof(TipoLista));
 
  l->primeiro = (TipoCelula *)malloc(sizeof(TipoCelula));

  //l->ultimo = (TipoCelula *)malloc(sizeof(TipoCelula));
  l->ultimo = l->primeiro;

  l->primeiro->prox = NULL;

  l->qtde = 0;

  return l;
}

int Vazia(TipoLista *Lista)
{ 
  return (Lista->primeiro == Lista->ultimo);
}

int Quantidade(TipoLista *l)
{
  return l->qtde;
}

void Insere(TipoLista *Lista, int v)
{ 
  Lista->ultimo->prox = (TipoCelula *)malloc(sizeof(TipoCelula));

  Lista->ultimo = Lista->ultimo->prox;

  Lista->ultimo->prox = NULL;
  Lista->ultimo->item = CriaItem(v);
  Lista->qtde++;

}

void InsereOrdenado(TipoLista *Lista, int v)
{ 

  //Lista vazia
  if (Vazia(Lista))
  {
    Insere(Lista,v);
    return;
  }
  //Ponteiros iniciais
  TipoCelula *ant = Lista->primeiro;
  TipoCelula *p = Lista->primeiro->prox;

  
  //Busca onde o conteudo tem que ser inserido
  while (p != NULL && Conteudo(p->item) < v)
  {
    ant = p;
    p = p->prox;    
  }

 TipoCelula *novo = (TipoCelula *)malloc(sizeof(TipoCelula));
 novo->item = CriaItem(v);

 //Atualiza os ponteiros para inserir uma nova celula
 // |ant|  ->   |p|->...      
 //     \|novo|/
 novo->prox =  ant->prox;
 ant->prox = novo;
 
 Lista->qtde++;

}

void ImprimeLista(TipoLista *le)
{
  TipoCelula * celula;

  celula = le->primeiro->prox;

  do{
    printf("%d\n", Conteudo(celula->item));
    celula = celula->prox;
  }while (celula != NULL);

/**  for (celula = le; celula != NULL; celula = celula->prox)
    printf("%d\n", Conteudo(celula->item));

*/
}

void Retira (TipoLista *  l, int v)
{
  TipoCelula *ant = l->primeiro;
  TipoCelula *p = l->primeiro->prox;

  while (p != NULL && Conteudo(p->item) != v)
  {
    ant = p;
    p = p->prox;    
  }
  if (p == NULL)
  {
    printf(" Erro   Lista vazia ou posi  cao nao existe\n");
     return;
  }
  

  if (p->prox == NULL)
  {
    l->ultimo = ant;
    l->ultimo->prox = NULL;
  }
    
  else
  {
    ant->prox = p->prox;
  }

  free(p->item);
  free(p);

  l->qtde--;
  
}
