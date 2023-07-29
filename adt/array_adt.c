#include "array_adt.h"

int main(void)
{
    struct Array arr =  {{2, 4, 6, 8, 10}, 10, 5};
    struct Array brr =  {{10, -1, 13, 22, -7, -5, 4}, 10, 7};
    struct Array err =  {{2,4,6,8,10,12}, 10, 6};
    struct Array frr =  {{1,2,3,4,11,12}, 10, 6};
    struct Array *crr;
    struct Array *drr;
    struct Array *grr;
    struct Array *hrr;

    drr = find_union(&err, &frr);
    printf("Union: ");
    display(*drr);

    grr = find_intersection(&err, &frr);
    printf("Intersection: ");
    display(*grr);

    hrr = find_diff(&err, &frr);
    printf("Diff: ");
    display(*hrr);

    append(&arr, 12);
    insert(&arr, 3, 7);
    printf("Append 12 & insert 7 at index 3: ");
    display(arr);

    printf("E(4) found at index: %d\n", binary_search(arr, 4));
    printf("E found at index 3: %d\n", get_element(arr, 3));
    set_element(&arr, 0, 1);
    printf("Set element at index 0 to 1: ");
    display(arr);
    printf("Max: %d\n", max(arr));
    printf("Min: %d\n", min(arr));
    printf("Sum: %d\n", sum(arr));
    printf("Avg: %.2f\n", avg(arr));

    // printf("Reversed array: \n");
    // reverse_swap(&arr);
    // display(arr);

    insert_sorted(&arr, 5);
    printf("Insert 5 in-order: ");
    display(arr);
    printf("arr is sorted?: %d\n", is_sorted(arr));

    printf("Before: ");
    display(brr);
    printf("After: ");
    rearrange(&brr);
    display(brr);

    crr = merge_arrays(&arr, &brr);
    printf("Merged arr & brr: ");
    display(*crr);

    
    return 0;
}
