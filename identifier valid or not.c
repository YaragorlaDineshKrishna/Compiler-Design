#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if a given character is a valid identifier character
bool isValidIdentifierChar(char ch) {
    return isalnum(ch) || ch == '_';
}

// Function to test whether a given identifier is valid
bool isValidIdentifier(char identifier[]) {
    // Check if the first character is a letter or underscore
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return false;
    }

    // Check the remaining characters
    for (int i = 1; identifier[i] != '\0'; i++) {
        if (!isValidIdentifierChar(identifier[i])) {
            return false;
        }
    }

    // The identifier is valid
    return true;
}

int main() {
    char identifier[100];

    // Get user input for the identifier
    printf("Enter an identifier: ");
    scanf("%s", identifier);

    // Test whether the identifier is valid
    if (isValidIdentifier(identifier)) {
        printf("Valid Identifier: %s\n", identifier);
    } else {
        printf("Invalid Identifier: %s\n", identifier);
    }

    return 0;
}
