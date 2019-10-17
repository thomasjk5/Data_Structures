#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[50],item;
int top=-1,top2=-1,n,st[50];
void push(char item)
    {
    top++;
    s[top]=item;
    }
void push2(int it)
    {
        top2++;
        st[top2]=it;
    }
char pop()
{
  top--;
  return s[top+1];
}
int pop2()
{
  top2--;
  return st[top2+1];
}

int isp(char c)
{
 switch(c)
 {
 case '+':
 case '-':
 	return 2;
 case '*':
 case '/':
 	return 4;
 case '^':
 	return 5;
 case '(':
 case '#':
 	return 0;
 }
}
int icp(char c)
{
 switch(c)
 {
 case '+':
 case '-':
 	return 1;
 case '*':
 case '/':
 	return 3;
 case '^':
 	return 6;
 case '(':
 	return 9;
 case ')':
 case '#':
 	return 0;
 }
}
int cal(int x,int y,char opr)
{
 int res;
 switch(opr)
 {
  case '+':
  	res=x+y;
  	break;
  case '-':
  	res=x-y;
  	break;
  case '*':
  	res=x*y;
  	break;
  case '/':
  	res=y/x;
  	break;
  case '^':
      res=1;
      while(x>0)
      {
          res=res*y;
          x--;
      }
  	break;
 }
 return res;
}

void eval(char p[])
{
 int i=0,op1,op2;
 while(p[i]!='\0')
 {
  if(isdigit(p[i]))
  {
    int pp=p[i];
    push2(pp-48);
  }
  else if(isalnum(p[i]))
    {
     int v;
     printf("\nEnter the value of %c:",p[i]);
     scanf("%d",&v);
     push2(v);
    }
  else
   {
    op1=pop2();
    op2=pop2();
    int result=cal(op1,op2,p[i]);
    push2(result);
   }
   i++;
  }
  printf("\n\tResult=%d\n\n",pop2());
}
void intopo(char exp[])
{
 strcat(exp,"#");
 push('#');
 int i=0,j=0;
 char post[50];
 while(exp[i]!='#')
 {
  if(isalnum(exp[i])==1)
  {
   post[j]=pop();
   j++;
  }
  else if(exp[i]==')')
  {
   while(s[top]!='(')
   {
    post[j]=pop();
    j++;
   }
   pop();
  }
  else
  {
   while(isp(s[top])>=icp(exp[i]))
   {
    post[j]=pop();
    j++;
   }
   push(exp[i]);
  }
  i++;
 }
 while(s[top]!='#')
 {
  post[j]=pop();
  j++;
 }
 post[j]='\0';
 printf("Postfix Expression is : %s",post);
 top=-1;
 eval(post);
}
void main()
{
 	char e[50];
 	int opt,end=0;
 	do
    {
 	printf("#####MENU#####\n1.To convert infix to postfix\n2.To evaluate a post fix expression\n3.exit the program\nEnter a option:");
 	scanf("%d",&opt);
 	switch(opt)
 	{
    case 1:
        printf("Enter the infix expression:");
        scanf("%s",&e);
        end=1;
        intopo(e);
        break;
 	case 2:
         printf("Enter the postfix expression:");
 	     scanf("%s",&e);
 	     end=1;
 	     eval(e);
         break;
 	case 3:
 	    end=1;
        break;
    default:
        printf("Invalid option....enter a option given in the menu.\n\n");
        break;
    }
    }while(end!=1);
}
