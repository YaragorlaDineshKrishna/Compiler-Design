#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a keyword
int isKeyword(char *str) {
    char keywords[][10] = {"int", "float", "char", "if", "else", "while", "for", "do", "switch", "case", "break", "continue", "return"};
    int i;
    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(keywords[i], str) == 0) {
            return 1; // It is a keyword
        }
    }
    return 0; // It is not a keyword
}


int isOperator(char ch) {
    char operators[] = "+-*/%=";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i]) {
            return 1; 
        }
    }
    return 0; 
}

int isDelimiter(char ch) {
    char delimiters[] = " \t\n,;(){}[]";
    for (int i = 0; i < strlen(delimiters); i++) {
        if (ch == delimiters[i]) {
            return 1; 
        }
    }
    return 0; 
}

void lexicalAnalyzer(char input[]) {
    int i = 0;

    while (input[i] != '\0') {
        char token[50];
        int tokenIndex = 0;

        if (isspace(input[i])) {
            i++;
            continue;
        }

    
        if (isalpha(input[i]) || input[i] == '_') {
            while (isalnum(input[i]) || input[i] == '_') {
                token[tokenIndex++] = input[i++];
            }
            token[tokenIndex] = '\0';

            if (isKeyword(token)) {
                printf("Keyword: %s\n", token);
            } else {
                printf("Identifier: %s\n", token);
            }
        }


        else if (isdigit(input[i])) {
            while (isdigit(input[i]) || input[i] == '.') {
                token[tokenIndex++] = input[i++];
            }
            token[tokenIndex] = '\0';
            printf("Constant: %s\n", token);
    
        else if (isOperator(input[i])) {
            printf("Operator: %c\n", input[i++]);
        }

        else if (isDelimiter(input[i])) {
            printf("Delimiter: %c\n", input[i++]);
        }

        
        else {
            i++;
        }
    }
}

int main() {
    char input[1000];

    printf("Enter C code:\n");
    gets(input); 

    printf("\nTokens:\n");
    lexicalAnalyzer(input);

    return 0;
}


output

Enter C code:
#include<stdio.h> int main(){return 100}

Tokens:
Identifier: include
Identifier: stdio
Identifier: h
Keyword: int
Identifier: main
Delimiter: (
Delimiter: )
Delimiter: {
Keyword: return
Constant: 100
Delimiter: }
