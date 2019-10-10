#include <stdio.h>
#include <stdlib.h>
#define max 100
int queue[max];
int front=-1;
int rear =-1;

void insert(int data, int pos)
{
    if(front==0 && rear==max-1)
        printf("Overflow condition \n");
    else if(pos==2)
    {

        if(front==-1 && rear ==-1)
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
    else  if(pos==1)
    {
        if(front==-1 && rear ==-1)
        {
        front=0;
        rear=0;
        queue[rear]= data;
        }
        else if(front==0)
            printf("Overflow condition\n");
        else if(front>0)
        {
            front--;
            queue[front]=data;
        }
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
        printf("Welcome to Output Restricted Double Ended Queue ADT via Array\n");
        printf("1. To enter a data into ORDE Queue \n2. To remove the data from ORDE Queue \n3. To print ORDE Queue \n");
        printf("4. To search the ORDE Queue \n0. To exit \nChoose from the above \n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            {
                int s=0;
                while(s==0)
                {
                    printf("Enter the 1 to insert the data into front 2 to insert data into rear\n");
                    scanf("%d",&e);
                    if(e==1||e==2)
                        break;
                }
                printf("Enter the data to be entered \n");
                scanf("%d",&data);
                insert(data,e);
            }
            break;
        case 2:
            {


                e = del();
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
