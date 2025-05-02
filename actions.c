#include <stdio.h>
#include "structs.c"

void createProduct(Product products[], int *size) {
    if (*size >= 10) {
        printf("Limite de produtos atingido!\n");
        return;
    };

    printf("Digite a descrição do produto:\n");
    scanf("%s", products[*size].descr);

    printf("Digite o preço do produto:\n");
    scanf("%f", &products[*size].price);

    // products[*size].id = *size + 1;

    printf("Produto cadastrado com sucesso!\n");

    (*size)++;
}

void createClient(Client clients[], int *size) {
    if (*size >= 10) {
        printf("Limite de clientes atingido!");
        return;
    };

    printf("Digite o nome do cliente:\n");
    scanf("%s", clients[*size].name);

	printf("Cadastro cliente");
}

void makeSale() {
	printf("Realiza venda");
}

void showSales() {
	printf("VCizu vendas");
}

void listProducts(Product products[], int size) {
    if (size == 0) {
        printf("Nenhum produto cadastrado ainda.\n");
        return;
    }

    printf("\nLista de Produtos Cadastrados:\n");
    for (int i = 0; i < size; i++) {
        printf("%d - %s: R$%.2f\n", i + 1, products[i].descr, products[i].price);
    }
}