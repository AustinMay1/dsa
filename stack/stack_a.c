#include <stdio.h>
#include <stdlib.h>

/* stack using an array */

struct Stack {
    int size;
    int top;
    int *S;
};

void create(struct Stack *st) {
    printf("Enter Size: ");
    scanf("%d", &st->size);

    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void display(struct Stack st) {
    for(int i = st.size; i >= 0; i--) {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x) {
    if(st->top == st->size - 1) {
        printf("Stack overflow\n");
    } else {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st) {
    int x = -1;

    if(st->top == -1) {
        printf("Stack underflow");
    } else {
        x = st->S[st->top--];
    }

    return x;
}

int peek(struct Stack st, int index) {
    int x = -1;

    if(st.top - index + 1 < 0) {
        printf("Invalid index");
    }

    x = st.S[st.top - index + 1];

    return x;
}

int is_empty(struct Stack st) {
    if(st.top == -1) {
        return 1;
    }

    return 0;
}

int is_full(struct Stack st) {
    return st.top == st.size - 1;
}

int peek_top(struct Stack st) {
    if(!is_empty(st)) {
        return st.S[st.top];
    }

    return -1;
}

int main(void) {
    struct Stack st;

    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    printf("%d\n", peek(st, 3));
    printf("%d\n", peek_top(st));

    return 0;
}
