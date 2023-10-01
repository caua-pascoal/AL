#include <stdio.h>
#include <stdlib.h>

/** Usando include para não quebrar o compilador imbutido no vscode 
 *  Ele não compila todos os arquivos do diretório, apenas o header mas sem as funções separadas
*/
#include "lista_files/listaFuncoes.c"

int buscaMelhoradaNaLista ( int **l, int n, int x );
int buscaBinariaNaLista ( int **l, int inicio, int fim, int x );
int buscarSeEstiverNaLista ( int **l, int n, int x );
void bubbleSort ( int *** l, int n );

void main () {
    /* Inicialização da lista */
    int ** lista;
    int N = 5;
    criarLista( &lista, N );

    /* Inserindo elementos */
    inserirNaLista( lista, N, 1 );
    inserirNaLista( lista, N, 4 );
    inserirNaLista( lista, N, 5 );
    inserirNaLista( lista, N, 2 );
    inserirNaLista( lista, N, 6 );

    imprimirLista( lista, N );

    /* 2.4) Bubble Sort */
    printf("Reordenando a lista...\n");
    bubbleSort ( &lista, N );

    imprimirLista( lista, N );
    
    /* Dados de controle*/
    int elemento = 2;
    int indice_encontrado = buscarNaLista( lista, N, elemento );
    printf("(Controle) Índice do elemento '%d' na lista: %d \n", elemento, indice_encontrado);

    /* 2.1) */
    indice_encontrado = buscaMelhoradaNaLista( lista, N, elemento );
    printf("(2.1) Índice do elemento '%d' na lista: %d \n", elemento, indice_encontrado);

    /* 2.3) */
    indice_encontrado = buscaBinariaNaLista( lista, 0, N, elemento );
    printf("(2.3) Índice do elemento '%d' na lista: %d \n", elemento, indice_encontrado);

    excluirDaLista( lista, N, elemento);
    imprimirLista( lista, N );

    /* 2.2) */
    indice_encontrado = buscarSeEstiverNaLista( lista, N, elemento );
    printf("(2.2) Índice do elemento '%d' na lista: %d \n", elemento, indice_encontrado);

    /* Pulo de linha para distanciar dados exibidos do resto do output padrão */
    printf("\n\n\n\n\n\n\n");
}

/* Infelizmente essa estratégia gerou conflito com a função de limpeza da lista (Exception no free) */
int buscaMelhoradaNaLista ( int **l, int n, int x ) {
    int i, qtd_elementos = elementosNaLista( l, n ); // Lembrando -> aqui tem um if( l[i] == NULL ) para cada elemento
   
    /* Adiciona elemento no fim do vetor */
    l[n] = ( int * ) malloc( sizeof( int ) ); // adicionando um espaço
    *(l[qtd_elementos]) = x; // pode ser ou não o último espaço

    for( i=0; *(l[i]) != x; i++ ); // sempre irá pegar uma posição
    free( l[n] );

    return i == qtd_elementos ? 
            -1 : // Pro caso de ter caído na posição que criamos 
            i;

    /** No fim das contas temos para cada elemento da lista apenas as seguintes verificações:
     * 1) *(l[i]) != x
     * 2) l[i] == NULL
     * Em troca de um ternário ali no retorno (roda apenas uma vez)
    */
}

/* Atualmente ela quebra se o elemento não estiver na lista */
int buscaBinariaNaLista ( int **l, int inicio, int fim, int x ) {
    int meio = inicio + ( (fim - inicio) / 2 );
    int valor_meio = *(l[meio]);

    if( x == valor_meio)
        return meio;
    if( x > valor_meio)
        return buscaBinariaNaLista(l, meio, fim, x);
    if( x < valor_meio)
        return buscaBinariaNaLista(l, inicio, meio, x);
}

int buscarSeEstiverNaLista ( int **l, int n, int x ) {
    int i;
    for( i=0; i < n; i++ ) {
        if( l[i] == NULL || *(l[i]) > x ) return -1; // não encontrado
        if( *(l[i]) == x ) return i; // índice do número
    }
}

void bubbleSort ( int *** l, int n ) {
    int i, j, aux;
    for( i = 0; i < n; i++ ) {
        for( j = 1; j < n - i; j++) {
            if( *((*l)[j-1]) > *((*l)[j]) ) {
                aux = *((*l)[j]);
                *((*l)[j]) = *((*l)[j-1]);
                *((*l)[j-1]) = aux;
            }
        }
    }
}
