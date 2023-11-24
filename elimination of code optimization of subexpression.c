#include <stdio.h>

int main() {
    int a, b, c, d, e, result;
    printf("Enter values for a, b, and c: ");
    scanf("%d %d %d", &a, &b, &c);
    result = a + b;

    printf("Result 1: %d\n", result);
    printf("Result 2: %d\n", result);
    d = result * c;
    printf("Result 3: %d\n", d);
    e = result * c;
    printf("Result 4: %d\n", e);

    return 0;
}

output;
Enter values for a, b, and c: 10 20 30
Result 1: 30
Result 2: 30
Result 3: 900
Result 4: 900
