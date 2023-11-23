#include <stdio.h>
#include <string.h>

// Function to eliminate left factoring
void eliminateLeftFactoring(char nonTerminal, char production[][20], int numProductions) {
    int i, j;

    printf("\nAfter Eliminating Left Factoring:\n");

    for (i = 0; i < numProductions; i++) {
        if (production[i][0] == nonTerminal) {
            char commonPrefix[20], remaining[20][20];
            int commonLength = 0, remainingCount = 0;

            // Find the common prefix
            for (j = 0; j < strlen(production[i]) && j < strlen(production[i + 1]); j++) {
                if (production[i][j] == production[i + 1][j]) {
                    commonPrefix[commonLength++] = production[i][j];
                } else {
                    break;
                }
            }
            commonPrefix[commonLength] = '\0';

            if (commonLength > 0) {
                // Display the eliminated left factoring
                printf("%c -> %s%c'\n", nonTerminal, commonPrefix, nonTerminal);
                printf("%c' -> %s\n", nonTerminal, &production[i][commonLength]);

                // Handling the remaining part of the second production
                if (production[i + 1][j] != '\0') {
                    printf("%c' -> %s\n", nonTerminal, &production[i + 1][j]);
                } else {
                    printf("%c' -> epsilon\n", nonTerminal);
                }
            } else {
                printf("%c -> %s\n", nonTerminal, production[i]);
            }

            i++; // Skip the next production since it has been handled
        } else {
            printf("%c -> %s\n", nonTerminal, production[i]);
        }
    }
}

int main() {
    char nonTerminal;
    char production[10][20];
    int numProductions;

    printf("Enter the non-terminal: ");
    scanf(" %c", &nonTerminal);

    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);

    printf("Enter the productions:\n");
    for (int i = 0; i < numProductions; i++) {
        scanf("%s", production[i]);
    }

    eliminateLeftFactoring(nonTerminal, production, numProductions);

    return 0;
}
