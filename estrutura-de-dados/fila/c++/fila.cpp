#include <iostream>
#include "fila.h"

using namespace std;

  fila::fila()
  {
    primeiro = 0;
    ultimo = 0;
    estrutura = new TipoItem[max_itens];
  }

  fila::~fila() // Destrutor
  {
    delete [] estrutura;
  }

  bool fila::estavazio()
  {
    return (ultimo == primeiro);
  }

  bool fila::estacheio()
  {
    return (ultimo-primeiro == max_itens);
  }

  void fila::inserir(TipoItem item) //  push // enqueue
  {
    if(estacheio()){
      cout << "A Fila está cheia!\n";
      cout << "Esse elemento não pode ser inserido!\n";
    }else{
      estrutura[ultimo % max_itens] = item;
      ultimo++;
    }
  }

  TipoItem fila::remover() // pop // dequeue
  {
    if(estavazio()){
      cout << "A fila está vazia!\n";
      cout << "Nenhum elemento foi removido!\n";
      return 0;
    }else{
      primeiro++;
      return estrutura[(primeiro-1) % max_itens];
    }
  }

  void fila::imprimir()
  {
    cout << "fila: [ ";
    for(int i=primeiro; i < ultimo; i++){
      cout << estrutura[i % max_itens] << " ";
    }
    cout << " ]\n";
  }