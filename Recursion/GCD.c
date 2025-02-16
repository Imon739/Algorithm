#include <stdio.h>

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return gcd(y, x % y);
    }
}

int main() {
    int x, y;
    printf("Enter two positive integers x and y: ");
    scanf("%d %d", &x, &y);

    if (x <= 0 || y <= 0) {
        printf("Both numbers must be positive.\n");
        return 1;
    }

    int result = gcd(x, y);
    printf("The GCD of %d and %d is: %d\n", x, y, result);

    return 0;
}

