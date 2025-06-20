#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


const char *keywords[] = {
    "int", "float", "char", "double", "long", "short",
    "if", "else", "while", "for", "do", "return",
    "switch", "case", "break", "continue", "void",
    "static", "struct", "sizeof", "typedef", "union"
};


int isKeyword(const char *str) {
    for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '%' ||
            ch == '&' || ch == '|' || ch == '!');
}


void lexicalAnalyzer(FILE *file) {
    char ch, buffer[100];
    int i = 0;

    while ((ch = fgetc(file)) != EOF) {
    
        if (isalnum(ch) || ch == '_') {
            buffer[i++] = ch;
        } else {
            if (i != 0) {
                buffer[i] = '\0';
                if (isKeyword(buffer)) {
                    printf("Keyword: %s\n", buffer);
                } else {
                    printf("Identifier: %s\n", buffer);
                }
                i = 0;
            }


            if (isOperator(ch)) {
                printf("Operator: %c\n", ch);
            }
        }
    }
}

int main() {
    FILE *file = fopen("input.c", "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n\n");
    lexicalAnalyzer(file);

    fclose(file);
    return 0;
}
