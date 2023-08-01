
struct Nodo
{
  Livro Elemento;
  struct Nodo *Prox;
};

typedef struct Nodo *PNodo;

#include <string.h>

PNodo Criar()
{
  PNodo L;
  L = NULL;
  return L;
}
int Pesquisar(Livro X, PNodo L);

int ProcurarISBN(PNodo T, int isbn){
  PNodo P = T;
  int i = 0;
  while(P!=NULL){
    if(P->Elemento.ISBN == isbn){
      i=1;
    }
    P=P->Prox;
  }
  return i;
}

PNodo CriarNodo(Livro X)
{
  PNodo P;
  P = (PNodo)malloc(sizeof(struct Nodo));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

void LibertarNodo(PNodo P)
{
  free(P);
  P = NULL;
}

PNodo Remover(Livro X, PNodo L);

Livro CriarElemento(PNodo A)
{
  Livro X;
  int ISBN;
  printf("ISBN : ");
  scanf("%i", &ISBN);
  if (ProcurarISBN(A, ISBN) == 1)
  {
    printf("Já existe um livro com este ISBN \n\n");
    X.ISBN = 0;
  }
  else
  {
    float rr;
    X.ISBN = ISBN;
    
    printf("Titulo : ");
    clear_keyboard_buffer();
    fgets(X.Titulo, 100, stdin);
    X.Titulo[strcspn(X.Titulo, "\n")] = 0;
    
    printf("Autor Principal : ");
    fgets(X.Autor1, 100, stdin);
    X.Autor1[strcspn(X.Autor1, "\n")] = 0;
    
    printf("Autor Secundário : ");
    fgets(X.Autor2, 100, stdin);
    X.Autor2[strcspn(X.Autor2, "\n")] = 0;
    
    printf("Idioma : ");
    fgets(X.Idioma, 50, stdin);
    X.Idioma[strcspn(X.Idioma, "\n")] = 0;
    
    printf("Ano de Publicação:");
    scanf("%d", &X.AnoPub);
    clear_keyboard_buffer();
    
    printf("Editora : ");
    fgets(X.Editora, 20, stdin);
    X.Editora[strcspn(X.Editora, "\n")] = 0;
    
    printf("Area Cientifica : ");
    fgets(X.Area, 50, stdin);
    X.Area[strcspn(X.Area, "\n")] = 0;
    
    printf("Preço do livro:");
    scanf("%f",&X.Preco);
    
    printf("Quantidade deste livro:");
    scanf("%d",&X.Quantidade);
  }
  return X;
}

void MostrarLivroPeloISBN(PNodo T, int ISBN)
{
  PNodo P = T;
  int i = 0;
  while (P != NULL)
  {
    if (ISBN == P->Elemento.ISBN)
    {
      MostrarElementoLivro(P->Elemento);
      i = 1;
    }
    P = P->Prox;
  }
  if (i == 0)
  {
    printf("Não existe um livro com ISBN %d \n", ISBN);
  }
}

void MostrarLivrosPeloTitulo(PNodo T, char titulo[200])
{
  PNodo P = T;
  int i = 0;
  while (P != NULL)
  {
    if (strstr(P->Elemento.Titulo, titulo) == 0)
    {
    }else{
      MostrarElementoLivro(P->Elemento);
      i = 1;
    }
    P = P->Prox;
  }
  if (i == 0)
  {
    printf("Nao foram encontrados livros com o titulo introduzido\n");
  }
}

void MostrarLivrosPeloAutorAno(PNodo T, char autor[100], int anoP)
{
  PNodo P = T;
  int i = 0;
  while (P != NULL)
  {
    if ((strcmp(P->Elemento.Autor1, autor) == 0 || strcmp(P->Elemento.Autor2, autor) == 0) && anoP == P->Elemento.AnoPub)
    {
      MostrarElementoLivro(P->Elemento);
      i = 1;
    }
    P = P->Prox;
  }
  if (i == 0)
  {
    printf("Nao foram encontrados livros com o autor %s no ano de publicacao %d\n", autor, anoP);
  }
}

void MostrarLivrosPelaEditoraArea(PNodo T, char editora[50], char area[50])
{
  PNodo P = T;
  int i = 0;
  while (P != NULL)
  {
    if ((strcmp(P->Elemento.Editora, editora) == 0 && strcmp(P->Elemento.Area, area) == 0))
    {
      MostrarElementoLivro(P->Elemento);
      i = 1;
    }
    P = P->Prox;
  }
  if (i == 0)
  {
    printf("Nao foram encontrados livros da editora %s e da area cientifica %s \n", editora, area);
  }
}

void MostrarLivrosMenorPreco(PNodo T, float preco)
{
  PNodo P = T;
  int i = 0;
  while (P != NULL)
  {
    if (P->Elemento.Preco < preco)
    {
      MostrarElementoLivro(P->Elemento);
      i = 1;
    }
    P = P->Prox;
  }
  if (i == 0)
  {
    printf("Nao foram encontrados livros com o preço inferior a %f", preco);
  }
}

void MostrarLivrosMenorQtd(PNodo T, int qtd)
{
  PNodo P = T;
  int i = 0;
  while (P != NULL)
  {
    if (P->Elemento.Quantidade < qtd)
    {
      MostrarElementoLivro(P->Elemento);
      i = 1;
    }
    P = P->Prox;
  }
  if (i == 0)
  {
    printf("Não existem na biblioteca livros com quantidades menores do que %d", qtd);
  }
}

int Vazia(PNodo L)
{
  if (L == NULL)
    return 1;
  else
    return 0;
}

void alterarLivro(PNodo A, int ISBN)
{
  PNodo P = A;
  char titulo[100], autor1[100], autor2[100];
  float npreco;
  int nqtd;
  int i = 0, op;
  while (P != NULL)
  {
    if (P->Elemento.ISBN == ISBN)
    {
      i = 1;
      do
      {
        printf("Introduza o que pretende modificar neste livro:\n");
        printf("\t\t1.Alterar Titulo\n");
        printf("\t\t2.Alterar Nome de Autores\n");
        printf("\t\t3.Alterar Quantidades:\n");
        printf("\t\t4.Alterar Preço:\n");
        printf("\n\n");
        printf("\t\t0.Voltar\n");
        scanf("%d", &op);
      } while (op < 1 || op > 4);
      switch (op)
      {
      case 0:
        break;
      case 1:
        printf("NOVO Titulo: ");
        clear_keyboard_buffer();
        fgets(titulo, 100, stdin);
        titulo[strcspn(titulo, "\n")] = 0;
        strcpy(P->Elemento.Titulo, titulo);
        break;
      case 2:
        printf("NOVO Autor Principal: ");
        clear_keyboard_buffer();
        fgets(titulo, 100, stdin);
        autor1[strcspn(autor1, "\n")] = 0;
        strcpy(P->Elemento.Autor1, autor1);

        printf("NOVO Autor Secundário: ");
        clear_keyboard_buffer();
        fgets(titulo, 100, stdin);
        autor2[strcspn(autor2, "\n")] = 0;
        strcpy(P->Elemento.Autor2, autor2);
        break;
      case 3:
        printf("NOVA Quantidade: ");
        scanf("%d", &nqtd);
        P->Elemento.Quantidade = nqtd;
        break;
      case 4:
        printf("NOVO Preço: ");
        scanf("%f", &npreco);
        P->Elemento.Preco = npreco;
        break;
      }
    }
    P = P->Prox;
  }
  if (i == 0)
  {
    printf("Nao existe \n");
  }
}

PNodo removerLivro(int X, PNodo L)
{
  Livro RX;
  RX.ISBN = X;
  if (Pesquisar(RX, L) == 1)
  {
    L = Remover(RX, L);
  }
  return L;
}

void Listar(PNodo L)
{
  PNodo P = L;
  while (P != NULL)
  {
    MostrarElementoLivro(P->Elemento);
    P = P->Prox;
  }
  printf("\n\n");
}

void ListarRec(PNodo L)
{
  if (L != NULL)
  {
    MostrarElementoLivro(L->Elemento);
    ListarRec(L->Prox);
  }
}

void ListarContrarioRec(PNodo L)
{
  if (L != NULL)
  {
    ListarContrarioRec(L->Prox);
    MostrarElementoLivro(L->Elemento);
  }
}

PNodo InserirInicio(Livro X, PNodo L)
{
  PNodo P;
  P = CriarNodo(X);
  if (P == NULL)
    return L;
  P->Prox = L;
  L = P;
  return L;
}

// ###############  A2  ########################

int Pesquisar(Livro X, PNodo L)
{
  while (L != NULL && CompararElementosLivro(L->Elemento, X) != 0)
    L = L->Prox;
  if (L == NULL)
    return 0;
  else
    return 1;
}

int PesquisarRec(Livro X, PNodo L)
{
  if (L == NULL)
    return 0;
  if (CompararElementosLivro(L->Elemento, X) == 0)
    return 1;
  else
    return PesquisarRec(X, L->Prox);
}

PNodo ProcurarAnterior(Livro X, PNodo L)
{
  PNodo Ant = NULL;
  while (L != NULL && CompararElementosLivro(L->Elemento, X) != 0)
  {
    Ant = L;
    L = L->Prox;
  }
  return Ant;
}

PNodo ProcurarAnteriorRec(Livro X, PNodo L)
{
  if (CompararElementosLivro(L->Elemento, X) == 0)
    return NULL; //  s� acontece se X estiver no in�cio de L
  if (CompararElementosLivro(L->Prox->Elemento, X) == 0)
    return L;
  return ProcurarAnteriorRec(X, L->Prox);
}

// remover X da lista L, em que X est� na lista
PNodo Remover(Livro X, PNodo L)
{
  PNodo P, PAnt;
  PAnt = ProcurarAnterior(X, L);
  if (PAnt == NULL)
  { // remover elemento do in�cio de L
    P = L;
    L = L->Prox;
  }
  else
  {
    P = PAnt->Prox;
    PAnt->Prox = P->Prox; // ou (PAnt->Prox)->Prox
  }
  LibertarNodo(P);
  return L;
}

// remover X da lista L, em que X est� na lista
PNodo RemoverRec(Livro X, PNodo L, PNodo LAux)
{
  PNodo P;
  if (CompararElementosLivro(L->Elemento, X) == 0)
  { // X est� no in�cio da Lista L
    P = L;
    L = L->Prox;
    free(P);
    return L;
  }
  if (CompararElementosLivro(LAux->Prox->Elemento, X) == 0)
  {
    // X est� na lista L, mas n�o no inicio
    P = LAux->Prox;
    LAux->Prox = P->Prox; // ou LAux->Prox->Prox;
    free(P);
    return L;
  }
  return RemoverRec(X, L, LAux->Prox);
}

// ###############  A3  ########################

int Tamanho(PNodo L)
{
  int tam = 0;
  while (L != NULL)
  {
    tam++;
    L = L->Prox;
  }
  return tam;
}

int TamanhoRec(PNodo L)
{
  if (L == NULL)
    return 0;
  else
    return 1 + TamanhoRec(L->Prox);
}

PNodo InserirFim(Livro X, PNodo L)
{
  PNodo P, PAux;
  P = CriarNodo(X);
  if (P == NULL)
    return L;
  if (L == NULL)
    return P;
  PAux = L;
  while (PAux->Prox != NULL) // marcar o elemento do fim de L
    PAux = PAux->Prox;
  PAux->Prox = P;
  return L;
}

PNodo InserirFimRec(Livro X, PNodo L)
{
  PNodo P;
  if (L == NULL)
  { // s� acontece se a lista inicial for vazia
    P = CriarNodo(X);
    if (P != NULL)
      L = P;
    return L;
  }
  if (L->Prox == NULL)
  { // fim da lista L
    P = CriarNodo(X);
    if (P != NULL)
      L->Prox = P;
  }
  else
    InserirFimRec(X, L->Prox); // o que devolve n�o interessa
  return L;                    // devolve o in�cio da lista
}

// assume-se que a lista est� ordenada por ordem crescente
PNodo ProcurarInserirOrdem(Livro X, PNodo L)
{
  PNodo Ant = NULL;
  while (L != NULL && CompararElementosLivro(L->Elemento, X) < 0)
  {
    Ant = L;
    L = L->Prox;
  }
  return Ant;
}

int encontrouLivro (PNodo P, int ISBN){
  PNodo Ant = NULL;
  int i = -2;
  while(P!=NULL){
    if (P->Elemento.ISBN==ISBN)
        i=0;
    Ant = P;
    P = P->Prox;
  }
  return i;
}

int existeQuantidade(PNodo P, int ISBN){
  PNodo Ant = P;
  int qtd=0;
  while(Ant!=NULL){
    if (Ant->Elemento.ISBN==ISBN)
        qtd=0;
    Ant = Ant->Prox;
  }
  return qtd;
}

void criarVetor(Livro X, Livro *vetor, int *tam){
    *tam = *tam + 1;
    vetor[*tam-1] = X;
}

void criarVetorPelaLista(PNodo A, Livro *vetor,  int *tam){
  PNodo P = A;
  while(P!=NULL){
    criarVetor(P->Elemento,vetor,tam);
    P = P->Prox;
  }
}

PNodo InserirOrdem(Livro X, PNodo L)
{
  PNodo P, PAnt;
  P = CriarNodo(X);
  if (P == NULL)
    return L;
  if (L == NULL)
    return P; // a lista L inicia-se em P
  PAnt = ProcurarInserirOrdem(X, L);
  if (PAnt == NULL)
  { // inserir no in�cio de L
    P->Prox = L;
    return P;
  }
  P->Prox = PAnt->Prox;
  PAnt->Prox = P;
  return L;
}

PNodo abrirficheiroLivro()
{
  PNodo p = Criar();
  Livro w;
  int rr;
  float y;
  FILE *ft = fopen("livraria.txt", "r");
  while(fscanf(ft," %i %s %s %s %s %i %s %s %f %i", &w.ISBN,w.Titulo,w.Idioma,w.Autor1,w.Autor2,&w.AnoPub,w.Editora,w.Area,&w.Preco,&w.Quantidade)==10)
  {
    p = InserirInicio(w, p);
  }
  fclose(ft);
  return p;
}


void guardarficheiroLivro(PNodo A){
  FILE *ft = fopen("livraria.txt", "w");
  while (A != NULL)
  {
    fprintf(ft, " %i %s %s %s %s %i %s %s %f %i\n", A->Elemento.ISBN, A->Elemento.Titulo, A->Elemento.Idioma, A->Elemento.Autor1,A->Elemento.Autor2,A->Elemento.AnoPub,A->Elemento.Editora,A->Elemento.Area,A->Elemento.Preco,A->Elemento.Quantidade);
    A = A->Prox;
  }
  fclose(ft);
}

int contarLivros(PNodo P)
{
  PNodo Aux = P;
  int num;
   while(Aux!=NULL){
     num++;
     Aux=Aux->Prox;
   }
   return num;
}