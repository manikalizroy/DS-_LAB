#include <stdio.h>
#include <stdlib.h>

int count = 0;

typedef struct Node
{
    int data;
    struct Node* link;
}node;

node* head = NULL;

void insert_begin(int x)
{
    node* newnode = (node*)malloc(sizeof(node));
    count++;
    if(head==NULL)
    {
        head = newnode;
        head->data = x;
        head->link = NULL;
        return;
    }
    newnode->data =x;
    newnode->link = head;
    head = newnode;
}

void insert_end(int x)
{
    node* newnode = (node*)malloc(sizeof(node));
    count++;
    if(head==NULL)
    {
        head = newnode;
        head->data = x;
        head->link = NULL;
        return;
    }
    node* ptr = head;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = newnode;
    newnode->data = x;
    newnode->link = NULL;
}

void Insert_any_postion(int x,int pos)
{
    node* newnode = (node*)malloc(sizeof(node));
    count++;
    if(pos == 1)
    {
        newnode->data = x;
        newnode->link = head;
        head = newnode;        
        return;
    }
    node* ptr = head;
    node* temp = NULL;
    int i;
    for(i = 0;i<pos && ptr != NULL;i++)
    {
        temp = ptr;
        ptr = ptr->link;
    }
    if(ptr == NULL && i<pos)
    {
        printf("Invalid position! Insertion not possible\n");
        return;
    }
    newnode->link = ptr;
    newnode->data = x;
    temp->link = newnode;
}

void delete_beginning()
{
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }
    if (head->link == NULL) { // Only one element in the list
        free(head);
        head = NULL;
        count--;
        return;
    }
    node* ptr = head->link;
    free(head);
    head = ptr;
    count--;
}

void Delete_from_end()
{
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }
    node* ptr = head->link;
    node* temp;
    while(ptr->link!=NULL)
    {
        temp = ptr;
        ptr = ptr->link;
    }
    temp->link = NULL;
    free(ptr);
    count--;
}

void Delete_from_anyposition(int pos)
{
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }
    node* ptr = head;
    node* temp = NULL;
    int i = 1;
    if(pos == 1)
    {
        head = ptr->link;
        free(ptr);
        count--;
        return;
    }
    while(ptr != NULL && i<pos)
    {
        temp = ptr;
        ptr=ptr->link;
        i++;
    }
    if(ptr == NULL)
    {
        printf("Invalid position! Deletion not possible\n");
        return;
    }
    temp->link = ptr->link;
    free(ptr);
    count--;
}

void Display()
{
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }
    printf("No.of elements = %d\n",count);
    node* ptr = head;
    printf("Elements are:\n");
    while(ptr != NULL)
    {
        printf("%d",ptr->data);
        printf("\n");
        ptr= ptr->link;
    }
}

void PrimeNum()
{
    node* ptr = head;
    int i,c=0;
    printf("Prime no.s are:\n");
    while(ptr != NULL)
    {
        int n = ptr->data;
        int flag = 0;
        if (n <= 1) 
        {
            ptr = ptr->link;
            continue; // Skip if the number is less than or equal to 1
        }
        for(i=2;i<=n/2;i++)
        {
            if(n%i == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            printf("%d\n",n);
            c++;
        }
        ptr = ptr->link;
    }
    printf("The no. of prime no.s = %d\n",c);
}

int main()
{
    printf("1.Insert at beginning\n2.Insert at end\n3.Insert at any position\n4.Prime numbers\n");
    printf("5.Delete from beginning\n6.Delete from end\n7.Delete rom any position\n8.Display\n9.Exit\n");
    
    int choice,data,pos;
    while(1)
    {
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter value to insert:\t");
                    scanf("%d",&data);
                    insert_begin(data);
                    break;
            case 2: printf("Enter value to insert:\t");
                    scanf("%d",&data);
                    insert_end(data);
                    break; 
            case 3: printf("Enter value to insert and position:\t");
                    scanf("%d %d",&data,&pos);
                    Insert_any_postion(data,pos);
                    break; 
            case 4: PrimeNum();
                    break;
            case 5: delete_beginning();
                    break;
            case 6: Delete_from_end();
                    break;
            case 7: printf("Enter position:\t");
                    scanf("%d",&pos);
                    Delete_from_anyposition(pos);
                    break;
            case 8: Display();
                    break;
            case 9: printf("Exiting...\n");
                    return;        
            default: printf("Invalid choice! Choose again!!\n\n");
                     break;
        }
    }    
    return 0;
}
