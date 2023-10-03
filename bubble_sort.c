#include <stdio.h>
#include <stdlib.h>

void imprimirVetor ( int v[], int n );
void bubbleSort ( int v[], int n );

void main () {
    int n = 11;
    int v[] = { 1, 9, 4, 6, 3, 7, 0, 34, 2, 47, 8 };
    imprimirVetor( v, n );
    bubbleSort( v, n );
    imprimirVetor( v, n );
}

void imprimirVetor ( int v[], int n ) {
    printf("|");
    for (int i = 0; i < n; i++) printf(" %d |", v[i]);
    printf("\n");
}

void bubbleSort ( int v[], int n ){
    int i, j, aux;
    for( i = n-1; i >= 1; i--) {
        for( j = 0; j < i; j++ ) {
            if ( v[j] > v [j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}
