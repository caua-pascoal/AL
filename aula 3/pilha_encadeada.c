#include <stdio.h>
#include <stdlib.h>

struct TNoDeCaractere {
    char caractere;
    struct TNoDeCaractere *proximo;
};

void armazenar( struct TNoDeCaractere*,  char );
void imprimir( struct TNoDeCaractere* );
void retirar( struct TNoDeCaractere* );
void bubbleSort( struct TNoDeCaractere* );

// 3.3 contemplada
void main () {

    struct TNoDeCaractere *inicio;
    inicio = (struct TNoDeCaractere *) malloc (sizeof(struct TNoDeCaractere));
    inicio->proximo = NULL;

    imprimir(inicio);

    armazenar(inicio, 'J');
    armazenar(inicio, 'G');
    armazenar(inicio, 'H');
    armazenar(inicio, 'D');
    armazenar(inicio, 'W');
    armazenar(inicio, 'V');

    imprimir(inicio);

    retirar(inicio);

    imprimir(inicio);

    bubbleSort(inicio);

    imprimir(inicio);

    printf("\n\n\n\n\n\n");

}


void armazenar ( struct TNoDeCaractere *inicio, char valor ) {
    struct TNoDeCaractere *p, *np;
    
    p = inicio;
    while ( p->proximo != NULL )
        p = p->proximo;

    np = (struct TNoDeCaractere *) malloc (sizeof(struct TNoDeCaractere));
    np->caractere = valor;
    np->proximo = NULL;
    p->proximo = np;
    return;
}

void retirar ( struct TNoDeCaractere *inicio ) {
    struct TNoDeCaractere *pAnt, *p;
    
    p = inicio;
    while ( p->proximo != NULL ) {
        pAnt = p;
        p = p->proximo;
    }

    if( pAnt == NULL ) return;
    
    pAnt->proximo = NULL;
    free(p);
    return;
       
}

void imprimir ( struct TNoDeCaractere *inicio ) {
    struct TNoDeCaractere *p;
    printf("|");
    for (p = inicio->proximo; p != NULL; p = p->proximo ) 
        printf(" %d |", p->caractere);
    printf(" <- TOPO \n");
    return;
}

void bubbleSort ( struct TNoDeCaractere *inicio ){
    struct TNoDeCaractere *pAnt, *p;
    char aux;
    int houveTroca;

    pAnt = inicio->proximo;
    if( pAnt == NULL ) return;

    p = pAnt->proximo;
    if( p == NULL ) return;

    do{
        houveTroca = 0;
        while (p != NULL) {
            if ( pAnt->caractere > p->caractere ) {
                aux = p->caractere;
                p->caractere = pAnt->caractere;
                pAnt->caractere = aux;
                houveTroca = 1;
                break;
            }
            pAnt = p;
            p = p->proximo;
        }
    } while ( houveTroca == 1 );
    return;
}