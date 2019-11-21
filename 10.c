#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *lchild;
	struct tree *rchild;
};

struct tree *pos=NULL;

void display(struct tree *t)
{
	if(t!=NULL)
	{
		printf("%d\t",t->data);
		display(t->lchild);
		display(t->rchild);
	}
}

void create(struct tree *t)
{
	int choice;
	int item;
	struct tree *temp;
	if(t!=NULL)
	{
		printf("Any left node for %d \n1(Yes)/0(No) :",t->data);
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter the element");
			scanf("%d",&item);
			temp=(struct tree *)malloc(sizeof(struct tree));
			temp->data=item;
			temp->rchild=NULL;
			temp->lchild=NULL;
			t->lchild=temp;
			create(temp);
		}
		printf("Any right node for %d \n1(Yes)/0(No) :",t->data);
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter the Element :");
			scanf("%d",&item);
			temp=(struct tree *)malloc(sizeof(struct tree));
			temp->data=item;
			temp->rchild=NULL;
			temp->lchild=NULL;
			t->rchild=temp;
			create(temp);
		}
	}
}


struct tree search(struct tree *t,int key)
{
if(t!=NULL)
{
if(t->data==key)
{
pos=t;
}
else
{
search(t->lchild,key);
search(t->rchild,key);
}
}
}


void insert(struct tree *t,int key,int item)
{
struct tree *temp;
int choice;
search(t,key);
if(pos==NULL)
	printf("Key element  not Found\n");
else
	{
	printf("1-Left Child\t/\t2-Right Child :");
	scanf("%d",&choice);
	if(choice==1)
	{
		if(pos->lchild==NULL)
		{
		temp=(struct tree *)malloc(sizeof(struct tree));
		temp->data=item;
		temp->lchild=NULL;
		temp->rchild=NULL;
		pos->lchild=temp;
		}
	else
	printf("Insertion not Possible\n");
	}
if(choice==2)
{
	if(pos->rchild==NULL)
	{
	temp=(struct tree *)malloc(sizeof(struct tree));
	temp->data=item;
	temp->lchild=NULL;
	temp->rchild=NULL;
	pos->rchild=temp;
	}
	else
	printf("Insertion not Possible\n");
}
}
}



void del(struct tree *t,int key)
{
struct tree *temp;
	if(t!=NULL)
	{
		if(t->lchild!=NULL)
		{
		if(t->lchild->data==key)
		{
		temp=t->lchild;
			if(temp->lchild==NULL&temp->rchild==NULL)
			{
				t->lchild=NULL;
				free(temp);
			}
			else
			printf("Deletion not Possible\n");
		}
		}
	else if(t->rchild!=NULL)
	{
	if(t->rchild->data==key)
		{
		temp=t->rchild;
			if(temp->lchild==NULL&temp->rchild==NULL)
			{
				t->rchild=NULL;
				free(temp);
			}
			else
			printf("Deletion not Possible\n");
		}
		}
		del(t->lchild,key);
		del(t->rchild,key);
}
}
int main()
{
	struct tree *root;
	int c,key,item,k;
	root=(struct tree *)malloc(sizeof(struct tree));
	printf("Enter the Root Node :");
	scanf("%d",&root->data);
	create(root);
	do
	{
	printf("\n*****MENU*****\n1.INSERTION\n2.DELETION\n3.SEARCH\n4.DISPLAY\nEnter Your Choice :");
	scanf("%d",&c);
	if(c==1)
	{
		pos=NULL;
		printf("Enter the element to be Searched : ");
		scanf("%d",&key);
		printf("Enter the element to be inserted : ");
		scanf("%d",&item);
		insert(root,key,item);
	}
	if(c==2)
	{
		printf("Enter the element to be deleted :");
		scanf("%d",&key);
		del(root,key);
	}
	if(c==3)
	{
		pos=NULL;
		printf("Enter the element to be Searched : ");
		scanf("%d",&key);
		search(root,key);
		if(pos==NULL)
		printf("Element not Found\n");
		else
		printf("Element Found\n");
	}
	if(c==4)
	{
	printf("Preorder Display\n");
	display(root);
	}
printf("\nDo you want to continue 1(Yes)/0(No) :");
scanf("%d",&k);
}
while(k==1);
}
