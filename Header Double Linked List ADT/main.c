#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
}
*start=NULL,*end=NULL;
void createone(int n)
{
    struct node *temp;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new-> data = n;
    new->next = NULL;
    new->prev = NULL;
    if (start == NULL)
    {
        struct node *n = (struct node*)malloc(sizeof(struct node));
        start = n;
        start->data=1;
        start->next=new;
        start->prev=NULL;
        new->prev=start;
        end= new;
    }
    else
    {
        temp = start->next;
        while(temp->next!= NULL)
            temp = temp->next;
        temp-> next = new;
        new->prev = temp;
        start->data++;
        end = new;
    }
}

void printbw()
{
    printf("No of nodes %d\n",start->data);
    struct node* t= end;
    while(t!= start)
    {
        printf("%d \n", t->data);
        t = t-> prev;
    }
}
void printfo()
{
    printf("No of nodes %d\n",start->data);
    struct node* t= start->next;
    while(t!= NULL)
    {
        printf("%d \n", t->data);
        t = t-> next;
    }
}
void insad(int data, int pos)
{
    int k =0;
    struct node* a = start->next;
    while(a!= NULL)
    {
        if(a->data == pos)
        {

            struct node* abc = (struct node*)malloc(sizeof(struct node));
            abc->next = a->next;
            abc->data = data;
            abc->prev = a;
            a->next = abc;
            start->data++;
            a->next->prev=abc;
            if(end == a)
            {
                end = abc;
            }
            k++;
        }
        a = a-> next;

    }
    if(k==0)
            printf("No such Data exist");

}

void insbd(int data, int pos)
{
    int k = 0;
    struct node* a = start->next;
    if(a->data == pos)
    {
        int ss =1;
        insin(data, ss);
        k++;
    }
    else
    {
        while(a->next!= NULL && a->data!=pos)
        {
              a = a-> next;

        }
            if(a->data== pos)
            {
                struct node* abc = (struct node*)malloc(sizeof(struct node));
            abc->next = a;
            abc->data = data;
            abc->prev = a->prev;
            a->prev->next = abc;
            a->prev = abc;
            start->data++;

            k++;
            }

        }

    if(k==0)
        printf("No such Data Exist");

}

void insin(int data,int pos)
{
    struct node* a = start->next;
    int n=start->data+1;
    int k = 1;
    if(pos>n)
    {
        printf("Too large of index");
    }
    else if (pos==1)
    {
        struct node* abc = (struct node*)malloc(sizeof(struct node));
        abc->next = a;
        abc->data = data;
        a->prev = abc;
        abc->prev=start;
        start->next = abc;
        start->data++;
    }
    else if(pos == 0)
    {

        struct node* abc = (struct node*)malloc(sizeof(struct node));
        abc->next = NULL;
        abc->data = data;
        abc->prev = end;
        end->next = abc;
        end = abc;
        start->data++;
    }
    else
    {
       k++;
    while(a!=NULL)
    {
        if (k==pos)
        {
            struct node* abc = (struct node*)malloc(sizeof(struct node));
            abc->next = a->next;
            abc->data = data;
            abc->prev = a;
            a->next = abc;
            a->next->prev = abc;
            start->data++;
        }
        a = a->next;
        k++;
    }

    }


}
void deld(int data)
{
    int k =0;
    struct node* a = start->next;
    if(a->data == data)
    {
        delin(1);
        k++;
    }
    else
    {
        a=a->next;
        while(a!=NULL)
        {

            if(a->data==data)
            {
                a->next->prev = a->prev;
                a->prev->next = a->next;
                k++;
                start->data--;
                break;
            }
            a = a->next;
        }

        }
        if(k==0)
        {
            printf("Enter a valid number \n");
        }

    }
void delin(int pos)
{
    struct node* a = start->next;
    int n=start->data;
    int k = 1;
    if(pos>n)
    {
        printf("Too large of index");
    }
    else if (pos==1)
    {
        start->next = a->next;
        a->next->prev = start;
        start->data--;
    }
    else if(pos == 0)
    {
        end = end->prev;
        end->next = NULL;
        start->data--;
    }
    else
    {
       k++;
    while(a!=NULL)
    {
        if (k==pos && k<n)
        {

            a->next->next->prev = a;
            a->next = a->next->next;
            start->data--;

        }
        else if(k==pos && k==n)
        {
            int ss =0;
            delin(ss);
        }
        a = a->next;
        k++;
    }

    }


}

