#include <iostream>

class Node {
    public:
        int data;
        Node *next;
};

class LinkedList {
    private:
        Node *head;

    public:
        LinkedList() {
            head = NULL;
        }

        LinkedList(int A[], int n);

        ~LinkedList();

        void display();
        void insert(int index, int x);
        int delete_at(int index);
        int length();
};

LinkedList::LinkedList(int A[], int n) {
    Node *last, *t;

    head = new Node;
    head->data = A[0];
    head->next = NULL;
    last = head;

    for(int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList() {
    Node *p = head;

    while(head) {
        head = head->next;
        delete p;
        p = head;
    }
}

void LinkedList::display() {
    Node *p = head;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

void LinkedList::insert(int index, int x) {

    Node *t, *p = head;

    if (index < 0 || index > length()) {
        return;
    }

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0) {
        t->next = head;
        head = t;

    } else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::length() {
    Node *p = head;
    int count = 0;

    while (p != NULL) {
        count++;
        p = p->next;
    }

    return (count);
}

int main(void) {
    int A[] = {2, 4, 6, 8, 10};
    LinkedList l(A, 5);

    l.display();
    return 0;
}
