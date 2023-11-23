#include <stdio.h>

// Function to validate arithmetic operators
int validateOperator(char input) {
    char operators[] = {'+', '-', '*', '/'};
    for (int i = 0; i < 3; i++) {
        if (input == operators[i]) {
            printf("Valid Operator: %c\n", input);
            return 1; 
        }
    }
    printf("Invalid Operator: %c\n", input);
    return 0;
}

int main() {
    char input;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &input);  
    validateOperator(input);

    return 0;
}
output
Enter an operator (+, -, *, /): *
Valid Operator: *
