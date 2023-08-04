#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *next;
}*first=NULL;

void create_list(int A[], int n) {
    int i;
    struct Node *t, *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i = 1; i < n; i++) {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display_list(struct Node *p) {
    while(p != NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

void display_rec(struct Node *p) {
    if(p != NULL) {
        printf("%d ", p->data);
        display_rec(p->next);
    }
}

int list_length(struct Node *p) {
    int count = 0;

    while(p != NULL) {
        count++;
        p = p->next;
    }
    
    return(count);
}

int length_rec(struct Node *p) {
    if(p == 0) {
        return 0;
    } else {
        return length_rec(p->next) + 1;
    }
}

int list_sum(struct Node *p) {
    int total = 0;

    while(p != NULL) {
        total += p->data;
        p = p->next;
    }
    return total;
}
    
int sum_rec(struct Node *p) {
    if(p == 0) {
        return 0;
    } else {
        return sum_rec(p->next) + p->data;
    }
}

int find_max(struct Node *p) {
    int max=INT_MIN;

    while(p) {
        if(p->data > max) {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

int max_rec(struct Node *p) {
    int max = 0;

    if(p == 0) {
        return INT_MIN;
    }

    max = max_rec(p -> next);

    return max > p -> data ? max : p -> data;
}

struct Node *search_list(struct Node *p, int key) {
    while(p) {
        if(p->data == key)
            return p;
        p=p->next;
    }
    return NULL;
}

struct Node *search_rec(struct Node *p, int key) {
    if(p == NULL) {
        return NULL;
    }

    return p->data == key ? p : search_rec(p->next, key);
}

void insert_at(struct Node *p, int index, int x) {
    struct Node *t;

    if(index < 0 || index > list_length(p)) {
        return;
    }

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index == 0) {
        t->next = first;
        first = t;
    } else {
        for(int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void sorted_insert(struct Node *p, int x) {
    struct Node *t, *q = NULL;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first == NULL) {
        first = t;
    } else {
        while(p && p->data < x) {
            q = p;
            p = p->next;

        }
        if(p == first) {
            t->next = first;
            first = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}
