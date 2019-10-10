#include <stdio.h>
#include <stdlib.h>
int fac(int n)
{
    int sum;
    if(n==0)
    {
        sum=1;
        return sum;
    }
    sum=fac(n-1);
    sum=sum*n;
    return sum;
}
int main()
{
    int n,data;
    printf("Hello world!\n");
    printf("Enter a number to calculate factorial\n");
    scanf("%d",&n);
    data = fac(n);
    printf("Factorial is %d \n",data);
    return 0;
}
