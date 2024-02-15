#include <iostream>
#include <cstddef>
#include <new>
#include "arvorebinaria.h"

using namespace std;

  ArvoreBinariadeBusca::ArvoreBinariadeBusca() // construtor
  {
    raiz = NULL;
  }

  ArvoreBinariadeBusca::~ArvoreBinariadeBusca() // destrutor
  {}

  void ArvoreBinariadeBusca::deletarArvore(No* NoAtual)
  {}

  No* ArvoreBinariadeBusca::obterRaiz()
  {
    return raiz;
  }

  bool ArvoreBinariadeBusca::estavazio()
  {
    return (raiz == NULL);
  }

  bool ArvoreBinariadeBusca::estacheio()
  {
    try {
      No* tmp = new No;
      delete tmp;
      return false;
    } catch (bad_alloc exception) {
      return true;
    }
  }

  void ArvoreBinariadeBusca::inserir(Aluno aluno)
  {}

  void ArvoreBinariadeBusca::remover(Aluno aluno)
  {}

  void ArvoreBinariadeBusca::buscar(Aluno& aluno, bool& busca)
  {}

  void imrimirpreordem(No* Noatual)
  {}

  void imprimiremordem(No* Noatual)
  {}

  