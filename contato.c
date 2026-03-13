#include <stdio.h>
#include <string.h>
#include "contatos.h"

void cadastrarContato(Contato contatos[], int *total)
{
    if (*total >= MAX_CONTATOS) {
        printf("Agenda cheia!\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", contatos[*total].nome);

    printf("Telefone: ");
    scanf(" %[^\n]", contatos[*total].telefone);

    printf("Email: ");
    scanf(" %[^\n]", contatos[*total].email);

    (*total)++;

    printf("Contato cadastrado com sucesso!\n");
}

void listarContatos(Contato contatos[], int total)
{
    int i;

    if (total == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        printf("\nContato %d\n", i);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("Email: %s\n", contatos[i].email);
    }
}

int buscarContato(Contato contatos[], int total, char nome[])
{
    int i;

    for (i = 0; i < total; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            return i;
        }
    }

    return -1;
}

void editarContato(Contato contatos[], int total)
{
    char nome[TAM_NOME];
    int indice;

    printf("Digite o nome do contato para editar: ");
    scanf(" %[^\n]", nome);

    indice = buscarContato(contatos, total, nome);

    if (indice == -1) {
        printf("Contato não encontrado.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", contatos[indice].nome);

    printf("Novo telefone: ");
    scanf(" %[^\n]", contatos[indice].telefone);

    printf("Novo email: ");
    scanf(" %[^\n]", contatos[indice].email);

    printf("Contato atualizado!\n");
}

void removerContato(Contato contatos[], int *total)
{
    char nome[TAM_NOME];
    int indice, i;

    printf("Digite o nome do contato para remover: ");
    scanf(" %[^\n]", nome);

    indice = buscarContato(contatos, *total, nome);

    if (indice == -1) {
        printf("Contato não encontrado.\n");
        return;
    }

    for (i = indice; i < (*total - 1); i++) {
        contatos[i] = contatos[i + 1];
    }

    (*total)--;

    printf("Contato removido com sucesso!\n");
}

/* FUNÇÃO RECURSIVA */
int contarNomesMaioresQue(Contato contatos[], int total, int indice, int tamanho)
{
    if (indice >= total)
        return 0;

    if (strlen(contatos[indice].nome) > tamanho)
        return 1 + contarNomesMaioresQue(contatos, total, indice + 1, tamanho);
    else
        return contarNomesMaioresQue(contatos, total, indice + 1, tamanho);
}
