#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* lchild;
    struct Node* rchild;
}node;

node* Insert(node* root,int item)
{
    if(root== NULL)
    {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = item;
        newnode->lchild = newnode->rchild = NULL;
        root = newnode;
    }
    if(item < root->data)
    {
        root->lchild = Insert(root->lchild,item);
    }
    else if(item > root->data)
    {
        root->rchild = Insert(root->rchild,item);
    }
    return root;
}    
    
void Inorder(node* ptr)
{
    if(ptr!=NULL)
    {
        Inorder(ptr->lchild);
        printf("%d\t",ptr->data);
        Inorder(ptr->rchild);
    }
}

void PreOrder(node* ptr)
{
    if(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        PreOrder(ptr->lchild);
        PreOrder(ptr->rchild);
    }
}

void PostOrder(node* ptr)
{
    if(ptr!=NULL)
    {
        PostOrder(ptr->lchild);
        PostOrder(ptr->rchild);
        printf("%d\t",ptr->data);
    }
}

node* minValueNode(node* root)
{
    node* current = root;
    while(current && current->lchild != NULL)
    {
        current = current->lchild;
    }
    return current;
}

node* Delete(node* root,int key)
{
    if(root == NULL)
    {
        return root;
    }
    if(key < root->data)
        root->lchild = Delete(root->lchild,key);
    else if(key > root->data)
        root->rchild = Delete(root->rchild,key);
    else if(root->data == key)
    {
        if(root->lchild == NULL)
        {
            node* temp = root->rchild;
            free(root);
            return temp;
        }
        if(root->rchild == NULL)
        {
            node* temp = root->lchild;
            free(root);
            return temp;
        }
        
        node* temp = minValueNode(root->rchild);
        root->data = temp->data;
        root->rchild = Delete(root->rchild,temp->data);
    }
    return root;
}

int Countleafnodes(node* root)
{
    if(root == NULL)
        return 0;

    if(root->lchild == NULL && root->rchild == NULL)
        return 1;
        
    return Countleafnodes(root->lchild) + Countleafnodes(root->rchild);    
}


int main()
{
    node* root = NULL;
    int data,choice,key;
    printf("1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Deletion\n6.No. of leafnodes\n");
    while(1)
    {
        printf("Enter ur choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter value:\t");
                    scanf("%d", &data);
                    root = Insert(root,data);
                    break;
            case 2: Inorder(root);
                    printf("\n");
                    break;
            case 3: PreOrder(root);
                    printf("\n");
                    break;
            case 4: PostOrder(root);
                    printf("\n");
                    break;
            case 5: printf("Enter the value to be deleted:\t");
                    scanf("%d", &key);
                    root = Delete(root,key);
                    break;
            case 6: int count = Countleafnodes(root);
                    printf("No. of leafnodes = %d\n",count);
                    break;
            default: printf("Invalid choice!");
                     break;
        }
    }    
}
