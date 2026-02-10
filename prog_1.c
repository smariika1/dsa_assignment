#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}


int isMatching(char a, char b) {
    if (a == '(' && b == ')') return 1;
    if (a == '{' && b == '}') return 1;
    if (a == '[' && b == ']') return 1;
    return 0;
}

int isBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) return 0;
            if (!isMatching(pop(), exp[i])) return 0;
        }
    }
    return top == -1;
}

int main() {
    char exp[MAX];
    printf("Enter expression: ");
    gets(exp);

    if (isBalanced(exp))
        printf("The parentheses are balanced\n");
    else
        printf("The parentheses are not balanced\n");

    return 0;
}
