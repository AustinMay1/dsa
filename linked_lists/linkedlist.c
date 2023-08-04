#include "linkedlist.h"

int main(void) {
    int A[] = {2,4,6,8,10};
    create_list(A, 5);

    printf("List Elements: ");
    display_list(first);

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

    return 0;
}
