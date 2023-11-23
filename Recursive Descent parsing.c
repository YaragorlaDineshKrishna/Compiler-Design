#include <stdio.h>

int i = 0;
char input[100];

int E();
int T();
int F();

void match(char expected) {
    if (input[i] == expected) {
        i++;
    } else {
        printf("Error: Expected %c but found %c\n", expected, input[i]);
    }
}

int main() {
    printf("Enter an arithmetic expression: ");
    scanf("%s", input);

    if (E() && input[i] == '\0') {
        printf("String is accepted\n");
    } else {
        printf("String is not accepted\n");
    }

    return 0;
}

int E() {
    if (T()) {
        if (input[i] == '+') {
            match('+');
            if (E()) {
                return 1;
            }
        } else {
            return 1;
        }
    }
    return 0;
}

int T() {
    if (F()) {
        if (input[i] == '*') {
            match('*');
            if (T()) {
                return 1;
            }
        } else {
            return 1;
        }
    }
    return 0;
}

int F() {
    if (input[i] == '(') {
        match('(');
        if (E()) {
            match(')');
            return 1;
        }
    } else if (input[i] >= '0' && input[i] <= '9') {
        match(input[i]);
        return 1;
    } else {
        return 0;
    }
}

Output:
Recursive descent parsing for the following grammar

E->TE'
E'->+TE'/@
T->FT'
T'->*FT'/@
F->(E)/ID

Enter the string to be checked: (a+b)*c

String is accepted

Enter the string to be checked: a/c+d

String is not accepted
