%{
#include <stdio.h>

int wh = 0, ne = 0;
%}

%%
[ \t] { wh++; }
\n { ne++; }
. { }
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Reading from file: %s\n", argv[1]);
    yyin = file;

    yylex();

    fclose(file);

    printf("\nTotal whitespaces: %d\n", wh);
    printf("Total newlines: %d\n", ne);

    return 0;
}
