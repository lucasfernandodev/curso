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
  {
    if(estacheio()){
      cout << "A Arvore esta cheia!\n";
      cout << "Não foi possivel inserir esse elemento!\n";
    }else{
      No* NoNovo = new No;
      NoNovo->aluno = aluno;
      NoNovo->filhodireita = NULL;
      NoNovo->filhoesquerda = NULL;

      if(raiz == NULL){
        raiz = NoNovo;
      }else{
        No* tmp = raiz;
        while (tmp != NULL){
          if(aluno.obterRa() < tmp->aluno.obterRa()){
            if(tmp->filhoesquerda == NULL){
              tmp->filhoesquerda = NoNovo;
              break;
            }else{
              tmp = tmp->filhoesquerda;
            }
          }else{
            if(tmp->filhodireita == NULL){
              tmp->filhodireita = NoNovo;
              break;
            }else{
              tmp = tmp->filhodireita;
            }
          }
        }
      }
    }
  }

  void ArvoreBinariadeBusca::remover(Aluno aluno)
  {}

  void ArvoreBinariadeBusca::buscar(Aluno& aluno, bool& busca)
  {}

  void imrimirpreordem(No* Noatual)
  {}

  void imprimiremordem(No* Noatual)
  {}

  