#include <stdio.h>
#include "contato.h"

int main()
{
    Contato contatos[MAX_CONTATOS];
    int total = 0;
    int opcao;
    char nome[TAM_NOME];
    int indice;
    int tamanho;
    int resultado;

    do {
        printf("\n--- GERENCIADOR DE CONTATOS ---\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar por nome\n");
        printf("4 - Editar\n");
        printf("5 - Excluir\n");
        printf("6 - Estatisticas (recursivo)\n");
        printf("7 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            cadastrarContato(contatos, &total);
            break;

        case 2:
            listarContatos(contatos, total);
            break;

        case 3:
            printf("Digite o nome: ");
            scanf(" %[^\n]", nome);

            indice = buscarContato(contatos, total, nome);

            if (indice == -1)
                printf("Contato nao encontrado.\n");
            else {
                printf("Nome: %s\n", contatos[indice].nome);
                printf("Telefone: %s\n", contatos[indice].telefone);
                printf("Email: %s\n", contatos[indice].email);
            }
            break;

        case 4:
            editarContato(contatos, total);
            break;

        case 5:
            removerContato(contatos, &total);
            break;

        case 6:
            printf("Contar nomes maiores que quantos caracteres? ");
            scanf("%d", &tamanho);

            resultado = contarNomesMaioresQue(contatos, total, 0, tamanho);

            printf("Quantidade de contatos com nome maior que %d: %d\n", tamanho, resultado);
            break;

        case 7:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 7);

    return 0;
}
