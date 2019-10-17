#include <stdio.h>
 
void linear(int a[],int n)
{
  int search,i;
printf("\nEnter the number to be searched :");
scanf("%d",&search);
  for(i=0;i<n;i++)
  {
    if(a[i]==search)
    {
printf("****SUCCESSFUL SEARCH****\n");
printf("%d is present at location %d\n", search,i+1);
    break;
    }
}
  if(i==n)
    printf("Element not found\n");
}

void binary(int a[],int n)
{
int i,l,u,mid,search;
   printf("Enter element to find :");
   scanf("%d",&search);
   l=0;
   u=n-1;
   mid=(l+u)/2;
   while(l<=u) 
   {
      if(a[mid]<search)
         l=mid+1;   
      else if(a[mid]==search)
	   {
	 printf("****SUCCESSFUL SEARCH****\n");
         printf("%d found at location %d\n",search,mid+1);
         break;
      }
      else
         u=mid-1;
         
      mid=(l+u)/2;
   }
   if(l>u)
      printf("Element not found\n"); 
}

int main()
{
	int a[50],i,n,c,ch;
  printf("\nEnter number of elements :");
  scanf("%d",&n);
for (i=0;i<n;i++)
{
	printf("\nEnter %d element :",i+1);
	scanf("%d", &a[i]);
}
do
{
printf("1.LINEAR SEARCH\n2.BINARY SEARCH\n");
printf("Enter your Choice :");
scanf("%d",&c);
switch(c)
{
	case 1:linear(a,n);
	break;
	case 2:binary(a,n);
	break;
	default:printf("Wrong choice");
}
printf("\nDo you want to continue(1 or 0) :");

scanf("%d",&ch);
printf("\n");
}
while(ch==1);
}







