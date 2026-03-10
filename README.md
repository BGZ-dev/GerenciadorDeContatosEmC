# Gerenciador de Contatos em C

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)
![Plataforma](https://img.shields.io/badge/Plataforma-Terminal-lightgrey.svg)
![Licença](https://img.shields.io/badge/Licen%C3%A7a-MIT-green.svg)

Projeto prático da disciplina de **Laboratório de Programação**, desenvolvido para consolidar os fundamentos da linguagem C. O sistema é um gerenciador de contatos executado em modo texto, com funcionalidades de cadastro, listagem, busca, edição, exclusão e estatísticas.

---

## Funcionalidades

O programa apresenta um menu interativo com as seguintes opções:

*   **Cadastrar Contato:** Adiciona um novo contato (nome, telefone e e-mail) à agenda.
*   **Listar Contatos:** Exibe todos os contatos cadastrados com seus respectivos IDs.
*   **Buscar Contato por Nome:** Procura e exibe contatos que correspondam a um nome específico.
*   **Editar Contato:** Permite alterar as informações de um contato existente através do seu ID.
*   **Excluir Contato:** Remove um contato da agenda de forma permanente através do seu ID.
*   **Exibir Estatísticas (Recursivo):** Uma função especial que conta, de forma recursiva, quantos contatos possuem um nome com mais de `N` caracteres.
*   **Sair:** Encerra a execução do programa.

---

## 🚀 Conceitos e Tecnologias Aplicadas

Este projeto foi construído aplicando os seguintes conceitos fundamentais da linguagem C:

*   **Modularização:** O código foi dividido em `main.c` (interface), `contato.h` (cabeçalho/definições) e `contato.c` (implementação), promovendo organização e reutilização.
*   **Estruturas (`struct`):** A `struct Contato` foi utilizada para agrupar os dados de cada registro de forma coesa.
*   **Ponteiros e Passagem por Referência:** Ponteiros foram essenciais para manipular o array de contatos e a variável de contagem total diretamente de dentro das funções (ex: `cadastrar` e `remover`), evitando cópias desnecessárias de dados.
*   **Manipulação de Strings:** Funções da biblioteca `string.h` (como `strcmp` e `strlen`) foram usadas para comparar nomes e calcular comprimentos de strings.
*   **Recursividade:** A função de estatísticas foi implementada com uma abordagem recursiva para demonstrar o conceito, percorrendo a lista de contatos para realizar uma contagem.
*   **Gerenciamento de Memória:** O armazenamento dos contatos é feito em um array estático, com controle do número de registros.
*   **Versionamento com Git:** O projeto foi versionado utilizando Git e hospedado no GitHub.

---

## 📂 Estrutura do Projeto

```
.
├── contato.c       // Implementação das funções de manipulação de contatos
├── contato.h       // Definição da struct Contato e protótipos das funções
├── main.c          // Ponto de entrada, menu principal e laço de execução
└── README.md       // Este arquivo
```

---

## ⚙️ Como Compilar e Executar

Para compilar e executar o projeto, você precisará de um compilador C, como o **GCC**.

1.  **Clone o repositório:**
    ```bash
    git clone https://github.com/BGZ-dev/gerenciador-contatos-c.git
    cd gerenciador-contatos-c
    ```

2.  **Compile os arquivos-fonte:**
    O comando abaixo irá compilar todos os arquivos `.c` e gerar um executável chamado `programa`.
    ```bash
    gcc main.c contato.c -o programa
    ```
    *Se estiver no Windows, o executável será `programa.exe`.*

3.  **Execute o programa:**
    ```bash
    ./programa
    ```
    *No Windows, use apenas `programa`.*

---

## 👥 Integrantes

Este projeto foi desenvolvido por:

*   **Joao Duarte Borges Neto** - `BGZ-dev`
*   **Eduardo Rodrigues dos Santos** - `Estque`
*   **luan de Avila Nunes** - `lAviila`
