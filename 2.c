#include<stdio.h>
#include<stdlib.h>
int top=-1;

void push(int s[],int n,int item)
     { 
       if(top>=n-1)
         { 
           printf("Stack Full");
         }
       else
         {
            top++;
            s[top]=item;
         }
      }
int pop(int s[],int item)
     {
       if(top<0)
        {
         printf("Stack Empty");
        }
       else
        {
         item=s[top];
         top=top-1;
         return item;
        }
      } 
int peep(int s[])
     {
       return s[top];
     }
            
void main()
{ int s[10],d,n,i,c,item;
   printf("Enter the number of elements :");
   scanf("%d",&n);

   while(1)
   { printf("\n***MENU***");
     printf("\n1.Push");
     printf("\n2.Pop");
     printf("\n3.Peep");
     printf("\n4.Display");
     printf("\n5.Exit");
     printf("\nEnter your Choice :");
     scanf("%d",&c);
    
     if(c==1)
       {
           printf("\nEnter the element :");
	   
	   scanf("%d",&item);
		   push(s,n,item);
	      	  
        }
     else if(c==2)
       { 
	   d=pop(s,item);
	   printf("Popped Element is %d",d);
        }
     else if(c==3)
        {

          int t=peep(s);   
          printf("\n Top most Element is :%d",t);     
        }
     else if(c==4)
        {
            printf("\nThe stack is :\n");
             
             for(i=top;i>=0;i--)
	        {
                   printf("%d \n",s[i]); 
                } 
        }
      else if(c==5)
         { 
            exit(0);

          }
       printf("\n");

     }        



}
