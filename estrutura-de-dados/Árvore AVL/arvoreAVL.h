#include <iostream>
#include "aluno.h"

struct No{
  Aluno aluno;
  No* filhoesquerda;
  No* filhodireita;

  int fatorB;
};

class ArvoreAVL{
  private:
  No* raiz;

  public:
  ArvoreAVL();
  ~ArvoreAVL();
  void deletarArvore(No* NoAtual);
  No* obterRaiz();
  bool estavazio();
  bool estacheio();
  void inserir(Aluno aluno);
  void remover(Aluno aluno);
  void removerBusca(Aluno aluno, No*& noatual, bool& diminuiu);
  void deletarNo(No*& noatual, bool& dminuiu);
  void obterSucessor(Aluno& AlunoSucessor, No* temp);
  void buscar(Aluno& aluno, bool& busca);
  void imprimirpreordem(No* Noatual);
  void imprimiremordem(No* Noatual);
  void imprimirposordem(No* Noatual);
  

  // Novos métodos
  void rotacaodireita(No*& tree);
  void rotacaoesquerda(No*& tree);
  void rotacaoesquerdadireita(No*& tree);
  void rotacaodireitaesquerda(No*& tree);
  void realizarotacao(No*& tree);
  void insererecursivo(No*& noatual, Aluno aluno, bool& cresceu);
};