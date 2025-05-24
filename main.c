#include <stdio.h>

#include "actions.c"

void exibeMenu();

int main()
{
	int opt = 0;

	Product products[10];
	int sizeProducts = 0;

	Client clients[10];
	int sizeClients = 0;

	Sale sales[10];
	int sizeSales = 0;

	do {
	  exibeMenu();
	  scanf("%d", &opt);

	  switch (opt) {
	    case 1:
		createProduct(products, &sizeProducts);
		break;
	    case 2:
		createClient(clients, &sizeClients);
		break;
	    case 3:
		makeSale(sales, &sizeSales, clients, sizeClients, products, sizeProducts);
		break;
	    case 4:
		showSales(sales, sizeSales, clients, products);
		break;
	    case 5:
		listProducts(products, sizeProducts);
		break;
            case 6:
		listClients(clients, sizeClients);
		break;
            case 7:
                deleteProduct(products, &sizeProducts);
                break;
            case 8:
                deleteClient(clients, &sizeClients);
                break;
            case 9:
                updateProduct(products, sizeProducts);
                break;
            case 10:
                updateClient(clients, sizeClients);
                break;
	  }

	} while (opt != 999);

	return 0;
}

void exibeMenu() {
    printDoubleLine();
    printf("Digite o que deseja fazer:\n");
	printf(" 1 - Cadastrar Produto\n");
	printf(" 2 - Cadastrar Cliente\n");
	printf(" 3 - Realizar Venda\n");
	printf(" 4 - Vizualizar Vendas\n");
	printf(" 5 - Vizualizar Produtos\n");
	printf(" 6 - Vizualizar Clientes\n");
	printf(" 7 - Deletar Produto\n");
	printf(" 8 - Deletar Cliente\n");
	printf(" 9 - Atualizar Produto\n");
	printf(" 10 - Atualizar Cliente\n");
	printf(" 999 - Sair do Sistema\n");
	printSingleLine();
}
