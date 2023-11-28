#include <stdio.h>
#include <stdlib.h>

struct TNoDeCaractere {
    char caractere;
    struct TNoDeCaractere *proximo;
    struct TNoDeCaractere *anterior;
};

void armazenar( struct TNoDeCaractere*,  char );
void imprimir( struct TNoDeCaractere* );
void retirar( struct TNoDeCaractere*, char );
void ehPalindromo( struct TNoDeCaractere* );

void main () {

    struct TNoDeCaractere *ptlista;
    ptlista = (struct TNoDeCaractere *) malloc (sizeof(struct TNoDeCaractere));
    ptlista->proximo = ptlista;
    ptlista->anterior = ptlista;

    armazenar(ptlista, 'A');
    armazenar(ptlista, 'R');
    armazenar(ptlista, 'A');
    armazenar(ptlista, 'R');
    armazenar(ptlista, 'A');

    imprimir(ptlista);

    ehPalindromo(ptlista);

    printf("\n\n");
}

void ehPalindromo( struct TNoDeCaractere *ptlista ) {
    struct TNoDeCaractere *indo, *vindo;

    indo = ptlista->proximo;
    vindo = ptlista->anterior;
    while ( indo != ptlista ) {

        if( indo->caractere != vindo->caractere ){
            printf("N eh palindromo");
            return;
        }

        indo = indo->proximo;
        vindo = vindo->anterior;
    }

    printf("Eh palindromo");
    return;
}

void armazenar ( struct TNoDeCaractere *ptlista, char valor ) {
    struct TNoDeCaractere *p, *np;

    p = ptlista->anterior;

    np = (struct TNoDeCaractere *) malloc (sizeof(struct TNoDeCaractere));
    np->caractere = valor;
    np->proximo = ptlista;
    np->anterior = p;
    p->proximo = np;
    ptlista->anterior = np;
    return;
}

void retirar ( struct TNoDeCaractere *ptlista, char valor ) {
    struct TNoDeCaractere *pAnt, *p;

    pAnt = ptlista;
    p = pAnt->proximo;

    while ( p != ptlista ) {
        if (p->caractere == valor) {
            pAnt->proximo = p->proximo;
            p->proximo->anterior = pAnt;
            free(p);
            return;
        } else {
            pAnt = p;
            p = p->proximo;
        }
    }
    return;
}

void imprimir ( struct TNoDeCaractere *ptlista ) {
    struct TNoDeCaractere *p;
    printf("|");
    for (p = ptlista->proximo; p != ptlista; p = p->proximo ) 
        printf(" %d |", p->caractere);
    printf("\n");
    return;
}
