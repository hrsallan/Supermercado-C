# Supermercado em C

![Status do Projeto](https://img.shields.io/badge/status-concluído-green)

## 📖 Sobre o Projeto

Este projeto consiste em um sistema simples de **Controle de Estoque** desenvolvido inteiramente em **Linguagem C**. A aplicação funciona via console (terminal) e permite ao usuário realizar operações básicas de gerenciamento de produtos, como cadastro, listagem, busca e movimentação de estoque.

O sistema foi desenvolvido como trabalho acadêmico para o curso de **Ciências da Computação** da **UNIPAC Barbacena**, com o objetivo de aplicar conceitos fundamentais de programação estruturada, manipulação de dados e algoritmos de busca.

---

## ✨ Funcionalidades

O sistema oferece um menu interativo com as seguintes opções:

* **Cadastrar Produto:** Adiciona um novo produto ao sistema, solicitando informações como ID (único), nome, categoria, quantidade, preço e validade.
* **Listar Produtos Ativos:** Exibe uma lista de todos os produtos que estão com o status "Ativo".
* **Buscar Produto:** Permite ao usuário buscar um produto específico no sistema por **ID** ou por **Nome**.
* **Registrar Entrada de Estoque:** Adiciona uma determinada quantidade ao estoque de um produto já cadastrado.
* **Registrar Saída de Estoque:** Remove uma determinada quantidade do estoque de um produto, com validação para evitar estoque negativo.
* **Atualizar Preço:** Permite modificar o preço de um produto existente a partir do seu ID.
* **Sair:** Encerra a execução do programa.

---

## 🚀 Conceitos e Tecnologias Utilizadas

* **Linguagem C (Padrão ANSI C)**
* Manipulação de vetores (arrays) multidimensionais para armazenamento de dados em memória.
* Uso de funções para modularização do código.
* **Recursividade:** As funções de busca por ID e por nome foram implementadas de forma recursiva.
* Estrutura de menu com `switch-case`.
* Manipulação de entrada e saída de dados padrão (`<stdio.h>`).
* Manipulação de strings (`<string.h>`).

---

## ⚙️ Como Compilar e Executar

Para compilar e executar o projeto, você precisará de um compilador C, como o **GCC**.

1.  **Clone ou baixe o repositório:**
    Salve o arquivo de código-fonte (ex: `main.c`).

2.  **Abra o terminal na pasta do projeto:**
    Navegue até o diretório onde você salvou o arquivo.

3.  **Compile o código:**
    Execute o seguinte comando no terminal:
    ```bash
    gcc main.c -o controle_estoque
    ```
    *(Caso seu arquivo tenha outro nome, substitua `main.c` pelo nome correto)*

4.  **Execute o programa:**
    * No Linux ou macOS:
        ```bash
        ./controle_estoque
        ```
    * No Windows:
        ```bash
        controle_estoque.exe
        ```

---

## 👨‍💻 Autor

* **Autor:** Allan Henrique Rosa Silva
* **Instituição:** UNIPAC Barbacena
* **Curso:** Ciências da Computação