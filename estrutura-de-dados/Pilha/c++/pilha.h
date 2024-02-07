
// Como no c++ os vetores aceitam somente um tipo de dados, o "typdef"
// Serve para abstrair a declaração desses tipos em um unico ponto.
typedef int TipoItem;

const int max_itens = 100;


class pilha{
  private:
  int tamanho;
  TipoItem* estrutura; // Cria o vetor

  public:
  pilha(); // Função construtora - Tem que ter o mesmo tamanho da classe
  ~pilha(); // Função destrutora
  bool estacheia(); // Retorna se a pilha está cheia [1]
  bool estavazia(); // Retorna se a pilha está vazia
  void inserir(TipoItem item); // push
  TipoItem remover(); //pop
  void imprimir(); //print
  int qualotamanho(); //lenght
};


// [1] - Se a pilha está cheia não se pode adicionar itens e se
//       estiver fazia não tem como retirar itens.