#include <stdio.h>
#define SIZE 20

int cq[SIZE];
int front = -1, rear = -1;

void CQ_Insert(int item)
{
    int next;
    if(front == -1)
    {
        front = rear = 0;
        cq[rear] = item;
    }
    else
    {
        next = (rear +1)%SIZE;
        if(next == front)
        {
            printf("queue  full\n");
        }
        else
        {
            rear = next;
            cq[rear] = item;
        }
    }
}

void CQ_del()
{
    int item;
    if(front == -1)
        printf("que emty\n");
    else
    {
        item = cq[front];
        if(front == rear)
            front = rear = -1;
        else
            front = (front+1)%SIZE;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue empty\n");
        return;
    }
    int i=0;
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", cq[i]);
    }
    printf("\n");
}


int main()
{
    CQ_Insert(1);
    CQ_Insert(5);
    display();
    CQ_del();
    display();
    CQ_del();
    display();
    CQ_del();

    return 0;
}
