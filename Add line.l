%{
int ln=0;
%}
%%
.* {ln++;fprintf(yyout,"\n%d%s",ln,yytext);}
%%
int yywrap()
{}
int main()
{
yyin=fopen("fabi.c","r");
yyout=fopen("out.txt","w");
yylex();
}
