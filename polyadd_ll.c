POLYNOMIAL ADD(LL)
-------------------------------------
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int coeff;
  int ex;
  struct node *link;
};

struct node* insert(struct node *head,int coeff,int ex)
{
  struct node *temp;
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->coeff=coeff;
  newnode->ex=ex;
  newnode->link=NULL;
  
  if(head==NULL || ex > head->ex)
  {
    newnode->link=head;
    head=newnode;
  }
  else
  {
    temp=head;
    while(temp->link!=NULL && temp->link->ex>=ex)
    {
      temp=temp->link;
    }
     newnode->link=temp->link;
     temp->link=newnode;
  }
  return head;
}

struct node* create(struct node *head)
{
  int n,i;
  int coeff;
  int ex;
  
  printf("Enter the number of terms: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Coefficient of term %d: " ,i+1);
    scanf("%d",&coeff);
    printf("Exponent of term %d: " ,i+1);
    scanf("%d",&ex);
    head=insert(head,coeff,ex);
  }
  return head;
}

void print(struct node *head)
{
  if(head==NULL)
  {
    printf("No polynomial\n");
  }
  else
  {
    struct node *ptr=head;
    while(ptr!=NULL)
    {
      printf("(%dx^%d)",ptr->coeff,ptr->ex);
      ptr=ptr->link;
      if(ptr!=NULL)
      {
        printf(" + ");
      }
      else
      {
        printf("\n");
      }
    }
  }
}

void add(struct node *head1,struct node *head2)
{
   struct node *ptr1=head1;
   struct node *ptr2=head2;
   struct node *head3=NULL;
   
   while(ptr1!=NULL && ptr2!=NULL)
   {
     if(ptr1->ex==ptr2->ex)
     {
       head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->ex);
       ptr1=ptr1->link;
       ptr2=ptr2->link;
     }
     else if(ptr1->ex>ptr2->ex)
     {
        head3=insert(head3,ptr1->coeff,ptr1->ex);
        ptr1=ptr1->link;
     }
     else if(ptr1->ex<ptr2->ex)
     {
       head3=insert(head3,ptr2->coeff,ptr2->ex);
       ptr2=ptr2->link;
     }
   }
   while(ptr1!=NULL)
   {
     head3=insert(head3,ptr1->coeff,ptr1->ex);
     ptr1=ptr1->link;
   }
   while(ptr2!=NULL)
   {
     head3=insert(head3,ptr2->coeff,ptr2->ex);
     ptr2=ptr2->link;
   }
  printf("Added polynomial is\n");
  print(head3);
}

void main()
{
  struct node *head1=NULL;
  struct node *head2=NULL;
  printf("Enter the first polynomial\n ");
  head1=create(head1);
  printf("Enter second polynomial\n");
  head2=create(head2);
  
  add(head1,head2);
}


--------------------------------------------------------------------------------------------------
  //SELF CODE
  #include <stdio.h>
#include <stdlib.h>

typedef struct Poly
{
    int coeff;
    int expo;
    struct Poly* link;
}poly;

//poly* head3 = NULL; 


poly* insert(poly** head, int coeff, int expo)
{
    poly* temp = *head;
    poly* newnode = (poly*)malloc(sizeof(poly));
    newnode->coeff = coeff;
    newnode->expo = expo;
    newnode->link = NULL;
    if(*head == NULL || expo > (*head)->expo)
    {
        newnode->link = *head;
        *head = newnode;
    }
    else
    {
        while(temp->link != NULL && temp->link->expo >= newnode->expo)
        {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
    return *head;
}

void Create(poly** head)
{
    int n,i,coeff,expo;
    printf("Enter no. of terms:\t");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Enter coefficient of term%d:",i);
        scanf("%d",&coeff);
        printf("Enter exponent of term%d:",i);
        scanf("%d",&expo);
        *head = insert(head,coeff,expo);
    }
}

int display(poly* head)
{
    poly* temp = head;
    if(head == NULL)
    {
        printf("No terms present\n");
        return 0;
    }
    printf("Terms are:\n");
    while(temp != NULL)
    {
        printf("%dx^%d",temp->coeff,temp->expo);
        temp = temp->link;
        if(temp != NULL)
        {
            printf("+");
        }
        else
        {
            printf("\n");
        }
    }
}


poly* addpoly(poly* head1,poly* head2)
{
    poly* ptr1 = head1;
    poly* ptr2 = head2;
    poly* head3 = NULL;
    
    while(ptr1 != NULL && ptr2!= NULL)
    {
        if(ptr1->expo == ptr2->expo)
        {
            head3 = insert(&head3,ptr1->coeff + ptr2->coeff,ptr2->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            head3 = insert(&head3,ptr1->coeff,ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3 = insert(&head3,ptr2->coeff,ptr2->expo);
            ptr2 = ptr2->link;
        } 
    }
    
    while(ptr1 != NULL)
    {
        head3 = insert(&head3,ptr1->coeff,ptr1->expo);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL)
    {
        head3 = insert(&head3,ptr2->coeff,ptr2->expo);
        ptr2 = ptr2->link;
    }
    
    printf("Added polynomial = \n");
    display(head3);
}

int main()
{
    poly* head1 = NULL; 
    poly* head2 = NULL;
    
    printf("First polynomial:\n");
    Create(&head1);
    printf("Second polynomial:\n");
    Create(&head2);
    addpoly(head1,head2);
    return 0;
}
