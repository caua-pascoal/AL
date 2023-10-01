#include <stdio.h>
#include <stdlib.h>

struct Tpilha {
    int tamanho;
    int topo;
    int * vetor;
};

/** Usando include para não quebrar o compilador imbutido no vscode 
 *  Ele não compila todos os arquivos do diretório, apenas o header mas sem as funções separadas
*/
#include "pilhaFuncoes.c"

void main () {

    /* Inicialização da pilha */
    struct Tpilha pilha;
    int N = 5;
    criarPilha( &pilha, N);

    /* Inserindo elementos */
    inserirNaPilha( &pilha, 1 );
    inserirNaPilha( &pilha, 4 );
    inserirNaPilha( &pilha, 5 );

    imprimirPilha( pilha );

    /* Quantidade de elementos */
    int qtd_elementos = elementosNaPilha( pilha );
    printf("Quantidade de elementos inicialmente: %d \n", qtd_elementos);

    /* Excluindo elemento */
    /**
     * Em pilha não se escolhe o elemento a excluir -> LIFO ( Last In First Out )
    */

    int elemento_sendo_excluido = pilha.vetor[pilha.topo];

    excluirDaPilha( &pilha );
    printf("Removendo o elemento '%d' da pilha.\n", elemento_sendo_excluido);

    imprimirPilha( pilha );

    /* Busca do elemento excluido */
    int indice_encontrado = buscarNaPilha( pilha, elemento_sendo_excluido );
    char * mensagem = 
        indice_encontrado != -1 ? 
            "Índice do elemento '%d' na pilha: %d \n" :
            "Elemento '%d' não encontrado na pilha (%d) \n";
    printf(mensagem, elemento_sendo_excluido, indice_encontrado);

    /* Liberando espaços de memória utilizados */
    printf("Apagando pilha...");
    eliminarPilha( &pilha );

    /* Pulo de linha para distanciar dados exibidos do resto do output padrão */
    printf("\n\n\n\n\n\n\n");
}