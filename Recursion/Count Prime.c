#include <stdio.h>
#include<stdbool.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


int countPrimes(int arr[], int n) {
    if (n == 0) {
        return 0;
    }

    int count = isPrime(arr[n - 1]) ? 1 : 0;
    return count + countPrimes(arr, n - 1);
}


int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements of the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int primeCount = countPrimes(arr, n);
    printf("Number of prime numbers in the array: %d\n", primeCount);

    return 0;
}

