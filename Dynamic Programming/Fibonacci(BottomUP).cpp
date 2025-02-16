#include<stdio.h>

int Fibonacci(int N)
{

    int Fib[N+1],i;

    Fib[0] = 0;
    Fib[1] = 1;

    for(i = 2; i <= N; i++)
        Fib[i] = Fib[i-1]+Fib[i-2];

    return Fib[N];
}

int main()
{
    int n;
    scanf("%d",&n);

    if(n <= 1)
        printf("Fib(%d) = %d\n",n,n);
    else
        printf("Fib(%d) = %d\n",n,Fibonacci(n));

    return 0;
}
