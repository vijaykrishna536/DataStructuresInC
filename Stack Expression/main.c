#include <stdio.h>
#include <stdlib.h>

struct nodee
{
    int data;
    int ch;
    struct nodee* next;
    struct nodee* prev;
}
*stat=NULL,*end=NULL;

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
}
void postfix()
{
    int s=0,a,b;
    obtain();
    priat();
    struct nodee* temp=stat;
    while(temp!=NULL)
    {
        if(temp->ch=='a')
        {
            push(temp->data);

        }
        else
        {

            a=pop();
            b=pop();

            char c = temp->ch;
            switch(c)
            {
            case '+':
                {
                    int d=b+a;
                    push(d);
                }
                break;
            case '-':
                {
                    int d=b-a;
                    push(d);
                }
                break;
            case '*':
                {
                    int d=b*a;
                    push(d);
                }
                break;
            case '/':
                {
                    int d=b/a;
                    push(d);
                }
                break;

            }

        }
        temp=temp->next;

    }
    if(start->next!=NULL)
    {
        printf("Not a valid postfix expression\n");
    }
    else
    {
        printf("Valid postfix expression\n");
        printf("Value is %d \n",pop());
    }

}

void prefix()
{
    int s=1,a,b;
    obtain();
    priat();
    struct nodee* temp=end;
    while(temp!=NULL)
    {
        if(temp->ch=='a')
        {
            push(temp->data);
        }
        else
        {
            b=pop();
            a=pop();
            char c = temp->ch;
            switch(c)
            {
            case'+':
                {
                    int d=b+a;
                    push(d);
                }
                break;
            case'-':
                {
                    int d=b-a;
                    push(d);
                }
                break;
            case'*':
                {
                    int d=b*a;
                    push(d);
                }
                break;
            case'/':
                {
                    int d=b/a;
                    push(d);
                }
                break;

            }
        }
        temp=temp->prev;
    }
    if(start->next!=NULL)
    {
        printf("Not a valid postfix expression\n");
    }
    else
    {
        printf("Valid postfix expression\n");
        printf("Value is %d \n",pop());
    }

}


void balancing()
{
    int s=1,a,b;
    obtain();
    priat();
    struct nodee* temp=stat;
    while(temp!=NULL)
    {
        if(temp->ch=='(')
            push(1);
        else if(temp->ch==')')
        {
            if(start==NULL)
            {
                printf("Not a parenthesis balanced infix expression\n");
                s=0;
                break;
            }
            else
                a=pop();
        }

        temp=temp->next;
    }
    if(start==NULL && s==1)
        printf("Parenthesis balanced infix expression\n");
    else if(start=!NULL && s==1)
        printf("Not a parenthesis balanced infix expression\n");
}


int main()
{
    int n=1, data;

    while(n!=0)
    {
        printf("Welcome to stack Expression via Linked List\n");
        printf("1. Check validity of given postfix expression and display output if valid\n");
        printf("2. Check validity of given prefix expression and display output if valid\n");
        printf("3. Balancing the parenthesis of infix expression\n");
        printf("0. To exit\n");
        printf("Choose from the above\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            {
                postfix();
            }
            break;
        case 2:
            {
                prefix();
            }
            break;
        case 3:
            {
                balancing();
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

