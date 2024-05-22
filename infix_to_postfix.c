#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->stack[++(s->top)] = c;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->stack[(s->top)--];
}

char peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->stack[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

char *infixToPostfix(char *infix) {
    Stack operatorStack;
    operatorStack.top = -1;

    int len = strlen(infix);
    char *postfix = (char *)malloc((len + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; i < len; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&operatorStack, c);
        } else if (c == ')') {
            while (!isEmpty(&operatorStack) && peek(&operatorStack) != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            pop(&operatorStack); // Discard '('
        } else { // Operator
            while (!isEmpty(&operatorStack) && precedence(peek(&operatorStack)) >= precedence(c)) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, c);
        }
    }

    while (!isEmpty(&operatorStack)) {
        postfix[j++] = pop(&operatorStack);
    }
    postfix[j] = '\0';

    return postfix;
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    char *postfix = infixToPostfix(infix);
    printf("Postfix expression: %s\n", postfix);

    free(postfix);
    return 0;
}
