#include <stdio.h>
#include <stdlib.h>

/** Usando include para não quebrar o compilador imbutido no vscode 
 *  Ele não compila todos os arquivos do diretório, apenas o header mas sem as funções separadas
*/
#include "listaFuncoes.c"

void main () {
    /* Inicialização da lista */
    int ** lista;
    int N = 5;
    criarLista( &lista, N );

    /* Inserindo elementos */
    inserirNaLista( lista, N, 1 );
    inserirNaLista( lista, N, 4 );
    inserirNaLista( lista, N, 5 );

    /* Quantidade de elementos */
    int qtd_elementos = elementosNaLista( lista, N );
    printf("Quantidade de elementos inicialmente: %d \n", qtd_elementos);

    imprimirLista( lista, N);

    /* Escluindo elemento */
    int elemento = 4;
    excluirDaLista( lista, N, elemento );
    printf("Removendo o elemento '%d' da lista.\n", elemento);

    imprimirLista( lista, N);

    /* Busca do elemento excluido */
    int indice_encontrado = buscarNaLista( lista, N, elemento );
    char * mensagem = 
        indice_encontrado != -1 ? 
            "Índice do elemento '%d' na lista: %d \n" :
            "Elemento '%d' não encontrado na lista (%d) \n";
    printf(mensagem, elemento, indice_encontrado);

    /* Liberando espaços de memória utilizados */
    printf("Apagando lista...");
    limparLista( &lista, N);

    /* Pulo de linha para distanciar dados exibidos do resto do output padrão */
    printf("\n\n\n\n\n\n\n");
}