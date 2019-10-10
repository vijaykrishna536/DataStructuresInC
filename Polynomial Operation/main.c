#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int pow;
    struct node* next;
}
;

void createone(struct node** start,int n, int pow)
{
    struct node *temp;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new-> data = n;
    new->pow=pow;
    new->next = NULL;
    if (*start == NULL)
        *start = new;
    else
    {
        temp = *start;
        while(temp->next!= NULL)
            temp = temp->next;
        temp-> next = new;
    }
}
void printpol(struct node** start)
{
    printf("data  power\n");
    struct node* t= *start;
    while(t!= NULL)
    {
        printf(" %d \t %d \n", t->data,t->pow);
        t = t-> next;
    }
}

void sort(struct node** start)
{
    struct node* t= *start;
    while(t!= NULL)
    {
        struct node* s = t->next;
        while(s !=NULL)
        {
            if(s->pow < t-> pow)
            {
                int d = s->data;
                s->data = t->data;
                t->data = d;
                int p = s->pow;
                s->pow = t->pow;
                t->pow = p;
            }
            s = s->next;
        }
        t = t->next;
    }
    //for()
}

void add(struct node** one, struct node** two)
{
    struct node* a=*one;
    struct node* b=*two;
    struct node* start=NULL;
    while(a!=NULL&&b!=NULL)
    {
        if(a->pow==b->pow)
        {
            createone(&start,a->data+b->data,a->pow);
            a=a->next;
            b=b->next;
        }
        else if(a->pow<b->pow)
        {
            createone(&start,a->data,a->pow);
            a=a->next;
        }
        else if(b->pow<a->pow)
        {
            createone(&start,b->data,b->pow);
            b=b->next;
        }

    }
    while(a!=NULL)
    {
        createone(&start,a->data,a->pow);
        a=a->next;
    }
    while(b!=NULL)
    {
        createone(&start,b->data,b->pow);
        b=b->next;
    }
    printf("Te solution is\n");
    printpol(&start);
}

void sub(struct node** one, struct node** two)
{
    struct node* a=*one;
    struct node* b=*two;
    struct node* start=NULL;
    while(a!=NULL&&b!=NULL)
    {
        if(a->pow==b->pow)
        {
            createone(&start,a->data-b->data,a->pow);
            a=a->next;
            b=b->next;
        }
        else if(a->pow<b->pow)
        {
            createone(&start,a->data,a->pow);
            a=a->next;
        }
        else if(b->pow<a->pow)
        {
            createone(&start,-(b->data),b->pow);
            b=b->next;
        }

    }
    while(a!=NULL)
    {
        createone(&start,a->data,a->pow);
        a=a->next;
    }
    while(b!=NULL)
    {
        createone(&start,-(b->data),b->pow);
        b=b->next;
    }
    printf("Te solution is\n");
    printpol(&start);
}

void mul(struct node** one, struct node** two)
{
    struct node* a=*one;

    struct node* start=NULL;
    while(a!=NULL)
    {
        struct node* b=*two;
        while(b!=NULL)
        {
            createone(&start,a->data*b->data,b->pow+a->pow);


            b=b->next;
        }
        a=a->next;
    }
    sort(&start);
    struct node* t =start;
    do
    {

        struct node* s=t->next;

        while(t->pow==s->pow)
        {
            t->data+=s->data;

            t->next=s->next;
            s=s->next;
        }

        t=t->next;
    }
    while (t->next!=NULL);
    printf("Te solution is\n");
    printpol(&start);
}

int main()
{
    int n=1, i=0, data, pow,a, no;
    struct node *one=NULL, *two=NULL;
    while(n!=0)
    {
        printf("Welcome to the polynomial world\n");
        printf("1. To enter a new polynomial \n");
        printf("2. To print the polynomial with according to number \n");
        printf("3. To add two polynomial \n4. To subtract two polynomial \n");
        printf("5. To multiply two polynomial \n0. To exit \n");
        printf("Choose one of the above\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            {
                int b=4;
                while(b==4)
                {
                    printf("Enter linked list no to continue\n");
                    scanf("%d",&a);
                    if (a==1 || a==2)
                        break;
                    else
                        printf("enter a valid no \n");
                }

                printf("Enter the no of data in polynomial \n");
                scanf("%d",&no);
                if(a==1)
                {
                    one=NULL;
                }
                else
                {
                    two=NULL;
                }
                for(i=0; i<no; i++)
                    {
                        printf("Enter data %d  ", i);
                        scanf("%d",&data);
                        printf("Enter power of %d ", i);
                        scanf("%d",&pow);
                        if(a==1)
                            createone(&one, data, pow);
                        else if (a==2)
                            createone(&two, data, pow);

                    }
                    if(a==1)
                        sort(&one);
                    else
                        sort(&two);
            }
            break;
        case 2:
            {
                int b=4;
                while(b==4)
                {
                    printf("Enter linked list no to continue\n");
                    scanf("%d",&a);
                    if (a==1 || a==2)
                        break;
                    else
                        printf("enter a valid no \n");
                }

                if(a==1)
                            printpol(&one);
                        else if (a==2)
                            printpol(&two);
                        else
                            printf("invalid input");

            }
            break;
        case 3:
            add(&one, &two);
            break;
        case 4:
            sub(&one, &two);
            break;
        case 5:
            mul(&one, &two);
            break;
        case 0:
            printf("See ya soon");
            break;
        default:
            printf("Enter a valid option");
            break;
        }
    }
    return 0;
}
