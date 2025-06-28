#ifndef MODULO_PILHA_H
#define MODULO_PILHA_H

#define LIMITE 100

typedef struct {
    void* conteudo[LIMITE];
    int pos_topo;
} Pilha;

void criar_pilha(Pilha* p);
int empilhar(Pilha* p, void* item);
void* desempilhar(Pilha* p);
int pilha_esta_vazia(Pilha* p);

#endif