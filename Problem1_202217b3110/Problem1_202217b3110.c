#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n = 0; // Array and current number of elements

int main() {
    int ch;
    char g = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display \n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: create(); break;
            case 2: deletion(); break;
            case 3: search(); break;
            case 4: insert(); break;
            case 5: display(); break;
            case 6: exit(0); break;
            default: printf("\nEnter the correct choice:");
        }

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g); // Note the space before %c to consume any newline characters
    } while (g == 'y' || g == 'Y');

    return 0;
}

void create() {
    int i;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    
    if (n > MAX) {
        printf("\nCannot create a list with more than %d elements.\n", MAX);
        n = 0;
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    int pos, i;
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("\nInvalid location.\n");
        return;
    }

    for (i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;

    printf("\nThe elements after deletion:\n");
    display();
}

void search() {
    int e, i;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is at position %d\n", i);
            return;
        }
    }
    printf("Value %d is not in the list\n", e);
}

void insert() {
    int pos, p, i;

    if (n >= MAX) {
        printf("\nThe list is full.\n");
        return;
    }

    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("\nInvalid position.\n");
        return;
    }

    for (i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }

    printf("Enter the element to insert: ");
    scanf("%d", &p);
    b[pos] = p;
    n++;

    printf("\nThe list after insertion:\n");
    display();
}

void display() {
    int i;
    printf("\nThe elements of the list ADT are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
