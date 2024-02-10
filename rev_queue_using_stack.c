#include <stdio.h> 
#include <stdlib.h>

void enqueue(int data);
void dequeue();
void Push(int data);
void Pop();
void reverse();
void display();

typedef struct node
{
    int data;
    struct node *link;
}node;

node *front = NULL;
node *rear = NULL;

void enqueue(int data)
{
    node *newnode = (node*)malloc(sizeof(node));
    if((front == NULL) && (rear == NULL))
    {
        front = rear = newnode;
        rear->data = data;
        rear->link = NULL;
    }
    else
    {
        rear->link = newnode;
        newnode->data = data;
        newnode->link = NULL;
        rear = newnode;
    }
}

void dequeue()
{
    node *ptr;
    int n;
    if(front == NULL)
    {
        printf("Empty queue\n");
        return;
    }
    n = front->data;
   // Push(n);
    ptr = front->link;
    free(front);
    front = ptr;
   // printf("Deletd item is %d\n",n);
    return;
}

void display()
{
   node *ptr;
   if((front==NULL)&& (rear==NULL)) 
   {
       printf("Queue is empty\n");
       return;
   }
   printf("The queue is \n");
   ptr=front;
   while(ptr->link != NULL)
   {
       printf("%d\t",ptr->data);
       ptr= ptr->link;
   }
   printf("%d",ptr->data);
   printf("\n");
}   

node* top = NULL;

void Push(int item)
{
    node* newnode = (node*)malloc(sizeof(node));
    if(top == NULL)
    {
        top = newnode;
        top->data = item;
        top->link = NULL;
        return;
    }
    node* ptr = top;
    top = newnode;
    top->link = ptr;
    top->data = item;
    
}

void Pop()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    node* temp = top;
    if(top->link == NULL)
    {
     //   enqueue(temp->data);
        free(temp);
        top = NULL;
        return;
    }
    top = top->link;
    free(temp);
}

void reverse()
{
    while(front != NULL)
    {
        int temp = front->data;
        dequeue();
        Push(temp);
    }
    
    front = rear = NULL;
    while(top!=NULL)
    {
        int temp = top->data;
        Pop();
        enqueue(temp);
    }
    display();
}

void main()
{
    int data, choice;
    printf("1.enqueue \n2.dequeue \n3.display \n4.exit\n5,Reverse\n");
    while(1)
    {
        printf("Enter ur choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nenter the value to be enqued: ");
                    scanf("%d",&data);
                    enqueue(data); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return;
            case 5: reverse(); break;
            default: printf("Invalid choice\n");break;
        }
    }
}
