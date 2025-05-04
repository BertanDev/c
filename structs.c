typedef struct {
	int id;
	char descr[20];
	float price;
} Product;

typedef struct {
	int id;
	char name[20];
} Client;

typedef struct {
	int id;
	int products_id[10];
	int id_cliente;
} Sale;

typedef struct {
    int id;
    int id_sale;
    int id_product;
} SaledProducts;