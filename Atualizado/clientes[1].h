#include<string.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct{
  int NIF;
  char Nome[100];
  char Morada[200]; 
  float telemovel;
}Cliente;

void clear_keyboard_buffer(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}

void MostrarElemento (Cliente X){
  printf("%i - %s - %s - %.0f", X.NIF,X.Nome,X.Morada,X.telemovel);

  printf("\n");
}





// comparação de 2 elementos do tipo INFO, segundo o campo NIF
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int CompararElementos (Cliente X, Cliente Y){
  if (X.NIF > Y.NIF)
    return 1;
  if (X.NIF < Y.NIF)
    return -1;
  return 0;
}