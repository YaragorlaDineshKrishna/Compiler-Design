#include<stdio.h> 
#include<conio.h> 
#include<string.h>
int main()
{
	char c[30];
	int l;
	printf("Enter the sentence to check \n");
	scanf("%s",c);
	l=strlen(c);
	if (c[0]=='/')
	{
		if (c[1]=='/')
		{
			printf("It is comment");
		
		}
		else if (c[1]=='*')
		{
			for (int i=2;i<l;i++){
			
			if (c[i-1]=='/' && c[i]=='*')
			{
			printf("it is comment");
		    }
		   }
	    }
	    else {
	    printf("it is not comment");
	}
}
}

output:
enter the comment:
//hello im doing c program
it is comment.

enter the comment:
/*hi
it is not a comment.
