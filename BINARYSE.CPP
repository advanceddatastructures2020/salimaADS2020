#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct btnode
{
	int value;
	struct btnode *l;
	struct btnode *r;
}*root=NULL, *temp=NULL, *t2, *t1;

void insert();
void create();
void search(struct btnode *t);

void main()
{
	int ch;
	clrscr();
	printf("\n____OPERATIONS____");
	printf("\n1. Insert an element into tree\n");
	printf("\n2. Exit\n");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
			insert();
			break;
			case 2:
			exit(0);
			default:
			printf("Wrong choice, Please enter correct choice");
			break;
		}
	}
	getch();
}

void insert()
{
	create();
	if(root==NULL)
		root=temp;
	else
		search(root);
}

void create()
{
	int data;
	printf("Enter data of node to be inserted: ");
	scanf("%d", &data);
	temp=(struct btnode *)malloc(1* sizeof(struct btnode));
	temp->value=data;
	temp->l=temp->r=NULL;
}

void search(struct btnode *t)
{
	if ((temp->value > t->value) && (t->r != NULL))
		search(t->r);
	else if((temp->value > t->value) && (t->r==NULL))
		t->r=temp;
	else if((temp->value < t->value) && (t->l !=NULL))
		search(t->l);
	else if((temp->value < t->value) && (t->l==NULL))
		t->l=temp;
}

