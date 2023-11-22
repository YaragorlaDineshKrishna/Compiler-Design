%{
#include <stdio.h>
#include <string.h>
%}

%%
apple     { printf("%s", "orange"); }
.         { printf("%s", yytext); }
%%
int yywrap()
{
return 1;
}

int main() 
{
    yylex();
    return 0;
}
