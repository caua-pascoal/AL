
/**
 * (*p). == p->
*/

void criarPilha (struct Tpilha *p, int n) {
    p->tamanho = n;
    p->topo = -1; // 0 é posição da pilha já
    p->vetor = ( int * ) malloc( sizeof( int[n] ) );
}

int elementosNaPilha (struct Tpilha p) {
    return p.topo+1;
}

int buscarNaPilha(struct Tpilha p, int x) {
    int i;
    for( i = 0; i <= p.topo && p.vetor[i] != x ; i++ ); // Quando terminar a lista i será p.topo + 1
    return p.topo != -1 && p.vetor[i-1] == x ? i : -1;
}

int inserirNaPilha ( struct Tpilha *p, int x ) {
    int qtd_elementos = elementosNaPilha( *p );

    /* Validações */
    if ( qtd_elementos >= p->tamanho ) return -1; // Overflow
    if ( buscarNaPilha( *p, x ) != -1 ) return 0; // Elemento já existe
    
    p->vetor[qtd_elementos] = x;
    p->topo++;
    return 1;
}

int excluirDaPilha ( struct Tpilha *p ) {
    if ( elementosNaPilha( *p ) == 0 ) return -1; // Pilha vazia
    p->topo--;
    return 1;
}

int eliminarPilha ( struct Tpilha *p ) {
    p->tamanho = 0;
    p->topo = -1;
    free ( p->vetor );
}

void imprimirPilha ( struct Tpilha p ) {
    int i = 0;
    printf("Pilha: |");
    for( i = 0; i <= p.tamanho; i++ ) {
        if ( i <= p.topo )
            printf(" %d |", p.vetor[i] );
        else
            printf(" N |");
    }
    printf("\n");
}