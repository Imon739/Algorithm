#include <stdio.h>

void printArray(int arr[], int n) {
    if (n == 0) {
        return;
    }

    printf("%d ", arr[0]);
    printArray(arr + 1, n - 1);
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

    printf("The array elements are: ");
    printArray(arr, n);

    return 0;



///Reverse Order


/*void printArrayReverse(int arr[], int n) {
    if (n == 0) {
        return;
    }

    printf("%d ", arr[n - 1]);
    printArrayReverse(arr, n - 1);
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

    printf("The array elements in reverse order are: ");
    printArrayReverse(arr, n);

    return 0;*/
}


