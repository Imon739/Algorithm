#include<stdio.h>
#include<stdbool.h>


int sum(int n)
{
    if(n==1) return 1;
    else return n+sum(n-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n",sum(n));
    return 0;
}
