struct Nodo {
  Cliente Elemento;
  struct Nodo *Prox;
};

typedef struct Nodo *PNodo;
#include<string.h>

PNodo Criar (){
  PNodo L;
  L = NULL;
  return L;
}
int Pesquisar (Cliente X, PNodo L);
int ProcNIFF (PNodo T,int r);

PNodo CriarNodo (Cliente X){
  PNodo P;
  P = (PNodo) malloc(sizeof(struct Nodo));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

void LibertarNodo (PNodo P){ 
  free(P);
  P = NULL;
}




PNodo Remover (Cliente X, PNodo L);

Cliente CriarElemento (PNodo A){
  Cliente X;
  int r;
  printf("NIF : ");
  scanf("%i",&r);
  if(ProcNIFF(A,r)==1){
    printf("NIF JA EM USO \n\n");
    X.NIF=0;
  }
  else{
    float rr;
    X.NIF=r;
    printf("Nome : ");
    clear_keyboard_buffer();
    fgets(X.Nome,100,stdin);
    X.Nome[strcspn(X.Nome, "\n")] = 0;
    printf("Morada : ");
    fgets(X.Morada,200,stdin);
    X.Morada[strcspn(X.Morada, "\n")] = 0;
    printf("Telemovel:");
    scanf("%f",&rr);
    X.telemovel = rr;
  }
  return X;
}


Cliente CriarElemento1 (PNodo A,int r){
  Cliente X;
  if(ProcNIFF(A,r)==1){
    printf("NIF JA EM USO \n\n");
    X.NIF=0;
  }
  else{
    float rr;
    X.NIF=r;
    printf("Nome : ");
    clear_keyboard_buffer();
    fgets(X.Nome,100,stdin);
    X.Nome[strcspn(X.Nome, "\n")] = 0;
    printf("Morada : ");
    fgets(X.Morada,200,stdin);
    X.Morada[strcspn(X.Morada, "\n")] = 0;
    printf("Telemovel:");
    scanf("%f",&rr);
    X.telemovel = rr;
  }
  return X;
}


void VerMorada(PNodo T,char t[200]){
  PNodo P = T;
  int i = 0;
  while (P != NULL){
    if(strcmp(P->Elemento.Morada,t)==0){
      MostrarElemento(P->Elemento);
      i=1;
    }
    P = P->Prox;
  }
  if(i == 0){
    printf("Nao existe \n");
  }  
}

int Vazia (PNodo L){
  if (L == NULL)
    return 1;
  else
    return 0;
}

int ProcNIFF (PNodo T,int r){
  PNodo P = T;
  int i =0;
  while (P != NULL){
    if(P->Elemento.NIF == r){
      i=1;
    }
    P = P->Prox;
  }
  return i; 
}

void ProcNIF (PNodo T,int r){
  PNodo P = T;
  int i =0;
  while (P != NULL){
    if(P->Elemento.NIF == r){
      MostrarElemento(P->Elemento);
      i=1;
    }
    P = P->Prox;
  }
  if(i == 0){
    printf("Nao existe \n");
  }  
}

int ProcNIF2 (PNodo T,int r){
  PNodo P = T;
  while (P != NULL){
    if(P->Elemento.NIF == r){
      return 1;
    }
    P = P->Prox;
  }
  return 0;
}


void alterar(PNodo A,int r){
  PNodo P = A;
  char novo[200];
  int i =0;
  while (P != NULL){
    if(P->Elemento.NIF == r){
      printf("NOVA MORADA: ");
      clear_keyboard_buffer();
      fgets(novo,200,stdin);
      novo[strcspn(novo, "\n")] = 0;
      strcpy(P->Elemento.Morada,novo);
      i=1;
    }
    P = P->Prox;
  }
  if(i == 0){
    printf("Nao existe \n");
  } 
}

void ProcNome (PNodo L,char r[100]){
  PNodo P = L;
  int i =0;
  while (P != NULL){
    if( strcmp( P->Elemento.Nome, r )  == 0){
      MostrarElemento(P->Elemento);
      i=1;
    }
    P = P->Prox;
  }
  if(i == 0){
    printf("Nao existe \n");
  }  
}



PNodo removerele(int X,PNodo L){
  Cliente RX;
  RX.NIF=X;
  if(Pesquisar(RX,L)==1){
    L=Remover(RX,L);
  }
  return L;
}

void Listar (PNodo L){
  PNodo P = L;
  while (P != NULL){
    MostrarElemento(P->Elemento);
    P = P->Prox;
  }
  printf("\n\n");
}

void ListarRec (PNodo L){
  if (L != NULL){
    MostrarElemento(L->Elemento);
    ListarRec(L->Prox);
  }
}

void ListarContrarioRec (PNodo L){
  if (L != NULL){
    ListarContrarioRec(L->Prox);
    MostrarElemento(L->Elemento);
  }
}

PNodo InserirInicio (Cliente X, PNodo L){
  PNodo P;
  P = CriarNodo(X);
  if (P == NULL)
    return L;
  P->Prox = L;
  L = P;
  return L;
}

// ###############  A2  ########################


int Pesquisar (Cliente X, PNodo L){ 
  while (L != NULL && CompararElementos(L->Elemento, X) != 0)
    L = L->Prox; 
  if (L == NULL)
    return 0; 
  else
    return 1;
} 

int PesquisarRec (Cliente X, PNodo L){
  if (L == NULL) 
    return  0;
  if (CompararElementos(L->Elemento, X) == 0) 
    return  1; 
  else 
    return PesquisarRec(X, L->Prox);
}

PNodo ProcurarAnterior (Cliente X, PNodo L){
  PNodo  Ant = NULL; 
  while (L != NULL && CompararElementos(L->Elemento, X) != 0){
    Ant = L;
    L = L->Prox;
  } 
  return Ant;
}

PNodo ProcurarAnteriorRec (Cliente X, PNodo L){ 
  if (CompararElementos(L->Elemento, X) == 0) 
    return  NULL;   //  só acontece se X estiver no início de L 
  if (CompararElementos(L->Prox->Elemento, X) == 0) 
    return  L; 
  return ProcurarAnteriorRec(X, L->Prox);
}

// remover X da lista L, em que X está na lista
PNodo Remover (Cliente X, PNodo L){ 
  PNodo P, PAnt;
  PAnt = ProcurarAnterior(X, L); 
  if (PAnt == NULL){   // remover elemento do início de L
    P = L;
    L = L->Prox;
  } 
  else{
    P = PAnt->Prox;
    PAnt->Prox = P->Prox; // ou (PAnt->Prox)->Prox
  } 
  LibertarNodo(P); 
  return  L;
}

// remover X da lista L, em que X está na lista
PNodo RemoverRec (Cliente X, PNodo L, PNodo LAux) {
  PNodo  P;
  if (CompararElementos(L->Elemento, X) == 0){   // X está no início da Lista L
    P = L;
    L = L->Prox;
    free(P);
    return  L;
  }
  if (CompararElementos(LAux->Prox->Elemento, X) == 0){    
    // X está na lista L, mas não no inicio
    P = LAux->Prox;
    LAux->Prox = P->Prox;    // ou LAux->Prox->Prox;
    free(P);
    return L;
  }
  return RemoverRec(X, L, LAux->Prox);
}

// ###############  A3  ########################

int Tamanho (PNodo L){
  int  tam = 0; 
  while (L != NULL){
    tam++;
    L = L->Prox;
  } 
  return tam;
}

int TamanhoRec (PNodo L){ 
  if (L == NULL) 
    return 0; 
  else 
    return 1 + TamanhoRec(L->Prox);
}

PNodo InserirFim (Cliente X, PNodo L){ 
  PNodo P, PAux;
  P = CriarNodo(X); 
  if (P == NULL) 
    return L; 
  if (L == NULL) 
    return P;
  PAux = L; 
  while (PAux->Prox != NULL)    // marcar o elemento do fim de L
    PAux = PAux->Prox;
  PAux->Prox = P; 
  return  L; 
}

PNodo InserirFimRec (Cliente X, PNodo L){
  PNodo P; 
  if (L == NULL){      // só acontece se a lista inicial for vazia
    P = CriarNodo(X); 
    if (P != NULL)
      L = P; 
    return  L;
  } 
  if (L->Prox == NULL){      // fim da lista L
    P = CriarNodo(X); 
    if (P != NULL)
      L->Prox = P;
  } 
  else 
    InserirFimRec(X, L->Prox);    // o que devolve não interessa 
  return L;    // devolve o início da lista 
}

// assume-se que a lista está ordenada por ordem crescente
PNodo ProcurarInserirOrdem (Cliente X, PNodo L){ 
  PNodo Ant = NULL; 
  while (L != NULL && CompararElementos(L->Elemento, X) < 0){
    Ant = L;
    L = L->Prox;
  } 
  return Ant; 
} 

PNodo InserirOrdem (Cliente X, PNodo L){
  PNodo P, PAnt;
  P = CriarNodo(X); 
  if (P == NULL) 
    return  L; 
  if (L == NULL) 
    return  P;    // a lista L inicia-se em P
  PAnt = ProcurarInserirOrdem(X, L); 
  if (PAnt == NULL){   // inserir no início de L
    P->Prox = L; 
    return  P;
  }   
  P->Prox = PAnt->Prox;
  PAnt->Prox = P;
  return  L; 
}



PNodo abrirficheirocliente(){
  PNodo p = Criar();
  Cliente q;
  char buf[100];
  char buf2[200];
  int rr;
  float y;
  FILE *ft = fopen("clien.txt", "r");
  while(fscanf(ft," %i %s %s %f", &rr,buf,buf2,&y)==4){   
    q.NIF=rr;
    strcpy(q.Nome, buf);
    strcpy(q.Morada, buf2);
    q.telemovel=y;
    p=InserirInicio(q,p);
  }
  fclose(ft);
  return p;
}


void guardarclientes(PNodo A){
  FILE *ft = fopen("clien.txt", "w");

  while(A != NULL){
    fprintf(ft,"%i %s %s %f\n",A->Elemento.NIF,A->Elemento.Nome,A->Elemento.Morada,A->Elemento.telemovel);
    A = A->Prox;
  }
}


int MemoriaCliente(PNodo p){
  int mem = 0;
  while(p != NULL){
    mem = mem + ( ( 100 - strlen(p->Elemento.Nome)) + (200 - strlen(p->Elemento.Morada) ) - 2); // /s
    p = p->Prox;
  }
  return mem;
}


