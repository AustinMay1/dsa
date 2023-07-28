#include <stdlib.h>
#include "array_adt.h"

int main(void) {
    struct Array arr = {{2,4,6,8,10}, 10, 5};
    append(&arr, 12);
    insert(&arr, 3, 7);
    display(arr);

    printf("Element found at index: %d\n", binary_search(arr, 4));
    printf("E found at index 3: %d\n", get_element(arr, 3));
    set_element(&arr, 0, 1);
    printf("Set element at index 0 to 1\n");
    display(arr);
    printf("Max: %d\n", max(arr));
    printf("Min: %d\n", min(arr));
    printf("Sum: %d\n", sum(arr));
    printf("Avg: %.2f\n", avg(arr));

    printf("Reversed array: ");
    reverse_swap(&arr);
    display(arr);
    return 0;
}
