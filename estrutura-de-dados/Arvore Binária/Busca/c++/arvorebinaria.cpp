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
  {
    removerBusca(aluno, raiz);
  }

  void ArvoreBinariadeBusca::removerBusca(Aluno aluno, No*& noatual)
  {
    if(aluno.obterRa() < noatual->aluno.obterRa()){
      removerBusca(aluno, noatual->filhoesquerda);
    }else if(aluno.obterRa() > noatual->aluno.obterRa()){
      removerBusca(aluno, noatual->filhodireita);
    }else{
      deletarNo(noatual);
    }
  }

  void ArvoreBinariadeBusca::deletarNo(No*& noatual)
  {
    No* temp = noatual;
    if(noatual->filhoesquerda == NULL){
      noatual = noatual->filhodireita;
      delete temp;
    }else if(noatual->filhodireita == NULL){
      noatual = noatual->filhodireita;
      delete temp;
    }else{
      Aluno AlunoSucessor;
      obterSucessor(AlunoSucessor, noatual);
      noatual->aluno = AlunoSucessor;
      removerBusca(AlunoSucessor,noatual->filhodireita);
    }
  }

  void ArvoreBinariadeBusca::obterSucessor(Aluno& AlunoSucessor, No* temp)
  {
    temp = temp->filhodireita;
    while (temp->filhoesquerda != NULL){
      temp = temp->filhoesquerda;
    }
    AlunoSucessor = temp->aluno;
  }

  void ArvoreBinariadeBusca::buscar(Aluno& aluno, bool& busca)
  {
    busca = false;
    No* noatual = raiz;
    while(noatual != NULL){
      if(aluno.obterRa() < noatual->aluno.obterRa()){
        noatual = noatual->filhoesquerda;
      }else if(aluno.obterRa() > noatual->aluno.obterRa()){
        noatual = noatual->filhodireita; 
      }else{
        busca = true;
        aluno = noatual->aluno;
        break;
      }
    }
  }

  void imrimirpreordem(No* Noatual)
  {}

  void imprimiremordem(No* Noatual)
  {}

  