#include <stdio.h>
#include <stdlib.h>

struct Tfila {
    int tamanho;
    int frente;
    int retaguarda;
    int * vetor;
};

/** Usando include para não quebrar o compilador imbutido no vscode 
 *  Ele não compila todos os arquivos do diretório, apenas o header mas sem as funções separadas
*/
#include "filaFuncoes.c"

void main () {

    /* Inicialização da fila */
    struct Tfila fila;
    int N = 5;
    criarFila( &fila, N);

    /* Inserindo elementos */
    inserirNaFila( &fila, 1 );
    inserirNaFila( &fila, 4 );
    inserirNaFila( &fila, 5 );
    inserirNaFila( &fila, 6 );
    inserirNaFila( &fila, 7 );

    /* Tentando adicionar um elemento a mais */
    printf("%d\n", inserirNaFila( &fila, 8 ));

    /* Quantidade de elementos */
    int qtd_elementos = elementosNaFila( fila );
    printf("Quantidade de elementos inicialmente: %d \n", qtd_elementos);

    /* Excluindo elemento */
    // /**
    //  * Em fila não se escolhe o elemento a excluir -> FIFO ( First In First Out )
    // */
    int elemento_sendo_excluido = fila.vetor[fila.frente];

    excluirDaFila( &fila );
    printf("Removendo o elemento '%d' da fila.\n", elemento_sendo_excluido);

    /* Avançando frente */
    excluirDaFila( &fila );
    excluirDaFila( &fila );

    /* Retaguarda dando volta na fila */
    inserirNaFila( &fila, 12 );

    /* Busca do elemento excluido */
    int indice_encontrado = buscarNaFila( fila, elemento_sendo_excluido );
    char * mensagem = 
        indice_encontrado != -1 ? 
            "Índice do elemento '%d' na fila: %d \n" :
            "Elemento '%d' não encontrado na fila (%d) \n";
    printf(mensagem, elemento_sendo_excluido, indice_encontrado);

    /* Liberando espaços de memória utilizados */
    printf("Apagando fila...");
    eliminarFila( &fila );

    /* Pulo de linha para distanciar dados exibidos do resto do output padrão */
    printf("\n\n\n\n\n\n\n");
}