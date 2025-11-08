#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
 
int main(int argc, char *argv[]) { 
    FILE *fp; 
    char ch; 
    char lexeme[100][50];   
    int row = 0, col = 0; 
    fp = fopen(argv[1], "r"); 
    while ((ch = fgetc(fp)) != EOF) { 
        if(isspace((unsigned char)ch)) { 
            if (col != 0) { 
                lexeme[row][col] = '\0'; 
                row++; 
                col = 0; 
            } 
        } 
        else if (ch == '(' || ch == ')' || ch == ';') { 
            if (col != 0) { 
                lexeme[row][col] = '\0'; 
                row++; 
                col = 0; 
            } 
            lexeme[row][0] = ch; 
            lexeme[row][1] = '\0'; 
            row++; 
        } 
        else { 
            lexeme[row][col++] = ch; 
        } 
    } 
    if (col != 0) { 
        lexeme[row][col] = '\0'; 
        row++; 
    } 
    fclose(fp); 
 
    int foundFor = 0; 
    for (int i = 0; i < row; i++) { 
        if (strcmp(lexeme[i], "for") == 0) { 
            foundFor = 1; 
 
            if (i + 1 >= row || strcmp(lexeme[i + 1], "(") != 0) { 
                printf("Error: Missing '('\n"); 
                return 0; 
            } 
 
            int semicolonCount = 0; 
            int foundClosing = 0; 
            for (int j = i + 2; j < row; j++) { 
                if (strcmp(lexeme[j], ";") == 0) { 
                    semicolonCount++; 
                } else if (strcmp(lexeme[j], ")") == 0) { 
                    foundClosing = 1; 
                     if (semicolonCount == 2) { 
                        printf("Syntax Correct: for loop\n"); 
                    } else if (semicolonCount < 2) { 
                        printf("Error: Missing semicolon(s) inside for loop\n"); 
                    } else { 
                        printf("Error: More than two semicolons inside for loop\n"); 
                    } 
                    break; 
                } 
            } 
 
            if (!foundClosing) { 
                printf("Error: Missing closing ')'\n"); 
            } 
 
            break; 
        } 
    } 
 
    if (!foundFor) { 
        printf("Error: 'for' keyword not found\n"); 
    } 
 
    return 0; 
} 
 
