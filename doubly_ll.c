#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}node;
node* head = NULL;

void insert_begin(int item)
{
	node* ptr = (node*)malloc(sizeof(node));
	if (ptr == NULL)
	{
		printf("Memory underflow, node not created\n");
	}
	else
	{
		if (head == NULL)
		{
			ptr->next = NULL;
			ptr->prev = NULL;
			ptr->data = item;
			head = ptr;
		}
		else
		{
			ptr->next = head;
			ptr->prev = NULL;
			ptr->data = item;
			head->prev = ptr;
			head = ptr;
			
		}

	}
}

void insert_end(int item)
{
	node* ptr = (node*)malloc(sizeof(node));
	if (ptr == NULL)
	{
		printf("Memory underflow, node not created\n");
	}
	else
	{
		ptr->data = item;
		ptr->next = NULL;
		if (head == NULL)
		{
			ptr->prev = NULL;
			head = ptr;
		}
		else 
		{
			node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;				
			}
			temp->next = ptr;
			ptr->prev = temp;
		}
	}
}

void insert_anyposition(int key, int item)
{
	node* ptr = (node*)malloc(sizeof(node));
	if (ptr == NULL)
	{
		printf("Memory underflow, node not created\n");
	}
	else
	{
		ptr->data = item;
		if (head == NULL)
		{
			ptr->next = NULL;
			ptr->prev = NULL;
			head = ptr;
		}
		else
		{
			node* ptr1 = NULL;
			node* ptr2 = head;
			while (ptr2 != NULL && ptr2->data != key)
			{
				ptr1 = ptr2;
				ptr2 = ptr2->next;
			}
			if (ptr2 == NULL)
			{
				printf("Key not found, insertion not possible\n");
				free(ptr);
				return;
			}

			ptr->prev = ptr1;
			ptr->next = ptr2->next;
			ptr2->next = ptr;
			if (ptr->next != NULL)
				ptr->next->prev = ptr;
		}
	}
}

void display()
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* ptr = head;
    printf("List items are:\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
	printf("1.Insertion at beginning\n2.Insertion at end\n3.Insertion at any position\n4.Display\n5.Exit\n");
	int choice,item,key;
	while (1)
	{
		printf("Enter ur choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter item: ");
					scanf("%d", &item);
					insert_begin(item);
					break;
			case 2: printf("Enter item: ");
					scanf("%d", &item);
					insert_end(item);
					break;
			case 3: printf("Enter item and key: ");
					scanf("%d %d", &item,&key);
					insert_anyposition(key,item);
					break;
			/*case 4: delete_front();
					break;
			case 5: delete_end();
					break;
			case 6: printf("Enter value to be deleted:");
					scanf("%d", &val);
					delete_at_any(val);
					break; */
			case 7: display();
					break;
			case 8: //free(head);
					return 0; 
			default: printf("Invalid choice, choose again\n");
					 break;
		}
	}

	return 0;
}
