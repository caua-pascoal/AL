#include <stdio.h>
#include <stdlib.h>

void imprimirVetor ( int v[], int n );
void mergeSort ( int v[], int tam );

void main () {
    int n = 11;
    int v[] = { 1, 9, 4, 6, 3, 7, 0, 34, 2, 47, 8 };
    imprimirVetor( v, n );
    mergeSort( v, n );
    imprimirVetor( v, n );
}

void imprimirVetor ( int v[], int n ) {
    printf("|");
    for (int i = 0; i < n; i++) printf(" %d |", v[i]);
    printf("\n");
}

void juntarOrdenadamente(int v[], int tam) {
    int aux[tam], i=0, k=0, meio = tam/2, j = meio;

    while ( i < meio && j < tam ) {
        if ( v[i] <= v[j] ) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }

    if ( i == meio ) {
        for( ; j < tam; j++, k++ )
            aux[k] = v[j];
    } else { 
        for( ; i < tam; i++, k++ )
            aux[k] = v[i];
    }

    for ( i = 0; i < tam; i++ )
        v[i] = aux[i];
}

void mergeSort(int v[], int tam)
{
    int meio;

    if (tam > 1)
    {
        meio = tam / 2;
        mergeSort(v, meio);
        mergeSort(v + meio, tam-meio);
        juntarOrdenadamente(v, tam);
    }
}
