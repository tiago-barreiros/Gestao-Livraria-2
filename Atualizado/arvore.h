
// Operações sobre ABP cuja chave é o campo "NIF"



int PesquisarABP (PNodoAB T, Livro X){   // 0 = nao existe; 1 = existe
  PNodoAB P;
  if (T == NULL)
    return 0;
  if (CompararElementosLivro(X, T->Elemento) == 0)
    return 1;
  if (CompararElementosLivro(X, T->Elemento) == -1)   // X.NIF < (T->Elemento).NIF)
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

PNodoAB InserirABP (PNodoAB T, Livro X){
  if (T == NULL) {
    T = CriarNodoAB(X);
    return T;
  }
  if (CompararElementosLivro(X, T->Elemento) == -1)   // X.NIF < (T->Elemento).NIF)
    T->Esquerda = InserirABP(T->Esquerda, X);
  else
    T->Direita = InserirABP(T->Direita, X);
  return T;
}


PNodoAB SubstituirNodoDireita (PNodoAB T, Livro *X){
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

PNodoAB SubstituirNodoEsquerda (PNodoAB T, Livro *X){
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
  Livro  X;
  if (T->Esquerda == NULL && T->Direita == NULL) {   // T é uma folha
    T = LibertarNodoAB(T);
    return T;
  }
  if (T->Esquerda == NULL) {   //  só um filho direito 
    R = T;
    T = T->Direita;
    R = LibertarNodoAB(R);
    return T;
  }
  if (T->Direita == NULL) {     // só um filho esquerdo
    R = T;
    T = T->Esquerda;
    R = LibertarNodoAB(R);
    return T;
  }
  // 2 filhos (1º caso): remover o nodo sucessor (nodo mais à esquerda da subárvore direita) e copiar a sua informação
  T->Direita = SubstituirNodoDireita(T->Direita, &X);
  // 2 filhos (2º caso): remover o nodo antecessor (nodo mais à direita da subárvore esquerda) e copiar a sua informação
  //  T->Esquerda = SubstituirNodoEsquerda(T->Esquerda, &X);  // 2º caso
  T->Elemento = X;
  return T;
}

PNodoAB RemoverABP (PNodoAB T, Livro X) {
  if (CompararElementosLivro(X, T->Elemento) == 0) {
    T = RemoverNodoABP(T);
    return T;
  }    
  if (CompararElementosLivro(X, T->Elemento) == -1)
    T->Esquerda = RemoverABP(T->Esquerda, X);
  else
    T->Direita = RemoverABP(T->Direita, X);
  return T;
}


PNodoAB abrirficheirolivro(){
  PNodoAB q = CriarAB();
  Livro w;
  FILE *ft = fopen("livraria.txt", "r");
  while(fscanf(ft," %i %s %s %s %s %i %s %s %f %i", &w.ISBN,w.Titulo,w.Idioma,w.PrimAutor,w.SegAutor,&w.AnoPub,w.editora,w.Area,&w.Preco,&w.Qtd)==10){   
    q = InserirABP(q,w);    
  }
 return q;
}


void guardar_livros(Livro *A,int tam){
   FILE *ft = fopen("livraria.txt", "w");

  for(int i=0;i<tam;i++){
    fprintf(ft,"%i %s %s %s %s %i %s %s %f %i\n",A[i].ISBN,A[i].Titulo,A[i].Idioma,A[i].PrimAutor,A[i].SegAutor,A[i].AnoPub,A[i].editora,A[i].Area,A[i].Preco,A[i].Qtd);
  }
}

void guardar_livros2(PNodoAB A){
  FILE *ft = fopen("livraria.txt", "w");
  if(A != NULL){
    fprintf(ft,"%i %s %s %s %s %i %s %s %f %i\n",A->Elemento.ISBN,A->Elemento.Titulo,A->Elemento.Idioma,A->Elemento.PrimAutor,A->Elemento.SegAutor,A->Elemento.AnoPub,A->Elemento.editora,A->Elemento.Area,A->Elemento.Preco,A->Elemento.Qtd);
    
    guardar_livros2(A->Esquerda);
    guardar_livros2(A->Direita);
  }
}

