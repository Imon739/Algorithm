#include <stdio.h>

int sumSeries(int n) {
    if (n == 0) {
        return 0;
    }
    return (n * (2 * n + 1)) + sumSeries(n - 1);
}

void printSeries(int n) {
    if (n == 0) {
        return;
    }
    printSeries(n - 1);
    if (n > 1) {
        printf(" + ");
    }
    printf("%d*%d", n, 2 * n + 1);

}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("The series up to %dth position: ", n);
    printSeries(n);
    printf("\n");

    int sum = sumSeries(n);
    printf("The sum of the series up to %dth position: %d\n", n, sum);

    return 0;
}

