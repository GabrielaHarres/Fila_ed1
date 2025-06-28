#ifndef MODULO_FILA_H
#define MODULO_FILA_H

#define LIMITE 100

typedef struct {
    void* elementos[LIMITE];
    int ini, fim, qtd;
} Fila;

void criar_fila(Fila* f);
int esta_vazia(Fila* f);
int esta_cheia(Fila* f);
int inserir_na_fila(Fila* f, void* item);
void* remover_da_fila(Fila* f);
void* elemento_inicio(Fila* f);

#endif