#include <stdio.h>
#include <stdlib.h>

struct TNoDeCaractere
{
    char caractere;
    struct TNoDeCaractere *proximo;
};

void armazenar( struct TNoDeCaractere*,  char );
void imprimir( struct TNoDeCaractere* );
void retirar( struct TNoDeCaractere*, char );
void bubbleSort( struct TNoDeCaractere* );


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

    retirar(inicio, 'D');

    imprimir(inicio);

    bubbleSort(inicio);

    imprimir(inicio);

    printf("\n\n\n\n\n\n");

}


void armazenar ( struct TNoDeCaractere *inicio, char valor ) {
    struct TNoDeCaractere *p, *np;

    if (inicio->proximo == NULL) {
        np = (struct TNoDeCaractere *) malloc (sizeof(struct TNoDeCaractere));
        np->caractere = valor;
        np->proximo = NULL;
        inicio->proximo = np;
        return;
    }

    p = inicio->proximo;

    while ( p->proximo != NULL ) {
        p = p->proximo;
    }

    np = (struct TNoDeCaractere *) malloc (sizeof(struct TNoDeCaractere));
    np->caractere = valor;
    np->proximo = NULL;
    p->proximo = np;
    return;
}

void retirar ( struct TNoDeCaractere *inicio, char valor ) {
    struct TNoDeCaractere *pAnt, *p;

    pAnt = inicio->proximo;
    p = pAnt->proximo;

    if ( pAnt->caractere == valor ) {
        inicio->proximo = p;
        free(pAnt);
        return;
    } 

    while ( p != NULL ) {
        if (p->caractere == valor) {
            pAnt->proximo = p->proximo;
            free(p);
            return;
        } else {
            pAnt = p;
            p = p->proximo;
        }
    }
    return;
}

void imprimir ( struct TNoDeCaractere *inicio ) {
    struct TNoDeCaractere *p;
    printf("|");
    for (p = inicio->proximo; p != NULL; p = p->proximo ) 
        printf(" %d |", p->caractere);
    printf("\n");
    return;
}

void bubbleSort ( struct TNoDeCaractere *inicio ){
    struct TNoDeCaractere *pAnt, *p;
    char aux;
    int houveTroca;

    pAnt = inicio->proximo;
    p = pAnt->proximo;

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