#include <stdio.h>
#include <stdlib.h>

void imprimirVetor ( int v[], int n );
void quickSort ( int v[], int inicio, int fim );

void main () {
    int n = 11;
    int v[] = { 1, 9, 4, 6, 3, 7, 0, 34, 2, 47, 8 };
    imprimirVetor( v, n );
    quickSort( v, 0, n-1 );
    imprimirVetor( v, n );
}

void imprimirVetor ( int v[], int n ) {
    printf("|");
    for (int i = 0; i < n; i++) printf(" %d |", v[i]);
    printf("\n");
}
/**
 * inicio = 0
 * fim = n - 1
*/
void quickSort ( int v[], int inicio, int fim ){
    int i, j, pivo, meio, houve_troca, aux;
    meio = ( inicio + fim ) / 2;
    do{
        houve_troca = 0;
        pivo = v[meio];

        for( i = inicio; v[i] < pivo; i++ );
        for( j = fim; v[j] > pivo; j-- );
        
        if( i < j ) {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            houve_troca = 1;
        }
        imprimirVetor ( v, 11 );

    } while ( houve_troca != 0 );
    if( meio > inicio ) quickSort( v, inicio, meio);
    if( meio+1 < fim ) quickSort( v, meio + 1, fim);
}