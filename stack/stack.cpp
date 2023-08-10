#include <iostream>
#include <ostream>

class Node {
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        Node *head;
    public:
        Stack() {
            head = NULL;
        }

        void push(int x);
        int pop();
        void display();
};

void Stack::push(int x) {
    Node *t = new Node;

    if(t == NULL) {
        std::cout << "Stack is full" << std::endl;
    } else {
        t->data = x;
        t->next = head;
        head = t;
    }
}

int Stack::pop() {
    int x = -1;

    if(head == NULL) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        x = head->data;
        Node *t = head;
        head = head->next;
        delete t;
    }

    return x;
}

void Stack::display() {
    Node *p = new Node;
    p = head;

    while(p != NULL) {
        std::cout << p->data; 
        std::cout << " ";
        p = p->next;
    }

    std::cout << std::endl;
}

int main(void) {
    Stack head = Stack();

    head.push(10);
    head.push(20);
    head.push(30);

    std::cout << "Curr Stack: ";
    head.display();

    std::cout << "Pop: " << head.pop() << std::endl;
    std::cout << "Curr Stack: ";
    head.display();

    return 0;
}
