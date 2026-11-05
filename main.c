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
    while (1) {
        scanf("%d %99s %f %d", &id, name, &price, &quantity);

        if (id == 999 && strcmp(name, "exit") == 0 && price == 99.0 && quantity == 99)
        {
            break;
        }
        

        product *p = createProduct(id, name, price, quantity);

        if (p == NULL)
            break;

        if (start == NULL)
            start = current = p;
        else {
            p->prev = current;
            current->next = p;
            current = p;
        }

        // printf("Add another product? (y/n): ");
        // scanf(" %c", &choice);

    }

    // listProduct(start);
    
    start = delProduct(start, searchName(start, "Bread"));
    
    printProductInfo(searchName(start, "Bread"));
    // listProduct(start);

    return 0;
}
