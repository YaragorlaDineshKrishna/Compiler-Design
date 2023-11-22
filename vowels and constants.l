%{
#include <stdio.h>
%}

%%
^[aeiouAEIOU].* { printf("Accepted: %s\n", yytext); }
.               { printf("Not Accepted\n"); }
%%

int yywrap()
{
	return 1;
}

int main(void) {
    printf("Enter a string: ");
    yylex();
    return 0;
}
