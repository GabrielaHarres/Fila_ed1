#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void criar_fila(Fila* f) {
    f->ini = 0;
    f->fim = 0;
    f->qtd = 0;
}

int esta_vazia(Fila* f) {
    return f->qtd == 0;
}

int esta_cheia(Fila* f) {
    return f->qtd == LIMITE;
}

int inserir_na_fila(Fila* f, void* item) {
    if (esta_cheia(f)) return 0;
    f->elementos[f->fim] = item;
    f->fim = (f->fim + 1) % LIMITE;
    f->qtd++;
    return 1;
}

void* remover_da_fila(Fila* f) {
    if (esta_vazia(f)) return NULL;
    void* temp = f->elementos[f->ini];
    f->ini = (f->ini + 1) % LIMITE;
    f->qtd--;
    return temp;
}

void* elemento_inicio(Fila* f) {
    if (esta_vazia(f)) return NULL;
    return f->elementos[f->ini];
}