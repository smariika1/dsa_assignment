#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}

void insertEnd(Node** head, int data) {
    Node* n = createNode(data);
    if (!*head) { *head = n; return; }
    Node* t = *head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void insertAfter(Node* prev, int data) {
    if (!prev) { printf("Error: NULL node\n"); return; }
    Node* n = createNode(data);
    n->next = prev->next;
    n->prev = prev;
    if (prev->next) prev->next->prev = n;
    prev->next = n;
    printf("Inserted %d after %d\n", data, prev->data);
}

void deleteNode(Node** head, Node* del) {
    if (!*head || !del) return;
    if (*head == del) *head = del->next;
    if (del->next) del->next->prev = del->prev;
    if (del->prev) del->prev->next = del->next;
    free(del);
}

Node* find(Node* h, int val) {
    while (h && h->data != val) h = h->next;
    return h;
}

void print(Node* h) {
    printf("List: ");
    while (h) { printf("%d ", h->data); h = h->next; }
    printf("\n");
}

void freeList(Node* h) {
    while (h) { Node* t = h; h = h->next; free(t); }
}

int main() {
    Node* head = NULL;
    printf("Doubly Linked List\n\n");
    
    int vals[] = {10, 20, 30, 40};
    for (int i = 0; i < 4; i++) insertEnd(&head, vals[i]);
    print(head);
    
    insertAfter(find(head, 20), 25);
    print(head);
    
    deleteNode(&head, find(head, 25));
    printf("Deleted 25\n");
    print(head);
    
    freeList(head);
    return 0;
}
