typedef struct{
   int   numeroencomenda;
   int   numerolivro;
   int   numerocliente;
   int   dia;
   int   mes;
   int   ano;
   int   num;
   float preco;
}ENC;


void MostrarElementoEncomenda (ENC X){
  printf("%i -- ", X.numeroencomenda); 
  printf("%i -- ", X.numerolivro);
  printf("%i -- ", X.numerocliente);
  printf("%i / %i / %i -- ", X.dia,X.mes,X.ano);
  printf("%i -- ",  X.num);
  printf("%f\n",  X.preco);
}

ENC CriarElementoEncomenda (int *p,int q,int w,int e,int r,float t,int dias,int mess,int anos){
  ENC X;
  X.numeroencomenda = *p;
  *p = *p + 1;
  X.numerolivro=q;
  X.numerocliente=w;
  X.dia = dias;
  X.mes = mess;
  X.ano = anos;
  X.num=r;
  X.preco=t;
  return X;
//juntar a fila depois
}
