#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top = -1;
struct node
{
int data;
struct node*next;
}*start=NULL;
void push(int z)
{
if(top==99)
printf("Overflow condition");
else
{
top++;
struct node *new = (struct node*)malloc(sizeof(struct node));
new->data = z;
if(start== NULL)
start = new;
else
{
new->next = start;
start = new;
}
}
}
int pop()
{
if(top==-1)
{printf("Underflow condition");
return (-1);}
else
{
int h =start->data;
start = start->next;
return (h);
}
}
void dis()
{int i;
struct node *t = start;
while(t!= NULL)
{
printf("%d \n",t->data);
t = t->next;
}
}
int main()
{
int f;
int n,j;
int i=0;
while(i==0)
{
printf("Enter 1 to push 2 to pop 3 to display and 4 to exit \n");
scanf("%d",&j);
switch (j)
{
case 1:
{
printf("Enter data to push");
scanf("%d",&f);
push(f);
}
break;
case 2:
{
f = pop();
printf("Poped data is %d",f);
}
break;
case 3:
dis();
break;
case 4:
i++;
break;
default:
printf("Enter valid number \n");
break;
}
}
return 0;
}
