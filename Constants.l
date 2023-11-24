digit [0-9]
%{
    int c=0;
%}
%%
{digit}+ {c++;printf("%s is constant\n", yytext); } 
.|\n {}
int yywrap(
{
   return 1;
}
int main(void)
{
    FILE *f;
    char file[20];
    printf("enter:");
    scanf("%s",file);
    f=fopen(file,"r");
    yyin=f;
    yylex();
    printf("%d total constant",c);
    fclose(yyin);
}
