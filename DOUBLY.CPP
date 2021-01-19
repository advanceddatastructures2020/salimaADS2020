#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	struct node *next;
	int data;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void display();


void main()
{
	int choice = 0;
	clrscr();
	while(choice != 9)
	{
		printf("\n**********Main Menu*************\n");
		printf("\nChoose one option from the following list...\n");
		printf("\n================================================\n");
		printf("\n1. Insert in beginning\n2. Insert at last\n3. Insert at any random location\n4.Show\n5.Exit\n");
		printf("\nEnter your choice: ");
		scanf("\n%d", &choice);
		switch(choice)
		{
			case 1:
			insertion_beginning();
			break;
			case 2:
			insertion_last();
			break;
			case 3:
			insertion_specified();
			break;
			case 4:
			display();
			break;
			case 5:
			exit(0);
			break;
			default:
			printf("Please Enter Valid Choice...");
		}
	}
	getch();
}

void insertion_beginning()
{
	struct node *ptr;
	int item;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("\nOVERFLOW");
	}
	else
	{
		printf("\nEnter Item Value: ");
		scanf("%d",&item);
		if (head == NULL)
		{
			ptr->next = NULL;
			ptr->prev = NULL;
			ptr->data = item;
			head = ptr;
		}
		else
		{
			ptr->data = item;
			ptr->prev = NULL;
			ptr->next = head;
			head->prev = ptr;
			head = ptr;
		}
		printf("\nNode Inserted\n");
	}
}

void insertion_last()
{
	struct node *ptr, *temp;
	int item;
	ptr = (struct node *) malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("\nOVERFLOW");
	}
	else
	{
		printf("\nEnter value: ");
		scanf("%d", &item);
		ptr->data = item;
		if(head == NULL)
		{
			ptr->next = NULL;
			ptr->prev = NULL;
			head = ptr;
		}
		else
		{
			temp = head;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->prev = temp;
			ptr->next = NULL;
		}
	}
	printf("\nNode inserted\n");
}

void insertion_specified()
{
	struct node *ptr,*temp;
	int item,loc,i;
	ptr = (struct node *)malloc(sizeof (struct node));
	if (ptr == NULL)
	{
		printf("\n OVERFLOW");
	}
	else
	{
		temp = head;
		printf("Enter the location: ");
		scanf("%d",&loc);
		for(i=0;i<loc;i++)
		{
			temp = temp->next;
			if(temp == NULL)
			{
				printf("\n There are less than %d elementd",loc);
				return;
			}
		}
		printf("Enter value: ");
		scanf("%d",&item);
		ptr->data = item;
		ptr->next = temp->next;
		ptr->prev = temp;
		temp->next = ptr;
		temp->next->prev=ptr;
		printf("\nNode inserted: \n");
	}
}
void display()
{
	struct node *ptr;
	printf("\n Printing values...\n");
	ptr = head;
	while(ptr != NULL)
	{
		printf("%d\n",ptr->data);
		ptr = ptr->next;
	}
}
