#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct {
    int codigo;
    char nome[50];
    int duracao;
} Cliente;

void incluir_cliente(Fila* f) {
    Cliente* c = malloc(sizeof(Cliente));
    printf("Informe o número do cliente: ");
    scanf("%d", &c->codigo);
    printf("Nome do cliente: ");
    scanf(" %[^\n]", c->nome);
    printf("Tempo estimado (min): ");
    scanf("%d", &c->duracao);
    inserir_na_fila(f, c);
    printf("Cliente inserido com sucesso!\n");
}

void cliente_exemplo(Fila* f, int id, const char* nome, int tempo) {
    Cliente* c = malloc(sizeof(Cliente));
    c->codigo = id;
    strcpy(c->nome, nome);
    c->duracao = tempo;
    inserir_na_fila(f, c);
}

void processar_cliente(Fila* f, int* tempo_total, int* atendidos) {
    Cliente* c = remover_da_fila(f);
    if (c) {
        printf("Atendendo: %s (%d min)\n", c->nome, c->duracao);
        *tempo_total += c->duracao;
        (*atendidos)++;
        free(c);
    } else {
        printf("Fila vazia!\n");
    }
}

void auto_teste(Fila* f, int* tempo_total, int* atendidos) {
    cliente_exemplo(f, 10, "Joao", 12);
    cliente_exemplo(f, 20, "Lia", 7);
    cliente_exemplo(f, 30, "Marcio", 9);

    while (!esta_vazia(f)) {
        processar_cliente(f, tempo_total, atendidos);
    }

    if (*atendidos > 0)
        printf("Tempo medio: %.2f minutos\n", (float)*tempo_total / *atendidos);
}

int main() {
    Fila fila;
    criar_fila(&fila);
    int tempo_total = 0, atendidos = 0, escolha;

    do {
        printf("\n1 - Incluir cliente\n2 - Atender proximo\n3 - Media tempo\n9 - Auto Teste\n0 - Sair\n>> ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1: incluir_cliente(&fila); break;
            case 2: processar_cliente(&fila, &tempo_total, &atendidos); break;
            case 3:
                if (atendidos)
                    printf("Tempo medio: %.2f min\n", (float)tempo_total / atendidos);
                else
                    printf("Nenhum atendimento ainda.\n");
                break;
            case 9: auto_teste(&fila, &tempo_total, &atendidos); break;
            case 0: printf("Finalizando...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (escolha != 0);

    return 0;
}