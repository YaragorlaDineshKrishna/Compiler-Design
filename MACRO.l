%{
    int m,h;
%}
%%
^#define {m++;}
^#include { h++;}
.|\n { }
%%
int yywrap(void)
{
   return 1;
}
int main(int argc, char *argv[] )
{
    yyin = fopen(argv[1], "r");
    yylex();
    printf("total macros: %d\n",m);
    printf("total header file: %d\n",h);
    fclose(yyin);
}
