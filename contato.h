#ifndef CONTATO_H
#define CONTATO_H

#define MAX_CONTATOS 100

typedef struct {
    int id;
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

void cadastrar(Contato lista[], int *total);
void listar(Contato lista[], int total);
void buscar(Contato lista[], int total);
void editar(Contato lista[], int total);
void remover(Contato lista[], int *total);
void estatisticas(Contato lista[], int total);

#endif
