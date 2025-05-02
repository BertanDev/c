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
				makeSale();	
				break;
			case 4:
				showSales();
				break;
			case 5:
				listProducts(products, sizeProducts);
				break;
		}

	} while (opt != 999);

	return 0;
}

void exibeMenu() {
	printf("Digite o que deseja fazer:\n");
	printf(" 1 - Cadastrar Produto\n");
	printf(" 2 - Cadastrar Cliente\n");
	printf(" 3 - Realizar Venda\n");
	printf(" 4 - Vizualizar Vendas\n");
	printf(" 5 - Vizualizar Produtos\n");
	printf(" 6 - Vizualizar Clientes\n");
	printf(" 999 - Sair do Sistema\n");
}
