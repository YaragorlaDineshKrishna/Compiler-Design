%%
[1-9][0-9]{9} {
    printf("valid\n");
}

.+ {printf("invalid\n"); }
%%
int main()
{
	printf("enter the mobile number:");
	yylex();
	printf("\n");
	return 0;
}
int yywrap()
{ }
