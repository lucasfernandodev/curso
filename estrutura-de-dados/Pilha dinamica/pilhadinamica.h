typedef int TipoItem;

struct No // Node
{
  TipoItem valor;
  No* proximo;
};


class pilhadinamica{
  private:
  No* NoTopo;

  public:
  pilhadinamica();
  ~pilhadinamica();
  bool estavazio(); // isEmpty
  bool estacheio(); //isFull
  void inserir(TipoItem item); // push
  TipoItem remover(); //pop
  void imprimir();
};