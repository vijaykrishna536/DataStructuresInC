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

int del(int end)
{
    int data = -1;
    if((front==-1 && rear==-1)||front>rear)
    {
        printf("Underflow condition \n");
        return data;
    }
    else if(end==1)
    {
        if(front<rear)
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
    else if(end==2)
    {
        if(front<rear)
        {
            data = queue[rear];
            queue[rear]=0;
            rear--;
            return data;
        }
        else if(front==rear)
        {
            data= queue[rear];
            queue[rear]=0;
            front=-1;
            rear=-1;
            return data;
        }
    }


}

void search(int data)
{
    int k=0,i;
    for(i=front;i<=rear;i++)
    {
        if(queue[i]==data)
        {
            k++;
            printf("Data found at %d \n",i);
            break;
        }
    }
    if(k==0)
        printf("Data not found\n");

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
    int n=1, data,e;

    while(n!=0)
    {
        printf("Welcome to Input Restricted Double Ended Queue ADT via Array\n");
        printf("1. To enter a data into IRDE Queue \n2. To remove the data from IRDE Queue \n3. To print IRDE Queue \n");
        printf("4. To search the IRDE Queue \n0. To exit \nChoose from the above \n");
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
                int s=0;
                while(s==0)
                {
                    printf("Enter the 1 to delete the data from front 2 to delete data from rear");
                    scanf("%d",&data);
                    if(data==1||data==2)
                        break;
                }

                e = del(data);
                printf("Removed data is %d \n",e);
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
