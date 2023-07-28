#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];
    int size;
    int length;
};

void display(struct Array arr) {
    int i;
    printf("{");
    for(i = 0; i < arr.length; i++) {
        printf(" %d ", arr.A[i]);
    }
    printf("}\n");
}

void append(struct Array *arr, int x) {
    if(arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void insert(struct Array *arr, int index, int x) {
    if(index >= 0 && index < arr->length) {
        for(int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i-1];
        }

        arr->A[index] = x;
        arr->length++;
    }
}

int arr_remove(struct Array *arr, int index) {
    int x = 0;

    if(index >= 0 && index < arr->length){
        x = arr->A[index];

        for(int i = index; i < arr->length - 1; i++){
            arr->A[i] = arr->A[i + 1];
        }

        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y) {
    int t;

    t = *x;
    *x = *y;
    *y = t;
} // transposition for improving linear search.

int linear_search(struct Array *arr, int key) {
    for(int i = 0; i < arr->length; i++) {
        if(arr->A[i] == key) {
            swap(&arr->A[i], &arr->A[0]); // move found element to head for O(1) access on future searches.
            return i;
        }
    }
    return -1;
}

int binary_search(struct Array arr, int key) {
    int low, mid, hi;
    low = 0;
    hi = arr.length - 1;

    while(low <= hi) {
        mid = (low + hi) / 2;

        if (key == arr.A[mid]) {
            return mid;
        } else if (key < arr.A[mid]) {
            hi = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
} // array must be sorted for binary search to work

int rec_binary_search(int arr[], int l, int h, int key) {
    int mid;

    if(l <= h) {
        mid = (l + h) / 2;
        if(key == arr[mid]) {
            return mid;
        } else if (key < arr[mid]) {
            return rec_binary_search(arr, l, mid - 1, key);
        } else {
            return rec_binary_search(arr, mid + 1, h, key);
        }
    }
    return -1;
}

int get_element(struct Array arr, int index) {
    if(index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

void set_element(struct Array *arr, int index, int x) {
    if(index >= 0 && index < arr->length) {
        arr->A[index] = x;
    }
}

int max(struct Array arr) {
    int max = arr.A[0];

    for(int i = 1; i < arr.length; i++) {
        if(arr.A[i] > max) {
            max = arr.A[i];
        }
    }
     return max;
}

int min(struct Array arr) {
    int min = arr.A[0];

    for(int i = 1; i < arr.length; i++) {
        if(arr.A[i] < min) {
            min = arr.A[i];
        }
    }

    return min;
}

int sum(struct Array arr) {
    int s = 0;

    for(int i = 0; i < arr.length; i++) {
        s += arr.A[i];
    }

    return s;
}

float avg(struct Array arr) {
    return (float) sum(arr) / arr.length;
}

void reverse(struct Array *arr) {
    int *b;
    int i,j;

    b=(int *)malloc(arr->length * sizeof(int));

    for(i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        b[j] = arr->A[i];
    }

    for(i = 0; i > arr->length; i++) {
        arr->A[i] = b[i];
    }
}

void reverse_swap(struct Array *arr) {
    int i, j;

    for(i = 0, j = arr->length - 1; i < j; i++, j--) {
        swap(&arr->A[i], &arr->A[j]);
    }
}
