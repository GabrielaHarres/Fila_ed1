#include <stdlib.h> 
#include "pilha.h"
#include <stdlib.h>


void criar_pilha(Pilha* p) {
    p->pos_topo = -1;
}

int empilhar(Pilha* p, void* item) {
    if (p->pos_topo >= LIMITE - 1) return 0;
    p->conteudo[++p->pos_topo] = item;
    return 1;
}

void* desempilhar(Pilha* p) {
    if (p->pos_topo < 0) return NULL;
    return p->conteudo[p->pos_topo--];
}

int pilha_esta_vazia(Pilha* p) {
    return p->pos_topo == -1;
}
