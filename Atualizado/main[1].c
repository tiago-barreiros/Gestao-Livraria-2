#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "incl.h"
#include "clientes.h"
#include "listaclientes.h"
#include "structlivro.h"
#include "operacoeslivros.h"
#include "arvore.h"
#include "binaria.h"
#include "encomenda.h"
#include "encom.h"
#include "filapessoal.h"
#include "menus.h"

int main(){
    PNodo cliente=Criar();
    PNodoAB Livros = CriarAB();
    PNodoAB LivrosaAux = CriarAB();
    PNodoFila Encomenda= CriarFila();
    Pessoa *ListaPessoal,*vetor;
    Livro l,livro_preco;
    Livro *ppp,*pl,*pl1,*pl2,*pl3,*pl4;
    ENC encomendaadd,vv;
    int opcao,n=0; 
    int s,s3,s2,s4,t,t1,t2,s5,z,x,c,v,s6;
    int q,w,e,r,y,u,existe,NIF;
    int numeroEncomenda = 0,nifenc,qtdenc;
    int ooo = 0,ii,re,numeroLista,is,qtdd,ano,numeroutil;
    float preco,precodaenc,mais;
    char verTitulo[50];
    char verAutor[50];
    char verEditora[50];
    char area[50]; 
    char verNome[100];
    char moradaa[200];
    time_t tt = time(NULL);
    struct tm tm = *localtime(&tt);
    bool ex;
    int *ww,num,*aa,contador,contador1,contador2,contador3;
    int o,mem1,mem2;
    Livro Q;
    Livro *aux2;
    
    do{
        menuPrincipal();
        do {
            printf( ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
            scanf("%i",&opcao);
            if (opcao < 1 || opcao > 6) {
              printf("Valor inválido!\n");
            }
        } while (opcao < 1 || opcao > 6);

        
        switch (opcao)
        {
        case 1 :
            
            do{
              menuFicheiro();
                do {
                    printf( ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
                    scanf("%i",&s);
                    if (s < 1 || s > 3) {
                        printf("Valor inválido!\n");
                    }
                } while (s < 1 || s > 3);

                switch(s){
                    case 1:

                        cliente = abrirficheirocliente();
                        LivrosaAux = abrirficheirolivro();
                        Livros = CriarABPEquilibradaIB(LivrosaAux);
                        Encomenda = abrirficheiroencomendas(&numeroEncomenda);
                        numeroEncomenda++;
                        ListaPessoal = ler(&numeroLista);

                        break;
                    case 2:
                        contador3 = NumeroNodosAB(Livros);//CONTA NODOS
                        int iop4=0;
                        PNodoAB qqq;
                        pl4 = (Livro *)malloc(sizeof(Livro) * (contador3)); //ALOCA MEMORIA
                        CriarVetor(Livros,pl4,&iop4);//CRIA ARRAY

                        guardar_livros(pl4, contador3);
                        guardarclientes(cliente);
                        guardar_enc(Encomenda);
                        guardarfila(ListaPessoal, &numeroLista);

                        break;   
                    case 3:
                        break; 
                }
            }while(s !=3);
        break;

        case 2:    
            do{
              menuLivros();
              printf("\n\n");
                do{
                    printf( ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
                    scanf("%i",&s2);
                    if (s2 < 1 || s2 > 9) {
                        printf("Valor inválido!\n");
                    }
                }while (s2 < 1 || s2 > 9);

                switch(s2){
                    case 1:

                        l = CriarElementoLivro(LivrosaAux);
                        if(l.ISBN != 0 ){
                          LivrosaAux = InserirABP(LivrosaAux, l);
                          Livros = CriarABPEquilibradaIB(LivrosaAux); 
                        }

                        break;
                    case 2:   

                        printf("ISBN do Livro a remover\n");
                        PNodoAB qq = CriarAB(); //Criar PNodo
                        contador2 = NumeroNodosAB(Livros);//CONTA NODOS
                        scanf("%i",&o); //LE

                        int iop2=0;
                        pl2 = (Livro *)malloc(sizeof(Livro) * (contador)); //ALOCA MEMORIA
                        CriarVetor(Livros,pl2,&iop2);//CRIA ARRAY
                        
                        if(ver_ex(pl2,contador2,o) == 1){ //VE SE EXISTE O LIVRO
                          Livro livroaux;
 
                          pl2 = Remover_Um_Livro(pl2,o,&contador2); //ATUALIZA

                          for(int o = 0;o<contador2;o++){
                            livroaux = pl2[o];
                            qq = InserirABP(qq, livroaux);
                          }

                          LibertarNodoAB(LivrosaAux); //LIMPA A ARVORE AUXILIAR
                          LibertarNodoAB(Livros);//LIMPA A ARVORE PRINCIPAL

                          LivrosaAux = CopiarAB(qq); //COPIA PARA A ARVORE SECUNDARIA
                          Livros = CriarABPEquilibradaIB(LivrosaAux); //EQULIBRA A ARVORE E METE A NA ARVORE PRINCIPAL
                        }
                        else{
                          printf("Este livro nao existe!\n");
                        }

                        break;   
                    case 3:

                        printf("ISBN: ");
                        scanf("%i",&is);
                        contador1 = NumeroNodosAB(Livros);//CONTA NODOS
                        int iop1=0;
                        pl1 = (Livro *)malloc(sizeof(Livro) * (contador)); //ALOCA MEMORIA
                        CriarVetor(Livros,pl1,&iop1);//CRIA ARRAY

                        if(ver_ex(pl1,contador1,is) == 1){
            
                          printf("\nAlterar Preco do Livro: ");
                          scanf("%f",&preco);
                          Livro qq ;
                          PNodoAB aux = CriarAB();
                          
                          for(int i=0;i<contador1;i++){
                            if(pl1[i].ISBN == is){
                              pl1[i].Preco = preco;
                            }
                          }
                      
                          LibertarNodoAB(LivrosaAux);
                          LibertarNodoAB(Livros);
                        

                          for(int o = 0;o<contador1;o++){
                            qq = pl1[o];
                            aux = InserirABP(aux, qq);
                          }
                          
                          LivrosaAux = CopiarAB(aux);
                          Livros = CriarABPEquilibradaIB(aux);
                        }
                        else{
                          printf("Este livro nao existe!\n");
                        }
                        break; 
                    case 4:

                        printf("ISBN: ");
                        scanf("%i",&y);
                        printf("\n");
                        ListarISBN(Livros, y);
                        printf("\n");

                        break;
                    case 5:

                        printf("Titulo:\n");
                        clear_keyboard_buffer();
                        fgets(verTitulo,100,stdin);
                        verTitulo[strcspn(verTitulo, "\n")] = 0;
                        ListarTitulo(Livros, verTitulo);

                        break;   
                    case 6:

                        printf("Autor:\n");
                        clear_keyboard_buffer();
                        fgets(verAutor,100,stdin);
                        verAutor[strcspn(verAutor, "\n")] = 0;
                        printf("Ano de Publicacao: \n");
                        scanf("%i",&ano);
                        Listarano(Livros, verAutor,ano);

                        break; 
                    case 7:

                        printf("Editora:\n");
                        clear_keyboard_buffer();
                        fgets(verEditora,100,stdin);
                        verEditora[strcspn(verEditora, "\n")] = 0;
                        printf("Area Cientifica: \n");
                        fgets(area,100,stdin);
                        area[strcspn(area, "\n")] = 0;
                        ListarEdiArea(Livros, verEditora,area);

                        break;
                    case 8:

                     if(ABVazia(Livros) == 0){
                        ListarEmOrdemAB(Livros);
                      }
                      else{
                        printf("\nArvore Vazia \n");
                      }

                        break;   
                    case 9:
                        break;    
                }
            }while(s2 != 9);
        break;
        
        case 3:
            do{
              menuClientes();
                do{
                    printf( ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
                    scanf("%i",&s3);
                    if (s3 < 1 || s3 > 8) {
                        printf("Valor inválido!\n");
                    }
                }while (s3 < 1 || s3 > 8);

                switch(s3){
                    case 1:

                        printf("");
                        Cliente p = CriarElemento(cliente);
                        if(p.NIF!=0){
                          cliente = InserirInicio(p, cliente);
                        }

                        break;
                    case 2:
                    
                        printf("NIF a Remover :");
                        scanf("%i",&t1);
                        cliente=removerele(t1, cliente);

                        break;   
                    case 3:

                        printf("NIF para alterar :");
                        scanf("%i",&t1);
                        alterar(cliente, t1);
                        break; 
                    case 4:

                        printf("NIF a Procurar :");
                        scanf("%i",&t);
                        ProcNIF(cliente, t);

                        break;
                    case 5:

                        printf("Nome a pesquisar: ");
                        clear_keyboard_buffer();
                        fgets(verNome,100,stdin);
                        verNome[strcspn(verNome, "\n")] = 0;
                        ProcNome(cliente,verNome);

                        break;   
                    case 6:

                        printf("Morada: ");
                        clear_keyboard_buffer();
                        fgets(moradaa,100,stdin);
                        moradaa[strcspn(moradaa, "\n")] = 0;
                        VerMorada(cliente,moradaa);

                        break; 
                    case 7:   

                        if((Vazia(cliente)==1)){
                          printf("Nao tem Clientes \n");
                        }else{
                          printf("Clientes Registados :\n");
                          Listar(cliente);
                        }

                        break;    
                    case 8:
                        break; 
                }
            }while(s3 != 8);
        break;
        case 4 :           
            do{
              ENC a;
               menuEncomendas();
                do{
                    printf( ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
                    scanf("%i",&s4);
                    if (s4 < 1 || s4 > 5) {
                        printf("Valor inválido!\n");
                    }
                }while (s4 < 1 || s4 > 5);

                switch(s4){
                    case 1:
                          //NUMERO ENCOMENDA
                          encomendaadd.numeroencomenda=numeroEncomenda;
                          printf("\nENCOMENDA NUMERO %i\n",encomendaadd.numeroencomenda); 

                          
                        
                          int rr,mm;
                          float pp;
                          int numero;
                          int contador3 = NumeroNodosAB(Livros);//CONTA NODOS
                          int iop3=0;
                          PNodoAB qqq = CriarAB();
                          pl3 = (Livro *)malloc(sizeof(Livro) * (contador3)); //ALOCA MEMORIA
                          CriarVetor(Livros,pl3,&iop3);//CRIA ARRAY
                          
                          ListarEmOrdemAB(Livros);

                          //NUMERO LIVRO
                          printf("\nNumero do Livro:");//numero livro
                          scanf("%i",&numero);
                          encomendaadd.numerolivro = numero;

                          //QUANTIDADE LIVRO
                          printf("\nQuantidade:");//qtd
                          scanf("%i",&encomendaadd.num);

                          //VER EXISTENCIA DE LIVRO 
                          rr = ver_exite_livro(pl3,contador3,numero);
                          if(rr == 1){
                            //VER EXISTENCIA DA QUANTIDADE DO LIVRO
                            ListarISBNqtd(Livros,encomendaadd.numerolivro,&mm);
                            if(encomendaadd.num <= mm){
                              numeroEncomenda = numeroEncomenda + 1;
                              contador = NumeroNodosAB(Livros);//CONTA NODOS
                              int iop=0;
                              pl = (Livro *)malloc(sizeof(Livro) * (contador)); //ALOCA MEMORIA
                              CriarVetor(Livros,pl,&iop);//CRIA ARRAY

                              int qwe = concint(tm.tm_year + 1900, tm.tm_mon + 1); //DATA
                              int qwee = concint(qwe, tm.tm_mday);//DATA
                              int opi = (int)qwee;//DATA


                              int dia = tm.tm_mday;
                              int mes = tm.tm_mon+1;
                              int ano = tm.tm_year+1900;

                              encomendaadd.dia = dia;//DATA
                              encomendaadd.mes = mes;//DATA
                              encomendaadd.ano = ano;//DATA

                              //PEDE NIF
                              printf("\nNIF:"); 
                              scanf("%i",&encomendaadd.numerocliente);
                              nifenc = encomendaadd.numerocliente;

                              //VER PRECO DO LIVRO
                              float o = VerPreco(pl,numero,contador);
                              encomendaadd.preco=o;
                              
                              //ADICIONA A ENCOMENDA
                              Encomenda = Juntar(encomendaadd, Encomenda);
                              
                              //PRECO TOTAL
                              precodaenc = encomendaadd.preco * encomendaadd.num; 

                              //QUANTIDADE
                              qtdenc = encomendaadd.num;

                              for(int o = 0;o<contador3;o++){ //remover a quantidade
                                if(pl3[o].ISBN == encomendaadd.numerolivro){
                                  pl3[o].Qtd = pl3[o].Qtd - qtdenc;
                                }
                              }
                              
                              for(int oo = 0;oo<contador3;oo++){ //atualizar valores
                                Livro livroaux = pl3[oo];
                                qqq = InserirABP(qqq, livroaux);
                              }

                              DestruirAB(LivrosaAux); //LIMPA A ARVORE AUXILIAR
                              DestruirAB(Livros);//LIMPA A ARVORE PRINCIPAL
                              LivrosaAux = CopiarAB(qqq); //COPIA PARA A ARVORE SECUNDARIA
                              Livros = CriarABPEquilibradaIB(LivrosaAux); //EQULIBRA A ARVORE E METE A NA ARVORE PRINCIPAL

                              //TOTAL
                              printf("\nTotal = %f\n",precodaenc);
                            }
                            else{
                              printf("\nNao esta Disponivel esta Quantidade \n");
                            }
                          }
                          else{
                            printf("\nNao existe o Livro desejado\n");
                          }

                    break;
                    case 2:

                        printf("\n");
                        if(FilaVazia(Encomenda)==1){
                          printf("Vazia\n");
                        }else{
                          listaenc(Encomenda);
                        }

                        break;   
                    case 3:

                        printf("\nDESPACHAR ENCOMENDA \n");
                        printf("------------------------\n");

                        //VE SE ESTA VAZIA
                        if(FilaVazia(Encomenda) != 1){

                          //GUARDA O VALOR E RETIRA
                          ENC top = Frente(Encomenda);
                          Encomenda = RemoverEncomenda(Encomenda);

                          //VER SE O CLIENTE JA ESTA NA FILA PESSOAL ATRAVES DO NIF
                          
                              if(ver_existe_encom(ListaPessoal,top.numerocliente,&numeroLista)){ //SIM
                                ListaPessoal = add_enc(ListaPessoal,top.numerocliente,top.num,top.preco*top.num,&numeroLista);
                              }
                              else{ //NAO
                                if(ProcNIF2(cliente,top.numerocliente) == 1){ //SE ESTIVER REGISTADO NOS CLIENTE VAI AUTOMATICAMENTE PARA A LISTA PESSOAL
                                  ListaPessoal = add_enc_nova(ListaPessoal,top.numerocliente,top.num,top.preco*top.num,&numeroLista);
                                }
                                else{ //CASO NAO ESTEJA, PODE IR OU NAO

                                  printf("\nDesja ser Cliente da Livraria ? (%i)\n",top.numerocliente);
                                  printf("\t\t 1.SIM\n");
                                  printf("\t\t 2.NAO\n");

                                  printf( ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
                                  scanf("%i",&re);
                                  if(re < 1 || re>2){
                                    do{
                                      printf( ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
                                      scanf("%i",&re);
                                      if (re < 1 || re > 2) {
                                        printf("Valor inválido!\n");
                                      }
                                    }while (re < 1 || re > 2);
                                  }

                                  if(re == 1){ //CASO QUEIRA TER LISTA PESSOAL
                                    Cliente p = CriarElemento1(cliente,top.numerocliente);
                                    int op;
                                    op =p.NIF;
                                    printf("%i\n",op);
                                    while(op == 0){
                                      Cliente p = CriarElemento1(cliente,top.numerocliente);
                                      op =p.NIF;
                                      printf("%i\n",op);
                                    }

                                    cliente = InserirInicio(p, cliente); //adicionar aos clientes
                                    ListaPessoal = add_enc_nova(ListaPessoal,top.numerocliente,top.num,top.preco*top.num,&numeroLista); //adicionar a lista pessoal
                                  }
                                }
                              }
                          printf("\nA Encomenda %i foi despachada\n",top.numeroencomenda);
                        }else{
                          printf("\nNAO EXISTE ENCOMENDAS\n");
                        }

                        break;
                    case 4:

                      escrever(ListaPessoal,&numeroLista);
                      
                      break;  
                    case 5:
                      break;                
              }
            }while(s4 != 5);
        break;

        case 5 :
            
           do{
              menuOperacoes();
                do {
                    printf(ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
                    scanf("%i",&s6);
                    if (s6 < 1 || s6 > 9) {
                        printf("Valor inválido!\n");
                    }
                } while (s6 < 1 || s6 > 9);

                switch(s6){
                    case 1:
                        printf("");
                        int contador6 = NumeroNodosAB(Livros);//CONTA NODOS
                        int iop6=0;
                        Livro *pl6;
                        pl6 = (Livro *)malloc(sizeof(Livro) * (contador6)); //ALOCA MEMORIA
                        CriarVetor(Livros,pl6,&iop6);//CRIA ARRAY

                        ordenar_Livro(pl6, contador6);
                        print_livros(pl6, contador6);

                        break;
                    case 2:
			                  printf("\nNumero do Cliente: ");
                        int numero,result;
                        scanf("%i",&numero);
                        printf("\n");
                        result = ClienteComprou(ListaPessoal, numeroLista, numero);
                        printf("NIF    -> %i\n",numero);
                        printf("Numero -> %i\n",result);
                        break;   
                    case 3:
                        printf("");
                        int contador66 = NumeroNodosAB(Livros);//CONTA NODOS
                        int iop66=0;
                        Livro *pl66;
                        pl66 = (Livro *)malloc(sizeof(Livro) * (contador66)); //ALOCA MEMORIA
                        CriarVetor(Livros,pl66,&iop66);//CRIA ARRAY

                        int kk=0;
                        int maior =0;
                        AREA *vv=AreaCientifica(pl66, contador66, &kk,&maior);

                        for(int i=0;i<kk;i++){
                          if(vv[i].qtd == maior){
                            printf("\n Area : %s  --- Quantidade : %i",vv[i].nome,vv[i].qtd);
                          }
                        }
                        printf("\n\n");
                        break;
                    case 4:
			                  ww = MaisLivrosComprados(ListaPessoal, numeroLista, &num);
                        for (int i=0;i<num;i++){
                          printf("NIF -> %i\n",ww[i]);
                        }
                        
                        break;
                    case 5:
			                  vetor = ordenar(ListaPessoal, numeroLista);
                        for (int i=0;i<numeroLista;i++){
                          printf("NIF -> %i  Qtd -> %i\n",vetor[i].NIF,vetor[i].qtd);
                        }

                        break;
                    case 6:
                        printf("");
                        int contador5 = NumeroNodosAB(Livros);//CONTA NODOS
                        int iop5=0;
                        Livro *pl5;
                        pl5 = (Livro *)malloc(sizeof(Livro) * (contador5)); //ALOCA MEMORIA
                        CriarVetor(Livros,pl5,&iop5);//CRIA ARRAY

                        int k=0;
                        int *v=AnoMaisPublicacoes(pl5, contador5, &k);

                        for(int i=0;i<k;i++){
                          printf("\n Ano : %i",v[i]);
                        }
                        printf("\n\n");
                        break;

                    case 7:
                       aa = ClienteGastouMais(ListaPessoal, numeroLista,&numeroutil,&mais);
                        for (int i=0;i<numeroutil;i++){
                          printf("NIF -> %i Valor -> %f \n",aa[i],mais);
                        }
                        break;
                    case 8:
                        mem1 = MemoriaCliente(cliente);
                        int contador4 = NumeroNodosAB(Livros);//CONTA NODOS
                        int iop4=0;
                        Livro *pl4;
                        pl4 = (Livro *)malloc(sizeof(Livro) * (contador4)); //ALOCA MEMORIA
                        CriarVetor(Livros,pl4,&iop4);//CRIA ARRAY

                        mem2 = MemoriaLivro(pl4, contador4);

                        int titulo = 50 - strlen(verTitulo) - 1 ;
                        int ed = 50 - strlen(verEditora) - 1 ;
                        int a = 50 - strlen(area) - 1 ;
                        int nome = 100 - strlen(verNome) - 1 ;
                        int mor = 200 - strlen(moradaa) - 1 ;

                        printf("\nMemoria Desperdicada : %i bytes\n",mem1+mem2+titulo+ed+a+nome+mor);
                        break;
                    case 9:
                        break;
                }
            }while(s6 !=9);
        break;
        }
    }while(opcao != 6);
}