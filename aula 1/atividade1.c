#include <stdio.h>

int fat(int n);
int fibonacci(int n);
int Gfibonacci(int n, int k);
int finder(int x, int inicio, int fim, int v[]);

void main() {
    /* 1.2) */ printf("Fatorial de 5: %d \n", fat(5));

    /* 1.6) */ printf("5 dígito de Finacci: %d \n", fibonacci(5));

    /* 1.7) */ printf("Dígito da sequência G solicitada: %d \n", Gfibonacci(4, 2));

    /* 1.9) */
    int x = 13;
    int inicio = 0;
    int fim = 10;
    int v[] = { 0, 1, 2, 7, 8, 9, 10, 11, 12, 13 };
    int posicao = finder(x, inicio, fim, v);
    printf("O elemento %d está na posição: %d", x, posicao);

    /* Pulo de linha para distanciar dados exibidos do resto do output padrão */
    printf("\n\n\n\n\n\n\n");
}

/**
 * 1.1) i) Falso. Com as chamadas recursivas a quantidade de memória será dinâmica.
 *    ii) Verdadeiro. o vetor fat será percorrido até fat[n], sendo que começa em 0, logo será n+1.
 * 
 * 1.2)
*/

int fat(int n) {
    int i, fat = 1;
    for( i = 1; i <= n; i++ )
        fat *=  i;
    return fat;
}

/**
 * 1.3) Para cada chamada da função recursiva da torre de Hanói outras duas chamadas são geradas, gerando assim 2^n passos. Porém para a última chamada quando n = 0 ali termina o código, portanto 2^n - 1.
 * 
 * 1.4) 

void hanoi (int n, ?a, ?b, ?c) {
    if(n == 1) {
        mover(a,b);
        return; // ealy return para não precisar do else
    }
    hanoi(n-1, a, c, b);
    mover(a,b);
    hanoi(n-1, c, b, a);
}

 * 1.5)
 * n^3 - 1  => O(n^3)
 * n^2 + 2 log n   => O(n^2)
 *  3n^n + 5.2^n  => O(n^n)
 * (n - l)^n + n^n-1  => O(n^n)
 * 302 => O(1)
 * 
 * 1.6) 
*/

int fibonacci (int n) {
    if ( n <= 2 )
        return n-1 > 0 ? n-1 : 0;
    
    int i, aux1=1, aux2=1, valor=0;
    for( i=2; i<n; i++ ) {
        valor = aux1 + aux2;
        aux2 = aux1;
        aux1 = valor;
    }
    return valor;
}

/**
 * 1.7)
*/

int Gfibonacci (int n, int k) {
    if ( n < 1 )
        return 0;

    int i, aux1=1, aux2=1, valor=0;
    for( i=0; i<n; i++ ) {
        if(i<=k) valor = i;
        else valor = aux1 + aux2;
        aux2 = aux1;
        aux1 = valor;
    }
    return valor;
}

/**
 * 1.8)
 * a) O(n) => irá perpassar pelos dados n vezes.
 * b) O(n^2) => Longa história envolvendo progressão aritimética
 * c) O(1) => não depende de um valor externo.
 * 
 * 1.9) Poderia ser o parecido com a ideia do merge sort.
*/

int finder(int x, int inicio, int fim, int v[]) {
    int meio = inicio + ( (fim - inicio) / 2 );
    int valor_meio = v[meio];

    if( x == valor_meio)
        return meio;
    if( x > valor_meio)
        return finder(x, meio, fim, v);
    if( x < valor_meio)
        return finder(x, inicio, meio, v);
}

/**
 * Ótimo: quando o valor buscado estiver no meio do vetor
 * Péssimo: quando o valor buscado não estiver no vetor ou se posicionar nas extremidades
*/