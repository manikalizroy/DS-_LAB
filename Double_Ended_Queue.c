#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


int cq[SIZE];
int front = -1, rear = -1;

void Insert_at_Front(int item)
{
    if(front == 0 && rear == SIZE-1)
    {
        printf("Queue overflow\n");
        return;
    }
    else if(front == -1)
    {
        front = rear = 0;
        cq[front] = item;
        return;
    } 
    else if(front > 0)
    {
        front--;
        cq[front] = item;
        return;
    }
    else
    {
        int i;
        for(i = rear; i >= 0; i--)
        {
            cq[i + 1] = cq[i];
        }
        rear++;
        cq[front] = item;
    }
}

void Delete_at_Front()
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
        front++;
    }
    printf("Dequeued item: %d\n", item);
}

void Insert_at_Rear(int item)
{
    if(front == 0 && rear == SIZE-1)
    {
        printf("Queue overflow\n");
        return;
    }
    else if(front == -1)
    {
        front = rear = 0;
        cq[rear] = item;
        return;
    } 
    else if(rear < SIZE-1)
    {
        rear++;
        cq[rear] = item;
    }
    else
    {
        int i;
        for(i = front; i <= SIZE-1;i++)
        {
            cq[i-1] = cq[i];
        }
        front--;
        cq[rear] = item;
    }
}

void Delete_at_Rear()
{
    int item;
    if(rear == -1)
    {
        printf("Queue underflow\n");
        return;
    }
    else if(front == rear)
    {
        item = cq[rear];
        front = rear = -1;
    }
    else
    {
       item =  cq[rear];
       rear--;
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
    printf("1.Inser at Front\n2.Delete at Front\n3.Insert at Rear\n4.Delete at Rear\n5.Display\n6.Exit\n");
    while(1)
    {
        printf("Enter ur choice:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter value to be inserted:\t");
                    scanf("%d",&val);
                    Insert_at_Front(val);
                    break;
            case 2: Delete_at_Front();
                    break;
            case 3: printf("Enter value to be inserted:\t");
                    scanf("%d",&val);
                    Insert_at_Rear(val);
                    break;
            case 4: Delete_at_Rear();
                    break;        
            case 5: Display();
                    break;
            case 6: return 0;
            default : printf("Invalid choice!!\n");
                      break;
        }
    }

    return 0;
}
  
