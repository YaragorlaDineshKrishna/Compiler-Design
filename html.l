%{
int tag;
%}
%%
"<"[^>]*> { tag++; printf("%s\n ", yytext); }
.|\n { }
%%
int yywrap(void)
{
return 1;
}
int main(void)
{
    FILE *f;
    char file[10];
    printf("enter file name:");
    scanf("%s",file);
    f=fopen(file,"r");
    yyin=f;
    yylex();
    printf("total:%d",tag);
    fclose(yyin);
}
