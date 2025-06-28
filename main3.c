#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE 100

typedef struct {
    char descricao[50];
    int nivel; // 1 = alta, 2 = média, 3 = baixa
} Tarefa;

typedef struct {
    Tarefa tarefas[LIMITE];
    int quantidade;
} FilaPrioridade;

void iniciar_fila(FilaPrioridade* fila) {
    fila->quantidade = 0;
}

int inserir_com_prioridade(FilaPrioridade* fila, Tarefa nova) {
    if (fila->quantidade >= LIMITE) return 0;

    int i = fila->quantidade - 1;
    while (i >= 0 && nova.nivel < fila->tarefas[i].nivel) {
        fila->tarefas[i + 1] = fila->tarefas[i];
        i--;
    }

    fila->tarefas[i + 1] = nova;
    fila->quantidade++;
    return 1;
}

Tarefa remover_tarefa(FilaPrioridade* fila) {
    Tarefa t = fila->tarefas[0];
    for (int i = 0; i < fila->quantidade - 1; i++) {
        fila->tarefas[i] = fila->tarefas[i + 1];
    }
    fila->quantidade--;
    return t;
}

void incluir_tarefa_manual(FilaPrioridade* fila) {
    Tarefa nova;
    printf("Informe a descricao da tarefa: ");
    scanf(" %[^\n]", nova.descricao);
    printf("Informe o nivel de prioridade (1 = alta, 2 = media, 3 = baixa): ");
    scanf("%d", &nova.nivel);
    if (inserir_com_prioridade(fila, nova))
        printf("Tarefa registrada com sucesso!\n");
    else
        printf("A fila esta cheia. Nao foi possivel adicionar.\n");
}

void incluir_tarefa_auto(FilaPrioridade* fila, const char* desc, int prioridade) {
    Tarefa nova;
    strcpy(nova.descricao, desc);
    nova.nivel = prioridade;
    inserir_com_prioridade(fila, nova);
}

void executar_tarefa(FilaPrioridade* fila) {
    if (fila->quantidade == 0) {
        printf("Nao ha nenhuma tarefa aguardando.\n");
        return;
    }
    Tarefa t = remover_tarefa(fila);
    printf("Executando tarefa: %s (prioridade %d)\n", t.descricao, t.nivel);
}

void modo_teste(FilaPrioridade* fila) {
    incluir_tarefa_auto(fila, "Corrigir bugs criticos", 1);
    incluir_tarefa_auto(fila, "Responder e-mails", 2);
    incluir_tarefa_auto(fila, "Ler forum da disciplina", 3);
    printf("Tarefas automaticas adicionadas.\n");

    while (fila->quantidade > 0) {
        executar_tarefa(fila);
    }
}

int main() {
    FilaPrioridade fila;
    iniciar_fila(&fila);
    int escolha;

    do {
        printf("\n==== MENU DE TAREFAS ====\n");
        printf("1 - Adicionar tarefa manual\n");
        printf("2 - Executar proxima tarefa\n");
        printf("9 - Teste automatico\n");
        printf("0 - Encerrar programa\n");
        printf("Opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: incluir_tarefa_manual(&fila); break;
            case 2: executar_tarefa(&fila); break;
            case 9: modo_teste(&fila); break;
            case 0: printf("Programa finalizado.\n"); break;
            default: printf("Escolha invalida, tente novamente.\n");
        }

    } while (escolha != 0);

    return 0;
}