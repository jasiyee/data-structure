#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;


void insert() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Node inserted.\n");
}


void deleteNode() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted.\n");
}

void search() {
    int data, pos = 1, found = 0;
    struct node *temp = head;

    printf("Enter the data to search: ");
    scanf("%d", &data);

    while (temp != NULL) {
        if (temp->data == data) {
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (found)
        printf("Data %d found at position %d\n", data, pos);
    else
        printf("Data %d NOT found in list.\n", data);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int opt;

    do {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: insert(); break;
            case 2: deleteNode(); break;
            case 3: display(); break;
            case 4: search(); break;
            case 5: exit(0);
            default: printf("Invalid option\n");
        }

    } while (opt != 5);

    return 0;
}

