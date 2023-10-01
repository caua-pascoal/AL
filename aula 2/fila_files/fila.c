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

void criarFila       ( struct Tfila *f, int n );
void eliminarFila    ( struct Tfila *f );
int  elementosNaFila ( struct Tfila f );
int  buscarNaFila    ( struct Tfila f, int x );
int  inserirNaFila   ( struct Tfila *f, int x );
int  excluirDaFila   ( struct Tfila *f );
void imprimirFila    ( struct Tfila f );
int  mod             ( int x, int m );


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
    inserirNaFila( &fila, 8 );

    imprimirFila( fila );

    // /* Quantidade de elementos */
    // int qtd_elementos = elementosNaFila( fila );
    // printf("Quantidade de elementos inicialmente: %d \n", qtd_elementos);

    // /* Excluindo elemento */
    // /**
    //  * Em fila não se escolhe o elemento a excluir -> FIFO ( First In First Out )
    // */

    // int elemento_sendo_excluido = fila.vetor[fila.topo]; || Ajeitar

    // excluirDaFila( &fila );
    // printf("Removendo o elemento '%d' da fila.\n", elemento_sendo_excluido);

    // imprimirFila( fila );

    // /* Busca do elemento excluido */
    // int indice_encontrado = buscarNaFila( fila, elemento_sendo_excluido );
    // char * mensagem = 
    //     indice_encontrado != -1 ? 
    //         "Índice do elemento '%d' na fila: %d \n" :
    //         "Elemento '%d' não encontrado na fila (%d) \n";
    // printf(mensagem, elemento_sendo_excluido, indice_encontrado);

    // /* Liberando espaços de memória utilizados */
    // printf("Apagando fila...");
    // eliminarFila( &fila );

    /* Pulo de linha para distanciar dados exibidos do resto do output padrão */
    printf("\n\n\n\n\n\n\n");
}

void criarFila ( struct Tfila *f, int n ) {
    f->tamanho = n;
    f->frente = f->retaguarda = -1;
    f->vetor = ( int * ) malloc( sizeof( int[n] ) );
}

void eliminarFila ( struct Tfila *f ) {
    f->tamanho = 0;
    f->frente = f->retaguarda = -1;
    free( f->vetor );
}

int elementosNaFila ( struct Tfila f ) {
    if( f.frente == -1 ) return 0; // Somente quando vazio frente e retaguarda serão -1
    if( f.retaguarda >= f.frente ) return f.retaguarda - f.frente + 1;
    if( f.frente > f.retaguarda ) return (f.tamanho - f.frente) + (f.retaguarda + 1);
}

int inserirNaFila ( struct Tfila *f, int x ) {
    int qtd_elementos = elementosNaFila( *f );

    if( qtd_elementos == f->tamanho ) return -1; // Overflow
    if( buscarNaFila( *f, x ) != -1 ) return 0; // Elemento já existe

    if( qtd_elementos == 0) {
        f->retaguarda = 0;
        f->frente = 0;
    } else {
        f->retaguarda = mod(f->retaguarda + 1, f->tamanho);
        f->vetor[f->retaguarda] = x;
    }
    return 1;
}

int buscarNaFila ( struct Tfila f, int x ) {
    int i, posicao, qtd_elementos = elementosNaFila( f );
    if( qtd_elementos == 0 ) return -1; // Fila vazia

    for ( i = 0; i < qtd_elementos; i++ ) {
        posicao = mod( f.frente + i, f.tamanho );
        if( f.vetor[ posicao ] == x ) return posicao;
    }
    return -1; // Não encontrado
}

int excluirDaFila ( struct Tfila *f ) {
    int qtd_elementos = elementosNaFila( *f );
    if( qtd_elementos == 0 ) return -1; // Underflow
    if( qtd_elementos == 1 ) {
        f->frente = -1;
        f->retaguarda = -1;
    } else {
        f->frente = mod(f->frente + 1, f->tamanho);
    }    
    return 1;
}

void imprimirFila ( struct Tfila f ) {
    int i, qtd_elementos = elementosNaFila( f );
    
    printf("Fila: |");
    for( i = 0; i < f.tamanho; i++ ) {
        if( f.frente <= i && i <= f.retaguarda )
            printf(" %d |", f.vetor[i]);
        else
            printf(" N |");
    }
}

int mod ( int x, int m ) {
    return x%m;
}

