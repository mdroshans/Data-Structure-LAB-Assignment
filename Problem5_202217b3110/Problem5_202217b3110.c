#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

void main() {
    int queue[QUEUE_SIZE], choice = 1, front = 0, rear = 0, index = 1, max_size = QUEUE_SIZE;

    printf("Queue using Array\n");
    printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");

    while (choice) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear == max_size)
                    printf("Queue is Full\n");
                else {
                    printf("Enter number %d: ", index++);
                    scanf("%d", &queue[rear++]);
                }
                break;
            case 2:
                if (front == rear)
                    printf("Queue is empty\n");
                else {
                    printf("Deleted Element is %d\n", queue[front++]);
                    max_size++;
                }
                break;
            case 3:
                printf("Queue Elements are:\n");
                if (front == rear)
                    printf("Queue is Empty\n");
                else {
                    for (int i = front; i < rear; i++)
                        printf("%d\n", queue[i]);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Choice: please see the options\n");
        }
    }
}
