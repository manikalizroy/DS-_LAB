#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* link;
}node;
node* head = NULL;
void insert_front(int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    
    if(head==NULL)
    {
        head = (node*)malloc(sizeof(node)); // Initialize head with a dummy node
        head->link = head; 
    }
    node* temp = head->link;
    head->link = newnode;
    newnode->data = data;
    newnode->link = temp;
    
}

void insert_end(int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    
    if (head == NULL) {
        head = (node*)malloc(sizeof(node)); // Initialize head with a dummy node
        head->link = head;  // Pointing to itself to represent an empty list
    }
    
    node* ptr = head->link;
    while(ptr->link != head)
    {
        ptr = ptr->link;
    }
    ptr->link = newnode;
    newnode->data = data;
    newnode->link = head;
}

void insert_at_any(int key,int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    
    if (head == NULL) {
        printf("List is empty, insertion not possible.\n");
        return;
    }
    
    node* ptr = head->link;
    while(ptr->data != key && ptr->link != head)
    {
        ptr = ptr->link;
    }
    if(ptr->data ==key)
    {
        node* temp = ptr->link;
        ptr->link = newnode;
        newnode->data = data;
        newnode->link = temp;
    }
    else
    {
        printf("Key not found, inserion not possible\n");
    }
}

void delete_front()
{
    if (head == NULL || head->link == head) {
        printf("List is empty, deletion not possible.\n");
        return;
    }
    
    node* ptr = head->link;
    node* ptr1 = ptr->link;
    free(ptr);
    head->link = ptr1;
}

void delete_end()
{
    if (head == NULL || head->link == head) {
        printf("List is empty, deletion not possible.\n");
        return;
    }
    
    node* ptr = head->link;
    node* ptr1 = NULL;
    while(ptr->link !=  head)
    {
        ptr1 = ptr;
        ptr = ptr->link;
    }
    free(ptr);
    ptr1->link = head;
}

void delete_at_any(int key)
{
    if (head == NULL || head->link == head) {
        printf("List is empty, deletion not possible.\n");
        return;
    }
    
    node* ptr = head->link;
    node* ptr1 = NULL;
    while(ptr->data != key && ptr->link != head)
    {
        ptr1=ptr;
        ptr = ptr->link;
    }
    if (ptr->data == key) 
    {
        if (ptr == head->link) 
        {
            // If the node to be deleted is the first node
            node* temp = head->link;
            head->link = temp->link;
            free(temp);
        }
        else 
        {
            // If the node to be deleted is not the first node
            ptr1->link = ptr->link;
            free(ptr);
        }
    } 
    else 
    {
        printf("Key not found, deletion not possible.\n");
    }
}

void display()
{
    if (head == NULL || head->link == head) {
        printf("List is empty.\n");
        return;
    }
    
    node* ptr = head->link;
    printf("List items are:\n");
    do 
    {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    } while (ptr != head);
    printf("\n");
    
}

int main()
{
    int choice,val,key;
    printf("1.Insert front\n2.Insert end\n3.Insert any pos\n");
    printf("4.Delete front\n5.Delete end\n6.Delete any pos\n7.Display\n8.Exit\n");
    
    head = (node*)malloc(sizeof(node));
    head->link = head; 

    while(1)
    {
        printf("Enter ur choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter value to be inserted: ");
                    scanf("%d",&val);
                    insert_front(val); break;
            case 2: printf("Enter value to be inserted: ");
                    scanf("%d",&val);
                    insert_end(val); break;    
            case 3: printf("Enter key to be searched:");
                    scanf("%d",&key);
                    printf("Enter value to be inserted: ");
                    scanf("%d",&val);
                    insert_at_any(key,val); break; 
            case 4: delete_front();
                    break;
            case 5: delete_end();
                    break;
            case 6: printf("Enter value to be deleted:");
                    scanf("%d",&val);
                    delete_at_any(val);
                    break;
            case 7: display();
                    break;
            case 8: free(head);
                    return;
            default: printf("Invalid choice, choose again\n");
                     break;
        }
    }

    return 0;
}
