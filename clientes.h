#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  int NIF;
  char Nome[100];
  char Morada[200];
  char Email[30];
  int Telemovel;
}Cliente;

void clear_keyboard_buffer(void)
{
  int c = 0;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
  return;
}

void MostrarElementoCliente(Cliente X)
{
  printf("NIF: %d - Nome: %s - Morada: %s - Email: %s - Telemovel: %d", X.NIF, X.Nome, X.Morada, X.Email, X.Telemovel);
  printf("\n");
}

void MostrarElementoClienteNIF(Cliente X, int T)
{
  if (X.NIF == T)
  {
    printf("NIF: %d - Nome: %s - Morada: %s - Email: %s - Telemovel: %d", X.NIF, X.Nome, X.Morada, X.Email, X.Telemovel);
    printf("\n");
  }
}

void MostrarElementoClienteNome(Cliente X, char nome[100])
{
  if (strcmp(X.Nome, nome) == 0)
  {
    printf("NIF: %d - Nome: %s - Morada: %s - Email: %s - Telemovel: %d", X.NIF, X.Nome, X.Morada, X.Email, X.Telemovel);
    printf("\n");
  }
}

void MostrarElementoClienteMorada(Cliente X, char morada[200])
{
  if (strstr(X.Morada, morada) == 0)
  {
  }
  else{
    printf("NIF: %d - Nome: %s - Morada: %s - Email: %s - Telemovel: %d", X.NIF, X.Nome, X.Morada, X.Email, X.Telemovel);
    printf("\n");
  }
}

void MostrarElementoClienteEmail(Cliente X, char email[30])
{
  if (strcmp(X.Email, email) == 0)
  {
    printf("NIF: %d - Nome: %s - Morada: %s - Email: %s - Telemovel: %d", X.NIF, X.Nome, X.Morada, X.Email, X.Telemovel);
    printf("\n");
  }
}

void MostrarElementoClienteTelemovel(Cliente X, int T)
{
  if (X.Telemovel == T)
  {
    printf("NIF: %d - Nome: %s - Morada: %s - Email: %s - Telemovel: %d", X.NIF, X.Nome, X.Morada, X.Email, X.Telemovel);
    printf("\n");
  }
}

// compara��o de 2 elementos do tipo INFO, segundo o campo NIF
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int CompararElementosCliente(Cliente X, Cliente Y)
{
  if (X.NIF > Y.NIF)
    return 1;
  if (X.NIF < Y.NIF)
    return -1;
  return 0;
}
