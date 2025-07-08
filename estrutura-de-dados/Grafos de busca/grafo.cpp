#include "grafo.h"
#include "No.h"
#include "filadinamica.h"
#include "pilhadinamica.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int max, int valorarestanula) { // construtor
  numvertices = 0;
  maxvertices = max;
  arestanula = valorarestanula;

  marcador = new bool[maxvertices];
  vertices = new TipoItem[maxvertices];

  // Criando um vetor de um vetor de inteiros
  matrizadjacencias = new int *[maxvertices];
  for (int i = 0; i < maxvertices; i++) {
    matrizadjacencias[i] = new int[maxvertices];
  }

  for (int i = 0; i < maxvertices; i++) {
    for (int j = 0; j < maxvertices; j++) {
      matrizadjacencias[i][j] = arestanula;
    }
  }
}

Grafo::~Grafo() { // destrutor
  delete[] vertices;
  for (int i = 0; i < maxvertices; i++) {
    delete[] matrizadjacencias[i];
  }
  delete[] matrizadjacencias;
}

int Grafo::obterindice(TipoItem item) {
  int indice = 0;
  while (indice < numvertices && item != vertices[indice]) {
    indice++;
  }

  if (vertices[indice] != item) {
    indice = -1;
  }

  return indice;
}

bool Grafo::estacheio() { return (numvertices == maxvertices); }

void Grafo::inserevertice(TipoItem item) {
  if (estacheio()) {
    cout << "O número maximo de vertices foi alcancado!\n";
  } else {
    vertices[numvertices] = item;
    numvertices++;
  }
}

void Grafo::inserearesta(TipoItem Nosaida, TipoItem Noentrada, int peso) {
  int linha = obterindice(Nosaida);
  int coluna = obterindice(Noentrada);

  matrizadjacencias[linha][coluna] = peso;
  // matrizadjacencias[coluna][linha] = peso; // Remover se for direcionado; 
}

int Grafo::obterpeso(TipoItem Nosaida, TipoItem Noentrada) {
  int linha = obterindice(Nosaida);
  int coluna = obterindice(Noentrada);

  if (linha != -1 && coluna != -1) {
    return (matrizadjacencias[linha][coluna]);
  }

  return -1;
}

int Grafo::obtergrau(TipoItem item) {
  int linha = obterindice(item);
  if (linha != -1) {
    int grau = 0;
    for (int i = 0; i < maxvertices; i++) {
      if (matrizadjacencias[linha][i] != arestanula) {
        grau++;
      }
    }

    return grau;
  }
  return -1;
}

void Grafo::imprimirmatriz() {
  cout << "Matriz de adjacencias:\n";
  for (int linha = 0; linha < maxvertices; linha++) {
    for (int coluna = 0; coluna < maxvertices; coluna++) {
      cout << matrizadjacencias[linha][coluna] << " ";
    }
    cout << endl;
  }
}

void Grafo::imprimirvertices() {
  cout << "Lista de Vertices:\n";
  for (int i = 0; i < numvertices; i++) {
    cout << i << ": " << vertices[i] << endl;
  }
}

void Grafo::limpamarcador() {
  for (int i = 0; i < maxvertices; i++) {
    marcador[i] = false;
  }
}

void Grafo::buscaemlargura(TipoItem origem, TipoItem destino) {
  filadinamica filavertices;
  bool encontrado = false;
  limpamarcador();
  filavertices.inserir(origem);
  do {
    TipoItem verticeatual = filavertices.remover();
    if (verticeatual == destino) {
      cout << "visitando: " << verticeatual << endl;
      cout << "Caminho encontrado! \n";
      encontrado = true;
    } else {
      int indice = obterindice(verticeatual);
      cout << "Visitando: " << verticeatual << endl;
      for (int i = 0; i < maxvertices; i++) {
        if (matrizadjacencias[indice][i] != arestanula) {
          if (!marcador[i]) {
            cout << "Enfileirando: " << vertices[i] << endl;
            filavertices.inserir(vertices[i]);
            marcador[i] = true;
          }
        }
      }
    }
  } while (!filavertices.estavazio() && !encontrado);
  if (!encontrado) {
    cout << "caminho não encontrado!\n";
  }
}

void Grafo::buscaemprofundidade(TipoItem origem, TipoItem destino) {
  pilhadinamica pilhavertices;
  bool encontrado = false;
  limpamarcador();
  pilhavertices.inserir(origem);
  do {
    TipoItem verticeatual = pilhavertices.remover();
    if (verticeatual == destino) {
      cout << "Visitando: " << verticeatual << endl;
      cout << "Caminho encontrado!\n";
      encontrado = true;
    } else {
      int indice = obterindice(verticeatual);
      cout << "Visitando: " << verticeatual << endl;
      for (int i = 0; i < maxvertices; i++) {
        if (matrizadjacencias[indice][i] != arestanula) {
          if (!marcador[i]) {
            cout << "Empilhando: " << vertices[i] << endl;
            pilhavertices.inserir(vertices[i]);
            marcador[i] = true;
          }
        }
      }
    }
  } while (!pilhavertices.estavazio() && !encontrado);
  if (!encontrado) {
    cout << "caminho não encontrado!\n";
  }
}