#include <stdio.h>
#define size 20

int f = -1, r = -1,i; // Initialize front and rear
struct pq
{
    int item, priority;
} q[size]; // Use the 'size' constant here

void enque(int item, int priority) // Pass 'item' and 'priority' as arguments
{
    if (f == 0 && r == size - 1)
    {
        printf("Queue is full\n");
    }
    else if (f == -1)
    {
        f = r = 0;
        q[f].item = item;
        q[f].priority = priority;
    }
    else if (r == size - 1)
    {
        for (int i = f; i < r; i++)
            q[i - 1] = q[i];
        f -= 1;
        r -= 1;
        for (int i = r; i > f; i--) // Check priority in descending order
        {
            if (q[i].priority < priority)
                break;
        }
        int loc = i + 1;
        for (int i = r; i >= loc; i--) // Adjust 'loc' calculation
        {
            q[i + 1] = q[i];
        }
        q[loc].item = item;
        q[loc].priority = priority;
        r = r + 1;
    }
    else
    {
        for (int i = r; i >= f; i--) // Check priority in descending order
        {
            if (q[i].priority < priority)
            {
                break;
            }
        }
        int loc = i + 1;
        for (int i = r; i >= loc; i--) // Adjust 'loc' calculation
        {
            q[i + 1] = q[i];
        }
        q[loc].item = item;
        q[loc].priority = priority;
        r += 1;
    }
}

void deque()
{
    if (f == -1 && r == -1)
    {
        printf("Priority queue is empty\n");
    }
    else
    {
        printf("Dequeued item is %d\n", q[f].item);
        for (int i = f; i < r; i++) // Shift elements to the left
        {
            q[i] = q[i + 1];
        }
        r--; // Decrement rear
        if (r == -1)
        {
            f = -1; // Reset front if queue is empty
        }
    }
}

void display()
{
    if (f == -1)
    {
        printf("Priority queue is empty\n");
    }
    else
    {
        for (int i = f; i <= r; i++) // Include 'r' in the loop
        {
            printf("%d\n", q[i].item);
        }
    }
}

int main()
{
    int choice;
    

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int item, priority;
            printf("Enter item and priority: ");
            scanf("%d %d", &item, &priority);
            enque(item, priority);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0; // You should include a graceful exit
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
