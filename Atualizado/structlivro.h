#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <ctype.h>


typedef struct{
  int ISBN;
  char Titulo[50];
  char Idioma[50]; 
  char PrimAutor[50]; 
  char SegAutor[50]; 
  int AnoPub;
  char editora[50];
  char Area[50];
  float Preco;
  int Qtd;
}Livro;

int MemoriaLivro(Livro *p,int tam){
  int mem = 0;
  for(int i=0;i<tam;i++){
    mem = mem + ( ( 50 - strlen(p[i].Titulo)) + (50 - strlen(p[i].Idioma)) + (50 - strlen(p[i].PrimAutor) ) + ( 50 - strlen(p[i].SegAutor) ) + ( 50 - strlen(p[i].editora) ) + ( 50 - strlen(p[i].Area) ) - 6) ; // /s
  }
  return mem;
}

void MostrarElementoLivro (Livro X){
  printf("\nISBN: %i  -  Titulo: %s  -  Autor Principal: %s  -  Preco: %.2f $  -  Quantidade: %i", X.ISBN,X.Titulo,X.PrimAutor,X.Preco,X.Qtd);
  printf("\n");
}

void MostrarElementoLivroISBN (Livro X,int T){
  if(X.ISBN == T){
    printf("\nISBN: %i  - Titulo: %s  - Autor Principal: %s  - Preco: %.2f $  - Quantidade: %i", X.ISBN,X.Titulo,X.PrimAutor,X.Preco,X.Qtd);
    printf("\n");
  }
}

void MostrarElementoLivroISBN2 (Livro X,int T,int *r){
  if(X.ISBN == T){
    *(r) = 1;
  }
}

void MostrarElementoLivroqtd (Livro X,int T,int *r){
  if(X.ISBN == T){
    *(r) = X.Qtd;
  }
}

void MostrarElementoLivroTitulo (Livro X,char T[50]){

  if(strcmp(  (X.Titulo), (T)) == 0){
    printf("\nISBN: %i  - Titulo: %s  - Autor Principal: %s  - Preco: %.2f $  - Quantidade: %i", X.ISBN,X.Titulo,X.PrimAutor,X.Preco,X.Qtd);
    printf("\n");
  }
}




void MostrarElementoLivroEdiArea (Livro X,char T[],char T1[]){
  if( (strcmp(X.editora,T) == 0) && (strcmp(X.Area,T1)== 0) ){
    printf("\nISBN: %i  - Titulo: %s  - Autor Principal: %s  - Preco: %.2f $  - Quantidade: %i", X.ISBN,X.Titulo,X.PrimAutor,X.Preco,X.Qtd);
    printf("\n");
  }
}


void MostrarElementoLivroAnoeAutor (Livro X,char T[],int r){
  
  
  if((strcmp(X.PrimAutor,T) == 0) && r==X.AnoPub){
    printf("\nISBN: %i  - Titulo: %s  - Autor Principal: %s  - Preco: %.2f $  - Quantidade: %i", X.ISBN,X.Titulo,X.PrimAutor,X.Preco,X.Qtd);
    printf("\n");
  }
}




// comparação de 2 elementos do tipo INFO, segundo o campo NIF
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int CompararElementosLivro (Livro X, Livro Y){
  if (X.Preco > Y.Preco)
    return 1;
  if (X.Preco < Y.Preco)
    return -1;
  return 0;
}


int CompararElementosLivro1 (int X, int Y){
  if (X == Y)
    return 1;
  return 0;
}