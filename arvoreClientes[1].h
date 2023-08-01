#define NULLL ((void*)0)

/*
typedef struct{
  int NIF;
  char Nome[100];
  char Morada[200]; 
  char Email [30];
  int Telemovel;
}Cliente;
///depois tirar
*/


int existe(PNodoAB X,int r){
  if(X == NULL){
    return 0;
  }

  int d = existe(X->Direita,r);
  int e = existe(X->Esquerda,r);

  if(X->Elemento.NIF == r){
    return 1;
  }
  return 0;
}

Cliente CriarElementoCliente(PNodoAB T){
  Cliente X;
  int nif;
  printf("NIF :");
  scanf("%i",&nif);
  X.NIF=nif;
  if(existe(T,X.NIF)==0){
    printf("Nome:\n");
    clear_keyboard_buffer();
    fgets(X.Nome,100,stdin);
    X.Nome[strcspn(X.Nome, "\n")] = 0;

    printf("Morada:\n");
    fgets(X.Morada,200,stdin);
    X.Morada[strcspn(X.Morada, "\n")] = 0;

    printf("Email:\n");
    fgets(X.Email,30,stdin);
    X.Email[strcspn(X.Email, "\n")] = 0;

    printf("Nº de Telemovel:\n");
    scanf("%i",&X.Telemovel);
  }
  else{
    printf("JA EXISTE UM CLIENTE COM O NIF %d REGISTADO\n",nif);
    X.NIF = 0;
  }
  return X;
}

Cliente CriarElementoCliente1(PNodoAB T, int nif){
  Cliente X;
  X.NIF=nif;
  if(existe(T,X.NIF)==0){
    printf("Nome:\n");
    clear_keyboard_buffer();
    fgets(X.Nome,100,stdin);
    X.Nome[strcspn(X.Nome, "\n")] = 0;

    printf("Morada:\n");
    fgets(X.Morada,200,stdin);
    X.Morada[strcspn(X.Morada, "\n")] = 0;

    printf("Email:\n");
    fgets(X.Email,30,stdin);
    X.Email[strcspn(X.Email, "\n")] = 0;

    printf("Nº de Telemovel:\n");
    scanf("%i",&X.Telemovel);
  }
  else{
    printf("JA EXISTE UM CLIENTE COM O NIF %d REGISTADO\n",nif);
    X.NIF = 0;
  }
  return X;
}


int ver_ex(Cliente *p,int contador,int nif){
  int o=0, i;
  for(i=0;i<contador;i++){
    if(p[i].NIF == nif){
      return 1;
    }
  }
  return 0;
}



