#include<stdio.h>
#include<stdlib.h>
int stack[20];
int top1=-1;
int top2=10;
void push(int item,int x)
{	
	if(x==1)
	{
	  if(top1>=9)
	  printf("Stack is Full");
	   else
	    { 
                top1++;
		stack[top1]=item;
	     }
	 }
	else
	   {
             if(top2>=20)
                printf("Stack is Full");
		
             else
		{	
                  top2++;
		  stack[top2]=item;
		}
	 }

}
void pop(int x)
{
	if(x==1)
	{
	   if(top1==-1)
		printf("Stack is Empty");
	   else
	      {	
		printf("\nPoped item is : %d\n",stack[top1]);
		stack[top1]=stack[top1+1];
		top1--;
	       }
         }
	else
	{
	   if(top2==9)
	   printf("Stack is Empty\n");
	   else
	     {	
		printf("\nPoped item is:%d\n",stack[top2]);
		stack[top2]=stack[top2+1];
		top2--;
	     }
	 }
		
}
void peep(int x)
{
 if(x==1)
   {
	if(top1==-1)
	 printf("Stack is Empty\n");
	else
	 printf("%d",stack[top1]);
  }
 else
  {
  if(top2==-1)
    printf("Stack is Empty\n");
  else
    printf("%d",stack[top2]);
   }
		
}
void main()
{
	int item,x,y;
	while(1)
	{	
		printf("\nChoose The Stack ");
		printf("\nStack 1 or Stack 2: ");
		scanf("%d",&y);
		printf("\n1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit\nEnter the choice: ");
		scanf("%d",&x);
		if(x==1)
		{
			printf("Enter the element ");
			scanf("%d",&item);
			push(item,y);
		}
		else if(x==2)
		{
			pop(y);
		}
		else if(x==3)
		{
			peep(y);
		}
		
		else if(x==4)
		{
			
			if(y==1)
			  {
				for(int i=top1;i>-1;i--)
				   printf("%d\n",stack[i]);
			  }
			else
			  {
			 	for(int i=top1;i>-1;i--)
				   printf("%d\n",stack[i]);	
			  }
		}
		else if(x==4)
		    {
			exit(0);
		    }
	}
}

