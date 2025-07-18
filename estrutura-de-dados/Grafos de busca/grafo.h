// Grafo Simples Direcionado ponderado
#include <iostream>
#include "No.h"
#include "pilhadinamica.h"
#include "filadinamica.h"

using namespace std;

// typedef string TipoItem;

class Grafo{
  private:
  int arestanula;
  int maxvertices;
  int numvertices;
  TipoItem* vertices;
  int** matrizadjacencias;
  bool* marcador;


  public:
  Grafo(int max, int valorarestanula);
  ~Grafo();
  int obterindice(TipoItem item);
  bool estacheio();
  void inserevertice(TipoItem item);
  void inserearesta(TipoItem Nosaida, TipoItem Noentrada, int peso);
  int obterpeso(TipoItem Nosaida, TipoItem Noentrada);
  int obtergrau(TipoItem item);
  void imprimirmatriz();
  void imprimirvertices();

  void limpamarcador();
  void buscaemlargura(TipoItem origem, TipoItem destino);
  void buscaemprofundidade(TipoItem origem, TipoItem destino);
};