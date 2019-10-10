#include <stdio.h>
#include <stdlib.h>
#define max 100
int queue[max];
int front=-1;
int rear =-1;

void insert(int data)
{
    if(front==0 && rear==max-1)
        printf("Overflow condition \n");
    else if(front==-1 && rear ==-1)
    {
        front=0;
        rear=0;
        queue[rear]= data;
    }
    else
    {
        rear++;
        queue[rear]=data;
    }

}

int del()
{
    int data = -1;
    if((front==-1 && rear==-1)||front>rear)
    {
        printf("Underflow condition \n");
        return data;
    }
    else if(front<rear)
    {
        data = queue[front];
        queue[front]=0;
        front++;
        return data;
    }
    else if(front==rear)
    {
        data= queue[front];
        queue[front]=0;
        front=-1;
        rear=-1;
        return data;
    }


}

void pri()
{
    int i=0;
    if(front!=-1&&rear!=-1)
    {
        for(i=front;i<=rear;i++)
            printf("%d \n",queue[i]);
    }
    else
        printf("No data present \n");

}
int main()
{
    int n=1, data;

    while(n!=0)
    {
        printf("Welcome to Queue ADT via Array\n");
        printf("1. To enter a data into Queue \n2. To remove the data from Queue \n3. To print Queue \n0. To exit \n");
        printf("Choose from the above \n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            {
                printf("Enter the data to be entered \n");
                scanf("%d",&data);
                insert(data);
            }
            break;
        case 2:
            {
                data = del();
                printf("Removed data is %d \n",data);
            }
            break;
        case 3:
            {
                pri();
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
