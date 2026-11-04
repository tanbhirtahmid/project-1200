#include <stdio.h>
#include "product.h"

int main(void)
{
    product *start = NULL;
    product *current = NULL;

    int id, quantity;
    char name[100];
    float price;
    char choice;

    do {
        printf("Enter product (ID Name Price Quantity): ");
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

        printf("Add another product? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    listProduct(start);

    return 0;
}
