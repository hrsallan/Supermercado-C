#include <stdio.h>
#include <string.h>
#include <locale.h>

// Variáveis Globais
char nomes[100][40];
char categorias[100][20];
char validades[100][11];
int quantidades[100];
int ativos[100];
int id[100];
double precos[100];
int contador = 0;

// Função Recursiva | Buscar Produto por NOME
int buscar_nome(char *nomePROCURADO, int indice_atual) {
	if(indice_atual >= contador) {
		return -1;
	}
	if(strcmp(nomes[indice_atual], nomePROCURADO) == 0) {
		return indice_atual;
	}
	return buscar_nome(nomePROCURADO, indice_atual + 1);
}

// Função Recursiva | Buscar Produto por ID
int buscar_id(int id_procurado, int indice_atual) {
	if (indice_atual >= contador) {
		return -1;
	}
	if (id[indice_atual] == id_procurado) {
		return indice_atual;
	}
	return buscar_id(id_procurado, indice_atual + 1);
}

// Função para exibir os dados de um produto
void exibir_produto(int indice) {
	printf("----------------------------------\n");
	printf("ID: %d\n", id[indice]);
	printf("NOME: %s\n", nomes[indice]);
	printf("CATEGORIA: %s\n", categorias[indice]);
	printf("QUANTIDADE: %d\n", quantidades[indice]);
	printf("PRECO: R$%.2lf\n", precos[indice]);
	printf("VALIDADE: %s\n", validades[indice]);
	printf("STATUS: %s\n", ativos[indice] ? "Ativo" : "Inativo");
	printf("----------------------------------\n");
}

// Função Listar Produtos Ativos
void ListarProdutos() {
	printf("\n--- LISTA DE PRODUTOS ATIVOS ---\n");
	int encontrou_ativos = 0;
	for (int i = 0; i < contador; i++) {
		if (ativos[i] == 1) {
			exibir_produto(i);
			encontrou_ativos = 1;
		}
	}
	if (!encontrou_ativos) {
		printf("Nenhum produto ativo encontrado.\n");
	}
}

// Função Cadastrar Produto
void CadastrarProduto() {
	int id_temp;
	int indice_encontrado;
	if (contador >= 100) {
		printf("Limite de 100 produtos cadastrados atingido!\n");
		return;
	}
	do {
		printf("\nDigite o ID do produto:\n");
		scanf("%d", &id_temp);
		getchar();
		indice_encontrado = buscar_id(id_temp, 0);
		if (indice_encontrado != -1) {
			printf("ERRO: ID ja cadastrado! Tente novamente.\n");
		}
	} while (indice_encontrado != -1);
	id[contador] = id_temp;
	printf("Digite o NOME:\n");
	fgets(nomes[contador], 40, stdin);
	nomes[contador][strcspn(nomes[contador], "\n")] = '\0';
	printf("Digite a CATEGORIA:\n");
	fgets(categorias[contador], 20, stdin);
	categorias[contador][strcspn(categorias[contador], "\n")] = '\0';
	printf("Digite a QUANTIDADE:\n");
	scanf("%d", &quantidades[contador]);
	printf("Digite o PRECO:\n");
	scanf("%lf", &precos[contador]);
	getchar();
	printf("Digite a VALIDADE (ex: DD/MM/AAAA):\n");
	fgets(validades[contador], 11, stdin);
	validades[contador][strcspn(validades[contador], "\n")] = '\0';
	printf("Esta ativo? 1 = SIM / 0 = NAO\n");
	scanf("%d", &ativos[contador]);
	contador++;
	printf("\nPRODUTO CADASTRADO COM SUCESSO!\n");
}

