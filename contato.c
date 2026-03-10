#include "contato.h" 
#include <stdio.h>
#include <string.h>

void cadastrar(Contato *lista, int *total) {
    printf("\n--- 1. Cadastro de Contato ---\n");

    if (*total >= MAX_CONTATOS) {
        printf("Erro: A agenda esta cheia!\n");
        return;
    }

    Contato *novoContato = &lista[*total];

    novoContato->id = (*total > 0) ? (lista[*total - 1].id + 1) : 1;

    printf("Digite o nome: ");
    scanf(" %[^\n]", novoContato->nome);

    printf("Digite o telefone: ");
    scanf(" %[^\n]", novoContato->telefone);

    printf("Digite o e-mail: ");
    scanf(" %[^\n]", novoContato->email);

    (*total)++; 

    printf("\n>> Contato '%s' cadastrado com sucesso! <<\n", novoContato->nome);
}

void listar(Contato *lista, int total) {
    printf("\n--- 2. Lista de Contatos ---\n");

    if (total == 0) {
        printf("Nenhum contato cadastrado na agenda.\n");
        return;
    }

    int = i;
    for (i = 0; i < total; i++) {
        printf("--------------------------------\n");
        printf("ID:       %d\n", (lista + i)->id);
        printf("Nome:     %s\n", (lista + i)->nome);
        printf("Telefone: %s\n", (lista + i)->telefone);
        printf("E-mail:   %s\n", (lista + i)->email);
    }
    printf("--------------------------------\n");
}


void buscar(Contato *lista, int total) {
    printf("\n--- 3. Buscar Contato por Nome ---\n");

    if (total == 0) {
        printf("Nenhum contato na agenda para buscar.\n");
        return;
    }

    char nomeBusca[50];
    printf("Digite o nome a ser buscado: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrados = 0;
    int i 
    for (i = 0; i < total; i++) {
        if (strcmp((lista + i)->nome, nomeBusca) == 0) {
            printf("\n>> Contato Encontrado! <<\n");
            printf("ID: %d, Nome: %s, Telefone: %s, E-mail: %s\n",
                   (lista + i)->id, (lista + i)->nome, (lista + i)->telefone, (lista + i)->email);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("\nNenhum contato encontrado com o nome '%s'.\n", nomeBusca);
    }
}


void editar(Contato *lista, int total) {
    printf("\n--- 4. Editar Contato ---\n");

    if (total == 0) {
        printf("Nenhum contato para editar.\n");
        return;
    }

    int idBusca;
    printf("Digite o ID do contato que deseja editar: ");
    scanf("%d", &idBusca);

    int indiceEncontrado = -1;
    int i 
    for ( i = 0; i < total; i++) {
        if ((lista + i)->id == idBusca) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado != -1) {
        Contato *contatoParaEditar = &lista[indiceEncontrado];
        printf("Editando contato de ID %d (Nome atual: %s).\n", contatoParaEditar->id, contatoParaEditar->nome);

        printf("Digite o novo nome: ");
        scanf(" %[^\n]", contatoParaEditar->nome);
        printf("Digite o novo telefone: ");
        scanf(" %[^\n]", contatoParaEditar->telefone);
        printf("Digite o novo e-mail: ");
        scanf(" %[^\n]", contatoParaEditar->email);

        printf("\n>> Contato atualizado com sucesso! <<\n");
    } else {
        printf("\nContato com ID %d nao foi encontrado.\n", idBusca);
    }
}

void remover(Contato *lista, int *total) {
    printf("\n--- 5. Excluir Contato ---\n");

    if (*total == 0) {
        printf("Nenhum contato para excluir.\n");
        return;
    }

    int idBusca;
    printf("Digite o ID do contato que deseja excluir: ");
    scanf("%d", &idBusca);

    int indiceParaRemover = -1;
    int i;
    for (i = 0; i < *total; i++) {
        if ((lista + i)->id == idBusca) {
            indiceParaRemover = i;
            break;
        }
    }

    if (indiceParaRemover != -1) {
        printf("Excluindo contato: %s\n", (lista + indiceParaRemover)->nome);

        int i 
        for (i = indiceParaRemover; i < *total - 1; i++) {
            lista[i] = lista[i + 1];
        }

        (*total)--; 

        printf("\n>> Contato excluido com sucesso! <<\n");
    } else {
        printf("\nContato com ID %d nao foi encontrado.\n", idBusca);
    }
}

// Ela recebe um ponteiro para um contato, o total de contatos que FALTAM analisar e o número N.
int contarNomesMaioresQue_recursivo(Contato *pContato, int restantes, int N) {
    // CASO BASE: A condição de parada. Se não tem mais contatos para ver, retorna 0.
    if (restantes == 0) {
        return 0;
    }

    int contadorAtual = (strlen(pContato->nome) > N) ? 1 : 0;

    // A função se chama de novo, só que agr,
    // 1. Passa o ponteiro para o PRÓXIMO contato (`pContato + 1`).
    // 2. Diminui a contagem de contatos restantes (`restantes - 1`).
    // O resultado é o já contado (0 ou 1) somado com o que a próxima chamada encontrar.
    return contadorAtual + contarNomesMaioresQue_recursivo(pContato + 1, restantes - 1, N);
}

// Essa é a função que a main chama. 
void estatisticas(Contato *lista, int total) {
    printf("\n--- 6. Estatisticas (Funcao Recursiva) ---\n");

    if (total == 0) {
        printf("Nenhum contato na agenda para gerar estatisticas.\n");
        return;
    }

    int N;
    printf("A funcao ira contar quantos contatos tem um nome com mais de N caracteres.\n");
    printf("Digite o valor de N: ");
    scanf("%d", &N);

    int resultado = contarNomesMaioresQue_recursivo(lista, total, N);

    printf("\n>> Resultado: %d contatos tem um nome com mais de %d caracteres. <<\n", resultado, N);
}