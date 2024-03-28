#include <iostream>
#include "aluno.h"

struct No{
  Aluno aluno;
  No* filhoesquerda;
  No* filhodireita;
};

class ArvoreBinariadeBusca{ //BST
  private:
  No* raiz;

  public:
  ArvoreBinariadeBusca();
  ~ArvoreBinariadeBusca();
  void deletarArvore(No* NoAtual);
  No* obterRaiz();
  bool estavazio();
  bool estacheio();
  void inserir(Aluno aluno);
  void remover(Aluno aluno);
  void removerBusca(Aluno aluno, No*& noatual);
  void deletarNo(No*& noatual);
  void obterSucessor(Aluno& AlunoSucessor, No* temp);
  void buscar(Aluno& aluno, bool& busca);
  void imprimirpreordem(No* Noatual);
  void imprimiremordem(No* Noatual);
  void imprimirposordem(No* Noatual);
  
};