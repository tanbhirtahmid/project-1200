#include <stdio.h>
#include "product.h"

product *menu(product *start)
{
    int id, quantity, choice;
    char name[100];
    float price;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. List products\n");
        printf("2. Search by id\n");
        printf("3. Search by name\n");
        printf("4. Add product\n");
        printf("5. Delete product\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Exit\n");
            break;
        }
        else if (choice == 1)
        {
            listProduct(start);
        }
        else if (choice == 2)
        {
            printf("Enter product id: ");
            scanf("%d", &id);

            printProductInfo(searchID(start, id));
        }
        else if (choice == 3)
        {
            printf("Enter product name: ");
            scanf("%99s", name);

            printProductInfo(searchName(start, name));
        }
        else if (choice == 4)
        {
            printf("Enter product (ID Name Price Quantity): ");
            scanf("%d %99s %f %d", &id, name, &price, &quantity);

            product *p = createProduct(id, name, price, quantity);
            product *current = start;

            if (p == NULL)
                break;

            if (start == NULL)
                start = p;
            else {
                while (current->next != NULL)
                    current = current->next;

                p->prev = current;
                current->next = p;
            }

            printf("Product added.\n");
        }
        else if (choice == 5)
        {
            printf("Enter product id: ");
            scanf("%d", &id);

            product *p = searchID(start, id);

            if (p == NULL)
            {
                printf("Product not found.\n");
            }
            else
            {
                start = delProduct(start, p);
                printf("Product deleted.\n");
            }
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return start;
}

int main(void)
{
    product *start = NULL;
    product *current = NULL;
    FILE *file = fopen("input.txt", "r");

    int id, quantity;
    char name[100];
    float price;

    if (file == NULL)
    {
        printf("input.txt not found\n");
        return 1;
    }

    // load products from file first
    while (fscanf(file, "%d %99s %f %d", &id, name, &price, &quantity) == 4)
    {
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
    }

    fclose(file);

    start = menu(start);

    return 0;
}
