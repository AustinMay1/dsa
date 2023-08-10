#include <stdio.h>
#include <stdlib.h>

/* stack using a linkedlist */

struct Node {
    int data;
    struct Node *next;
}*head = NULL;

void push(int x) {
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL) {
        printf("Stack is full\n");
    } else {
        t->data = x;
        t->next = head;
        head = t;
    }
}

int pop() {
    struct Node *t;
    int x = -1;

    if(head == NULL) {
        printf("Stack is empty\n");
    } else {
        t = head;
        head = head->next;
        x = t->data;
        free(t);
    }

    return x;
}

void display() {
    struct Node *p;
    p = head;

    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void) {
    push(2);
    push(4);
    push(6);
    push(8);
    push(10);
    display(); 

    return 0;
}
