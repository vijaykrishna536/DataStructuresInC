#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
}
*start=NULL,*end=NULL;

void insert(int n)
{
    struct node *temp;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new-> data = n;
    new->prev=NULL;
    new->next = NULL;
    if (start == NULL)
    {
        end= new;
        start = new;
    }
    else
    {
        end->next=new;
        new->prev=end;
        end=new;

    }
}

int del()
{
    int data=-1;
    struct node* a = start;
    if(start==NULL)
    {
        printf("Stack Underflow \n");
        data = 0;
    }
    else if(a->next==NULL)
    {
        data=a->data;
        start=NULL;
    }
    else
    {
        data=a->data;
        start=start->next;
        start->prev=NULL;
    }



    return data;
}

void pri()
{
    struct node* t= start;
    while(t!= NULL)
    {
        printf("%d \n", t->data);
        t = t-> next;
    }
}


int main()
{
    int n=1, data;

    while(n!=0)
    {
        printf("Welcome to Queue ADT via Linked List\n");
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
                printf("See ya all soon homies\n");
            }
            break;
        default:
            printf("Enter a valid option \n");
            break;
        }


    }

    return 0;
}

