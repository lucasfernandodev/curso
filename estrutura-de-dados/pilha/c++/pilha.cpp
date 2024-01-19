#include <iostream>
#include "pilha.h"

using namespace std;

  pilha::pilha() // Função construtora - Tem que ter o mesmo tamanho da classe
  {
    tamanho = 0;
    estrutura = new TipoItem[max_itens];
  }

  pilha::~pilha() // Função destrutora
  {
    delete [] estrutura;
  }

  bool pilha::estacheia() // Retorna se a pilha está cheia [1]
  {
    return (tamanho == max_itens);
  }

  bool pilha::estavazia() // Retorna se a pilha está vazia
  {
    return (tamanho == 0);
  }

  void pilha::inserir(TipoItem item) // push
  {
    if(estacheia()){
      cout << "A pilha está cheia!\n";
      cout << "Não é possivel inserir este elemento!\n";
    }else{
      estrutura[tamanho] = item;
      tamanho++;
    }
  }

  TipoItem pilha::remover() //pop
  {
    if(estavazia()){
      cout << "A pilha está vazia!\n"; // pode add throw - para parar a fila e dar error
      cout << "Não tem elemento para ser removindo";
      return 0;
    }else{
      tamanho--;
      return estrutura[tamanho]; // posso ter que adicionar - 1, caso o tamnho-- ainda não tenha diminuido
    }
  }

  void pilha::imprimir() //print
  {
    cout << "Pilha: [";
    for(int i=0 ; i<tamanho; i++){
      cout << estrutura[i] << " ";
    }
    cout << "]\n";
  }

  int pilha::qualotamanho() //lenght
  {
    return tamanho;
  }