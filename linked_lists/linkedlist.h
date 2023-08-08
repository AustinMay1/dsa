#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
} *first = NULL, *snd = NULL, *thd = NULL;

void create_list(int A[], int n) {
  int i;
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

void create_list_snd(int A[], int n) {
  int i;
  struct Node *t, *last;
  snd = (struct Node *)malloc(sizeof(struct Node));
  snd->data = A[0];
  snd->next = NULL;
  last = snd;

  for (i = 1; i < n; i++) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}


void display_list(struct Node *p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void display_rec(struct Node *p) {
  if (p != NULL) {
    printf("%d ", p->data);
    display_rec(p->next);
  }
}

int list_length(struct Node *p) {
  int count = 0;

  while (p != NULL) {
    count++;
    p = p->next;
  }

  return (count);
}

int length_rec(struct Node *p) {
  if (p == 0) {
    return 0;
  } else {
    return length_rec(p->next) + 1;
  }
}

int list_sum(struct Node *p) {
  int total = 0;

  while (p != NULL) {
    total += p->data;
    p = p->next;
  }
  return total;
}

int sum_rec(struct Node *p) {
  if (p == 0) {
    return 0;
  } else {
    return sum_rec(p->next) + p->data;
  }
}

int find_max(struct Node *p) {
  int max = INT_MIN;

  while (p) {
    if (p->data > max) {
      max = p->data;
    }
    p = p->next;
  }
  return max;
}

int max_rec(struct Node *p) {
  int max = 0;

  if (p == 0) {
    return INT_MIN;
  }

  max = max_rec(p->next);

  return max > p->data ? max : p->data;
}

struct Node *search_list(struct Node *p, int key) {
  while (p) {
    if (p->data == key)
      return p;
    p = p->next;
  }
  return NULL;
}

struct Node *search_rec(struct Node *p, int key) {
  if (p == NULL) {
    return NULL;
  }

  return p->data == key ? p : search_rec(p->next, key);
}

void insert_at(struct Node *p, int index, int x) {
  struct Node *t;

  if (index < 0 || index > list_length(p)) {
    return;
  }

  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;

  if (index == 0) {
    t->next = first;
    first = t;
  } else {
    for (int i = 0; i < index - 1; i++) {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

void sorted_insert(struct Node *p, int x) {
  struct Node *t, *q = NULL;

  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;

  if (first == NULL) {
    first = t;
  } else {
    while (p && p->data < x) {
      q = p;
      p = p->next;
    }
    if (p == first) {
      t->next = first;
      first = t;
    } else {
      t->next = q->next;
      q->next = t;
    }
  }
}

int list_delete(struct Node *p, int index) {
  struct Node *q = NULL;
  int x = -1, i;

  if (index < 1 || index > list_length(p)) {
    return x;
  }

  if (index == 1) {
    q = first;
    x = first->data;
    first = first->next;
    free(q);
    return x;
  } else {
    for (i = 0; i < index - 1; i++) {
      q = p;
      p = p->next;
    }

    q->next = p->next;
    x = p->data;
    free(p);
    return x;
  }
}

int is_sorted(struct Node *p) {
    int x = INT_MIN;

    while(p != NULL) {
        if(p->data < x) {
            return 0;
        }

        x = p->data;
        p = p->next;
    }

    return 1;
}

void remove_dupes(struct Node *p) {
    struct Node *q = p->next;

    while(q != NULL) {
        if(p->data != q->data) {
            p = q;
            q = p->next;
        } else {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
} // Linked List must be sorted 

void reverse_list(struct Node *p) {
    int i = 0;
    int *A; 
    struct Node *q = p;

    A=(int *)malloc(sizeof(int) * list_length(p));

    while(q != NULL) {
        A[i] = q->data;
        q = q->next;
        i++;
    } 
    
    q = p;
    i--;

    while(q != NULL) {
        q->data = A[i];
        q = q->next;
        i--;
    }
} // using array, reversing the data

void reverse_list_pointers(struct Node *p) {
    struct Node *q = NULL, *r = NULL;
    
    while(p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first = q;
} // using sliding pointers

void reverse_list_rec(struct Node *q, struct Node *p) {
    if(p) {
        reverse_list_rec(p, p->next);
        p->next = q;
    } else {
        first = q;
    }
} // recursive

void concate(struct Node *p, struct Node *q){
    thd = p;    

    while(p->next != NULL) {
        p = p->next;
    }

    p->next = q;
}

void merge(struct Node *p, struct Node *q) {
    struct Node *last;

    if(p->data < q->data) {
        thd = last = p;
        p = p->next;
        thd->next = NULL;
    } else {
        thd = last = q;
        q = q->next;
        thd->next = NULL;
    }

    while (p && q) {
        if(p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p) last->next = p;
    if(q) last->next = q;
}
