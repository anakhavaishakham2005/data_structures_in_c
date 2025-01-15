#include <stdio.h>

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int choice, n;
    while (1) {
        printf("Choose a sorting method:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        printf("Enter the size of the array: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Invalid size. Please enter a positive integer.\n");
            continue;
        }

        int a[n];
        printf("Enter the elements of the array:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        printf("Unsorted array:\n");
        printArray(a, n);

        switch (choice) {
            case 1:
                bubbleSort(a, n);
                printf("Sorted array (Bubble Sort):\n");
                break;
            case 2:
                selectionSort(a, n);
                printf("Sorted array (Selection Sort):\n");
                break;
            case 3:
                insertionSort(a, n);
                printf("Sorted array (Insertion Sort):\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        printArray(a, n);
    }
    return 0;
}
