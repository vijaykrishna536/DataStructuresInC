#include <stdio.h>
#include <stdlib.h>

struct nodee
{
    int data;
    int ch;
    struct nodee* next;
    struct nodee* prev;
}
*stat=NULL,*end=NULL,*stat1=NULL,*end1=NULL;

struct node
{
    char data;
    struct node* next;
    struct node* prev;
}
*start=NULL,*endd=NULL;
void push(char n)
{
    struct node *temp;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new-> data = n;
    new->next = NULL;
    new->prev = NULL;
    if (start == NULL)
    {
        endd =new;
        start = new;
    }
    else
    {
        temp = endd;
        temp-> next = new;
        new->prev = temp;
        endd = new;
    }
}

void pop()
{

    struct node* a = endd;
    if(start==NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        while(a->data!='(')
        {
            int c =0;
            pushat1(c,a->data);
            a=a->prev;

        }
        if(a==start)
        {
            start=NULL;
            endd=NULL;
        }
        else
        {
            endd = a->prev;
            a->prev->next=NULL;
        }

    }
}

void pri()
{
    struct node* t= start;
    while(t!= NULL)
    {
        printf("%c \n", t->data);
        t = t-> next;
    }
}

void pushat1(int n, char ch)
{
    struct nodee *temp;
    struct nodee *new = (struct nodee*)malloc(sizeof(struct nodee));
    new-> data = n;
    new->ch = ch;
    new->next = NULL;
    new->prev = NULL;
    if (stat1 == NULL)
    {
        stat1 = new;
        end1 =new;
    }
    else
    {
        end1->next = new;
        new->prev = end1;
        end1= new;
    }
}

void priat1()
{
    struct nodee* t= stat1;
    while(t!= NULL)
    {
        if(t->ch=='a')
        {
            printf("%d \n", t->data);
        }
        else
        {
            printf("%c \n", t->ch);
        }
        t = t-> next;
    }
}










void pushat(int n, char ch)
{
    struct nodee *temp;
    struct nodee *new = (struct nodee*)malloc(sizeof(struct nodee));
    new-> data = n;
    new->ch = ch;
    new->next = NULL;
    new->prev = NULL;
    if (stat == NULL)
    {
        stat = new;
        end =new;
    }
    else
    {
        end->next = new;
        new->prev = end;
        end= new;
    }
}

void priat()
{
    struct nodee* t= stat;
    while(t->next!= NULL)
    {
        if(t->ch=='a')
        {
            printf("%d \n", t->data);
        }
        else
        {
            printf("%c \n", t->ch);
        }
        t = t-> next;
    }
}
void obtain()
{
    stat=NULL;
    int data;
    char ch;
    int n = 1;
    while(n!=0)
    {
        printf("Let's start entering expression\nPress 1 to enter number\nPress 2 to enter character\nPress 0 to exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            {
                printf("Enter the number to be entered \n");
                scanf("%d",&data);
                char c='a';
                pushat(data,c);
            }
            break;
        case 2:
            {
                printf("Enter the character to be entered \n");
                scanf(" %c",&ch);
                if(ch=='+'||ch=='-'||ch=='/'||ch=='*'||ch=='('||ch==')')
                {
                    int data = -1;
                    pushat(data, ch);
                }
                else
                    printf("Enter valid Character\n");
            }
            break;
        case 0:
            printf("Expression complete\n");
            break;
        default:
            printf("Invalid option\n");
            break;

        }
    }
    data = -1;
    ch =')';
    pushat(data, ch);
}
int main()
{
    int s,i,j,n=9;
    while(n!=0)
    {
    printf("Welcome to conversion from Infix expression to Postfix expression\n");
    obtain();
    priat();
    struct nodee* temp=stat;
    char c='(';
    push(c);

    while(temp!=NULL)
    {
        if(temp->ch=='a')
        {
            char c ='a';
            pushat1(temp->data,c);


        }
        else if(temp->ch!=')'&&temp->ch!='a')
        {

            push(temp->ch);

        }
        else if(temp->ch==')')
        {
            pri();
            pop();
        }
        temp=temp->next;

    }
    printf("After conversion from inorder to postorder\n");
    priat1();
    printf("Wanna give it another try? \n1.Yes\t0.No\n");
    scanf("%d",&n);
    }


    return 0;
}
