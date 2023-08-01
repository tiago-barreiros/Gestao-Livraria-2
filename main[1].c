#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "incl.h"
#include "clientes.h"
#include "structlivro.h"
//#include "listaclientes.h"
#include "listaLivros.h"

#include "arvore.h"
#include "binaria.h"
#include "arvoreClientes.h"
//#include "operacoeslivros.h"
#include <time.h>
#include "encomenda.h"
#include "encom.h"
#include "listacompras.h"
#include "filapessoal.h"
#include "menus.h"

int main()
{
  //PNodo cliente=Criar();
  PNodoAB ClientesLista = CriarAB();
  PNodoAB ClienteAux = CriarAB();
  PNodo Livros = Criar();
  PNodo LivrosAux = Criar();
  PNodoFila Encomenda = CriarFila();
  Pessoa *ListaPessoal, *vetor;
  Cliente l;
  //Cliente livro_preco;
  Cliente *ppp, *pl, *pl1, *pl3;
  Livro *liv1, *liv2;
  Cliente *pl2;
  ENC encomendaadd, vv;
  int opcao, n = 0;
  int s, s3, s2, s4, t, t1, t2, s5, z, x, c, v, s6;
  int q, w, e, r, y, u, exist, NIF;
  int numeroEncomenda = 0, nifenc, qtdenc;
  int ooo = 0, ii, re, numeroLista, is, qtdd, ano, numeroutil;
  float preco, precodaenc;
  char Titulo[100];
  char Editora[50];
  char AreaCientifica[50];
  char Nome[100];
  char Morada[200];
  char Autor[100];
  time_t tt = time(NULL);
  struct tm tm = *localtime(&tt);
  bool ex;
  int *ww, num, *aa, contador, contador1, contador2;
  int o;
  Livro Q;
  Livro *aux2;

  do
  {
    menuPrincipal();
    do
    {
      printf(ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
      scanf("%i", &opcao);
      if (opcao < 1 || opcao > 6)
      {
        printf("Valor invalido!\n");
      }
    } while (opcao < 1 || opcao > 6);

    switch (opcao)
    {
    case 1:

      do
      {
        menuFicheiro();
        do
        {
          printf(ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
          scanf("%i", &s);
          if (s < 1 || s > 3)
          {
            printf("Valor invalido!\n");
          }
        } while (s < 1 || s > 3);

        switch (s)
        {
        case 1:

          Livros = abrirficheiroLivro();
          ClienteAux = abrirficheirocliente();
          ClientesLista = CriarABPEquilibradaIB(ClienteAux);
          Encomenda = abrirficheiroencomendas(&numeroEncomenda);
          //EncTotal = abrirficheiroencomendasTotal(&numero_Enc_Total);
          //numero_Enc_Total++;
          numeroEncomenda++;
          //Livros = CriarABPEquilibradaIB(LivrosaAux);
          //Encomenda = abrirficheiroencomendas(&numeroEncomenda);
          ListaPessoal = ler(&numeroLista);

          break;
        case 2:

          guardarficheiroLivro(Livros);
          guardarclientes(ClientesLista);
          //guardar_enc(Encomenda);
          //guardarfila(ListaPessoal, &numeroLista);

          break;
        case 3:
          break;
        }
      } while (s != 3);
      break;

    case 3:
      do
      {
        menuClientes();
        printf("\n\n");
        do
        {
          printf(ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
          scanf("%i", &s2);
          if (s2 < 1 || s2 > 8)
          {
            printf("Valor inválido!\n");
          }
        } while (s2 < 1 || s2 > 8);

        switch (s2)
        {
        case 1:

          l = CriarElementoCliente(ClienteAux);
          if (l.NIF != 0)
          {
            ClienteAux = InserirPorAlturaAB(ClienteAux, l);
            ClientesLista = CriarABPEquilibradaIB(ClienteAux);
          }

          break;
        case 2:

          printf("NIF do Cliente a remover\n");
          PNodoAB qq = CriarAB();                   //Criar PNodo
          contador2 = NumeroNodosAB(ClientesLista); //CONTA NODOS
          scanf("%i", &o);                          //LE

          int iop2 = 0;
          pl2 = (Cliente *)malloc(sizeof(Cliente) * (contador)); //ALOCA MEMORIA
          CriarVetor(ClientesLista, pl2, &iop2);                 //CRIA ARRAY

          if (ver_ex(pl2, contador2, o) == 1)
          { //VE SE EXISTE O CLIENTE
            Cliente clienteaux;

            pl2 = Remover_Um_Cliente(pl2, o, &contador2); //ATUALIZA

            for (int o = 0; o < contador2; o++)
            {
              clienteaux = pl2[o];
              qq = InserirABP(qq, clienteaux);
            }

            LibertarNodoAB(ClienteAux);    //LIMPA A ARVORE AUXILIAR
            LibertarNodoAB(ClientesLista); //LIMPA A ARVORE PRINCIPAL

            ClienteAux = CopiarAB(qq);                         //COPIA PARA A ARVORE SECUNDARIA
            ClientesLista = CriarABPEquilibradaIB(ClienteAux); //EQULIBRA A ARVORE E METE A NA ARVORE PRINCIPAL
          }
          else
          {
            printf("Este cliente nao existe!\n");
          }

          break;
        case 3:

          printf("NIF: ");
          scanf("%i", &is);
          contador1 = NumeroNodosAB(ClientesLista); //CONTA NODOS
          int iop1 = 0, telefone;
          pl1 = (Cliente *)malloc(sizeof(Cliente) * (contador)); //ALOCA MEMORIA
          CriarVetor(ClientesLista, pl1, &iop1);                 //CRIA ARRAY

          if (ver_ex(pl1, contador1, is) == 1)
          {

            printf("\nAlterar telemovel do Cliente: ");
            scanf("%d", &telefone);
            Cliente qq;
            PNodoAB aux = CriarAB();

            for (int i = 0; i < contador1; i++)
            {
              if (pl1[i].NIF == is)
              {
                pl1[i].Telemovel = telefone;
              }
            }

            LibertarNodoAB(ClienteAux);
            LibertarNodoAB(ClientesLista);

            for (int o = 0; o < contador1; o++)
            {
              qq = pl1[o];
              aux = InserirABP(aux, qq);
            }

            ClienteAux = CopiarAB(aux);
            ClientesLista = CriarABPEquilibradaIB(aux);
          }
          else
          {
            printf("Este cliente nao existe!\n");
          }
          break;
        case 4:
          printf("NIF: ");
          scanf("%i", &y);
          printf("\n");
          ListarNIF(ClientesLista, y);
          printf("\n");
          break;
        case 5:
          printf("Nome:\n");
          clear_keyboard_buffer();
          fgets(Nome, 100, stdin);
          Nome[strcspn(Nome, "\n")] = 0;
          ListarNome(ClientesLista, Nome);
          break;
        case 6:
          printf("Morada:\n");
          clear_keyboard_buffer();
          fgets(Morada, 200, stdin);
          Morada[strcspn(Morada, "\n")] = 0;
          ListarMorada(ClientesLista, Morada);
          break;
        case 7:
          if (ABVazia(ClientesLista) == 0)
          {
            printf("Clientes Registados no Sistema da Biblioteca: \n");
            ListarEmOrdemAB(ClientesLista);
          }
          else
          {
            printf("\nNão existem clientes registados no sistema \n");
          }
          break;
        case 8:
          break;
        }
      } while (s2 != 8);
      break;
    case 2:
      do
      {
        menuLivros();
        do
        {
          printf(ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
          scanf("%i", &s3);
          if (s3 < 1 || s3 > 9)
          {
            printf("Valor inválido!\n");
          }
        } while (s3 < 1 || s3 > 9);

        switch (s3)
        {
        case 1:
          printf("\n");
          Livro p = CriarElemento(Livros);
          if (p.ISBN != 0)
          {
            Livros = InserirInicio(p, Livros);
            printf("Novo Livro Introduzido com Sucesso");
          }
          break;
        case 2:
          printf("ISBN a Remover :");
          scanf("%i", &t1);
          Livros = removerLivro(t1, Livros);
          break;
        case 3:
          printf("ISBN para alterar :");
          scanf("%i", &t1);
          alterarLivro(Livros, t1);
          break;
        case 4:
          printf("ISBN para consultar :");
          scanf("%i", &t1);
          MostrarLivroPeloISBN(Livros, t1);
          break;
        case 5:
          printf("Titulo a pesquisar: ");
          clear_keyboard_buffer();
          fgets(Titulo, 100, stdin);
          Titulo[strcspn(Titulo, "\n")] = 0;
          MostrarLivrosPeloTitulo(Livros, Titulo);
          break;
        case 6:
          printf("Encontrar o Livro pelo Autor e Ano de Publicação\n");
          printf("Autor (Nome Completo): ");
          clear_keyboard_buffer();
          fgets(Autor, 100, stdin);
          Autor[strcspn(Autor, "\n")] = 0;
          printf("Ano de Publicação: ");
          scanf("%d", &ano);
          MostrarLivrosPeloAutorAno(Livros, Autor, ano);
          break;
        case 7:
          printf("Encontrar o Livro pela Editora e Area Científica\n");
          printf("Editora : ");
          clear_keyboard_buffer();
          fgets(Editora, 20, stdin);
          Editora[strcspn(Editora, "\n")] = 0;
          printf("Area Cientifica: ");
          fgets(AreaCientifica, 50, stdin);
          AreaCientifica[strcspn(AreaCientifica, "\n")] = 0;
          printf("%s", AreaCientifica);
          MostrarLivrosPelaEditoraArea(Livros, Editora, AreaCientifica);
          break;
        case 8:
          if ((Vazia(Livros) == 1))
          {
            printf("Não existem Livros na registados no sistema \n");
          }
          else
          {
            printf("Todos os Livros Existentes na Biblioteca:\n");
            Listar(Livros);
          }
          break;
        case 9:
          break;
        }
      } while (s3 != 9);
      break;
    case 4:
      do
      {
        ENC a;
        menuEncomendas();
        do
        {
          printf(ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
          scanf("%i", &s4);
          if (s4 < 1 || s4 > 5)
          {
            printf("Valor inv�lido!\n");
          }
        } while (s4 < 1 || s4 > 5);

        switch (s4)
        {
        case 1:
          //NUMERO ENCOMENDA
          printf("\nENCOMENDA NUMERO %i\n", numeroEncomenda);
          encomendaadd.numeroencomenda = numeroEncomenda;

          int rr, mm;
          float pp;
          int numero;
          int contagemLivros = contarLivros(Livros);
          int op = 0;
          PNodo ListaLivrosAux = Criar();
          liv1 = (Livro *)malloc(sizeof(Livro) * contagemLivros);
          criarVetorPelaLista(Livros, liv1, &op);
          Listar(Livros);
          //ListarEmOrdemAB(Livros);

          //NUMERO LIVRO
          printf("\nNumero do Livro:"); //numero livro
          scanf("%i", &numero);
          encomendaadd.numerolivro = numero;

          //QUANTIDADE LIVRO
          printf("\nQuantidade:"); //qtd
          scanf("%i", &encomendaadd.num);

          //VER EXISTENCIA DE LIVRO
          //ListarISBN2(Livros,encomendaadd.numerolivro , &rr);
          
          rr = encontrouLivro(Livros, encomendaadd.numerolivro);
          if (rr == 0)
          {
            //VER EXISTENCIA DA QUANTIDADE DO LIVRO
            ElementosLivroqtd(Livros,numero,&mm);
            //ListarISBNqtd(Livros, encomendaadd.numerolivro, &mm);
            if (encomendaadd.num <= mm)
            {
              numeroEncomenda = numeroEncomenda + 1;
              int contadorLivro = contarLivros(Livros); //CONTA NODOS
      
              int tam = 0;
              liv2 = (Livro *)malloc((contadorLivro*sizeof(Livro))); //ALOCA MEMORIA

              //CriarVetor(Livros,liv2,&iop);//CRIA ARRAY
              CriarVetorLivros(Livros, liv2, &tam);


              int qwe = concint(tm.tm_year + 1900, tm.tm_mon + 1); //DATA
              int qwee = concint(qwe, tm.tm_mday);                 //DATA
              int opi = (int)qwee;                                 //DATA

              int dia = tm.tm_mday;
              int mes = tm.tm_mon + 1;
              int ano = tm.tm_year + 1900;

              encomendaadd.dia = dia; //DATA
              encomendaadd.mes = mes; //DATA
              encomendaadd.ano = ano; //DATA

              //PEDE NIF
              printf("\nNIF:");
              scanf("%i", &encomendaadd.numerocliente);
              nifenc = encomendaadd.numerocliente;

              //VER PRECO DO LIVRO
              float o = VerPreco(liv1, numero, contador);
              encomendaadd.preco = o;

              //ADICIONA A ENCOMENDA
              Encomenda = Juntar(encomendaadd, Encomenda);

              //PRECO TOTAL
              precodaenc = encomendaadd.preco * encomendaadd.num;

              //QUANTIDADE
              qtdenc = encomendaadd.num;

              //int contador3 = NumeroNodosAB(Livros);//CONTA NODOS
              //int iop3=0;
              //PNodoAB qqq;
              //pl3 = (Livro *)malloc(sizeof(Livro) * (contador3)); //ALOCA MEMORIA
              //CriarVetor(Livros,pl3,&iop3);//CRIA ARRAY

              /*for(int o = 0;o<contador3;o++){
                                if(pl3[o].ISBN == encomendaadd.numerolivro){
                                  pl3[o].Qtd = pl3[o].Qtd - qtdenc;
                                }
                              }


                              for(int o = 0;o<contador3;o++){
                                Livro livroaux = pl3[o];
                                qqq = InserirABP(qqq, livroaux);
                              }

                              LibertarNodoAB(LivrosaAux); //LIMPA A ARVORE AUXILIAR
                              LibertarNodoAB(Livros);//LIMPA A ARVORE PRINCIPAL

                              LivrosaAux = CopiarAB(qqq); //COPIA PARA A ARVORE SECUNDARIA
                              Livros = CriarABPEquilibradaIB(LivrosaAux); //EQULIBRA A ARVORE E METE A NA ARVORE PRINCIPAL
                              */

              for (int o = 0; o < contagemLivros; o++)
              { //remover a quantidade
                if (liv1[o].ISBN == encomendaadd.numerolivro)
                {
                  liv1[o].Quantidade = liv1[o].Quantidade- qtdenc;
                }
              }
            
              for (int var = 0; var < contagemLivros; var++)
              { //atualizar valores
                Livro livroaux = liv1[var];
                //qqq = InserirABP(qqq, livroaux);
                ListaLivrosAux = InserirFim(livroaux,ListaLivrosAux);
              }

              //DestruirAB(LivrosaAux);                     //LIMPA A ARVORE AUXILIAR
              //DestruirAB(Livros);                         //LIMPA A ARVORE PRINCIPAL
              LibertarNodo(Livros);

              Cliente A;
              A = PesquisarABCliente(encomendaadd.numerocliente,ClientesLista);


              //LivrosaAux = CopiarAB(qqq);                 //COPIA PARA A ARVORE SECUNDARIA
              //Livros = CriarABPEquilibradaIB(LivrosaAux); //EQULIBRA A ARVORE E METE A NA ARVORE PRINCIPAL

              for(int i = 0; i<contagemLivros; i++){
                ListaLivrosAux[i] = Livros[i];
              }

              Listar(ListaLivrosAux);

              //TOTAL
              printf("\nValor total da encomenda do cliente %s (NIF: %d)  = %.2f\n",A.Nome,A.NIF, precodaenc);
              printf("%s",A.Nome);
            }
            else
            {
              printf("\nNao esta Disponivel esta Quantidade \n");
            }
          }
          else
          {
            printf("\nNao existe o Livro desejado! \n");

          }

          break;
        case 2:

          printf("\n");
          if (FilaVazia(Encomenda) == 1)
          {
            printf("Lista de Encomendas Vazia\n");
          }
          else
          {
            listaenc(Encomenda);
          }

          break;
        case 3:
      
          printf("\nDESPACHAR ENCOMENDA \n");
          printf("------------------------\n");

          //VE SE ESTA VAZIA
          if (FilaVazia(Encomenda) != 1)
          {
            int opcao1;
            //GUARDA O VALOR E RETIRA
            ENC top = Frente(Encomenda);
            
            //PERGUNTA SE É PARA DESPACHAR A ENCOMENDA X
            do{
            printf("Deseja mesmo depachar a encomenda seguinte?\n");
            printf("\t\t1.Sim");
            printf("\t\t2.Não");
            scanf("%d",&opcao1);
            }while(opcao1<1 || opcao1 > 2);

            if(opcao1 == 2)
              menuEncomendas();

            MostrarElementoEncomenda(top);
            Encomenda = RemoverEncomenda(Encomenda);

            //VER SE O CLIENTE JA ESTA NA FILA PESSOAL ATRAVES DO NIF

            if (ver_existe_encom(ListaPessoal, top.numerocliente, &numeroLista))
            { //SIM
              ListaPessoal = add_enc(ListaPessoal, top.numerocliente, top.num, top.preco * top.num, &numeroLista);
              printf("\ali\n");
            }
            else
            { //NAO
            int verificado = existe(ClientesLista,top.numerocliente);
              if ( verificado == 1)
              { //SE ESTIVER REGISTADO NOS CLIENTE VAI AUTOMATICAMENTE PARA A LISTA PESSOAL
                printf("\aqui\n");
                ListaPessoal = add_enc_nova(ListaPessoal, top.numerocliente, top.num, top.preco * top.num, &numeroLista);
              }
              else
              { //CASO NAO ESTEJA, PODE IR OU NAO

                printf("\nDesja ser Cliente da Livraria ?\n");
                printf("\t\t 1.SIM\n");
                printf("\t\t 2.NAO\n");

                printf(ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
                scanf("%i", &re);
                if (re < 1 || re > 2)
                {
                  do
                  {
                    printf(ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
                    scanf("%i", &re);
                    if (re < 1 || re > 2)
                    {
                      printf("Valor invalido!\n");
                    }
                  } while (re < 1 || re > 2);
                }

                if (re == 1)
                { //CASO QUEIRA TER LISTA PESSOAL
                  Cliente p = CriarElementoCliente1(ClientesLista, top.numerocliente);
                  int op;
                  op = p.NIF;
                  printf("%i\n", op);
                  while (op == 0)
                  {
                    Cliente p = CriarElementoCliente1(ClientesLista, top.numerocliente);
                    op = p.NIF;
                    printf("%i\n", op);
                  }
                  ClientesLista = InserirPorAlturaAB(ClientesLista, p);
                  //cliente = InserirInicio(p, cliente);                                                                      //adicionar aos clientes
                  ListaPessoal = add_enc_nova(ListaPessoal, top.numerocliente, top.num, top.preco * top.num, &numeroLista); //adicionar a lista pessoal
                }
              }
            }
            printf("\nEncomenda despachada\n");
          }
          else
          {
            printf("\nNAO EXISTE ENCOMENDAS");
          }

          break;
        case 4:

          escrever(ListaPessoal, &numeroLista);

          break;
        case 5:
          break;
        }
      } while (s4 != 5);
          break;

    case 5:
/*
      do{
              menuOperacoes();
                do {
                    printf( ANSI_COLOR_DARK_GRAY "\nopcao > " ANSI_COLOR_RESET);
                    scanf("%i",&s6);
                    if (s6 < 1 || s6 > 12) {
                        printf("Valor inv�lido!\n");
                    }
                } while (s6 < 1 || s6 > 12);

                switch(s6){
                    case 1:
                        
                        break;
                    case 2:
                        break;   
                    case 3:
                        printf("\nNumero do Cliente: ");
                        int numero,result;
                        scanf("%i",&numero);
                        printf("\n");
                        result = ClienteComprou(ListaPessoal, numeroLista, numero);
                        printf("NIF    -> %i\n",numero);
                        printf("Numero -> %i\n",result);
                        break; 
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        ww = MaisLivrosComprados(ListaPessoal, numeroLista, &num);
                        for (int i=0;i<num;i++){
                          printf("NIF -> %i\n",ww[i]);
                        }
                        break;
                    case 8:
                        vetor = ordenar(ListaPessoal, numeroLista);
                        for (int i=0;i<numeroLista;i++){
                          printf("NIF -> %i  Qtd -> %i\n",vetor[i].NIF,vetor[i].qtd);
                        }
                        break;
                    case 9:
                        break;
                    case 10:
                        aa = ClienteGastouMais(ListaPessoal, numeroLista,&numeroutil);
                        for (int i=0;i<numeroutil;i++){
                          printf("NIF -> %i\n",aa[i]);
                        }
                        break;
                    case 11:
                        break;
                    case 12:
                        break;
                }
            }while(s6 !=12);*/  
      break;
    }
  }while (opcao != 6);
    }
