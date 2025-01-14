#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int item;
    int priority;
} Element;
Element A[100];
int FRONT = -1, REAR = -1;
int max;
void assign(int x) {
    max = x;
}
void enqueue_pq(int item, int priority) {
    if (REAR == max - 1) {
        printf("Queue is full!\n");
        return;
    }

    if (FRONT == -1) { // Queue is empty
        FRONT = REAR = 0;
        A[REAR].item = item;
        A[REAR].priority = priority;
    } else {
        int i;
        for (i = REAR; i >= FRONT && A[i].priority > priority; i--) {
            A[i + 1] = A[i];
        }
        A[i + 1].item = item;
        A[i + 1].priority = priority;
        REAR++;
    }
}
void dequeue_pq() {
    if (FRONT == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Dequeued item: %d with priority: %d\n", A[FRONT].item, A[FRONT].priority);

    if (FRONT == REAR) { // Only one element was present
        FRONT = REAR = -1;
    } else {
        FRONT++;
    }
}
void display_pq() {
    if (FRONT == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents:\n");
    for (int i = FRONT; i <= REAR; i++) {
        printf("Item: %d Priority: %d\n", A[i].item, A[i].priority);
    }
}
int main() {
    int choice, item, priority, size;

    printf("Enter the size of the Queue: ");
    scanf("%d", &size);

    assign(size);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item and priority: ");
                scanf("%d %d", &item, &priority);
                enqueue_pq(item, priority);
                break;
            case 2:
                dequeue_pq();
                break;
            case 3:
                display_pq();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
