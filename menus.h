void menuFicheiro(){
    printf("\n\t\t1.Abrir \n");
    printf("\t\t2.Guardar\n\n");
    printf(ANSI_COLOR_ORANGE"\t\t3.Voltar \n\n");
}

void menuPrincipal(){
    printf("\n\t1.Ficheiro(Quase Completo)\n");
    printf("\t2.Livros(FEITO)\n");
    printf("\t3.Clientes(FEITO)\n");
    printf("\t4.Encomendas(FEITO)\n");
    printf("\t5.Opcoes\n\n");
    printf(ANSI_COLOR_ORANGE "\t6.Exit\n\n");
}

void menuLivros(){
    printf("\n\t\t1.Inserir(FEITO)\n");
    printf("\t\t2.Remover(FEITO)\n");
    printf("\t\t3.Alterar(FEITO)\n");
    printf("\t\t4.Consultar por ISBN(FEITO)\n");
    printf("\t\t5.Consultar por Titulo(FEITO)\n");
    printf("\t\t6.Consultar por Autor e ano de publicacao(FEITO)\n");
    printf("\t\t7.Consultar por Editora e Area Cientifica(FEITO)\n");
    printf("\t\t8.Consultar Todos(FEITO)\n\n");
    printf(ANSI_COLOR_ORANGE"\t\t9.Voltar\n");

}

void menuClientes(){
    printf("\n\t\t1.Inserir(FEITO)\n");
    printf("\t\t2.Remover(FEITO)\n");
    printf("\t\t3.Alterar(FEITO)\n");
    printf("\t\t4.Consultar por NIF(FEITO)\n");
    printf("\t\t5.Consultar por Nome(FEITO)\n");
    printf("\t\t6.Morada(FEITO)\n");
    printf("\t\t7.Mostrar(FEITO)\n\n");
    printf(ANSI_COLOR_ORANGE"\t\t8.Voltar\n");
}

void menuEncomendas(){
    printf("\n\t\t1.Inserir(Feito)\n");
    printf("\t\t2.Listar(Feito)\n");
    printf("\t\t3.Despachar Encomenda(Feito)\n");
    printf("\t\t4.Ver Lista Pessoal(Feito)\n\n");
    printf(ANSI_COLOR_ORANGE"\t\t5.Voltar\n\n");
}

void menuOperacoes(){
    printf("\n\t\t1.Quantos livros foram vendidos num dado período de tempo \n");
    printf("\t\t2.Determinar a data da última compra/venda de um dado livro\n");
    printf("\t\t3.Determinar quantos livros um dado cliente já comprou(Feito)\n");
    printf("\t\t4.Mostrar os K livros mais recentes de uma dada Área Científica\n");
    printf("\t\t5.Mostrar os K livros mais vendidos num dado período \n");
    printf("\t\t6.Determinar a Área Científica com mais livros\n");
    printf("\t\t7.Determinar qual o Cliente com mais livros comprados(Feito)\n");
    printf("\t\t8.Mostrar os Clientes por ordem decrescente do número de compras(Feito)\n");
    printf("\t\t9.Determinar o Ano com mais publicações\n");
    printf("\t\t10.Calcular o cliente que mais gastou(Feito)\n");
    printf("\t\t11.Determinar o desperdício de memória (no caso em que por exemplo num livro, no campo TITULO tenham char TITULO[100], se os TITULOS forem mais pequenos existe muito desperdício\n\n");
    printf(ANSI_COLOR_ORANGE"\t\t12.Voltar\n");
}
