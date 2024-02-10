#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    char data;
    struct Node* prev;
    struct Node* next;
}node;

node* head = NULL;

void Insert(char item)
{
    node* newnode = (node*)malloc(sizeof(node));
    if(head == NULL)
    {
        head = newnode;
        head->data = item;
        head->next = NULL;
        head->prev = NULL;
    }
    node* ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = ptr;
}

bool isPal()
{
    node* start = head;
    node* end = head;
    while(end->next != NULL)
    {
        end = end->next;
    }
    while(start != end)
    {
        if(start->data != end->data)
        {
           return false; 
        }
        start = start->next;
        end = end->prev;
        
        if(start == end)
            break;
    }
    return true;
}

int main()
{
    char str[10];
    int i;
    char item;
    printf("Enter a string:\n");
    scanf("%s",str);
    for(i=0; str[i]!= '\0';i++)
    {
        item = str[i];
        Insert(item);
    }
    if(isPal())
        printf("The string is a palindrome\n");
    else
        printf("The string is not a palindrome\n");

    return 0;
}
