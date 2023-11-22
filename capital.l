%%
[A-Z]+[\t\n ] { printf("%s is a capital letter\n", yytext);}
.  ;
%%
int yywrap()
{
return 1;
}

int main()
{
	printf("enter the sentence:");
	yylex();
}
