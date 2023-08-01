typedef struct{
   int   NIF;
   int   qtd;
   float preco;
}Pessoa;


void MostrarListaPessoal (Pessoa X){
  printf("%d - ", X.NIF); 
  printf("%d - ", X.qtd);
  printf("%f \n", X.preco);
}

Pessoa CriarListaPessoal (int e,int r,float t){
  Pessoa X;
  X.NIF=e;
  X.qtd=r;
  X.preco=t;
  return X;
}

int ver_existe_encom(Pessoa *V,int n,int *po){
  for(int i=0;i<*po;i++){
    if(V[i].NIF == n){
      return 1;
    }
  }
  return 0;
}

Pessoa *add_enc(Pessoa *V , int n,int m,float y,int *p){
  for(int i=0;i<*p;i++){
    if(V[i].NIF == n){
      V[i].qtd = V[i].qtd + m;
      V[i].preco = V[i].preco + y;
    }
  }
  return V;
}

Pessoa *add_enc_nova(Pessoa *V , int n,int m,float y,int *p){
  *p = *p + 1;
  V=(Pessoa *) realloc(V,(*p)*sizeof(Pessoa));
  Pessoa k;
  k.NIF = n;
  k.qtd = m;
  k.preco = y;
  V[*p-1]=k;
  return V;
}

Pessoa *ler(int *n){
  FILE *f;
  Pessoa *V,AL;
  f=fopen("dados.txt","r");
  *n=0;
  V=(Pessoa *)malloc(sizeof(Pessoa));
  while(fscanf(f,"%i %i %f",&AL.NIF,&AL.qtd,&AL.preco)==3){
    *n=*n+1;
    V=(Pessoa *) realloc(V,(*n)*sizeof(Pessoa));
    V[*n-1]=AL;
  }
  return V;
}


void guardarfila(Pessoa *V,int *t){
  FILE *ft = fopen("dados.txt", "w");

  for(int i=0;i<*t;i++){
    fprintf(ft,"%i %i %f\n",V[i].NIF,V[i].qtd,V[i].preco);
  }
}


Pessoa *ordenar (Pessoa *V, int N){
    int k, Num_trocas;
    Pessoa aux;
    do{
        Num_trocas = 0;
        for (k = 0; k < N-1; k++)
            if (V[k].qtd < V[k+1].qtd){
            aux = V[k];
            V[k] = V[k+1];
            V[k+1] = aux;
            Num_trocas++;
        }
    }while (Num_trocas != 0);
    return V;
}

void escrever(Pessoa *V,int *n){

    printf(ANSI_COLOR_YELLOW"\n\t\t NIF -- Quantidade -- Preco \n\n"ANSI_COLOR_RESET);
    for(int x=0;x<*n;x++){
        printf("%d -- ", V[x].NIF); 
        printf("%d -- ", V[x].qtd);
        printf("%f  \n", V[x].preco);
    }
}


int *MaisLivrosComprados(Pessoa *V,int p,int *num){
  int maior=0;
  int *i;
  *num =0;
  i=(int *)malloc(sizeof(int));

  for( int iii = 0;iii < p; iii++ ){
    if(maior < V[iii].qtd){
      maior = V[iii].qtd;
    }
  }

  for(int ii=0;ii<p;ii++){
    if(maior == V[ii].qtd){
      *num=*num+1;
      i=(int *) realloc(i,(*num)*sizeof(int));
      i[*num-1]=V[ii].NIF;
    }
  }
  return i;
}

int ClienteComprou(Pessoa *V,int p,int nif){
  for( int iii = 0;iii < p; iii++ ){
    if(V[iii].NIF == nif){
      return V[iii].qtd;
    }
  }
  return 0;
}

int *ClienteGastouMais(Pessoa *V,int p,int *num){
  int maior=0;
  int *i;
  *num =0;
  i=(int *)malloc(sizeof(int));

  for( int iii = 0;iii < p; iii++){
    if(maior < V[iii].preco){
      maior = V[iii].preco;
    }
  }

  for(int ii=0;ii<p;ii++){
    if(maior == V[ii].preco){
      *num=*num+1;
      i=(int *) realloc(i,(*num)*sizeof(int));
      i[*num-1]=V[ii].NIF;
    }
  }
  return i;
}

