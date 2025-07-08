#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

#include "No.h"


class pilhadinamica{
  private:
  No* NoTopo;

  public:
  pilhadinamica();
  ~pilhadinamica();
  bool estavazio(); // isEmpty
  bool estacheio(); //isFull
  void inserir(TipoItem item); // push
  TipoItem remover(); //pop
  void imprimir();
};

#endif