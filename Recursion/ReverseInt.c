#include<stdio.h>
#include<stdbool.h>


void reverseDigits(int n)
{
    if(n==0) return;

    printf("%d", n%10 );
    reverseDigits(n/10);

}

int main()
{
    int n;
    scanf("%d", &n);
    reverseDigits(n);
    return 0;
}


