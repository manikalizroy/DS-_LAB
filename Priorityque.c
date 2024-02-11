#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


int cq[SIZE];
int front = -1, rear = -1;

struct Queue
{
    int item,priority;
}pq[SIZE];

void Dequeue()
{
    int item;
    if(front == -1)
    {
        printf("Queue underflow\n");
        return;
    }
    else if(front == rear)
    {
        item = pq[front].item;
        front = rear = -1;
    }
    else
    {
        item = pq[front].item;
        front++;
    }
    printf("Dequeued item: %d\n", item);
}

void Enqueue(int item,int priority)
{
    if(rear == SIZE-1)
    {
        printf("Queue overflow\n");
        return;
    }
    else if(front == -1)
    {
        front = rear = 0;
    } 
    else if(rear < SIZE-1)
    {
        int i;
        for(i=rear;i>=front;i--)
        {
            if(pq[i].priority > priority)
                pq[i + 1] = pq[i];
            else
                break;
        }
        rear++;
    }    
    pq[rear].item = item;
    pq[rear].priority = priority;
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
            printf("%d %d",pq[i].item,pq[i].priority);
            printf("\n");
        }
    }
}

int main()
{
    int choice,item,priority;
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while(1)
    {
        printf("Enter ur choice:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter value of item and priority:\t");
                    scanf("%d %d", &item, &priority);
                    Enqueue(item,priority);
                    break;
            case 2: Dequeue();
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

---------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


int cq[SIZE];
int front = -1, rear = -1;

struct Queue
{
    int item,priority;
}pq[SIZE];

void Dequeue()
{
    int item,i,highpr,highprindex;
    if(front == -1)
    {
        printf("Queue underflow\n");
        return;
    }
    else if(front == rear)
    {
        item = pq[front].item;
        front = rear = -1;
    }
    else
    {
        highpr = pq[front].priority;
        highprindex = front;
        for(i = front;i <= rear;i++)
        {
            if(pq[i].priority > highpr)
            {
                highpr = pq[i].priority;
                highprindex = i;
            }
        }
        
        item = pq[highprindex].item;
        for(i = highprindex;i < rear; i++)
        {
            pq[i] = pq[i+1];
        }    
        rear--;    
        
    }
    printf("Dequeued item: %d\n", item);
}

void Enqueue(int item,int priority)
{
    if(rear == SIZE-1)
    {
        printf("Queue overflow\n");
        return;
    }
    else if(front == -1)
    {
        front = rear = 0;
    } 
    else if(rear < SIZE-1)
    {
        int i;
        for(i=rear;i>=front;i--)
        {
            if(pq[i].priority > priority)
                pq[i + 1] = pq[i];
            else
                break;
        }
        rear++;
    }    
    pq[rear].item = item;
    pq[rear].priority = priority;
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
            printf("%d %d",pq[i].item,pq[i].priority);
            printf("\n");
        }
    }
}

int main()
{
    int choice,item,priority;
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while(1)
    {
        printf("Enter ur choice:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter value of item and priority:\t");
                    scanf("%d %d", &item, &priority);
                    Enqueue(item,priority);
                    break;
            case 2: Dequeue();
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
