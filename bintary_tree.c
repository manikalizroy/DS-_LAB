#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* lchild;
    struct Node* rchild;
}node;

void BuildTree(node* ptr,int data)
{
    node *LC,*RC;
    int left,right;
    char opt;
    if(ptr!=NULL)
    {
        ptr->data = data;
        printf("Do the node have a left child(y/n)?\n");
        scanf(" %c", &opt);
        if(opt == 'y' || opt == 'Y')
        {
            LC = (node*)malloc(sizeof(node));
            printf("Enter data:\t");
            scanf("%d", &left);
            ptr->lchild = LC;
            BuildTree(LC,left);
        }
        else
        {
            ptr->lchild = NULL;
        } 
        
        printf("Do the node have a right child(y/n)?\n");
        scanf(" %c", &opt);
        if(opt == 'y' || opt == 'Y')
        {
            RC = (node*)malloc(sizeof(node));
            printf("Enter data:\t");
            scanf("%d", &right);
            ptr->rchild = RC;
            BuildTree(RC,right);
        }
        else
        {
            ptr->rchild = NULL;
        } 
    }
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

node* Deletion(node* root,int key)
{
    if(root == NULL)
        return root;
    if(root->data == key && root->lchild == NULL && root->rchild == NULL)
    {
        free(root);
        return NULL;
    }
    
    if(root->lchild != NULL)
        root->lchild = Deletion(root->lchild,key);
    if(root->rchild != NULL)
        root->rchild = Deletion(root->rchild,key); 
        
    if(root->data == key)
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
        root->rchild = Deletion(root->rchild,temp->data);
    }
    return root;
}



int main()
{
    node* root = NULL;
    int data,choice,key;
    printf("1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Deletion\n");
    while(1)
    {
        printf("Enter ur choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter value:\t");
                    scanf("%d",&data);
                    node* newnode = (node*)malloc(sizeof(node));
                    if(root == NULL)
                    {
                        root = newnode;
                    }
                    BuildTree(root,data);
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
                    Deletion(root,key);
                    break;
            default: printf("Invalid choice!");
                     break;
        }
    }    
}
