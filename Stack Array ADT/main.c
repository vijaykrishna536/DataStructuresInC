#include <stdio.h>
#include <stdlib.h>
#define max 100
int stack[max];
int top=-1;

void push(int data)
{
    if(top == max-1)
        printf("Overflow condition");
    else
    {
        top++;
        stack[top]= data;
    }

}

int pop()
{
    int data = -1;
    if(top==-1)
        printf("Underflow condition");
    else
    {
        data = stack[top];
        top--;
    }

    return data;
}

void pri()
{
    int i=0;

    for(i=top;i>=0;i--)
        printf("%d \n",stack[i]);
}
int main()
{
    int n=1, data;

    while(n!=0)
    {
        printf("Welcome to stack ADT via Array\n");
        printf("1. To enter a data into stack \n2. To remove the data from stack \n3. To print stack \n0. To exit \n");
        printf("Choose from the above \n");
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
