#include <stdio.h>
int FRONT = -1, REAR = -1;
int MAX;
int A[100];

void EJECT_DQO() {
    if (FRONT == -1 && REAR == -1) {
        printf("Deque is EMPTY\n");
    } else if (FRONT == REAR) {
        printf("Dequeued item is %d\n", A[REAR]);
        FRONT = REAR = -1;
    } else {
        printf("Dequeued item is %d\n", A[REAR]);
        REAR = REAR - 1;
    }
}

void DISPLAY_DQ() {
    if (FRONT == -1 && REAR == -1) {
        printf("Deque is EMPTY\n");
    } else {
        for (int i = FRONT; i <= REAR; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}

void INJECT_DQ(int ITEM) {
    if (FRONT == -1 && REAR == MAX - 1) {
        printf("Deque is FULL\n");
    } else if (FRONT == -1 && REAR == -1) {
        FRONT = REAR = 0;
        A[REAR] = ITEM;
    } else if (REAR == MAX - 1) {
        for (int i = FRONT; i <= REAR; i++) {
            A[i - 1] = A[i];
        }
        A[REAR] = ITEM;
        FRONT--;
    } else {
        REAR++;
        A[REAR] = ITEM;
    }
}

void POP_DQ() {
    if (FRONT == -1 && REAR == -1) {
        printf("Deque is EMPTY\n");
    } else if (FRONT == REAR) {
        printf("Dequeued item is %d\n", A[FRONT]);
        FRONT = REAR = -1;
    } else {
        printf("Dequeued item is %d\n", A[FRONT]);
        FRONT = FRONT + 1;
    }
}

void assign(int x) {
    MAX = x;
}

void PUSH_DQ(int ITEM) {
    if (FRONT == -1 && REAR == MAX - 1) {
        printf("Deque is FULL\n");
    } else if (FRONT == -1 && REAR == -1) {
        FRONT = REAR = 0;
        A[FRONT] = ITEM;
    } else if (FRONT > 0) {
        FRONT--;
        A[FRONT] = ITEM;
    } else {
        for (int i = REAR; i >= FRONT; i--) {
            A[i + 1] = A[i];
        }
        A[FRONT] = ITEM;
        REAR++;
    }
}

int main() {
    int choice, item;
    printf("Enter the size of the Double-ended queue: ");
    scanf("%d", &MAX);
    while (1) {
        printf("\nMenu:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. INJECT\n");
        printf("4. EJECT\n");
        printf("5. DISPLAY\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                PUSH_DQ(item);
                break;
            case 2:
                POP_DQ();
                break;
            case 3:
                printf("Enter the item to be injected: ");
                scanf("%d", &item);
                INJECT_DQ(item);
                break;
            case 4:
                EJECT_DQO();
                break;
            case 5:
                DISPLAY_DQ();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
