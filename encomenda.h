typedef struct{
   int   numeroencomenda;
   int   numerolivro;
   int   numerocliente;
   int   data;
   int   num;
   float preco;
}ENC;


void MostrarElementoEncomenda (ENC X){
  printf("%i -- ", X.numeroencomenda); 
  printf("%i -- ", X.numerolivro);
  printf("%i -- ", X.numerocliente);
  printf("%i -- ", X.data);
  printf("%i -- ",  X.num);
  printf("%f\n",  X.preco);
}

ENC CriarElementoEncomenda (int *p,int q,int w,int e,int r,float t){
  ENC X;
  X.numeroencomenda = *p;
  *p = *p + 1;
  X.numerolivro=q;
  X.numerocliente=w;
  X.data=e;
  X.num=r;
  X.preco=t;
  return X;
//juntar a fila depois
}

