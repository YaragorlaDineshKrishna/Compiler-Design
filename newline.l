%{
	int line;	
%}
%%
^(.*)\n printf("%4d\t%s",++line, yytext);
%%
int yywrap(void)
{
	return 1;
}
int main(int argc,char *argv[])
{
	yyin=fopen(argv[1],"r");
	yylex();
	fclose(yyin);
}
