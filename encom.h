struct NodoFila {
  ENC  Elemento;
  struct NodoFila *Prox;
};

typedef struct NodoFila *PNodoFila;

// Operações sobre o Nodo

PNodoFila CriarNodoFila (ENC X){
  PNodoFila P;
  P = (PNodoFila) malloc(sizeof(struct NodoFila));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

PNodoFila LibertarNodoFila (PNodoFila P){ 
  free(P);
  P = NULL;
  return P;
}


// Operações sobre a Pilha

PNodoFila CriarFila (){
  PNodoFila P;
  P = NULL;
  return P;
}

int FilaVazia (PNodoFila Fila){
  if (Fila == NULL)
    return 1;
  else
    return 0;
}

PNodoFila Juntar (ENC X, PNodoFila Fila){
  PNodoFila Novo, PAnt;
  Novo = CriarNodoFila(X);
  if (Novo == NULL)
    return Fila;
  if (FilaVazia(Fila)){
    Fila = Novo;
    return Fila;
  }
  PAnt = Fila;
  while(PAnt->Prox != NULL)
    PAnt = PAnt->Prox;
  PAnt->Prox = Novo;
  return Fila;
}


PNodoFila RemoverEncomenda (PNodoFila Fila){
  PNodoFila P;
  P = Fila;
  Fila = Fila->Prox;
  P = LibertarNodoFila(P);
  return Fila;
}


ENC Frente (PNodoFila Fila){
  return Fila->Elemento;
}

void listaenc(PNodoFila E){
  printf(ANSI_COLOR_YELLOW "\t\t Encomenda -- Livro -- Cliente -- Data -- Numero -- Preco \n\n"ANSI_COLOR_RESET);
  while(E != NULL){
    MostrarElementoEncomenda(Frente(E));
    E = E->Prox;
  }
}


void encomendareturn(PNodoFila E,int r,ENC *t){
  while(E != NULL){
    if(E->Elemento.numeroencomenda == r){
      *t = E->Elemento;
    }
    E = E->Prox;
  }
}

bool ver_existe_enc(PNodoFila E,int r){
  while(E != NULL){
    if(E->Elemento.numeroencomenda == r){
      return true;
    }
    //RemoverEncomenda(E);
    E = E ->Prox;
  }
  return false;
}


PNodoFila eliminar(PNodoFila A,int z){
  PNodoFila aux = CriarFila();
  ENC w;
  while(A->Elemento.numeroencomenda != z){
    w=Frente(A);
    aux = Juntar(w,aux);
    RemoverEncomenda(A);
  }
  RemoverEncomenda(A);
  while(FilaVazia(aux) != 1){
    A=Juntar(Frente(aux),A);
    RemoverEncomenda(aux);
  }
  return A;
}

PNodoFila Removerfi (PNodoFila Fila){
  PNodoFila P;
  P = Fila;
  Fila = Fila->Prox;
  P = LibertarNodoFila(P);
  return Fila;
}


PNodoFila eliminar2(PNodoFila A,int z){
  PNodoFila aux = CriarFila();
  ENC w;
  while(ver_existe_enc(A,z) == 1){

    while(A->Elemento.numeroencomenda != z){
      w=Frente(A);
      aux = Juntar(w,aux);
      RemoverEncomenda(A);
    }
    RemoverEncomenda(A);
    while(FilaVazia(aux) != 1){
      A=Juntar(Frente(aux),A);
      RemoverEncomenda(aux);
    }
  }
  return A;
}


void guardar_enc(PNodoFila A){
  FILE *ft = fopen("encc.txt", "w");

  while(A != NULL){
    fprintf(ft,"%i %i %i %i %i %f\n",A->Elemento.numeroencomenda,A->Elemento.numerolivro,A->Elemento.numerocliente,A->Elemento.data,A->Elemento.num,A->Elemento.preco);
    A = A->Prox;
  }
}


PNodoFila abrirficheiroencomendas(int *p){
  PNodoFila q = CriarFila();
  ENC k;
  FILE *ft = fopen("encc.txt", "r");
  while(fscanf(ft,"%i %i %i %i %i %f",&k.numeroencomenda ,&k.numerolivro,&k.numerocliente,&k.data,&k.num,&k.preco)==6){ 
    *p = *p + 1;
    q = Juntar(k,q);
  }
  return q;
}

