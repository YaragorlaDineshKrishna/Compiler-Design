%{
#include <stdio.h>
%}

%%

int|char|float|double|void   { printf("Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*       { printf("Identifier: %s\n", yytext); }
[0-9]+                       { printf("Constant: %s\n", yytext); }
"(" | ")" | "{" | "}" | ";" | "," | "=" | "+" | "-" | "*" | "/" | "==" | ">" | "<"
                            { printf("Operator: %s\n", yytext); }
[ \t\n]                      ; // Ignore whitespace and newline characters
.                            { printf("Unrecognized: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}
