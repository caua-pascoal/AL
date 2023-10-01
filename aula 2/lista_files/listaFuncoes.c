void criarLista ( int *** l, int n) {
    int i;
    *l = ( int ** ) malloc( sizeof( int*[n] ) );
    for(i = 0; i < n; i++){
        (*l)[i] = NULL;
    }
}

int elementosNaLista ( int **l, int n ) {
    int i;
    for(i = 0; i < n; i++)
        if( l[i] == NULL ) return i;
}

int buscarNaLista ( int **l, int n, int x ) {
    int i;
    for( i=0; i < n; i++ ) {
        if( l[i] == NULL) return -1; // não encontrado
        if( *(l[i]) == x ) return i; // índice do número
    }
}

/* não precisa ter lista por referência | vamos alterar um valor da lista de ponteiros referenciado pelo endereço contido em l, não exatamente alteraremos l */
int inserirNaLista ( int **l, int n, int x ) {
    int indice = elementosNaLista( l, n ); // quantidade de elementos já desconsidera offset inicial da lista em [0]
   
    /* Validações */
    if ( indice >= n ) return -1; // Overflow
    if ( buscarNaLista( l, n, x ) != -1 ) return 0; // Elemento já existe
    
    /* Alocação de memória e inserção do valor */
    l[indice] = ( int * ) malloc( sizeof( int ) );
    *( l[indice] ) = x; // Wrap explícito por segurança
   
    return 1;
}

int  excluirDaLista ( int **l, int n, int x ) {
    int i, qtd_elementos = elementosNaLista( l, n );

    /* Validações */
    if ( qtd_elementos <= 0 ) return -1; // Underflow
    int indice = buscarNaLista( l, n, x );
    if ( indice == -1 ) return 0; // Elemento não exite na lista

    /* Liberando espaço de memória e neutralizando valor obsoleto */
    free(l[indice]);
    if( indice != qtd_elementos - 1 ) { // Se ele não for o último elemento da lista
        for( i = indice; i < qtd_elementos; i++ ) l[i] = l[i+1]; // realoca os posteriores a ele
        indice = qtd_elementos - 1;
    }
    l[indice] = NULL;

    return 1;
}

void imprimirLista ( int **l, int n) {
    int i = 0;
    printf("Lista: |");
    for( i = 0; i < n ; i++ ) {
        if ( l[i] != NULL )
            printf(" %d |", *(l[i]) );
        else
            printf(" N |");
    }
    printf("\n");
}

void limparLista ( int ***l, int n) {
    int i;
    for( i = 0; (*l)[i] != NULL && i < n; i++) {
        if( (*l)[i] != NULL ) free( (*l)[i] );
    }
    free( (*l) );
}
