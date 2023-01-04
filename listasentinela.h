#ifndef LISTAENC_H_
#define LISTAENC_H_

#include <stdio.h>
#include <stdlib.h>

#include "tipoitem.h"

typedef struct TipoCelula TipoCelula;
typedef struct TipoLista TipoLista;


TipoLista *CriaLista();

int Quantidade(TipoLista *l);

void Insere(TipoLista *Lista, int v);
void InsereOrdenado(TipoLista *Lista, int v);

void ImprimeLista(TipoLista *le);

void Retira (TipoLista *  l, int v);

#endif