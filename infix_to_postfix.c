#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char STACK[MAX];
int TOP = -1;

void PUSH(char item) {
    if (TOP == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        TOP = TOP + 1;
        STACK[TOP] = item;
    }
}

char POP() {
    if (TOP == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        char item = STACK[TOP];
        TOP = TOP - 1;
        return item;
    }
}

int PRECEDENCE(char symbol) {
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

void INFIX_TO_POSTFIX(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char symbol;

    PUSH('(');
    strcat(infix, ")");   

    while (infix[i] != '\0') {
        symbol = infix[i];

        if (symbol == ' ') {
            i++;
            continue;
        } else if (symbol == '(') {
            PUSH(symbol);
        } else if (isalnum((unsigned char)symbol)) {   
            postfix[j++] = symbol;
        } else if (symbol == ')') {
            while (TOP != -1 && STACK[TOP] != '(') {
                postfix[j++] = POP();
            }
            POP();  
        } else {     
            while (TOP != -1 && PRECEDENCE(STACK[TOP]) >= PRECEDENCE(symbol)) {
                postfix[j++] = POP();
            }
            PUSH(symbol);
        }
        i++;
    }
    postfix[j] = '\0';
}

/* Step 7: MAIN */
int main() {
    char infix[MAX + 2];    
    char postfix[MAX + 2];

    printf("Enter an infix expression: ");
    if (fgets(infix, MAX, stdin) == NULL) {
        return 1;
    }
    infix[strcspn(infix, "\n")] = '\0';  

    printf("Infix Expression: %s\n", infix);
    INFIX_TO_POSTFIX(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}