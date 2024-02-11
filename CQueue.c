#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


int cq[SIZE];
int front = -1, rear = -1;

void Enque(int data)
{
    if(front == -1)
    {
        front = rear = 0;
        cq[rear] = data;
    } 
    else
    {
        int next = (rear + 1)%SIZE;
        if(front == next)
        {
            printf("Queue overflow\n");
            return;
        }
        rear = next;
        cq[rear] = data;
    }
}

void Deque()
{
    int item;
    if(front == -1)
    {
        printf("Queue underflow\n");
        return;
    }
    else if(front == rear)
    {
        item = cq[front];
        front = rear = -1;
    }
    else
    {
        item = cq[front];
        front = (front + 1)%SIZE;
    }
    printf("Dequeued item: %d\n", item);
}

void Display()
{
    if(front == -1)
    {
        printf("Queue empty\n");
        return;
    }
    else
    {
        int i;
        printf("Queue elements are:\n");
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",cq[i]);
        }
    }
}

int main()
{
    int choice,val;
    printf("1.Enque\n2.Deque\n3.Display\n4.Exit\n");
    while(1)
    {
        printf("Enter ur choice:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter value to be enqued:\t");
                    scanf("%d",&val);
                    Enque(val);
                    break;
            case 2: Deque();
                    break;
            case 3: Display();
                    break;
            case 4: return 0;
            default : printf("Invalid choice!!\n");
                      break;
        }
    }

    return 0;
}
