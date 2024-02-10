#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* link;
}node;

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
        free(top);
        return;
    }
    top = top->link;
    free(temp);
}

void Display()
{
    node* ptr = top;
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    do
    {
        printf("%d",ptr->data);
        printf("\t");
        ptr = ptr->link;
    } while(ptr != NULL);
    printf("\n");
}

int main()
{
    int item,choice;
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    while(1)
    {
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter element to be pushed:\t");
                    scanf("%d",&item);
                    Push(item);
                    break;
            case 2: Pop();
                    break;
            case 3: Display();
                    break;
            case 4: return 0;
            default: printf("\nInvalid choice!\n");
                     break;
        }
    }
    

    return 0;
}
