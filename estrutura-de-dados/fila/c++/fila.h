// Fila = queue

typedef int TipoItem;
const int max_itens = 100;

class fila{
  private:
  int primeiro, ultimo;
  TipoItem* estrutura;

  public:
  fila();
  ~fila(); // Destrutor
  bool estavazio();
  bool estacheio();
  void inserir(TipoItem item); //  push // enqueue
  TipoItem remover(); // pop // dequeue
  void imprimir();
};