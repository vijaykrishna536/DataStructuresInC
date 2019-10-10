#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL;







void create(int n)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    ptr->data=n;
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }
}









void display()
{
    struct node *t=start;
    while(t)
    {
        printf("%d\n",t->data);
        t=t->next;
    }
}







void sort()
{
    int info;
    struct node *temp;
    struct node *t;
    for(temp=start;temp;temp=temp->next)
    {
        for(t=start;t;t=t->next)
        {
            if(temp->data > t->data)
            {
                 info=temp->data;
                 temp->data=t->data;
                 t->data=info;
            }
        }
    }
    display();
   printf("Done sorting");
}





void insertatfirst()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element you want to insert\t");
    int k;
    scanf("%d",&k);
        temp->next=start;
        temp->data=k;
        start=temp;
    printf("Done inserting");
}





void insertatlast()
{   int k;
    struct node *t1=start;
    struct node *t2=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element you want to insert at last\t");
    scanf("%d",&k);
    while(t1->next!=NULL)
    {
        t1=t1->next;
    }
        t2->data=k;
        t2->next=NULL;
        t1->next= t2;
    printf("Done inserting\n");
}






void insertatany()
{
    int k,pos,i=1;
    struct node *t1=start;
    struct node *t2=(struct node*)malloc(sizeof(struct node));
    printf("Enter the position where you want to insert\t");
    scanf("%d",&pos);
    printf("Enter the element you want to insert\t");
    scanf("%d",&k);
    while(t1)
    {
        if(i==pos-1)
        {
            t2->next=t1->next;
            t1->next=t2;
            t2->data=k;
            break;
        }
        i++;
        t1=t1->next;
    }

     printf("Done inserting\n");
}






void deleteatfirst()
{
    struct node *t1=start;
    start=t1->next;

}
void deleteatlast()
{
    struct node *t1=start;

    while(t1->next->next!=NULL)
    {
       t1= t1->next;
    }
     t1->next=NULL;
}





void deleteatany()
{
    int i=1,pos;
    struct node *t1=start;
    printf("Enter the position  ");
    scanf("%d",&pos);
    while(t1->next!=NULL)
    {
        if(i==pos-2)
        {
            t1=t1->next;
            t1->next=t1->next->next;
        }
        i++;
        t1=t1->next;
    }
}







int main()
{
    int i,n,data,x;
    printf("Enter the no of nodes\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the element\n");
        scanf("%d",&data);
        create(data);
    }
    a:
    printf("Enter your choice");
    scanf("%d",&x);

        switch(x)
        {
            case 1: sort();goto a;
            break;
            case 2: insertatfirst();goto a;
            break;
            case 3: insertatlast();goto a;
            break;
            case 4: insertatany();goto a;
            break;
            case 5: deleteatfirst();goto a;
            break;
            case 6: deleteatlast();goto a;
            break;
            case 7: deleteatany();goto a;
            break;
            case 8: display();goto a;
            break;
            case 9: exit(1);goto a;
            default:printf("Enter a valid choice");
        }
    return 0;
}
