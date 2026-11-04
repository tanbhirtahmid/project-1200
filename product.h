// #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int id;
    char name[100];
    float price;
    int quantity;
    struct product *next;
    struct product *prev;
}product;

void printProductInfo(product *p)
{
    if (p == NULL) {
        printf("Product not found.\n");
        return;
    }

    printf("ID: %d | Name: %s | Price: %.3f | Quantity: %d\n",
           p->id, p->name, p->price, p->quantity);
}

product * createProduct(int id, char *name, float price, int quantitiy){
    product *p = (product *) malloc(sizeof(product));
    p->id = id;
    strcpy(p->name,name);
    // p->name = name;
    p->price = price;
    p->quantity = quantitiy;
    p->next = NULL;
    p->prev = NULL;
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

            return p;
        }

        p = p->next;
    }
    return NULL;
}

product *searchName(product *p, char *name)
{
    while (p != NULL) {
        if (strcmp(p->name, name) == 0) {

            return p;
        }

        p = p->next;
    }

    return NULL;
}

void delProduct(product **start, product *p)
{
    if (p == NULL)
        return;

    if (p->prev != NULL)
        p->prev->next = p->next;
    else
        *start = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;

}
