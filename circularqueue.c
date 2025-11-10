#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int rear = -1, front = -1;

void enqueue() {
    int val;
    printf("Enter the data: ");
    scanf("%d", &val);

    if ((rear + 1) % N == front) {
        printf("Queue is overflow\n");
        return;
    } else if (rear == -1 && front == -1) {
        rear = front = 0;
    } else {
        rear = (rear + 1) % N;
    }
    queue[rear] = val;
}

void dequeue() {
    if (rear == -1 && front == -1) {
        printf("Queue is underflow\n");
        return;
    } else if (rear == front) {
        printf("Deleted item is %d\n", queue[front]);
        rear = front = -1;
    } else {
        printf("Deleted item is %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    int i = front;
    if (rear == -1 && front == -1) {
        printf("Queue is underflow\n");
        return;
    }
    printf("Queue elements: ");
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", queue[rear]);
}

void search() {
    int data, flag = 0, count = 0;
    if (rear == -1 && front == -1) {
        printf("Queue is underflow\n");
        return;
    }

    printf("Enter the data to search: ");
    scanf("%d", &data);

    int i = front;
    do {
        count++;
        if (queue[i] == data) {
            flag = 1;
            break;
        }
        i = (i + 1) % N;
    } while (i != (rear + 1) % N);

    if (flag == 1)
        printf("Element found at position %d\n", count);
    else
        printf("Element not found\n");
}

int main() {
    int opt;
    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter the option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: search(); break;
            case 5: exit(0);
            default: printf("Invalid option\n");
        }
    } while (1);
}