Cliente *Remover_Um_Cliente ( Cliente * cad, int cod ,int *qtd)
{
  for( int i = 0; i < *qtd; i++ )
    {
        //Verifica se o cliente possui o codigo desejado
        if( cad[i].NIF == cod )
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




int verificar(PNodoAB X,int r){
  if(X == NULL){
    return 0;
  }

  int d = existe(X->Direita,r);
  int e = existe(X->Esquerda,r);

  if(X->Elemento.NIF == r){
    return 1;
  }
  return 0;
}

/*
APLICAR NA LISTA DE LIVROS!!!!!
int verificarqtd(PNodoAB X,int r,int qtd){
  if(X == NULL){
    return 0;
  }

  int d = verificarqtd(X->Direita,r,qtd);
  int e = verificarqtd(X->Esquerda,r,qtd);

  if(X->Elemento.NIF == r){
    if(X->Elemento.Quantidade < qtd){
      return 1;
    }
  }
  return 0;
}
*/



int ABIguais (PNodoAB T, PNodoAB R) {
  int  ig;
  if (T == NULL && R == NULL)  // se s�o ambas nulas, ent�o s�o iguais
    return 1;
  if (T == NULL || R == NULL)  // se uma delas � nula, ent�o s�o diferentes
    return 0;
  if (CompararElementosCliente(T->Elemento, R->Elemento) != 0)  // ra�zes diferentes, �rvores diferentes
    return 0;
  if (ABIguais(T->Esquerda, R->Esquerda) == 0) // sub�rvores esq. diferentes
    return 0;
  if (ABIguais(T->Direita, R->Direita) == 0)  // sub�rvores direitas diferentes
    return 0;
  return 1;    // caso contr�rio, s�o iguais
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
    MostrarElementoCliente(T->Elemento);
    ListarPreOrdemAB(T->Esquerda);
    ListarPreOrdemAB(T->Direita);
  }
}

void fazervetor(Cliente T,Cliente *vetor,int *tam);

void CriarVetor (PNodoAB T,Cliente *p,int *tam) { //arvore , vetor para armazenar, tamanha do vertor
  if (T != NULL) {
    fazervetor(T->Elemento,p,tam);
    CriarVetor(T->Esquerda,p,tam);
    CriarVetor(T->Direita,p,tam);
  }
}

void fazervetor(Cliente T,Cliente *vetor,int *tam){
  *tam=*tam+1;
  vetor[*tam-1]=T;
}


void ListarNIF (PNodoAB T,int x) {
  if (T != NULL) {
    MostrarElementoClienteNIF(T->Elemento,x);
    ListarNIF(T->Esquerda,x);
    ListarNIF(T->Direita,x);
  }
}


void ListarNome (PNodoAB T, char nome[100]) {
  if (T != NULL) {
    MostrarElementoClienteNome(T->Elemento,nome);
    ListarNome(T->Esquerda,nome);
    ListarNome(T->Direita,nome);
  }
}

void ListarMorada (PNodoAB T, char morada[200]) {
  if (T != NULL) {
    MostrarElementoClienteMorada(T->Elemento,morada);
    ListarMorada(T->Esquerda,morada);
    ListarMorada(T->Direita,morada);
  }
}

void ListarEmail (PNodoAB T, char email[30]) {
  if (T != NULL) {
    MostrarElementoClienteEmail(T->Elemento,email);
    ListarEmail(T->Esquerda,email);
    ListarEmail(T->Direita,email);
  }
}

void ListarTelemovel (PNodoAB T, int telemovel) {
  if (T != NULL) {
    MostrarElementoClienteTelemovel(T->Elemento,telemovel);
    ListarTelemovel(T->Esquerda,telemovel);
    ListarTelemovel(T->Direita,telemovel);
  }
}


void ListarEmOrdemAB (PNodoAB T) {
  if (T != NULL) {
    ListarEmOrdemAB(T->Esquerda);
    MostrarElementoCliente(T->Elemento);
    ListarEmOrdemAB(T->Direita);
  }
}

void ListarPosOrdemAB (PNodoAB T) {
  if (T != NULL) {
    ListarPosOrdemAB(T->Esquerda);
    ListarPosOrdemAB(T->Direita);
    MostrarElementoCliente(T->Elemento);
  }
}

/*void alterarpreco (PNodoAB T,float Q,int A) {
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
*/

/*Livro valorLivro(PNodoAB T , int r){

  Livro i;
  Livro ii;
  Livro f;

  if(T == NULL){
    i.ISBN = 0;
    return i;
  }

  if(T->Elemento.NIF == r){
    return T->Elemento;
  }
  
  ii = valorLivro(T->Esquerda,r);
  
  if(ii.ISBN == r){
    return T->Elemento;
  }
   
  return valorLivro(T->Direita,r); 
}
*/

PNodoAB alterarTelemovelCliente(PNodoAB T , int nif,float Q){
  PNodoAB A = T;

  if(A == NULL){
    return T;
  }

  if(A->Elemento.NIF == nif){
    A->Elemento.Telemovel = Q;
    return T;
  }
  
  PNodoAB ii = alterarTelemovelCliente(A->Esquerda,nif,Q);
  
  if(ii != NULL){
    A->Elemento.Telemovel = Q;
    return T;
  } 
   
  return alterarTelemovelCliente(A->Direita,nif,Q);
}

PNodoAB alterarEmailCliente(PNodoAB T , int nif,char email[30] ){
  PNodoAB A = T;

  if(A == NULL){
    return T;
  }

  if(A->Elemento.NIF == nif){
    strcpy(A->Elemento.Email ,email);
    return T;
  }
  
  PNodoAB ii = alterarEmailCliente(A->Esquerda,nif,email);
  
  if(ii != NULL){
    strcpy(A->Elemento.Email,email);
    return T;
  } 
   
  return alterarEmailCliente(A->Direita,nif,email);
}

PNodoAB alterarNomeCliente(PNodoAB T , int nif,char nome[100] ){
  PNodoAB A = T;

  if(A == NULL){
    return T;
  }

  if(A->Elemento.NIF == nif){
    strcpy(A->Elemento.Nome,nome);
    return T;
  }
  
  PNodoAB ii = alterarNomeCliente(A->Esquerda,nif,nome);
  
  if(ii != NULL){
    strcpy(A->Elemento.Nome,nome);
    return T;
  } 
   
  return alterarNomeCliente(A->Direita,nif,nome);
}

PNodoAB alterarMoradaCliente(PNodoAB T , int nif,char morada[200] ){
  PNodoAB A = T;

  if(A == NULL){
    return T;
  }

  if(A->Elemento.NIF == nif){
    strcpy(A->Elemento.Morada,morada);
    return T;
  }
  
  PNodoAB ii = alterarMoradaCliente(A->Esquerda,nif,morada);
  
  if(ii != NULL){
    strcpy(A->Elemento.Morada,morada);
    return T;
  } 
   
  return alterarMoradaCliente(A->Direita,nif,morada);
}



PNodoAB PesquisarAB (Cliente X, PNodoAB T) {
  PNodoAB P;
  if (T == NULL)
    return NULL;
  if (CompararElementosCliente(X, T->Elemento) == 0)
    return T;
  P = PesquisarAB(X, T->Esquerda);
  if (P != NULL)
    return P;
  return PesquisarAB(X, T->Direita);
}

int CompararElementosCliente1 (int X, int Y){
  if (X == Y)
    return 1;
  return 0;
}

Cliente PesquisarABCliente (int X, PNodoAB T) {
  Cliente p;
  Cliente i;
  if (T == NULL)
    i.NIF = 0;
    return i;
  if (CompararElementosCliente1(X, T->Elemento.NIF) == 1)
    return T->Elemento;
  p = PesquisarABCliente(X, T->Esquerda);
  if (p.NIF != 0)
    return p;
  return PesquisarABCliente(X, T->Direita);
}


PNodoAB InserirPorAlturaAB (PNodoAB T, Cliente X) {
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
    
PNodoAB ProcurarFolhaAB (PNodoAB T, Cliente *X) {
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
  // 2 filhos: remover a folha escolhida e copiar a sua informa��o
  P = ProcurarFolhaAB(T, &X);
  //T->Elemento = P->Elemento;
  P = LibertarNodoAB(P);
  T->Elemento = X;
  return T;
}

PNodoAB RemoverAB (PNodoAB T,Cliente X) {
  PNodoAB P;
  if (T == NULL)
    return NULL;
  if (CompararElementosCliente(T->Elemento, X) == 0) {
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


PNodoAB abrirficheirocliente(){
  PNodoAB p = CriarAB();
  Cliente q;
  FILE *ft = fopen("clien.txt", "r");
  while(fscanf(ft," %d %s %s %s %d", &q.NIF,q.Nome,q.Morada,q.Email,&q.Telemovel)==5){   
    p=InserirABP(p,q);
    //p=InserirPorAlturaAB(p,q);
  }
  fclose(ft);
  return p;
}



void guardarclientes(PNodoAB A){
  if(A==NULL)
    return ;
  FILE *ft = fopen("clien.txt", "a");
  fclose(ft);
  fprintf(ft," %d %s %s %s %d\n",A->Elemento.NIF,A->Elemento.Nome,A->Elemento.Morada,A->Elemento.Email,A->Elemento.Telemovel);
  guardarclientes(A->Direita);
  guardarclientes(A->Esquerda);
}



/*
float VerPreco(Livro *p,int r,int cont){
  for(int i=0;i<cont;i++){
    if(p[i].ISBN == r){
      return p[i].Preco;
    }
  }
  return 0;
}

*/

