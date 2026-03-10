#include <stdio.h>
#include "contato.h"

int main() {
    Contato agenda[MAX_CONTATOS];
    int totalContatos = 0;
    int opcao;

    do {
        printf("\n--- SISTEMA DE AGENDA ---\n");
        printf("1. Cadastrar\n");
        printf("2. Listar\n");
        printf("3. Buscar por nome\n");
        printf("4. Editar\n");
        printf("5. Excluir\n");
        printf("6. Estatisticas (recursivo)\n"); // 
        printf("7. Sair\n");                     
        printf("Escolha uma opcao: ");

        
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastrar(agenda, &totalContatos); break;
            case 2: listar(agenda, totalContatos); break;
            case 3: buscar(agenda, totalContatos); break;
            case 4: editar(agenda, totalContatos); break;
            case 5: remover(agenda, &totalContatos); break;
            case 6: estatisticas(agenda, totalContatos); break; // 
            case 7: printf("Encerrando...\n"); break;           
        }
    } while(opcao != 7);

    return 0;
}