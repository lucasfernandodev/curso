#include "arvoreAVL.h"
#include <cstddef>
#include <iostream>
#include <new>

using namespace std;

ArvoreAVL::ArvoreAVL() // construtor
{
  raiz = NULL;
}

ArvoreAVL::~ArvoreAVL() // destrutor
{
  deletarArvore(raiz);
}

void ArvoreAVL::deletarArvore(No *NoAtual) {
  if (NoAtual != NULL) {
    deletarArvore(NoAtual->filhoesquerda);
    deletarArvore(NoAtual->filhodireita);
    delete NoAtual;
  }
}

No *ArvoreAVL::obterRaiz() { return raiz; }

bool ArvoreAVL::estavazio() { return (raiz == NULL); }

bool ArvoreAVL::estacheio() {
  try {
    No *tmp = new No;
    delete tmp;
    return false;
  } catch (bad_alloc exception) {
    return true;
  }
}

void ArvoreAVL::inserir(Aluno aluno) {
  bool cresceu;
  insererecursivo(raiz, aluno, cresceu);
}

void ArvoreAVL::insererecursivo(No *&noatual, Aluno aluno, bool &cresceu) {
  if (noatual == NULL) {
    noatual = new No;
    noatual->filhoesquerda = NULL;
    noatual->filhodireita = NULL;
    noatual->aluno = aluno;
    noatual->fatorB = 0;
    cresceu = true;
    return;
  }

  if (aluno.obterRa() < noatual->aluno.obterRa()) {
    insererecursivo(noatual->filhoesquerda, aluno, cresceu);
    if (cresceu) {
      noatual->fatorB -= 1;
    }
  } else {
    insererecursivo(noatual->filhodireita, aluno, cresceu);
    if (cresceu) {
      noatual->fatorB += 1;
    }
  }

  realizarotacao(noatual);

  if (cresceu && noatual->fatorB == 0) {
    cresceu = false;
  }
}

void ArvoreAVL::remover(Aluno aluno) {
  bool diminuiu;
  removerBusca(aluno, raiz, diminuiu);
}

void ArvoreAVL::removerBusca(Aluno aluno, No *&noatual, bool &diminuiu) {
  if (aluno.obterRa() < noatual->aluno.obterRa()) {
    removerBusca(aluno, noatual->filhoesquerda, diminuiu);
  } else if (aluno.obterRa() > noatual->aluno.obterRa()) {
    removerBusca(aluno, noatual->filhodireita, diminuiu);
    if (diminuiu) {
      noatual->fatorB -= 1;
    }
  } else {
    deletarNo(noatual, diminuiu);
  }

  if (noatual != NULL) {
    realizarotacao(noatual);
    if (diminuiu && noatual->fatorB != 0) {
      diminuiu = false;
    }
  }
}

void ArvoreAVL::deletarNo(No *&noatual, bool &diminuiu) {
  No *temp = noatual;
  if (noatual->filhoesquerda == NULL) {
    noatual = noatual->filhodireita;
    diminuiu = true;
    delete temp;
  } else if (noatual->filhodireita == NULL) {
    noatual = noatual->filhodireita;
    diminuiu = true;
    delete temp;
  } else {
    Aluno AlunoSucessor;
    obterSucessor(AlunoSucessor, noatual);
    noatual->aluno = AlunoSucessor;
    removerBusca(AlunoSucessor, noatual->filhodireita, diminuiu);
    if (diminuiu) {
      noatual->fatorB -= 1;
    }
  }
}

void ArvoreAVL::obterSucessor(Aluno &AlunoSucessor, No *temp) {
  temp = temp->filhodireita;
  while (temp->filhoesquerda != NULL) {
    temp = temp->filhoesquerda;
  }
  AlunoSucessor = temp->aluno;
}

void ArvoreAVL::buscar(Aluno &aluno, bool &busca) {
  busca = false;
  No *noatual = raiz;
  while (noatual != NULL) {
    if (aluno.obterRa() < noatual->aluno.obterRa()) {
      noatual = noatual->filhoesquerda;
    } else if (aluno.obterRa() > noatual->aluno.obterRa()) {
      noatual = noatual->filhodireita;
    } else {
      busca = true;
      aluno = noatual->aluno;
      break;
    }
  }
}

