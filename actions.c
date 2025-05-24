#include <stdio.h>
#include <string.h>

#include "structs.c"
#include "utils.c"

void createProduct(Product products[], int *size) {
    if (warningLimit("Limite de produtos atingido!", *size)) return;

    printSingleLine();
    printf("Digite a descrição do produto:\n");
    scanf("%s", products[*size].descr);

    printf("Digite o preço do produto:\n");
    scanf("%f", &products[*size].price);

    products[*size].id = getLastIdProduct(products, *size) + 1;

    printf("Produto cadastrado com sucesso!\n");
    printDoubleLine();

    (*size)++;
}

void createClient(Client clients[], int *size) {
    if (warningLimit("Limite de clientes atingido!", *size)) return;

    printSingleLine();
    printf("Digite o nome do cliente:\n");
    scanf("%s", clients[*size].name);

    clients[*size].id = getLastIdClient(clients, *size) + 1;

	printf("Cliente cadastrado com sucesso!\n");
	printDoubleLine();

	(*size)++;
}

void makeSale(Sale sales[], int *size, Client clients[], int sizeClients, Product products[], int sizeProducts) {
    if (warningLimit("Limite de vendas atingido!", *size)) return;

    int id_client, id_product, n_products;

    listClients(clients, sizeClients);
    printSingleLine();
    printf("Selecione um cliente:\n");
    scanf("%d", &id_client);

    n_products = 0;
    do {
        listProducts(products, sizeProducts);
        printf("999 - Sair\n");
        printf("Selecione o produto:\n");

        scanf("%d", &id_product);

        if (id_product == 999) break;

        sales[*size].products_id[n_products] = id_product;
        n_products++;

        if (n_products >= 10) break;
    } while (id_product != 999);

    sales[*size].id_cliente = id_client;
    sales[*size].id = *size + 1;
    (*size)++;

    printf("Venda cadastrada com sucesso!\n");
    printDoubleLine();
}

void showSales(Sale sales[], int size, Client clients[], Product products[]) {
    int clientIndex, productIndex;

	if (warningEmpty("Nenhuma venda cadastrada ainda.", size)) return;

	printSingleLine();
	for (int i = 0; i < size; i++) {
        printf("Venda código %d\n", sales[i].id);
        clientIndex = getIndexClient(clients, sales[i].id_cliente);
        printf("Cliente: %d - %s\n", sales[i].id_cliente, clients[clientIndex].name);

        printf("Produtos:\n");
        for (int j = 0; j < 10; j++){
            if (!(sales[i].products_id[j] > 0)) break;
            productIndex = getIndexProduct(products, sales[i].products_id[j]);
            printf("%d - %s\n", sales[i].products_id[j], products[productIndex].descr);
        }
	}
	printDoubleLine();
}

void listProducts(Product products[], int size) {
    if (warningEmpty("Nenhum produto cadastrado ainda.", size)) return;

    printSingleLine();
    printf("\nLista de Produtos Cadastrados:\n");
    for (int i = 0; i < size; i++) {
        printf("%d - %s: R$%.2f\n", products[i].id, products[i].descr, products[i].price);
    }
}

void listClients(Client clients[], int size) {
    if (warningEmpty("Nenhum cliente cadastrado ainda.", size)) return;

    printSingleLine();
    printf("Lista de clientes Cadastrados:\n");
    for (int i = 0; i < size; i++) {
        printf("%d - %s\n", clients[i].id, clients[i].name);
    }
}

void deleteProduct(Product products[], int *size) {
    if (warningEmpty("Nenhum produto cadastrado ainda.", *size)) return;

    int idToDelete, indexToDelete;

    listProducts(products, *size);
    printf("Digite o código para excluir:\n");
    scanf("%d", &idToDelete);
    indexToDelete = getIndexProduct(products, idToDelete);

    for(int i = indexToDelete; i < *size - 1; i++) {
        products[i] = products[i + 1];
    };

    (*size)--;
}

void deleteClient(Client clients[], int *size) {
    if (warningEmpty("Nenhum cliente cadastrado ainda.", *size)) return;

    int idToDelete, indexToDelete;

    listClients(clients, *size);
    printf("Digite o código para excluir:\n");
    scanf("%d", &idToDelete);
    indexToDelete = getIndexClient(clients, idToDelete);

    for(int i = indexToDelete; i < *size - 1; i++) {
        clients[i] = clients[i + 1];
    };

    (*size)--;
}

void updateProduct(Product products[], int size) {
    if (warningEmpty("Nenhum produto cadastrado ainda.", size)) return;

    int idToUpdate, indexToUpdate;
    char newDescr[20];
	float newPrice;

    listProducts(products, size);
    printf("Digite o código para atualizar:\n");
    scanf("%d", &idToUpdate);
    indexToUpdate = getIndexProduct(products, idToUpdate);
    printf("Digite a descrição do produto:\n");
    scanf("%s", newDescr);
    printf("Digite o preço do produto:\n");
    scanf("%f", &newPrice);
    strcpy(products[indexToUpdate].descr, newDescr);
    products[indexToUpdate].price = newPrice;
}

void updateClient(Client clients[], int size) {
    if (warningEmpty("Nenhum cliente cadastrado ainda.", size)) return;

    int idToUpdate, indexToUpdate;
    char newName[20];

    listClients(clients, size);
    printf("Digite o código para atualizar:\n");
    scanf("%d", &idToUpdate);
    indexToUpdate = getIndexClient(clients, idToUpdate);
    printf("Digite o nome do cliente:\n");
    scanf("%s", newName);
    strcpy(clients[indexToUpdate].name, newName);
}
