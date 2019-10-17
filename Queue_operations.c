#include<stdio.h>
#include<stdlib.h>
int q[50],cq[50],dq[50],n,front=0,rear=0,cfront=0,crear=0,dfront=0,drear=0,cc=0,dc=0;
void display(int fr,int rr,int arr[])
{
    printf("\nElements are: "); 
    if (rr >= fr) 
    { 
        for (int i = fr; i <= rr; i++) 
            printf("%d ",arr[i]); 
    } 
    else
    { 
        for (int i = fr; i <=n; i++) 
            printf("%d ", arr[i]); 
  
        for (int i = 1; i <= rr; i++) 
            printf("%d ", arr[i]); 
    } 
} 
void qinsert()
{
    int item;
    if(rear==n)
        printf("\n\t!!!!Queue is full!!!!\n");
    else
    {
        printf("Enter a item:");
        scanf("%d",&item);
        if(front==0&&rear==0)
            front++;
        rear++;
        q[rear]=item;
    }
}
void qdelete()
{
    int item;
    if(front==0&&rear==0)
        printf("\n\t!!!!Queue is empty!!!!\n");
    else
    {
        item=q[front];
        if(front==rear)
        {
            front=0;
            rear=0;
        }
        else
            front++;
        printf("\n\titem:%d\n",item);
    }
}
void cqinsert()
{
    int item;
    if(cfront==(crear%n)+1)
        printf("\n\t!!!!Queue is full!!!!\n");
    else
    {
        printf("Enter a item:");
        scanf("%d",&item);
        if(cfront==0&&crear==0)
            cfront++;
        crear=(crear%n)+1;
        cq[crear]=item;
    	cc++;
    }
}
void cqdelete()
{
    int item;
    if(cfront==0&&crear==0)
        printf("\n\t!!!!Stack is empty!!!!\n");
    else
    {
        item=cq[cfront];
        if(cfront==crear)
        {
            cfront=0;
            crear=0;
        }
        else if(cfront==n)
            cfront=1;
        else
            cfront++;
        printf("\n\tItem:%d\n",item);
    	cc--;
    }
}

void dqinsertrear()
{
    int item;
    if(dfront==(drear%n)+1)
        printf("\n\t!!!!Queue is full!!!!\n");
    else
    {
        printf("Enter a item:");
        scanf("%d",&item);
        if(dfront==0&&drear==0)
            dfront++;
        drear=(drear%n)+1;
        dq[drear]=item;
    	dc++;
    }
}
void dqinsertfront()
{
    int item;
    if(dfront==(drear%n)+1)
        printf("\n\t!!!!Queue is full!!!!\n");
    else
    {
        printf("Enter a item:");
        scanf("%d",&item);
         if(dfront==0&&drear==0)
        {
         dfront=1;
         drear=1;
        }
        else if(dfront==1)
            dfront=n;
        else
            dfront--;
        dq[dfront]=item;
    dc++;
    }
}
void dqdeletefront()
{
    int item;
    if(dfront==0&&drear==0)
        printf("\n\t!!!!Queue is empty!!!!\n");
    else
    {
        item=dq[dfront];
        if(dfront==drear)
        {
            dfront=0;
            drear=0;
        }
        else if(dfront==n)
            dfront=1;
        else
            dfront++;
        printf("\n\tItem:%d\n",item);
    	dc--;
    }
}
void dqdeleterear()
{
     int item;
    if(dfront==0&&drear==0)
        printf("\n\t!!!!Queue is empty!!!!\n");
    else
    {
        item=dq[drear];
        if(dfront==drear)
        {
            dfront=0;
            drear=0;
        }
        else if(drear==1)
            drear=n;
        else
            drear--;
    printf("\n\tItem:%d\n",item);
    dc--;
    }
}
void main()
{
    int op,i;
    printf("Enter the size of queue:");
    scanf("%d",&n);
    do
    {
        printf("\n\n#####MENU#####\n1.Linear queue\n2.Circular queue\n3.Dequeue\n4.Exit\n\nEnter an option:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            do
            {
                printf("\n#####LINAER QUEUE#####\n1.Insertion\n2.Deletion\n3.Display\n4.Go back to previous menu\n\nEnter an option:");
                scanf("%d",&i);
                if(i==1)
                {
                    qinsert();
                }
                else if(i==2)
                {
                    qdelete();
                }
                else if(i==3)
                {
                
   		 if (front==0)  
  		      printf("\n\t!!!!Stack is empty!!!!\n"); 
    		 else
                	display(front,rear,q);
                
                }
                else if(i!=4)
                    printf("\n\t!!!!Invalid option!!!!\n");
            }while(i!=4);
            break;
        case 2:
            do
            {
            int a;
            printf("\n#####CIRCULAR QUEUE#####\n1.Insertion\n2.Deletion\n3.Display\n4.Go back to previous menu\nEnter an option:");
                scanf("%d",&i);
                if(i==1)
                {

                    cqinsert();
                }
                else if(i==2)
                {
                    cqdelete();
                }
                else if(i==3)
                {	
   		 if (cc==0)  
  		      printf("\n\t!!!!Stack is empty!!!!\n"); 
    		 else
                	display(cfront,crear,cq);
                
                }
                else if(i!=4)
                    printf("\n!!!!Invalid option!!!!\n");
            }while(i!=4);
            break;
        case 3:
            do
            {
            int a;
            printf("\n#####DOUBLE ENDED QUEUE#####\n1.Insertion at front\n2.Insertion at rear\n3.Deletion at front\n4.Deletion at rear\n5.Display\n6.Go back to previous menu\n\nEnter an option:");
                scanf("%d",&i);
                if(i==1)
                {
                    dqinsertfront();
                }
                else if(i==2)
                {
                    dqinsertrear();
                }
                 else if(i==3)
                {
                    dqdeletefront();
                }
                 else if(i==4)
                {
                    dqdeleterear();
                }
                else if(i==5)
                {
                	
   		 if (dc==0)  
  		      printf("\n!!!!Queue is Empty!!!!"); 
    		 else
                	display(dfront,drear,dq);
                
                }
                else if(i!=6)
                    printf("\n!!!!Invalid option!!!!\n");
            }while(i!=6);
            break;
        case 4:
                exit(0);

    }
}while(1);
}
