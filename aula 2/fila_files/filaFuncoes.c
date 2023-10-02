
void criarFila ( struct Tfila *f, int n ) {
    f->tamanho = n;
    f->frente = f->retaguarda = -1;
    f->vetor = ( int * ) malloc( sizeof( int[n] ) );
}

void eliminarFila ( struct Tfila *f ) {
    f->tamanho = 0;
    f->frente = f->retaguarda = -1;
    free( f->vetor );
}

int elementosNaFila ( struct Tfila f ) {
    if( f.frente == -1 ) return 0; // Somente quando vazio frente e retaguarda serão -1
    return 1 + mod(f.retaguarda - f.frente, f.tamanho);
}

int inserirNaFila ( struct Tfila *f, int x ) {
    int aux = mod( f->retaguarda + 1, f->tamanho);

    if( aux == f->frente ) return -1; // Overflow
    if( buscarNaFila( *f, x ) != -1 ) return 0; // Elemento já existe

    f->retaguarda = aux;
    f->vetor[f->retaguarda] = x;
    if ( f->frente == -1 ) f->frente++;
    return 1;
}

int buscarNaFila ( struct Tfila f, int x ) {
    int i, posicao, qtd_elementos = elementosNaFila( f );
    if( qtd_elementos == 0 ) return -1; // Fila vazia

    for ( i = f.frente; i < qtd_elementos; i++ ) {
        posicao = mod( i, f.tamanho );
        if( f.vetor[ posicao ] == x ) return posicao;
    }
    return -1; // Não encontrado
}

int excluirDaFila ( struct Tfila *f ) {
    int qtd_elementos = elementosNaFila( *f );
    if( qtd_elementos == 0 ) return -1; // Underflow
    if( qtd_elementos == 1 ) {
        f->frente = -1;
        f->retaguarda = -1;
    } else {
        f->frente = mod(f->frente + 1, f->tamanho);
    }    
    return 1;
}

int mod ( int x, int m ) {
    return x%m < 0 ? x%m+m : x%m;
}

