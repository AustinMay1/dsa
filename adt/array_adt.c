#include <stdlib.h>
#include "array_adt.h"

int main(void) {
    struct Array arr;
    int n, i;
    printf("Enter array size");
    scanf("%d", &arr.size);

    arr.A=(int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter # of elements to add");
    scanf("%d", &n);

    printf("Enter all elements\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;

    display(arr);
    printf("\n");
    append(&arr, 100);
    insert(&arr, 1, 22);
    display(arr);
    printf("%d\n", arr_remove(&arr, 1));
    display(arr);
    printf("%d", linear_search(arr, 3));    
    return 0;
}