void ArvoreAVL::imprimirpreordem(No *Noatual) {
  if (Noatual != NULL) {
    cout << Noatual->aluno.obterNome() << ": ";
    cout << Noatual->aluno.obterRa() << endl;

    imprimirpreordem(Noatual->filhoesquerda);
    imprimirpreordem(Noatual->filhodireita);
  }
}

void ArvoreAVL::imprimiremordem(No *Noatual) {
  if (Noatual != NULL) {
    imprimiremordem(Noatual->filhoesquerda);
    cout << Noatual->aluno.obterNome() << ": ";
    cout << Noatual->aluno.obterRa() << endl;
    imprimiremordem(Noatual->filhodireita);
  }
}

void ArvoreAVL::imprimirposordem(No *Noatual) {
  if (Noatual != NULL) {
    imprimirposordem(Noatual->filhoesquerda);
    imprimirposordem(Noatual->filhodireita);
    cout << Noatual->aluno.obterNome() << ": ";
    cout << Noatual->aluno.obterRa() << endl;
  }
}

void ArvoreAVL::rotacaodireita(No *&pai) {
  No *novopai = pai->filhoesquerda;
  pai->filhoesquerda = novopai->filhodireita;
  novopai->filhodireita = pai;
  pai = novopai;
}

void ArvoreAVL::rotacaoesquerda(No *&pai) {
  No *novopai = pai->filhodireita;
  pai->filhodireita = novopai->filhoesquerda;
  novopai->filhoesquerda = pai;
  pai = novopai;
}

void ArvoreAVL::rotacaoesquerdadireita(No *&pai) {
  No *filho = pai->filhoesquerda;
  rotacaoesquerda(filho);
  pai->filhoesquerda = filho;
  rotacaodireita(pai);
}

void ArvoreAVL::rotacaodireitaesquerda(No *&pai) {
  No *filho = pai->filhodireita;
  rotacaodireita(filho);
  pai->filhodireita = filho;
  rotacaoesquerda(pai);
}

void ArvoreAVL::realizarotacao(No *&pai) {
  No *filho;
  No *neto; // caso precise rotação dupla;

  if (pai->fatorB == -2) { // rotação para a direita;
    filho = pai->filhoesquerda;

    if (filho->fatorB == -1) { // simples para a direita
      pai->fatorB = 0;
      filho->fatorB = 0;
      rotacaodireita(pai);
    } else if (filho->fatorB == 0) { // simple apra a direita
      pai->fatorB = -1;
      filho->fatorB = 1;
      rotacaodireita(pai);
    } else if (filho->fatorB == 1) {
      neto = filho->filhodireita;
      if (neto->fatorB == -1) {
        pai->fatorB = 1;
        filho->fatorB = 0;
      } else if (neto->fatorB == 0) {
        pai->fatorB = 0;
        filho->fatorB = 0;
      } else if (neto->fatorB == 1) {
        pai->fatorB = 0;
        filho->fatorB = -1;
      }

      neto->fatorB = 0;
      rotacaoesquerdadireita(pai);
    }

  } else if (pai->fatorB == 2) { // rotaciona para a esquerda
    filho = pai->filhodireita;
    if (filho->fatorB == 1) {
      pai->fatorB = 0;
      filho->fatorB = 0;
      rotacaoesquerda(pai);
    } else if (filho->fatorB == 0) {
      pai->fatorB = 1;
      filho->fatorB = -1;
      rotacaoesquerda(pai);
    } else if (filho->fatorB == -1) { // rotação dupla
      neto = filho->filhoesquerda;
      if (neto->fatorB == -1) {
        pai->fatorB = 0;
        filho->fatorB = 1;
      }else if(neto->fatorB == 0){
        pai->fatorB = 0;
        filho->fatorB = 0;
      }else if(neto->fatorB == 1){
        pai->fatorB = -1;
        filho->fatorB = 0;
      }

      neto->fatorB = 0;
      rotacaodireitaesquerda(pai);
    }
  }
}