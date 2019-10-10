#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
}
*head =NULL;
void createone(int n)
{
    struct node *temp;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new-> data = n;
    new->next = NULL;
    if (head == NULL)
    {
        struct node *h = (struct node*)malloc(sizeof(struct node));
        h->data = 1;
        h->next = NULL;
        head =h;
        head->next = new;

    }
    else
    {
        temp = head->next;
        while(temp->next!= NULL)
            temp = temp->next;
        temp-> next = new;
        head->data++;
    }
}

void print()
{
    struct node* t= head;
    printf("No of node %d\n",t->data);
    t=t->next;
    while(t!= NULL)
    {
        printf("%d \n", t->data);
        t = t-> next;
    }
}

void insad(int data, int pos)
{
    int k =0;
    struct node* a = head->next;
    while(a!= NULL)
    {
        if(a->data == pos)
        {
            struct node* abc = (struct node*)malloc(sizeof(struct node));
            abc->next = a->next;
            abc->data = data;
            a->next = abc;
            head->data++;
            k++;
        }
        a = a-> next;

    }
    if(k==0)
            printf("No such Data exist\n");

}

void insbd(int data, int pos)
{
    int k = 0;
    struct node* a = head->next;
    struct node* b = a->next;
    if(a->data == pos)
    {
        int ss =1;
        insin(data, ss);
        k++;
    }
    else
    {
        while(a->next!= NULL && b->data!=pos)
        {
        b = b->next;
        a = a-> next;

        }
            struct node* abc = (struct node*)malloc(sizeof(struct node));
            abc->next = b;
            abc->data = data;
            a->next = abc;
            head->data++;
            k++;
        }

    if(k==0)
        printf("No such Data Exist\n");

}

void insin(int data,int pos)
{
    struct node* a = head->next;

    int k = 1;
    int max = head->data + 1;
    if(pos>max)
    {
        printf("Too large index \n");
    }
    else if (pos==1)
    {
        struct node* abc = (struct node*)malloc(sizeof(struct node));
        abc->next = a;
        abc->data = data;
        head->next = abc;
        head->data++;
    }
    else if(pos == 0)
    {
        while(a->next!=NULL)
    {
        a = a->next;
    }
        struct node* abc = (struct node*)malloc(sizeof(struct node));
        abc->next = NULL;
        abc->data = data;
        a->next = abc;
        head->data++;
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
            a->next = abc;
            head->data++;
        }
        a = a->next;
        k++;
    }

    }


}
void deld(int data)
{
    struct node* a = head->next;
    int k= 0;
    if(a->data == data)
    {
        delin(1);
        k++;
    }
    else
    {
        struct node* b = a->next;
        while(b!=NULL)
        {

            if(b->data==data)
            {
                a->next= b->next;
                head->data--;
                k++;
            }
            a= a->next;
            b = b->next;
        }

    }
    if (k==0)
        printf("Sorry Mate Number not found!\n");

}
void delin(int pos)
{
    struct node* a = head->next;
    struct node* temp;
    int k = 1;
    if(pos>head->data)
    {
        printf("Index out of Range\n");
    }
    else if (pos==1)
    {
        head->next = a->next;
        head->data--;
    }
    else if(pos == 0)
    {
        while(a->next->next!=NULL)
    {
        a = a->next;
    }
        a->next = NULL;
        head->data--;
    }
    else
    {
       k++;
    while(a!=NULL)
    {
        if (k==pos)
        {

            a->next = a->next->next;
            head->data--;
        }
        a = a->next;

        k++;
    }

    }


}

void search(int data)
{
    int s =1, v =0;
    struct node* t = head->next;
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
    struct node* t = head;

    int k =0;
    struct node* s = head;
    while(t!=NULL)
    {
        if(t->next == s)
        {
            k++;
            break;
        }
        t=t->next;
    }
    if (k==0)
        printf("No loop exist \n");
    else
        printf("Loop exist\n");
}

void sort()
{
    struct node* t= head->next;
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
int main()
{
    int data,no,i,pos,ss;
    int n =1;
    while(n!=0)
    {

        printf("Welcome to Header Linked List as ADT, Choose from the following: \n");
        printf(" 1. To create link list \n 2. To print the linked list \n 3. Search in linked list\n ");
        printf("4. To insert data into linked list after a data \n 5. To insert data into linked list before a data\n ");
        printf("6. To insert data into linked list at beginning   \n 7. To insert data into linked list at end \n");
    printf(" 8. To delete values from linked list \n 9. Delete last node \n 10. delete first node \n");
    printf(" 11. To sort the link list\n 12. To reverse the nodes of linked list \n 13. To delete from a position\n");
    printf(" 14. To insert at a position \n 15. To check whether a loop exist or not \n 0. To exit \n");
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
            print();
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
        default:
        {
            printf("Enter a valid option \n");
        }
        break;

    }
    }


    return(0);
}

