#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <ctype.h>

typedef struct{
  int ISBN;
  char Titulo[100];
  char Idioma[50]; 
  char Autor1[100]; 
  char Autor2[100]; 
  int AnoPub;
  char Editora[20];
  char Area[50];
  float Preco;
  int Quantidade;
}Livro;

void MostrarElementoLivro (Livro X){
  printf("\nISBN: %i  -  Titulo: %s  -  Autor Principal: %s  -  Preco: %.2f $  -  Quantidade: %i", X.ISBN,X.Titulo,X.Autor1,X.Preco,X.Quantidade);
  printf("\n");
}

/*
void MostrarElementoLivroISBN (Livro X,int T){
  if(X.ISBN == T){
    printf("\nISBN: %i  - Titulo: %s  - Autor Principal: %s  - Preco: %.2f $  - Quantidade: %i", X.ISBN,X.Titulo,X.Autor1,X.Preco,X.Quantidade);
    printf("\n");
  }
}

void MostrarElementoLivroISBN2 (Livro X,int T,int *r){
  if(X.ISBN == T){
    *(r) = 1;
  }
}

void MostrarElementoLivroQuantidade (Livro X,int T,int *r){
  if(X.ISBN == T){
    *(r) = X.Quantidade;
  }
}

void MostrarElementoLivroTitulo (Livro X,char T[50]){
  if(strcmp(X.Titulo,T) == 0){
    printf("\nISBN: %i  - Titulo: %s  - Autor Principal: %s  - Preco: %.2f $  - Quantidade: %i", X.ISBN,X.Titulo,X.Autor1,X.Preco,X.Quantidade);
    printf("\n");
  }
}


void MostrarElementoLivroEdiArea (Livro X,char T[],char T1[]){
  if( (strcmp(X.Editora,T) == 0) && (strcmp(X.Area,T1)== 0) ){
    printf("\nISBN: %i  - Titulo: %s  - Autor Principal: %s  - Preco: %.2f $  - Quantidade: %i", X.ISBN,X.Titulo,X.Autor1,X.Preco,X.Quantidade);
    printf("\n");
  }
}


void MostrarElementoLivroAnoeAutor (Livro X,char T[],int r){
  if((strcmp(X.Autor1,T) == 0) && r==X.AnoPub){
    printf("\nISBN: %i  - Titulo: %s  - Autor Principal: %s  - Preco: %.2f $  - Quantidade: %i", X.ISBN,X.Titulo,X.Autor1,X.Preco,X.Quantidade);
    printf("\n");
  }
}
*/

// compara��o de 2 elementos do tipo INFO, segundo o campo NIF
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int CompararElementosLivro (Livro X, Livro Y){
  if (X.ISBN > Y.ISBN)
    return 1;
  if (X.ISBN < Y.ISBN)
    return -1;
  return 0;
}

int CompararElementosLivro1 (int X, int Y){
  if (X == Y)
    return 1;
  return 0;
}