void search(int data)
{
    int s =1, v =0;
    struct node* t = start->next;
    while(t!=NULL)
    {
        if(t->data==data)
        {
            v++;
            printf("Number Found at position %d \n", s);
        }
        s++;
        t = t-> next;
    }
    if(v==0)
        printf("Sorry Mate Number not found\n");
}
void loop()
{
    if (end->next==start->next)
        printf("Loop exists \n");
    else
        printf("No loop exists \n");
}

void sort()
{
    struct node* t= start->next;
    while(t!= NULL)
    {
        struct node* s = t->next;
        while(s !=NULL)
        {
            if(s->data < t-> data)
            {
                int d = s->data;
                s->data = t->data;
                t->data = d;
            }
            s = s->next;
        }
        t = t->next;
    }
    //for()
}

void rev()
{
    struct node* t = start->next;
    struct node* tt = end;
    int temp = tt->data;
    tt->data= t->data;
    t->data = temp;

    while(tt->prev!= t && t->next!= tt && tt->prev!=t->next)
    {
        t= t->next;
        tt=tt->prev;
        int temp = tt->data;
        tt->data= t->data;
        t->data = temp;

    }

}


int main()
{
    int data,no,i,pos,ss;
    int n =1;
    while(n!=0)
    {

        printf("Welcome to Header Double Linked List as ADT, Choose from the following: \n");
        printf(" 1. To create double link list \n 2. To print in forward \n 3. To search in double linked list\n ");
        printf("4. To insert data after a data \n 5. To insert data before a data\n ");
        printf("6. To insert data at beginning   \n 7. To insert data at end \n");
    printf(" 8. To delete values \n 9. To delete last node \n 10. To delete first node \n");
    printf(" 11. To sort \n 12. To reverse the nodes \n 13. To delete from a position\n");
    printf(" 14. To insert at a position \n 15. To check whether a loop exist or not \n 16. To print in backward \n");
    printf(" 0. To exit \n");
    printf("Choose from above? \n");
    scanf("%d", &n);
    switch (n)
    {
        case 1:
        {
            printf("Enter the no of data in linked list \n");
            scanf("%d",&no);
            for(i=0; i<no; i++)
                {
                    printf("Enter data %d  ", i);
                    scanf("%d",&data);
                    createone(data);
                }
        }
        break;
        case 2:
        {
            printfo();
        }
        break;
        case 3:
        {
            printf("Enter the data to be searched \n");
            scanf("%d",&data);
            search(data);
        }
        break;
        case 4:
        {
            printf("Enter the data to be added \n");
            scanf("%d",&data);
            printf("Enter data after which to be inserted\n");
            scanf("%d",&pos);
            insad(data, pos);
        }
        break;
        case 5:
        {
            printf("Enter the data to be added \n");
            scanf("%d",&data);
            printf("Enter data before which to be inserted\n");
            scanf("%d",&pos);
            insbd(data, pos);
        }
        break;
        case 6:
        {
            printf("Enter the data to be added \n");
            scanf("%d",&data);
            ss =1;
            insin(data, ss);
        }
        break;
        case 7:
        {
            printf("Enter the data to be added \n");
            scanf("%d",&data);
            ss=0;
            insin(data, ss);
        }
        break;
        case 8:
        {
            printf("Enter data to be deleted \n");
            scanf("%d",&data);
            deld(data);
        }
        break;
        case 9:
        {
            ss=0;
            delin(ss);
        }
        break;
        case 10:
        {
            ss=1;
            delin(ss);
        }
        break;
        case 11:
        {
            sort();
        }
        break;
        case 12:
        {
            rev();
        }
        break;
        case 13:
        {
            printf("Enter position\n");
            scanf("%d",&pos);
            delin(pos);
        }
        break;
        case 14:
        {
            printf("Enter the data to be added \n");
            scanf("%d",&data);
            printf("Enter position\n");
            scanf("%d",&pos);
            insin(data, pos);
        }
        break;
        case 15:
        {
            loop();
        }
        break;
        case 16:
        {
            printbw();
        }
        break;
        default:
        {
            printf("Enter a valid option \n");
        }
        break;

    }
    }


    return(0);
}

//Reverse not working
