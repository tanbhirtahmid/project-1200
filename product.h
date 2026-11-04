// #include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct product {
    int id;
    char name[100];
    float price;
    int quantity;
    struct product *next;
}product;

product * createProduct(int id, char *name, float price, int quantitiy){
    product *p = (product *) malloc(sizeof(product));
    p->id = id;
    strcpy(p->name,name);
    // p->name = name;
    p->price = price;
    p->quantity = quantitiy;
    p->next = NULL;
    return p;
}

void listProduct(product * p)
{
    printf("\n--- Product Inventory ---\n");
    while (p!=NULL) {
        printf("ID: %d | Name: %s | Price: %.3f | Quantity: %d\n", p->id, p->name, p->price, p->quantity);
        p = p->next;
    }
}

product *searchID(product *p, int id)
{
    while (p != NULL) {
        if (p->id == id) {
            
            printf("Product found!\n");
            printf("ID: %d | Name: %s | Price: %.3f | Quantity: %d\n", p->id, p->name, p->price, p->quantity);

            return p;
        }

        p = p->next;
    }

    printf("Product with ID %d not found.\n", id);
    return NULL;
}
