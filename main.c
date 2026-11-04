#include <stdio.h>
#include "product.h"

int main(void)
{
    freopen("input.txt", "r", stdin);
    product *start = NULL;
    product *current = NULL;

    int id, quantity;
    char name[100];
    float price;
    char choice;

    // printf("Enter product (ID Name Price Quantity): ");
    while (!(id == 999 && strcmp(name, "exit") == 0 && price == 99.0 && quantity == 99)) {
        scanf("%d %99s %f %d", &id, name, &price, &quantity);

        product *p = createProduct(id, name, price, quantity);

        if (p == NULL)
            break;

        if (start == NULL)
            start = current = p;
        else {
            current->next = p;
            current = p;
        }

        // printf("Add another product? (y/n): ");
        // scanf(" %c", &choice);

    }

    // listProduct(start);
    printProductInfo(searchName(start, "Bread"));

    return 0;
}
