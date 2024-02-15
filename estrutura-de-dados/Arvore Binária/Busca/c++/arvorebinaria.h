#include <iostream>
#include "aluno.h"

struct No{
  Aluno aluno;
  No* filhoesquerda;
  No* filhodireita;
};

class ArvoreBinariadeBusca{ //BST
  public:
  No* raiz;

  private:
  ArvoreBinariadeBusca();
  ~ArvoreBinariadeBusca();
  void deletarArvore(No* NoAtual);
  No* obterRaiz();
  bool estavazio();
  bool estacheio();
  void inserir(Aluno aluno);
  void remover(Aluno aluno);
  void buscar(Aluno& aluno, bool& busca);
  void imrimirpreordem(No* Noatual);
  void imprimiremordem(No* Noatual);
  
};