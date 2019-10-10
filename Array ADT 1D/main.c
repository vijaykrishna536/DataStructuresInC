#include <stdio.h>
#include <stdlib.h>

int* create(int s)
{
    int i,n,data;

    int *a = (int*) malloc(s *sizeof(int));
    printf("Array of size %d created\n", s);
    printf("Enter the data\n");
    for(i=0;i<s;i++)
    {
        printf("Data %d  ",i+1);
        scanf("%d",&data);
        a[i]= data;
    }

    printf("Entered array is: \n");
    for(i=0;i<s;i++)
    {
        printf("%d \n",a[i]);
    }
    return &a;
}
int insert(int* a, int so)
{
    int no,n,i,data,in,k=0,index,s=0,p=so-1,b,len;
    while(n!=0)
    {
        printf("Press: \n1 To enter before data \n2 To enter after data \n3 To enter at position \n0 To exit\n");
        scanf("%d",&in);
        printf("Enter  no of data to be entered\n");
        scanf("%d",&no);
        switch(in)
        {
        case 1:
            {
                printf("Enter data before which data to be entered  ");
                scanf("%d",&data);
                for(i=0;i<so;i++)
                {
                    if(data==a[i])
                    {
                        k++;
                        index=i;
                        s++;
                    }
                }
            }
            break;
        case 2:
            {
                printf("Enter data after which data to be entered  ");
                scanf("%d",&data);
                for(i=0;i<so;i++)
                {
                    if(data==a[i])
                    {
                        k++;
                        index=i+1;
                        s++;
                    }
                }
            }
            break;
        case 3:
            {
                printf("Enter index at which data to be entered  ");
                scanf("%d",&index);
                if(index<=so)
                    {
                        s++;
                    }
            }
            break;
        case 0:
            printf("I'm cool with it! \n");
            break;
        default:
            printf("Enter a valid option\n");
        }
        if(s!=0&&k==0)
        {
            printf("Data \ Index out of Bound \n");
        }
        else if(s!=0)
        {
            len = so+no;
            void *realloc(void *a, size_t len);
            for(i=(so+no)-1;i>=index;i--)
                {
                    a[i]=a[p];
                    p--;
                }
            for(i=0;i<no;i++)
                {
                    printf("Enter data %d  ",i);
                    scanf("%d",&b);
                    a[index]=b;
                    index++;
                }
        }
    }
    return len;
}
void del(int* a, int s)
{

}
void printt(int* a, int s)
{
    int i;
    printf("Entered array is: \n");
    for(i=0;i<s;i++)
    {
        printf("%d \n",a[i]);
    }
}
void sort(int* a, int s)
{

}
void lin(int* a, int s)
{

}
void bin(int* a, int s)
{

}
int main()
{
    int n,s;
    int* a;
    while(n!=0)
    {
    printf("Welcome to 1D array as ADT, Choose from the following: \n");
    printf(" 1. To create array of size n \n 2. To insert values into array \n 3. To delete values from array \n");
    printf(" 4. To print the array \n 5. To sort array \n 6. Linear search in array \n 7. Binary search in array \n");
    printf(" 0. To exit \n Choose from above? \n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        {
            printf("Enter the size of array\n");
            scanf("%d", &s);
            a =create(s);
        }
        break;
    case 2:
        {
            s = insert(*a,s);
        }
        break;
    case 3:
        {
            del(&a,s);
        }
        break;
    case 4:
        {
            printt(a,s);
        }
        break;
    case 5:
        {
            sort(&a,s);
        }
        break;
    case 6:
        {
            lin(a,s);
        }
        break;
    case 7:
        {
            bin(a,s);
        }
        break;
    case 0:
        printf("See ya soon fellas...\n");
        break;
    default:
        printf("Enter a valid response \n");
        break;


    }
    }


    return 0;
}