// Função Atualizar PreC'o
void atualizar_preco() {
	int entrada_id;
	double entrada_preconew;
	if (contador == 0) {
		printf("Nenhum produto cadastrado ainda.\n");
		return;
	}
	printf("Digite o ID do produto que deseja atualizar o preco:\n");
	scanf("%d", &entrada_id);
	int indice_encontrado = buscar_id(entrada_id, 0);
	if (indice_encontrado != -1) {
		printf("Produto encontrado: %s\n", nomes[indice_encontrado]);
		printf("Preco atual: R$%.2lf\n", precos[indice_encontrado]);
		printf("Digite o novo preco para o produto:\n");
		scanf("%lf", &entrada_preconew);
		precos[indice_encontrado] = entrada_preconew;
		printf("Preco do produto '%s' atualizado com sucesso!\n",
		       nomes[indice_encontrado]);
	} else {
		printf("Erro: Produto com ID %d nao encontrado.\n", entrada_id);
	}
}

// Função para buscar um produto e exibir seus dados
void buscar_produto() {
	int opcao, id_busca;
	char nome_busca[40];
	int indice_encontrado = -1;
	if (contador == 0) {
		printf("Nenhum produto cadastrado ainda.\n");
		return;
	}
	printf("\nBuscar por:\n1 - ID\n2 - Nome\n");
	scanf("%d", &opcao);
	getchar();
	if (opcao == 1) {
		printf("Digite o ID do produto: ");
		scanf("%d", &id_busca);
		indice_encontrado = buscar_id(id_busca, 0);
	} else if (opcao == 2) {
		printf("Digite o nome do produto: ");
		fgets(nome_busca, 40, stdin);
		nome_busca[strcspn(nome_busca, "\n")] = '\0';
		indice_encontrado = buscar_nome(nome_busca, 0);
	} else {
		printf("Opcao invalida.\n");
		return;
	}
	if (indice_encontrado != -1) {
		printf("\n--- PRODUTO ENCONTRADO ---\n");
		exibir_produto(indice_encontrado);
	} else {
		printf("Produto nao encontrado.\n");
	}
}

// Função para registrar entrada ou saC-da de estoque
int movimentar_estoque(int tipo) {
	int id_busca, quantidade;
	if (contador == 0) {
		printf("Nenhum produto cadastrado ainda.\n");
		return;
	}
	printf("Digite o ID do produto: ");
	scanf("%d", &id_busca);
	int indice = buscar_id(id_busca, 0);
	if (indice != -1) {
		printf("Produto: %s | Estoque atual: %d\n", nomes[indice], quantidades[indice]);
		printf("Digite a quantidade para %s: ", tipo == 1 ? "entrada" : "saida");
		scanf("%d", &quantidade);
		if (tipo == 1) {
			quantidades[indice] += quantidade;
			printf("Entrada registrada com sucesso!\n");
		} else {
			if (quantidades[indice] >= quantidade) {
				quantidades[indice] -= quantidade;
				printf("Saida registrada com sucesso!\n");
			} else {
				printf("Erro: Estoque insuficiente.\n");
			}
		}
		printf("Novo estoque: %d\n", quantidades[indice]);
	} else {
		printf("Produto com ID %d nao encontrado.\n", id_busca);
	}
}

// Loop Menu | Switch Case
int main() {
	setlocale(LC_ALL, "Portuguese");
	int entrada, log = 1;
	while(log == 1) {
		printf("\n==== Controle de Estoque ====\n");
		printf("1 | Cadastrar Produto\n");
		printf("2 | Listar Produtos Ativos\n");
		printf("3 | Buscar Produto\n");
		printf("4 | Registrar Entrada de Estoque\n");
		printf("5 | Registrar Saida de Estoque\n");
		printf("6 | Atualizar Preco\n");
		printf("0 | Sair\n");
		printf("=============================\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &entrada);
		getchar();
		switch(entrada) {
		case 0:
			log = 0;
			printf("Saindo do programa...\n");
			break;
		case 1:
			CadastrarProduto();
			break;
		case 2:
			ListarProdutos();
			break;
		case 3:
			buscar_produto();
			break;
		case 4:
			movimentar_estoque(1);
			break;
		case 5:
			movimentar_estoque(-1);
			break;
		case 6:
			atualizar_preco();
			break;
		default:
			printf("Opcao invalida! Tente novamente.\n");
		}
	}
	return 0;
}
