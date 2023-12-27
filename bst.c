// Binary search tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node* rchild;
    struct node* lchild;
}node;

node *root = NULL;
node *ptr;
node *ptr1;
bool flag = false;

void insert(int item)
{
    ptr = root;
    ptr1 = NULL;
    
    while (ptr != NULL) 
    {
        ptr1 = ptr;
        if (item < ptr->data)
            ptr = ptr->lchild;
        else if(item > ptr->data)
            ptr = ptr->rchild;
        else
            return;  // item already exists
    }
    
    
    node *newnode = (struct node*)malloc(sizeof(node));
    newnode->data = item;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    
    if (ptr1 == NULL) 
    {    // or you can check root == NULL
        root = newnode;
        return;
    }
    

    if(item < ptr1->data)
        ptr1->lchild = newnode;
    else  
        ptr1->rchild = newnode;
    
}

void search(int item)
{
    ptr = root;
    
    while(ptr!=NULL && flag == false)
    {
        if(item < ptr->data)
        {
            ptr1 = ptr;
            ptr=ptr->lchild;
        }
        else if(item > ptr->data)
        {
            ptr1 = ptr;
            ptr=ptr->rchild;
        }
        else
            if(item == ptr->data)
                flag = true;
    }
    if(flag == true)
        printf("Item found\n");
    else
        printf("Item does not exist\n");
}

node* succ(node* ptr);


void delete(int item)
{
    ptr = root;
    ptr1 = NULL;
    flag = false;  // Reset flag

    while(ptr!=NULL && flag == false)
    {
        if(item < ptr->data)
        {
            ptr1 = ptr;
            ptr=ptr->lchild;
        }
        else if(item > ptr->data)
        {
            ptr1 = ptr;
            ptr=ptr->rchild;
        }
        else
            if(item == ptr->data)
                flag = true;
    }
    if(flag == false)
    {
        printf("Item does not exists\n");
        return;
    }
    
    /*Deciding deletion case*/
    int del_case;
    if(ptr->lchild == NULL && ptr->rchild == NULL)
        del_case = 1;
    else
    {
        if(ptr->lchild != NULL && ptr->rchild != NULL)  
            del_case = 2;
        else
            del_case = 3;
    }
    
    if(del_case == 1)  //no child
    {
        if(ptr1->lchild == ptr)
            ptr1->lchild = NULL;
        else
            ptr1->rchild = NULL; 
        free(ptr);    
    }
    if(del_case == 2) //both child
    {
        int item1;
        ptr1=succ(ptr);
        item1 = ptr1->data;
        delete(item1);
        ptr->data = item1;
    }
    
    if(del_case == 3) // one child
    {
        if(ptr1->lchild == ptr)
        {
            if(ptr->lchild == NULL)
                ptr1->lchild = ptr->rchild;
            else
                ptr1->lchild = ptr->lchild;
        }
        else
            if(ptr1->rchild == ptr)
            {
                if(ptr->lchild == NULL)
                    ptr1->lchild = ptr->rchild;
                else
                    ptr1->lchild = ptr->lchild;
            }
            
        free(ptr);    
    }
    
}

node* succ(node* ptr)
{
    ptr1 = ptr->rchild;
    if(ptr1 !=NULL)
        while(ptr1->lchild != NULL)
            ptr1 = ptr1->lchild;
    return ptr1;        
}

int main()
{
    int choice,data;
    printf("1.Insertion\n2.Deletion\n3.Search\n4.Exit\n");
    while(1)
    {
        printf("enter ur choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter the no. to be inserted: ");
                    scanf("%d",&data);
                    insert(data); break;
            case 2: printf("enter the no. to be deleted: ");
                    scanf("%d",&data);
                    delete(data); break;   
            case 3: printf("enter the no. to be searched: ");
                    scanf("%d",&data);
                    search(data); break; 
            case 4: printf("Exiting the program.\n");
                    return 0;        
            default: printf("invalid choice\n");
                     break;
        }
    }
    return 0;
}
