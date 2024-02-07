#include "hash.h"
#include <iostream>

using namespace std;

int main() {
  cout << "Programa gerador de Hash\n";
  int tam_vetor, max;
  cout << "Digite o tamanho da hash!\n";
  cin >> tam_vetor;
  cout << "Digite o número maximo de elementos!\n";
  cin >> max;
  cout << "O fator de carga é: " << (float)max / (float)tam_vetor << endl;

  Hash alunoHash(tam_vetor, max);
  int opcao;
  int ra;
  string nome;
  bool busca;

  do {
    cout << "Digite 0 para parar o algoritmo!\n";
    cout << "Digite 1 para inserir um elemento!\n";
    cout << "Digite 2 para remover um elemento!\n";
    cout << "Digite 3 para buscar um elemento!\n";
    cout << "digite 4 para imprimir a Hash!\n";
    cin >> opcao;

    if (opcao == 1) {
      cout << "Qual e o RA do aluno?\n";
      cin >> ra;
      cout << "Qual e o nome do aluno?\n";
      cin >> nome;

      Aluno aluno(ra, nome);
      alunoHash.inserir(aluno);

    } else if (opcao == 2) {
      cout << "Qual e o RA do aluno?\n";
      cin >> ra;
      Aluno aluno(ra, " ");
      alunoHash.deletar(aluno);

    } else if (opcao == 3) {
      cout << "Qual e o RA do aluno a ser buscado?\n";
      cin >> ra;
      Aluno aluno(ra, " ");
      alunoHash.buscar(aluno, busca);

      if (busca) {
        cout << "Aluno encontrado: \n";
        cout << "RA: " << aluno.obterRa() << endl;
        cout << "Nome do aluno: " << aluno.obterNome() << endl;
      } else {
        cout << "Aluno não encontrado!\n";
      }
    } else if (opcao == 4) {
      alunoHash.imprimir();
    }
  } while (opcao != 0);

  return 0;
}