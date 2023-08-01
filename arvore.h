struct NodoAB {
  Cliente  Elemento;
  struct NodoAB *Esquerda;
  struct NodoAB *Direita;
};

typedef struct NodoAB *PNodoAB;

#include<string.h>

PNodoAB CriarAB(){ 
  PNodoAB T;
  T = NULL;
  return T;
}

int ABVazia(PNodoAB T){
  if (T == NULL)
    return 1;
  return 0;
}

int NumeroNodosAB (PNodoAB T) {
  int  e, d;
  if (T == NULL)
    return 0;
  e = NumeroNodosAB(T->Esquerda);
  d = NumeroNodosAB(T->Direita);
  return (e + d + 1);
}


PNodoAB CriarNodoAB(Cliente X){
  PNodoAB P = (PNodoAB) malloc(sizeof(struct NodoAB));
  if (P == NULL)
    return  NULL;
  P->Elemento = X;
  P->Esquerda = NULL;
  P->Direita = NULL;
  return P;
}

PNodoAB LibertarNodoAB(PNodoAB P){
  P->Esquerda = NULL;
  P->Direita = NULL;
  free(P);
  P = NULL;
  return P;
}

PNodoAB DestruirAB(PNodoAB T){
  if (T == NULL) 
    return NULL;
  T->Esquerda = DestruirAB(T->Esquerda);
  T->Direita = DestruirAB(T->Direita);
  return LibertarNodoAB(T);
}

PNodoAB CopiarAB (PNodoAB T) {
  PNodoAB E, D, R;    // R � a nova �rvore, que � uma c�pia de T
  R = CriarAB();
  if (T == NULL)
    return R;
  E = CopiarAB(T->Esquerda);
  D = CopiarAB(T->Direita);
  R = CriarNodoAB(T->Elemento);
  R->Esquerda = E;
  R->Direita = D;
  return R;
}

int PesquisarABP (PNodoAB T, Cliente X){   // 0 = nao existe; 1 = existe
  PNodoAB P;
  if (T == NULL)
    return 0;
  if (CompararElementosCliente(X, T->Elemento) == 0)
    return 1;
  if (CompararElementosCliente(X, T->Elemento) == -1)   // X.NIF < (T->Elemento).NIF)
    return PesquisarABP(T->Esquerda, X);
  else
    return PesquisarABP(T->Direita, X);
}

PNodoAB NodoMaiorElementoABP (PNodoAB T){
  if (T == NULL)
    return NULL;
  if (T->Direita == NULL)
    return T;
  return NodoMaiorElementoABP(T->Direita);
}

PNodoAB NodoMenorElementoABP (PNodoAB T){
  if (T == NULL)
    return NULL;
  if (T->Esquerda == NULL)
    return T;
  return NodoMenorElementoABP(T->Esquerda);
}

PNodoAB InserirABP (PNodoAB T, Cliente X){
  if (T == NULL) {
    T = CriarNodoAB(X);
    return T;
  }
  if (CompararElementosCliente(X, T->Elemento) == -1)   // X.NIF < (T->Elemento).NIF)
    T->Esquerda = InserirABP(T->Esquerda, X);
  else
    T->Direita = InserirABP(T->Direita, X);
  return T;
}

PNodoAB SubstituirNodoDireita (PNodoAB T, Cliente *X){
  PNodoAB  PAux;
  if (T->Esquerda == NULL) {
    *X = T->Elemento;
    PAux = T;
    T = T->Direita;
    PAux = LibertarNodoAB(PAux);
    return T;
  }
  T->Esquerda = SubstituirNodoDireita(T->Esquerda, X);
  return T;
}

PNodoAB SubstituirNodoEsquerda (PNodoAB T, Cliente *X){
  PNodoAB  PAux;
  if (T->Direita == NULL) {
    *X = T->Elemento;
    PAux = T;
    T = T->Esquerda;
    PAux = LibertarNodoAB(PAux);
    return  T;
  }
  T->Direita = SubstituirNodoEsquerda(T->Direita, X);
  return T;
}

PNodoAB RemoverNodoABP (PNodoAB T){
  PNodoAB  R;
  Cliente  X;
  if (T->Esquerda == NULL && T->Direita == NULL) {   // T � uma folha
    T = LibertarNodoAB(T);
    return T;
  }
  if (T->Esquerda == NULL) {   //  s� um filho direito 
    R = T;
    T = T->Direita;
    R = LibertarNodoAB(R);
    return T;
  }
  if (T->Direita == NULL) {     // s� um filho esquerdo
    R = T;
    T = T->Esquerda;
    R = LibertarNodoAB(R);
    return T;
  }
  // 2 filhos (1� caso): remover o nodo sucessor (nodo mais � esquerda da sub�rvore direita) e copiar a sua informa��o
  T->Direita = SubstituirNodoDireita(T->Direita, &X);
  // 2 filhos (2� caso): remover o nodo antecessor (nodo mais � direita da sub�rvore esquerda) e copiar a sua informa��o
  //  T->Esquerda = SubstituirNodoEsquerda(T->Esquerda, &X);  // 2� caso
  T->Elemento = X;
  return T;
}

PNodoAB RemoverABP (PNodoAB T, Cliente X) {
  if (CompararElementosCliente(X, T->Elemento) == 0) {
    T = RemoverNodoABP(T);
    return T;
  }    
  if (CompararElementosCliente(X, T->Elemento) == -1)
    T->Esquerda = RemoverABP(T->Esquerda, X);
  else
    T->Direita = RemoverABP(T->Direita, X);
  return T;
}

/*
PNodoAB abrirficheiroCliente(){
  PNodoAB q = CriarAB();
  Cliente w;
  FILE *ft = fopen("livraria.txt", "r");
  while(fscanf(ft," %i %s %s %s %s %i %s %s %f %i", &w.ISBN,w.Titulo,w.Idioma,w.Autor1,w.Autor2,&w.AnoPub,w.Editora,w.Area,&w.Preco,&w.Quantidade)==10){   
    q = InserirABP(q,w);    
  }
 return q;
}
*/




/*
//tirar
#include <stdlib.h>
#include <stdio.h>
*/
