#include<stdio.h>
#include<string.h>
#include<math.h>
int top=-1;
char s[20];
int isop(char c)
	{
	  if(c=='A'||c=='B'||c=='C'||c=='D'||c=='E'||c=='F'||c=='G'||c=='a'||c=='b'||c=='c'||c=='d'||c=='e'||c=='f'||c=='g')
	     return 1;
	  else
	     return 0;
	 }
void push(char item)
     { 
       if(top>=19)
         { 
           printf("Stack Full");
         }
       else
         {
            top++;
            s[top]=item;
         }
      }
      
char pop()
     {
       
       
        
       char item=s[top];
         top=top-1;
         return item;
        
      } 	 
int isp(char c)
	{
		
		     if(c=='+'||c=='-')
                          {
                            return 2;
                            
                          }
                     else if(c=='*'||c=='/')
                          {
                            return 4;
                            
                          }
                     else if(c=='^')
                          {
                           return 5;
                           
                          }
                     else if(c=='('||c==')')
                          {
                           return 0;
                           
                          }
                    
	}
int icp(char c)
	{
		
		     if(c=='+'||c=='-')
                          {
                            return 1;
                            
                          }
                     else if(c=='*'||c=='/')
                          {
                            return 3;
                            
                          }
                     else if(c=='^')
                          {
                           return 6;
                           
                          }
                     else if(c=='(')
                          {
                           return 9;
                           
                          }
                     else if(c==')')
			return 0;
                    
	}
		        
void ifpf(char e[])
	{
	  int i=0;
	  char token;
          push('#');
	  while(e[i]!='#')
	  	{
	  	  token=e[i];
	  	  if(isop(token)==1)
	  	     printf("%c",token);
	  	  else if(token==')')
	  	     {
	  	       while(s[top]!='(')
	  	            {
	  	               printf("%c",pop());
	  	             }
	  	             pop();
	  	      }
	  	   else
	  	      {
	  	        while(isp(s[top])>=icp(token))
	  	             {
	  	                printf("%c",pop());
	  	             }
                               push(token);
                       }        	  	                             
	  	     i=i+1;
	  	 }
	  while(s[top]!='#')
	      {
	         printf("%c",pop());
	      }	
	                 
	  } 
int eval(char op1,char op2,char item)
	{
		int a,b,c;		
		printf("Enter value of %c :",op1);
                scanf("%d",&a);	
		printf("Enter value of %c :",op2);
                scanf("%d",&b);
		if(item=='+')
			c=a+b;
		else if(item=='-')
			c=a-b;
		else if(item=='*')
			c=a*b;
		else if(item=='/')
			c=a/b;
		else if(item=='^')
			c=a*b;
		return c;
	}					  
int postfix(char p[])
	{
		char item,op1,op2;
		int result;
                int i=0;		
		while(p[i]!='#')
			{
				item=p[i];
				
				if(isop(item)==1)
					push(item);
			         
			        else
			        	{
			        	 	op2=pop();
			        	 	op1=pop();
			        	 	result=eval(op1,op2,item);
			        	
			                        push(result);
			                 }
			       i++;
			   }
			   result=pop();
			   //printf("%c",result); 
                           return result;      	 
	}		   	
				

void main()
	{
	 	
	 	char e[20],p[20];
	 	printf("Enter the Expression : ");
	 	scanf("%s",p);
	 	




	 	int r=postfix(p);
             printf("%d",r);
	}	 
	          

