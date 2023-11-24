#include <stdio.h>

// Function to check if the given input string satisfies the grammar
int checkGrammar(char input[]) {
    int countA = 0, countB = 0;

    // Count the number of 'a's and 'b's
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'a') {
            countA++;
        } else if (input[i] == 'b') {
            countB++;
        } else {
            // Invalid character in the input string
            return 0;
        }
    }

    // Check if the number of 'a's is equal to the number of 'b's
    return countA == countB;
}

int main() {
    char input[100];

    // Get user input for the string
    printf("Enter a string (a^n b^n): ");
    scanf("%s", input);

    // Check if the input string satisfies the grammar
    if (checkGrammar(input)) {
        printf("The string satisfies the grammar.\n");
    } else {
        printf("The string does not satisfy the grammar.\n");
    }

    return 0;
}
