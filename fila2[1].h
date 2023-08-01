typedef struct{
   int   NIF;
   int   qtd;
   int   *item;
   float preco;
}Pessoa;

/*
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
}*/

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

/*
void ordenar (Pessoa *V, int N){
    int k, Num_trocas;
    Pessoa aux;
    do{
        Num_trocas = 0;
        for (k = 0; k < N-1; k++)
            if (V[k].NIF < V[k+1].NIF){
            aux = V[k];
            V[k] = V[k+1];
            V[k+1] = aux;
            Num_trocas++;
        }
    }while (Num_trocas != 0);
}

*/

void escrever(Pessoa *V,int *n){
    for(int x=0;x<*n;x++){
        printf("%d - ", V[x].NIF); 
        printf("%d - ", V[x].qtd);
        printf("%f  \n", V[x].preco);
    }
}

Pessoa *actualizar(Pessoa *V,int n,int pp,float p,int ppp){
  for( int i = 0;i < pp; i++ ){
    if(V[i].NIF == n){
      V[i].preco = V[i].preco - p;
      V[i].qtd = V[i].qtd - p;
    }
  }
  return V;
}
