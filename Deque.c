#include <stdio.h>
#define SIZE 20

int q[SIZE]; // Increase the size to match your intended capacity
int f = -1, r = -1;
int item, i;

void push() {
    if (f == 0 && r == SIZE - 1) {
        printf("Deque is full\n");
    } else if (f == -1 && r == -1) {
        f = r = 0;
        printf("Enter the item to push: ");
        scanf("%d", &item);
        q[f] = item;
    } else if (f > 0) {
        f--;
        printf("Enter the item to push: ");
        scanf("%d", &item);
        q[f] = item;
    } else {
        for (i = r; i >= 0; i--) {
            q[i + 1] = q[i];
        }
        r++;
        printf("Enter the item to push: ");
        scanf("%d", &item);
        q[f] = item;
    }
}

void pop() {
    if (f == -1 && r == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Dequeued item is: %d\n", q[f]);
    if (f == r) {
        f = r = -1; // Reset the indices when the deque becomes empty
    } else {
        f++;
    }
}

void inject() {
    if (f == 0 && r == SIZE - 1) {
        printf("Deque is full\n");
    } else if (f == -1 && r == -1) {
        f = r = 0;
        printf("Enter the item to inject: ");
        scanf("%d", &item);
        q[r] = item;
    } else if (r < SIZE - 1) {
        r++;
        printf("Enter the item to inject: ");
        scanf("%d", &item);
        q[r] = item;
    } else {
        for (i = f; i <= r; i++) {
            q[i - 1] = q[i];
        }
        f--;
        printf("Enter the item to inject: ");
        scanf("%d", &item);
        q[r] = item;
    }
}

void eject() {
    if (f == -1 && r == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Dequeued item is: %d\n", q[r]);
    if (f == r) {
        f = r = -1; // Reset the indices when the deque becomes empty
    } else {
        r--;
    }
}

void display() {
    if (f == -1 && r == -1) {
        printf("Deque is empty\n");
        return;
    }

    for (i = f; i <= r; i++) {
        printf("%d\n", q[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Inject\n4. Eject\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                inject();
                break;
            case 4:
                eject();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
  
