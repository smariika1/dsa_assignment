#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100

typedef struct { char items[MAX]; int top; } CharStack;
typedef struct { int items[MAX]; int top; } IntStack;

void initC(CharStack* s) { s->top = -1; }
void pushC(CharStack* s, char c) { s->items[++(s->top)] = c; }
char popC(CharStack* s) { return s->items[(s->top)--]; }
char peekC(CharStack* s) { return s->top == -1 ? '\0' : s->items[s->top]; }
bool emptyC(CharStack* s) { return s->top == -1; }

void initI(IntStack* s) { s->top = -1; }
void pushI(IntStack* s, int n) { s->items[++(s->top)] = n; }
int popI(IntStack* s) { return s->items[(s->top)--]; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) { return c=='+' || c=='-' || c=='*' || c=='/' || c=='^'; }

void infixToPostfix(char* infix, char* postfix) {
    CharStack s;
    initC(&s);
    int j = 0;
    
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == ' ') continue;
        
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
            postfix[j++] = ' ';
        } else if (infix[i] == '(') {
            pushC(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!emptyC(&s) && peekC(&s) != '(')
                postfix[j++] = popC(&s), postfix[j++] = ' ';
            popC(&s);
        } else if (isOperator(infix[i])) {
            while (!emptyC(&s) && peekC(&s) != '(' && 
                   precedence(peekC(&s)) >= precedence(infix[i]))
                postfix[j++] = popC(&s), postfix[j++] = ' ';
            pushC(&s, infix[i]);
        }
    }
    while (!emptyC(&s))
        postfix[j++] = popC(&s), postfix[j++] = ' ';
    postfix[j] = '\0';
}


int evaluate(char* postfix) {
    IntStack s;
    initI(&s);
    char* token = strtok(postfix, " ");
    
    while (token) {
        if (isdigit(token[0])) {
            pushI(&s, atoi(token));
        } else if (isOperator(token[0])) {
            int b = popI(&s), a = popI(&s);
            switch(token[0]) {
                case '+': pushI(&s, a + b); break;
                case '-': pushI(&s, a - b); break;
                case '*': pushI(&s, a * b); break;
                case '/': pushI(&s, a / b); break;
                case '^': pushI(&s, (int)pow(a, b)); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return popI(&s);
}

int main() {
    char* tests[] = {"3 + 5 * 2", "( 3 + 5 ) * 2", "10 + 2 * 6"};
    char postfix[MAX], temp[MAX];
    
    printf("Infix to Postfix Converter\n\n");
    for (int i = 0; i < 3; i++) {
        infixToPostfix(tests[i], postfix);
        printf("Infix:   %s\n", tests[i]);
        printf("Postfix: %s\n", postfix);
        strcpy(temp, postfix);
        printf("Result:  %d\n\n", evaluate(temp));
    }
    return 0;
}
