
#include "tipoitem.h"

struct item{
  int conteudo;
  /** qualquer outro item*/
};

TipoItem *CriaItem(int v)
{
  TipoItem *t = malloc(sizeof(struct item));
  t->conteudo = v;
  return t;

}

int Conteudo(TipoItem *t)
{
  return t->conteudo;
}
