#include <stdio.h>
#include <stdlib.h>
#define max 100
int stack[max];
int top1=-1;
int top2=max;

void push(int data, int pos)
{
    if(pos==1)
    {
        if(top1 == max-1 || top1+1==top2)
        printf("Overflow condition");
        else
        {
            top1++;
            stack[top1]= data;
        }
    }
    else
    {
        if(top2 == 0 || top2-1==top2)
        printf("Overflow condition");
        else
        {
            top2--;
            stack[top2]= data;
        }
    }
}

int pop(int pos)
{
    int data = -1;
    if(pos==1)
    {
        if(top1==-1)
        printf("Underflow condition");
        else
        {
            data = stack[top1];
            top1--;
        }
    }
    else
    {
        if(top2==max)
        printf("Underflow condition");
        else
        {
            data = stack[top2];
            top2--;
        }
    }


    return data;
}

void pri(int pos)
{
    int i=0;
    if(pos==1)
    {
        for(i=top1;i>=0;i--)
        printf("%d \n",stack[i]);
    }
    else
    {
        for(i=top2;i<max;i++)
        printf("%d \n",stack[i]);
    }

}
void prib()
{
    int i;
    printf("Data in forward\n");
    for(i=top1;i>=0;i--)
        printf("%d \n",stack[i]);
    printf("Data in backward\n");
    for(i=top2;i<max;i++)
        printf("%d \n",stack[i]);
}
int main()
{
    int n=1, data,pos;

    while(n!=0)
    {
        printf("Welcome to double sided stack ADT via Array\n");
        printf("1. To enter a data into stack \n2. To remove the data from stack \n3. To print stack one side \n");
        printf("4. To print stack both sides \n0. To exit \nChoose from the above \n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            {
                printf("Enter the data to be entered \n");
                scanf("%d",&data);
                printf("Enter 1 to insert in front 2 to insert in back");
                scanf("%d",&pos);
                while(n!=0)
                {
                    if(pos==1 ||  pos==2)
                        break;
                    else
                        printf("Invalid input");
                }
                push(data, pos);
            }
            break;
        case 2:
            {
                printf("Enter 1 to pop from front 2 to pop from back");
                scanf("%d",&pos);
                while(n!=0)
                {
                    if(pos==1 ||  pos==2)
                        break;
                    else
                        printf("Invalid input");
                }
                data = pop(pos);
                printf("Removed data is %d \n",data);
            }
            break;
        case 3:
            {
                printf("Enter 1 to print from front 2 to print from back");
                scanf("%d",&pos);
                while(n!=0)
                {
                    if(pos==1 ||  pos==2)
                        break;
                    else
                        printf("Invalid input");
                }
                pri(pos);
            }
            break;
        case 4:
            {
                prib();
            }
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
