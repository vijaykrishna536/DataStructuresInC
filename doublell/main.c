#include <stdio.h>
#include <stdlib.h>
int c=0;
struct node
{
    int info;
    struct node *next,*prev;
}*start='\0',*temp,*ptr;
void create(int);
void display();
void traverseback();
void insertatlast();
void insertafteranypos();
void tofindfromlast();
void swapofnodes();

void create(int data)
{
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->next='\0';
    temp->prev='\0';
    if(start=='\0')
    {
        start=temp;
        c++;
    }
    else
    {

        ptr=start;
        {
            while(ptr->next!='\0')
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->prev=ptr;

            c++;
        }
    }
}
void display()
{
    ptr=start;
    if(start=='\0')
    {
        printf("List not created\n");
    }
    while(ptr!='\0')
    {
        printf("%d\n",ptr->info);
        ptr=ptr->next;
    }
}
void traverseback()
{
 /*struct node *p = NULL;
 struct node *c = start;
 struct node *n ;
 while (c!= NULL)
 {
     n = c->next;
     c->next = p;
     c->prev = n;
     p=c;
     c=n;
 }
 display();
}
*/ temp=start;
  while(temp->next!='\0')
   {
       temp=temp->next;
   }
   printf("%d\n",temp->info );
   while(temp!='\0')
  {
       printf("%d\n",temp->info);
       temp=temp->prev;
   }
}
void insertatlast()
{
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be  inserted at last\n");
    scanf("%d",&ptr->info);
    ptr->next='\0';
    ptr->prev='\0';



    temp=start;
    while(temp->next!='\0')
    {
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
    ptr->next='\0';

}
void insertafteranypos()
{
    int i,p;
    temp=start;
     ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be  inserted at last\n");
    scanf("%d",&ptr->info);
    ptr->next='\0';
    ptr->prev='\0';
    printf("Enter the position no.\n");
    scanf("%d",&p);
    for(i=1;i<p-1;i++)
    {
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next->prev=ptr;
    temp->next=ptr;
    ptr->prev=temp;
}
void tofindfromlast()


{
    int  p,i;
    temp=start;
    printf("Enter the data to be searched\n");
    scanf("%d",&p);
    while(temp->next!='\0')
    {
        temp=temp->next;
    }
    while(temp->info!=p && temp!='\0')
    {
        temp=temp->prev;
    }
    printf("%d found %d position",temp->info,c);
}

int main()
{
    int m,data,i;
    while(1)
    {
        printf("Enter 1 for creation of list\n");
        printf("Enter 2 for display\n");
        printf("Enter 3 for traversing back\n");
        printf("Enter 4 for inserting node at last\n");
        printf("Enter 5 for inserting node after kth position\n");
        printf("Enter 6 fto find a nth node from last\n");
        printf("Enter 7 fto find a nth node from last\n");
        printf("enter your choice\n");
        scanf("%d",&m);
        switch(m)
        {
            case 1:printf("Enter the data\n");
                scanf("%d",&data);
                create(data);
                break;
            case 2: printf("list:\n");
                    display();
                    break;
            case 3:traverseback();
                break;
            case 4:insertatlast();
                break;
            case 5:insertafteranypos();
                break;
            case 6:tofindfromlast();
                break;
            case 7:exit(1);
        }

    }

    return 0;
}

