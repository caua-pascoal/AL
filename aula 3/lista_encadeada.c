#include <stdio.h>
#include <stdlib.h>

struct TNoDeCaractere {
    char caractere;
    struct TNoDeCaractere *proximo;
};

void armazenar( struct TNoDeCaractere*,  char );
void imprimir( struct TNoDeCaractere* );
void retirar( struct TNoDeCaractere*, char );
void bubbleSort( struct TNoDeCaractere* );
void gerarL1( struct TNoDeCaractere* );
void gerarL2( struct TNoDeCaractere* );

// 3.1 E 3.2 contempladas
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

    printf("\n\nListas da atividade 6: \n\n");

    gerarL1(inicio);

    gerarL2(inicio);

    printf("\n\n");
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

void retirar ( struct TNoDeCaractere *inicio, char valor ) {
    struct TNoDeCaractere *pAnt, *p;

    pAnt = inicio;
    p = pAnt->proximo;

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

// 3.7 a)
void gerarL1 ( struct TNoDeCaractere *inicio ) {
    struct TNoDeCaractere *lista, *p, *aux, *np, *primeiro;

    // inicia nova lista
    lista = (struct TNoDeCaractere *) malloc (sizeof(struct TNoDeCaractere));
    lista->proximo = NULL;

    primeiro = inicio->proximo;
    p = primeiro->proximo;
    aux = lista;

    // armazena valores na nova lista
    while ( p != NULL ) {

        np = (struct TNoDeCaractere *) malloc (sizeof(struct TNoDeCaractere));
        np->caractere = p->caractere;
        np->proximo = NULL;
        aux->proximo = np;

        // próximo elemlento
        aux = aux->proximo;
        p = p->proximo;
    }

    np = (struct TNoDeCaractere *) malloc (sizeof(struct TNoDeCaractere));
    np->caractere = primeiro->caractere;
    np->proximo = NULL;
    aux->proximo = np;

    imprimir(lista);
}

// 3.7 b)
void gerarL2 ( struct TNoDeCaractere *inicio ) {
    struct TNoDeCaractere *lista, *p, *aux, *np;

    // inicia nova lista
    lista = (struct TNoDeCaractere *) malloc (sizeof(struct TNoDeCaractere));
    lista->proximo = NULL;

    p = inicio->proximo;

    // armazena valores na nova lista
    while ( p != NULL ) {

        np = (struct TNoDeCaractere *) malloc (sizeof(struct TNoDeCaractere));
        np->caractere = p->caractere;
        np->proximo = lista->proximo;
        lista->proximo = np;

        // próximo elemlento
        aux = aux->proximo;
        p = p->proximo;
    }

    imprimir(lista);
}