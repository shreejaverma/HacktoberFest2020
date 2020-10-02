#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *root = NULL;
int count = 0;

void end()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter Data : ");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root = temp;
	}
	else
	{
		struct node *ptr;
		ptr = root;
		while(ptr->link!=NULL)
		{
			ptr = ptr->link;
		}
		ptr->link = temp;
	}
	count++;
	main();
}
void begin()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter Data : ");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root = temp;
	}
	else
	{
		temp->link = root;
		root = temp;
	}
	count++;
	main();
}
void display()
{
	struct node *ptr;
	ptr = root;
	while(ptr->link!=NULL)
	{
		printf("\n%d",ptr->data);
		ptr = ptr->link;
	}
	printf("\n%d",ptr->data);
	main();
}

void addNode()
{
	printf("\nEnter the location : ");
	int loc, i=1;
	scanf("%d",&loc);
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter node data : ");
	scanf("%d",&temp->data);
	temp->link = NULL;
	if(loc>count+1)
	{
		printf("Invalid");
	}
	else if(loc==1)
	{
		
		
		temp->link=root;
		root = temp;
		
	}
	else
	{
		struct node *ptr, *q;
		ptr = root;
		while(i<loc-1)
		{
			ptr = ptr->link;
			i++;
		}
		q = ptr->link;
		ptr->link = temp;
		temp->link = q;
	}
	count++;
	main();
}
void delete_node()
{
	printf("\nEnter the location of node to be deleted : ");
	int loc;
	struct node *temp;
	scanf("%d",&loc);
	if(loc>count)
	{
		printf("Node doen't exist");
	}
	else if(loc==1)
	{
		temp = root;
		root = temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		temp = root;
		struct node *q;
		int i = 1;
		while(i<loc-1)
		{
			temp = temp->link;
			i++;
		}
		q = temp->link;
		temp->link = q->link;
		q->link = NULL;
		free(q);
	}
	count--;
	main();
}
void sort()
{
	struct node *p,*q;
	int temp;
	p = root;
	q = p->link;
	int i;
	for(i=1;i<count;i++)
	{
	
	while(q->link!=NULL)
	{
		if(q->data<p->data)
		{
			temp = p->data;
			p->data = q->data;
			q->data = temp;
			
		}
		q=q->link;
	}
		
		if(q->data<p->data)
		{
			temp = p->data;
			p->data = q->data;
			q->data = temp;
			
		}
		
		
		p=p->link;
		q = p->link;
		
		
    }
	
	main();
}
int main()
{
	int choice;
	
	printf("\n1. Add Node at end\n2. Print Linked List\n3. Add Node at beginning\n4.Delete A Node\n5. Add node at any position\n6.Sort Linked List");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 : end();break;
		case 2 : display();break;
		case 3 : begin();break;
		case 4 : delete_node();break;
		case 5 : addNode();break;
		case 6 : sort();break;
		default : return 0;
	}
	return 0;
}
