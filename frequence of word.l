%{
#include <stdio.h>
#include <string.h>

int count = 0; // Global variable to store the count
char word[] = "a"; // Replace with the word you want to count
%}

%option noyywrap

%%
[a-zA-Z]+ { 
    if (strcmp(yytext, word) == 0)
        count++; 
}
. ;		 
%%

int main() {
    FILE *yyin;
    
    yyin = fopen("sample.c", "r");
    
    if (yyin == NULL) {
        perror("Error opening file");
        return 1;
    }

    yylex();
    
    printf("Count of '%s': %d\n", word, count);
    
    fclose(yyin); // Close the file
    
    return 0;
}
