#include "linkedlist.h"

int main(void) {
    /* struct Node *t1, *t2; */

    int A[] = {2,4,6,8,10};
    create_list(A, 5);

    printf("List 1: ");
    display_list(first);

    /* t1 = first->next->next; */
    /* t2 = first->next->next->next->next; */
    /* t2->next = t1; */

    /* printf("Loop: %d\n", has_loop(first)); */

    printf("List Length: %d\n",list_length(first));
    printf("List Sum:    %d\n",list_sum(first));
    printf("Max E:       %d\n", max_rec(first));

    struct Node *p = search_list(first, 6);
    printf("Found:       %d\n", p->data);

    insert_at(first, 1, 3);
    display_list(first);

    sorted_insert(first, 5);
    printf("Insert 5 (sorted): ");
    display_list(first);

    if(is_sorted(first)) {
        printf("Sorted.\n");
        display_list(first);
    } else {
        printf("Not Sorted.\n");
    }

    return 0;
}
