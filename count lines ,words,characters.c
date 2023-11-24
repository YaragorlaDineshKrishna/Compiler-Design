#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100], ch;
    int charCount = 0, wordCount = 0, lineCount = 0, inWord = 0;
    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found or unable to open.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        charCount++;
        if (ch == '\n') {
            lineCount++;
        }
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            wordCount++;
        }
    }

    fclose(file);

    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}

output:
Enter the filename: input.txt
Number of characters: 70
Number of words: 9
Number of lines: 1
