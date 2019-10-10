#include <stdio.h>
#include <stdlib.h>
#define max 100
int queue1[max];
int queue2[max];
int front1=-1;
int rear1 =-1;
int front2 =-1;
int rear2 =-1;

void insert(int data)
{
    if(front1==0 && rear1==max-1)
        printf("Overflow condition \n");
    else if(front1==-1 && rear1 ==-1)
    {
        front1=0;
        rear1=0;
        queue1[rear1]= data;
    }
    else
    {
        rear1++;
        queue1[rear1]=data;
    }
    update();

}
void update()
{
    if(rear2==-1)
    {
        queue2[rear2]=queue1[rear1];
        front2=0;
    }

    rear2++;
    int i=rear2;
    for(i;i>=front2;i--)
    {
        queue2[i]=queue2[i-1];
    }
    queue2[front2]=queue1[rear1];
    front1=-1;
    rear1=-1;
}


int del()
{
    int data = -1;
    if((front2==-1 && rear2==-1)||front2>rear2)
    {
        printf("Underflow condition \n");
        return data;
    }
    else if(front2<rear2)
    {
        data = queue2[front2];
        queue2[front2]=0;
        front2++;
        return data;
    }
    else if(front2==rear2)
    {
        data= queue2[front2];
        queue2[front2]=0;
        front2=-1;
        rear2=-1;
        return data;
    }


}

void search(int data)
{
    int i,k=0;
    if(front2!=-1&&rear2!=-1)
    {
    for(i=front2;i<=rear2;i++)
    {
        if(data==queue2[i])
        {
            printf("Data Found\n");
            k++;
            break;
        }

    }
    }
    if(k==0)
        printf("Sorry Data not present\n");
}

void pri()
{
    int i=0;
    if(front2!=-1&&rear2!=-1)
    {
        for(i=front2;i<=rear2;i++)
            printf("%d \n",queue2[i]);
    }
    else
        printf("No data present \n");

}
int main()
{
    int n=1, data;

    while(n!=0)
    {
        printf("Welcome to Stack using Queue ADT via Array\n");
        printf("1. To enter a data into Stack \n2. To remove the data from Stack \n3. To print Stack \n");
        printf("4. To search data \n0. To exit \nChoose from the above \n");
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
