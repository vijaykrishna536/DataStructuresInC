#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int pri;
    struct node* next;
    struct node* prev;
}
*start=NULL,*end=NULL;

void insert(int n,int p)
{
    struct node *temp;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new-> data = n;
    new->pri=p;
    new->prev=NULL;
    new->next = NULL;
    if (start == NULL)
    {
        end= new;
        start = new;
    }
    else
    {
        temp=start;
        while(temp->pri<=new->pri&&temp->next!=NULL)
            temp=temp->next;
        if(temp->next==NULL && temp->pri<=new->pri)
        {
            end->next=new;
            new->prev=end;
            end=new;
        }
        else
        {
            new->next=temp;
            new->prev=temp->prev;
            temp->prev->next=new;
            temp->prev=new;
        }

    }
}

int* del()
{
    int data=-1;
    int pr=0;
    struct node* a = start;
    if(start==NULL)
    {
        printf("Stack Underflow \n");
        data = 0;
    }
    else if(a->next==NULL)
    {
        data=a->data;
        pr= a->pri;
        start=NULL;
    }
    else
    {
        data=a->data;
        pr=a->pri;
        start=start->next;
        start->prev=NULL;
    }

    int arr[2]={data,pr};

    return &arr;
}
void search(int data, int p)
{
    int k=0;
    struct node* temp = start;
    while(temp!=NULL)
    {
        if(temp->data==data&&temp->pri==p)
        {
            printf("Number %d found with priority %d \n",temp->data,temp->pri);
            k++;
            break;
        }
        temp=temp->next;
    }
    if(k==0)
        printf("Not found\n");
}

void pri()
{
    struct node* t= start;
    printf("Data Priority \n");
    while(t!= NULL)
    {
        printf("  %d \t %d \n", t->data,t->pri);
        t = t-> next;
    }
}


int main()
{
    int n=1, data,p;

    while(n!=0)
    {
        printf("Welcome to Priority Queue ADT via Linked List\nNote: lower the number higher the priority\n");
        printf("1. To enter a data into Queue \n2. To remove the data from Queue \n3. To print Queue \n");
        printf("4. To search the queue \n0. To exit \nChoose from the above \n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            {
                printf("Enter the data to be entered \n");
                scanf("%d",&data);
                printf("Enter the priority of data \n");
                scanf("%d",&p);
                insert(data, p);
            }
            break;
        case 2:
            {
                int *data = del();
                printf("Removed data is %d with priority %d \n",data[0],data[1]);
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
                printf("Enter the priority of data \n");
                scanf("%d",&p);
                search(data,p);
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

