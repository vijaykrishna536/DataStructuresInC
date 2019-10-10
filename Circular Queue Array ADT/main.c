#include <stdio.h>
#include <stdlib.h>
#define max 100
int queue[max];
int front=-1;
int rear =-1;

void insert(int data)
{
    if((front==0 && rear==max-1)||front==rear+1)
        printf("Overflow condition \n");
    else if(front==-1 && rear ==-1)
    {
        front=0;
        rear=0;
        queue[rear]= data;
    }
    else if(rear==max-1)
    {
        rear=0;
        queue[rear]=data;
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
    if(front==-1 && rear==-1)
    {
        printf("Underflow condition");
        return data;
    }
    else if(front+1==rear)
    {
        data = queue[front];
        queue[front]=0;
        front=-1;
        rear=-1;
        return data;
    }
    else if(front==max-1)
    {

        data= queue[front];
        queue[front]=0;
        front=0;
        return data;
    }
    else
    {

        data= queue[front];
        queue[front]=0;
        front++;
        return data;

    }


}
void search(data)
{
    int i=0,k=0;
    for(i=front;i!=rear; i=(i+1)%max)
    {
        if(data==queue[i])
        {
            printf("No found at %d index  \n",i);
            k++;
            break;
        }


    }
    if(k==0)
        printf("No not found \n");



}

void pri()
{
    int i=0;
    if((front!=-1&&rear!=-1)&&front<rear)
    {
        for(i=front;i<=rear;i++)
            printf("%d \n",queue[i]);
    }
    else if((front!=-1&&rear!=-1)&&front>rear)
    {
        for(i=front;i<max;i++)
            printf("%d \n",queue[i]);
        for(i=0;i<=rear;i++)
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
        printf("Welcome to Circular Queue ADT via Array\n");
        printf("1. To enter a data into Queue \n2. To remove the data from Queue \n3. To print Queue \n");
        printf("4. To search Queue \n0. To exit \nChoose from the above \n");
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
        case 4:
            {
                printf("Enter data to be searched\n");
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
