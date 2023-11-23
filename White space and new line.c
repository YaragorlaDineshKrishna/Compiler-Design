#include <stdio.h>

// Function to count whitespaces and newline characters
void countWhitespaceAndNewline(char input[]) {
    int whitespaceCount = 0;
    int newlineCount = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ' || input[i] == '\t') {
            whitespaceCount++;
        } else if (input[i] == '\n') {
            newlineCount++;
        }
    }

    printf("Number of Whitespaces: %d\n", whitespaceCount);
    printf("Number of Newline Characters: %d\n", newlineCount);
}

int main() {
    char input[1000];
    printf("Enter code:\n");
    
    while (fgets(input, sizeof(input), stdin) != NULL) {
        countWhitespaceAndNewline(input);
    }

    return 0;
}
