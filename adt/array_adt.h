#include <stdio.h>

struct Array {
    int *A;
    int size;
    int length;
};

void display(struct Array arr) {
    int i;

    for(i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
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

int linear_search(struct Array arr, int x) {
    for(int i = 0; i < arr.length; i++) {
        if(arr.A[i] == x) {
            return i;
        }
    }
}
