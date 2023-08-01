#define NULLL ((void*)0)


struct NodoAB {
  Livro  Elemento;
  struct NodoAB *Esquerda;
  struct NodoAB *Direita;
};

typedef struct NodoAB *PNodoAB;



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

PNodoAB CriarNodoAB(Livro X){
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
  PNodoAB E, D, R;    // R é a nova árvore, que é uma cópia de T
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

int existe(PNodoAB X,int r);
int verificar(PNodoAB X,int r);


Livro CriarElementoLivro(PNodoAB T){
  Livro X;
  time_t tt = time(NULL);
  struct tm tm = *localtime(&tt);
  printf(ANSI_COLOR_G1"\nISBN :"ANSI_COLOR_RESET);
  scanf("%i",&X.ISBN);
  if(verificar(T,X.ISBN)==0){
    printf(ANSI_COLOR_G1"\nLivro:"ANSI_COLOR_RESET);
    clear_keyboard_buffer();
    fgets(X.Titulo,100,stdin);
    X.Titulo[strcspn(X.Titulo, "\n")] = 0;

    printf(ANSI_COLOR_G1"\nIdioma:"ANSI_COLOR_RESET);
    fgets(X.Idioma,100,stdin);
    X.Idioma[strcspn(X.Idioma, "\n")] = 0;

    printf(ANSI_COLOR_G1"\nPrimeiro Autor:"ANSI_COLOR_RESET);
    fgets(X.PrimAutor,100,stdin);
    X.PrimAutor[strcspn(X.PrimAutor, "\n")] = 0;

    printf(ANSI_COLOR_G1"\nSegundo Autor:"ANSI_COLOR_RESET);
    fgets(X.SegAutor,100,stdin);
    X.SegAutor[strcspn(X.SegAutor, "\n")] = 0;
    
    int anoss = tm.tm_year+1900;

    printf(ANSI_COLOR_G1"\nAno de publicacao:"ANSI_COLOR_RESET);
    scanf("%i",&X.AnoPub);
    while(X.AnoPub > anoss){
      printf("\nAinda nao chegamos a este ano\n");
      printf(ANSI_COLOR_G1"\nAno de publicacao:"ANSI_COLOR_RESET);
      scanf("%i",&X.AnoPub);
    }

    
    clear_keyboard_buffer();
    printf(ANSI_COLOR_G1"\nEditora:"ANSI_COLOR_RESET);
    fgets(X.editora,100,stdin);
    X.editora[strcspn(X.editora, "\n")] = 0;

    
    printf(ANSI_COLOR_G1"\nArea:"ANSI_COLOR_RESET);
    fgets(X.Area,100,stdin);
    X.Area[strcspn(X.Area, "\n")] = 0;

    printf(ANSI_COLOR_G1"\nPreco:"ANSI_COLOR_RESET);
    scanf("%f",&X.Preco);
    int aB = X.Preco;
    while( aB <= 0){
      printf("\nPreco Invalido!\n");
      printf(ANSI_COLOR_G1"\nPreco:"ANSI_COLOR_RESET);
      scanf("%f",&X.Preco);
      aB = X.Preco;
    }

    printf(ANSI_COLOR_G1"\nQuantidade:"ANSI_COLOR_RESET);
    scanf("%i",&X.Qtd);
    int aC = X.Qtd;
    while( aC < 0){
      printf("\nQuantidade Invalido!\n");
      printf(ANSI_COLOR_G1"\nQunatidade:"ANSI_COLOR_RESET);
      scanf("%i",&X.Qtd);
      aC = X.Qtd;
    }
  }
  else{
    printf("JA EXISTE UM ISBN IGUAL \n");
    X.ISBN = 0;
  }
  return X;
}


int ver_ex(Livro *p,int contador,int isbn){
  int o=0;
  for(int i=0;i<contador;i++){
    if(p[i].ISBN == isbn){
      return 1;
    }
  }
  return 0;
}



Livro *Remover_Um_Livro( Livro * cad, int cod ,int *qtd)
{
 
    for( int i = 0; i < *qtd; i++ )
    {
        /* Verifica se o cliente possui o codigo desejado */ 
        if( cad[i].ISBN == cod )
        {
            /* Ajusta vetor: Desloca todos os clientes uma posicao */ 
            for( int j = i; j < *qtd - 1; j++ )
                cad[j] = cad[ j + 1 ];

            /* Decrementa contador de clientes */
            *qtd = *qtd -1;

            return cad;
        }
    }

    return cad;
}


int existe(PNodoAB X,int r){
  if(X == NULL){
    return 0;
  }

  int d = existe(X->Direita,r);
  int e = existe(X->Esquerda,r);

  if(X->Elemento.ISBN == r){
    return 1;
  }
  return 0;
}

int verificar(PNodoAB X,int r){
  if(X == NULL){
    return 0;
  }

  int d = existe(X->Direita,r);
  int e = existe(X->Esquerda,r);

  if(X->Elemento.ISBN == r){
    return d+e+1;
  }
  return d+e;
}

int verificarqtd(PNodoAB X,int r,int qtd){
  if(X == NULL){
    return 0;
  }

  int d = verificarqtd(X->Direita,r,qtd);
  int e = verificarqtd(X->Esquerda,r,qtd);

  if(X->Elemento.ISBN == r){
    if(X->Elemento.Qtd < qtd){
      return 1;
    }
  }
  return 0;
}



int ABIguais (PNodoAB T, PNodoAB R) {
  int  ig;
  if (T == NULL && R == NULL)  // se são ambas nulas, então são iguais
    return 1;
  if (T == NULL || R == NULL)  // se uma delas é nula, então são diferentes
    return 0;
  if (CompararElementosLivro(T->Elemento, R->Elemento) != 0)  // raízes diferentes, árvores diferentes
    return 0;
  if (ABIguais(T->Esquerda, R->Esquerda) == 0) // subárvores esq. diferentes
    return 0;
  if (ABIguais(T->Direita, R->Direita) == 0)  // subárvores direitas diferentes
    return 0;
  return 1;    // caso contrário, são iguais
}

int NumeroNodosAB (PNodoAB T) {
  int  e, d;
  if (T == NULL)
    return 0;
  e = NumeroNodosAB(T->Esquerda);
  d = NumeroNodosAB(T->Direita);
  return (e + d + 1);
}

int AlturaAB (PNodoAB T) {
  int  e, d;
  if (T == NULL)
    return -1;
  e = AlturaAB(T->Esquerda);
  d = AlturaAB(T->Direita);
  if (e > d)
    return (e + 1);  // e (altura da esquerda), 1 a raiz
  else
    return (d + 1);  // d (altura da direita), 1 a raiz
}

void ListarPreOrdemAB (PNodoAB T) {
  if (T != NULL) {
    MostrarElementoLivro(T->Elemento);
    ListarPreOrdemAB(T->Esquerda);
    ListarPreOrdemAB(T->Direita);
  }
}

void fazervetor(Livro T,Livro *vetor,int *tam);

void CriarVetor (PNodoAB T,Livro *p,int *tam) { //arvore , vetor para armazenar, tamanha do vertor
  if (T != NULL) {
    fazervetor(T->Elemento,p,tam);
    CriarVetor(T->Esquerda,p,tam);
    CriarVetor(T->Direita,p,tam);
  }
}

void fazervetor(Livro T,Livro *vetor,int *tam){
  *tam=*tam+1;
  vetor[*tam-1]=T;
}

void ListarISBN (PNodoAB T,int x) {
  if (T != NULL) {
    MostrarElementoLivroISBN(T->Elemento,x);
    ListarISBN(T->Esquerda,x);
    ListarISBN(T->Direita,x);
  }
}

void ListarISBN2 (PNodoAB T,int x,int *y) {
  if (T != NULL) {
    MostrarElementoLivroISBN2(T->Elemento,x,y);
    ListarISBN2(T->Esquerda,x,y);
    ListarISBN2(T->Direita,x,y);
  }
}

void ListarISBNqtd (PNodoAB T,int x,int *y) {
  if (T != NULL) {
    MostrarElementoLivroqtd(T->Elemento,x,y);
    ListarISBNqtd(T->Esquerda,x,y);
    ListarISBNqtd(T->Direita,x,y);
  }
}


void ListarTitulo (PNodoAB T,char x[50]) {
  if (T != NULL) {
    MostrarElementoLivroTitulo(T->Elemento,x);
    ListarTitulo(T->Esquerda,x);
    ListarTitulo(T->Direita,x);
  }
}

void ListarEdiArea (PNodoAB T,char x[],char x1[]) {
  if (T != NULL) {
    MostrarElementoLivroEdiArea(T->Elemento,x,x1);
    ListarEdiArea(T->Esquerda,x,x1);
    ListarEdiArea(T->Direita,x,x1);
  }
}

void Listarano (PNodoAB T,char x[],int r) {
  if (T != NULL) {
    MostrarElementoLivroAnoeAutor(T->Elemento,x,r);
    Listarano(T->Esquerda,x,r);
    Listarano(T->Direita,x,r);
  }
}

void ListarEmOrdemAB (PNodoAB T) {
  if (T != NULL) {
    ListarEmOrdemAB(T->Esquerda);
    MostrarElementoLivro(T->Elemento);
    ListarEmOrdemAB(T->Direita);
  }
}

void ListarPosOrdemAB (PNodoAB T) {
  if (T != NULL) {
    ListarPosOrdemAB(T->Esquerda);
    ListarPosOrdemAB(T->Direita);
    MostrarElementoLivro(T->Elemento);
  }
}

void alterarpreco (PNodoAB T,float Q,int A) {
  if (T == NULL) {
    return;
  }
  
  if(T->Elemento.ISBN == A){
      printf("ola\n");
      T->Elemento.Preco = Q;
      return;
    
  }
  alterarpreco (T->Direita,Q,A);
  alterarpreco (T->Esquerda, Q, A);
}


Livro valorLivro(PNodoAB T , int r){

  Livro i;
  Livro ii;
  Livro f;

  if(T == NULL){
    i.ISBN = 0;
    return i;
  }

  if(T->Elemento.ISBN == r){
    return T->Elemento;
  }
  
  ii = valorLivro(T->Esquerda,r);
  
  if(ii.ISBN == r){
    return T->Elemento;
  }
   
  return valorLivro(T->Direita,r); 
}


PNodoAB alterarvalorLivro(PNodoAB T , int r,float Q){
  PNodoAB A = T;

  if(A == NULL){
    return T;
  }

  if(A->Elemento.ISBN == r){
    A->Elemento.Preco = Q;
    return T;
  }
  
  PNodoAB ii = alterarvalorLivro(A->Esquerda,r,Q);
  
  if(ii != NULL){
    A->Elemento.Preco = Q;
    return T;
  } 
   
  return alterarvalorLivro(A->Direita,r,Q);
}


PNodoAB PesquisarAB (Livro X, PNodoAB T) {
  PNodoAB P;
  if (T == NULL)
    return NULL;
  if (CompararElementosLivro(X, T->Elemento) == 0)
    return T;
  P = PesquisarAB(X, T->Esquerda);
  if (P != NULL)
    return P;
  return PesquisarAB(X, T->Direita);
}



Livro PesquisarABLivro (int X, PNodoAB T) {
  Livro p;
  Livro i;
  if (T == NULL)
    i.ISBN = 0;
    return i;
  if (CompararElementosLivro1(X, T->Elemento.ISBN) == 1)
    return T->Elemento;
  p = PesquisarABLivro(X, T->Esquerda);
  if (p.ISBN != 0)
    return p;
  return PesquisarABLivro(X, T->Direita);
}


PNodoAB InserirPorAlturaAB (PNodoAB T, Livro X) {
  if (T == NULL) {
   T = CriarNodoAB(X);
    return T;
  }
  if (AlturaAB(T->Esquerda) > AlturaAB(T->Direita))
    T->Direita = InserirPorAlturaAB(T->Direita, X);
  else
    T->Esquerda = InserirPorAlturaAB(T->Esquerda, X);
  return T;
}
    
PNodoAB ProcurarFolhaAB (PNodoAB T, Livro *X) {
  if (T->Esquerda == NULL  &&  T->Direita == NULL) {
    *X = T->Elemento;
    return T;
  }
  if (AlturaAB(T->Esquerda) > AlturaAB(T->Direita))
    return ProcurarFolhaAB(T->Esquerda, X);
  else
    return ProcurarFolhaAB(T->Direita, X);
}

PNodoAB RemoverNodoAB (PNodoAB T) {
  PNodoAB P, R;
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
  // 2 filhos: remover a folha escolhida e copiar a sua informação
  P = ProcurarFolhaAB(T, &X);
  //T->Elemento = P->Elemento;
  P = LibertarNodoAB(P);
  T->Elemento = X;
  return T;
}

PNodoAB RemoverAB (PNodoAB T,Livro X) {
  PNodoAB P;
  if (T == NULL)
    return NULL;
  if (CompararElementosLivro(T->Elemento, X) == 0) {
    T = RemoverNodoAB(T);
    return T;
  }
  P = PesquisarAB(X, T->Esquerda);
  if (P != NULL)
    T->Esquerda = RemoverAB(T->Esquerda, X);
  else
    T->Direita = RemoverAB(T->Direita, X);
  return T;
}


/*
int equilibrada(PNodoAB T){
  int e,d;
  e= AlturaAB(T->Esquerda);
  d=AlturaAB(T->Direita);

  if(abs(e-d)> 1 ){
    return 0;
  }

  if(T->Esquerda != NULL && equilibrada(T->Esquerda)== 0){
    return 0;
  }
  if(T->Direita != NULL && equilibrada(T->Direita)== 0){
    return 0;
  }
  return 1;
}
*/


float VerPreco(Livro *p,int r,int cont){
  for(int i=0;i<cont;i++){
    if(p[i].ISBN == r){
      return p[i].Preco;
    }
  }
  return 0;
}

typedef struct{
  int ano;
  int qtd;
}ANO;



int ver_es(ANO *h,int tam,int r);

int *AnoMaisPublicacoes(Livro *p,int r,int *tamanhoreturn){
  
  ANO *h;
  int aj = 0;
  h = (ANO *)malloc(sizeof(ANO) * (aj)) ;

  int *t;
  int tam=0;
  t = (int *)malloc(tam * sizeof(int) );

  for(int i=0;i<r;i++){

    if(ver_es(h,aj,p[i].AnoPub) == 0){ //existe
      int pp = p[i].AnoPub;
      for(int i =0;i<aj;i++){
        if(pp == h[i].ano){
          h[i].qtd = h[i].qtd + 1;
        }
      }
    }

    else{
      aj++;
      h = realloc(h, aj*sizeof(ANO));
      h[aj -1].ano = p[i].AnoPub;
      h[aj -1].qtd = 1;
    }
  }

/*
  for(int i=0;i<aj;i++){
    printf("%i %i\n",h[i].ano,h[i].qtd); //ATE AQUI ESTA BEM
  }
*/

  int maior = 0;
  for(int y=0 ; y< aj;y++){

    if(maior < h[y].qtd){
      maior = h[y].qtd;
    }
  }
  
  for(int ii=0;ii<aj;ii++){
    if(maior == h[ii].qtd){
      tam++;
      t = (int*)realloc(t, tam*sizeof(int));
      t[tam-1] = h[ii].ano;
    }
  }

  *tamanhoreturn = tam;

  return t;
}

int ver_es(ANO *h,int tam,int r){

  for(int i=0;i<tam;i++){
    if(h[i].ano == r){
      return 0;
    }

  }
  return 1;
}


typedef struct{
  char nome[50];
  int qtd;
}AREA;


int ver_es_area(AREA *h,int tam,char r[50]){

  for(int i=0;i<tam;i++){
    if(strcmp(h[i].nome,r) == 0){
      return 0;
    }
  }
  return 1;

}




AREA *AreaCientifica(Livro *p,int r,int *tamanhoreturn,int *maior){
  
  AREA *h;
  int aj = 0;
  h = (AREA *)malloc(sizeof(AREA) * (aj)) ;
  char pp[50];
  char *t;
  int tam=0;
  t = (char *)malloc(tam * sizeof(char*) );

  for(int i=0;i<r;i++){

    if(ver_es_area(h,aj,p[i].Area) == 0){ //existe
      strcpy(pp,p[i].Area);
      for(int i =0;i<aj;i++){
        if(strcmp(pp,h[i].nome) == 0){
          h[i].qtd = h[i].qtd + 1;
        }
      }
    }

    else{
      aj++;
      h = realloc(h, aj*sizeof(AREA));
      strcpy(h[aj -1].nome,p[i].Area);
      h[aj -1].qtd = 1;
    }
  }

/*
  for(int i=0;i<aj;i++){
    printf("%s %i\n",h[i].nome,h[i].qtd); //ATE AQUI ESTA BEM
  }
*/

  int maior1 = 0;
  for(int y=0 ; y< aj;y++){
    tam++;
    if(maior1 < h[y].qtd){
      maior1 = h[y].qtd;
    }
  }

  *maior = maior1;
  
 

  *tamanhoreturn = tam;
  return h;
}



void print_livros(Livro *p,int tam){
  for(int i=0;i<tam;i++){
    printf("\nLivro : %s -> Quantidade : %i",p[i].Titulo,p[i].Qtd);
  }
  printf("\n\n");
}

void ordenar_Livro (Livro *V, int N){
    int k, Num_trocas;
    Livro aux;
    do{
        Num_trocas = 0;
        for (k = 0; k < N-1; k++)
            if (V[k].Qtd < V[k+1].Qtd){
            aux = V[k];
            V[k] = V[k+1];
            V[k+1] = aux;
            Num_trocas++;
        }
    }while (Num_trocas != 0);
}


int ver_exite_livro(Livro *p,int tam,int numero){
  for(int i=0;i<tam;i++){
    if(p[i].ISBN == numero){
      return 1;
    }
  }
  return 0;
}