#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *keywords[] = {
    "int", "float", "char", "double", "if", "else", "while", "for", "return", 
    "void", "main", "switch", "case", "break", "continue", "static", "struct"
};

int isKeyword(const char *word) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>';
}

int main() {
    FILE *file = fopen("input.c", "r");
    if (!file) {
        printf("Failed to open input file.\n");
        return 1;
    }

    char ch, buffer[100];
    int i = 0;

    printf("Lexical Analysis Output:\n");

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            buffer[i++] = ch;
        } else if (isdigit(ch)) {
            buffer[i++] = ch;
        } else if (ch == ' ' || ch == '\n' || ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ',') {
            if (i > 0) {
                buffer[i] = '\0';
                if (isKeyword(buffer))
                    printf("[Keyword]: %s\n", buffer);
                else
                    printf("[Identifier]: %s\n", buffer);
                i = 0;
            }
        } else if (isOperator(ch)) {
            if (i > 0) {
                buffer[i] = '\0';
                if (isKeyword(buffer))
                    printf("[Keyword]: %s\n", buffer);
                else
                    printf("[Identifier]: %s\n", buffer);
                i = 0;
            }
            printf("[Operator]: %c\n", ch);
        }
    }

    fclose(file);
    return 0;
}
