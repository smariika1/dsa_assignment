#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insertEnd(Node** head, int data) {
    Node* n = createNode(data);
    if (!*head) { *head = n; return; }
    Node* t = *head;
    while (t->next) t = t->next;
    t->next = n;
}

void printForward(Node* h) {
    printf("Forward: ");
    while (h) { printf("%d ", h->data); h = h->next; }
    printf("\n");
}

void printReverseRecursive(Node* h) {
    if (!h) return;
    printReverseRecursive(h->next);
    printf("%d ", h->data);
}

void printReverseStack(Node* h) {
    int stack[100], top = -1;
    while (h) { stack[++top] = h->data; h = h->next; }
    printf("Reverse (Stack): ");
    while (top >= 0) printf("%d ", stack[top--]);
    printf("\n");
}

void freeList(Node* h) {
    while (h) { Node* t = h; h = h->next; free(t); }
}

int main() {
    Node* head = NULL;
    int vals[] = {10, 20, 30, 40, 50};
    
    printf("Reverse Linked List Traversal\n\n");
    for (int i = 0; i < 5; i++) insertEnd(&head, vals[i]);
    
    printForward(head);
    printf("Reverse (Recursive): ");
    printReverseRecursive(head);
    printf("\n");
    printReverseStack(head);
    
    freeList(head);
    return 0;
}
