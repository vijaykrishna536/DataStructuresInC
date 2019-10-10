#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
}
*start=NULL;

void push(int n)
{
    struct node *temp;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new-> data = n;
    new->next = NULL;
    if (start == NULL)
        start = new;
    else
    {
        temp = start;
        while(temp->next!= NULL)
            temp = temp->next;
        temp-> next = new;
    }
}

int pop()
{
    int data=-1;
    struct node* a = start;
    if(start==NULL)
    {
        printf("Stack Underflow\n");
        data = 0;
    }
    else if(a->next==NULL)
    {
        data=a->data;
        start=NULL;
    }
    else
    {
        while(a->next->next!=NULL)
        {
            a = a->next;
        }
        data=a->next->data;
        a->next = NULL;
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
        printf("Welcome to stack ADT via Linked List\n");
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

