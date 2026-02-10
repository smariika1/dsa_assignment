#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void init(Stack* s) { s->top = -1; }
bool isEmpty(Stack* s) { return s->top == -1; }
void push(Stack* s, char c) { s->items[++(s->top)] = c; }
char pop(Stack* s) { return isEmpty(s) ? '\0' : s->items[(s->top)--]; }

bool isOpening(char c) { return c == '(' || c == '[' || c == '{'; }
bool isClosing(char c) { return c == ')' || c == ']' || c == '}'; }
bool matches(char open, char close) {
    return (open == '(' && close == ')') || 
           (open == '[' && close == ']') || 
           (open == '{' && close == '}');
}

bool isBalanced(char* expr) {
    Stack s;
    init(&s);
    
    for (int i = 0; expr[i]; i++) {
        if (isOpening(expr[i])) {
            push(&s, expr[i]);
        } else if (isClosing(expr[i])) {
            if (isEmpty(&s) || !matches(pop(&s), expr[i]))
                return false;
        }
    }
    return isEmpty(&s);
}

int main() {
    char* tests[] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };
    
    printf("Balanced Parentheses Checker\n\n");
    for (int i = 0; i < 3; i++) {
        printf("Expression: %s\n", tests[i]);
        printf("Result: %s\n\n", isBalanced(tests[i]) ? "BALANCED" : "NOT BALANCED");
    }
    return 0;
}