#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "fila.h"
#include "pilha.h"

int verificar_palindromo(char* texto) {
    Fila f;
    Pilha p;
    criar_fila(&f);
    criar_pilha(&p);

    for (int i = 0; texto[i]; i++) {
        char ch = tolower(texto[i]);
        if (isalpha(ch)) {
            inserir_na_fila(&f, (void*)(long)ch);
            empilhar(&p, (void*)(long)ch);
        }
    }

    while (!esta_vazia(&f)) {
        char a = (char)(long)remover_da_fila(&f);
        char b = (char)(long)desempilhar(&p);
        if (a != b) return 0;
    }

    return 1;
}

int main() {
    char palavra[100];
    printf("Digite palavras para verificar palindromos (0 para sair).\n");

    while (1) {
        printf("\nPalavra: ");
        scanf("%s", palavra);
        if (strcmp(palavra, "0") == 0) break;

        if (verificar_palindromo(palavra))
            printf("Eh palindromo!\n");
        else
            printf("Nao eh palindromo.\n");
    }

    return 0;
}