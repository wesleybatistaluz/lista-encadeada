#ifndef TIPOITEM_H_
#define TIPOITEM_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct item TipoItem;

TipoItem *CriaItem(int v);

int Conteudo(TipoItem *t);

#endif