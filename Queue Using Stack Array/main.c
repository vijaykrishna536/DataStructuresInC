#include <stdio.h>
#include <stdlib.h>
#define max 100
int stack1[max];
int stack2[max];
int top1=-1;
int top=-1;

void push(int data)
{
    if(top == max-1)
        printf("Overflow condition");
    else
    {
        top++;
        stack1[top]= data;
    }

}

void update()
{

    for(top;top>=0;top--)
    {
        top1++;
        stack2[top1]=stack1[top];
        stack1[top]=0;

    }


}

int pop()
{
    int data = -1;

    if(top1==-1&&top==-1)
        printf("Underflow condition");
    else if(top1==-1&& top!=-1)
    {
        update();
        data = stack2[top1];
        top1--;
    }
    else if(top1!=-1)
    {
        data = stack2[top1];
        top1--;
    }

    return data;
}

void search(data)
{
    int i,k=0;
    if(top==-1&& top1!=-1)
    {
        for(i=0;i<top1;i++)
        {
        if(stack2[i]==data)
        {
            printf("Found the number\n");
            k++;
            break;
        }

    }
    }
    else if(top!=-1&& top1==-1)
    {
        for(i=0;i<top;i++)
    {
        if(stack1[i]==data)
        {
            printf("Found the number\n");
            k++;
            break;
        }

    }
    }
    else if(top!=-1&& top1!=-1)
    {
        for(i=0;i<top1;i++)
        {
        if(stack2[i]==data)
        {
            printf("Found the number \n");
            k++;
            break;
        }
        }
        for(i=0;i<top;i++)
        {
            if(stack1[i]==data)
        {
            printf("Found the number \n");
            k++;
            break;
        }
        }


    }

    if(k==0)
        printf("Sorry mate number not found \n");

}


void pri()
{
    int i=0;
    if(top==-1&&top1==-1)
        printf("Empty Queue\n");
    else if(top==-1&& top1!=-1)
    {
        for(i=0;i<=top1;i++)
            printf("%d \n",stack2[i]);
    }
    else if(top!=-1&& top1==-1)
    {
        for(i=top;i>=0;i--)
            printf("%d \n",stack1[i]);
    }
    else if(top!=-1&& top1!=-1)
    {
        for(i=0;i<=top1;i++)
            printf("%d \n",stack2[i]);
        for(i=top;i>=0;i--)
            printf("%d \n",stack1[i]);
    }

}
int main()
{
    int n=1, data;

    while(n!=0)
    {
        printf("Welcome to implementation of queue using stack ADT via Array\n");
        printf("1. To enter a data into Queue \n2. To remove the data from Queue \n3. To print Queue \n");
        printf("4. To search data \n0. To exit \nChoose from the above \n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            {
                printf("Enter the data to be entered \n");
                scanf("%d",&data);
                push(data);
            }
            break;
        case 2:
            {
                data = pop();
                printf("Removed data is %d \n",data);
            }
            break;
        case 3:
            {
                pri();
            }
            break;
        case 4:
            {
                printf("Enter the data to be searched \n");
                scanf("%d",&data);
                search(data);
            }
            break;
        case 0:
            {
                printf("See ya all soon homies");
            }
            break;
        default:
            printf("Enter a valid option \n");
            break;
        }


    }

    return 0;
}
