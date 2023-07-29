#include <iostream>

class ArrayADT {
    private:
        int *A;
        int size;
        int length;

        void Swap(int *x, int *y);

    public:
        ArrayADT() {
            size = 10;
            length = 0;
            A = new int[size];
        }

        ArrayADT(int size) {
            this->size = size;
            length = 0;
            A = new int[size];
        }

        ~ArrayADT() {
            delete []A;
        }
    
        void Display();
        void Append(int x);
        void Insert(int index, int x);
        int Remove(int index);
        int LinearSearch(int key);
        int BinarySearch(int key);
        int Get(int index);
        void Set(int index, int x);
        int Max();
        int Min();
        int Sum();
        float Avg();
        void Reverse();
        void InsertSorted(int x);
        int IsSorted();
        ArrayADT* Merge(ArrayADT arr2);
};

void ArrayADT::Display() {
        int i;
        printf("{");
        for (i = 0; i < length; i++)
        {
            printf(" %d ", A[i]);
        }
        printf("}\n");
}

void ArrayADT::Append(int x) {
    if (length < size) {
        A[length++] = x;
    }
}

void ArrayADT::Insert(int index, int x) {
    if (index >= 0 && index < length)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }

        A[index] = x;
        length++;
    }
}

int ArrayADT::Remove(int index) {
    int x = 0;

    if (index >= 0 && index < length)
    {
        x = A[index];

        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }

        length--;
        return x;
    }
    return 0;
}

void ArrayADT::Swap(int *x, int *y) {
    int t;

    t = *x;
    *x = *y;
    *y = t;
}

int ArrayADT::LinearSearch(int key) {
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            Swap(&A[i], &A[0]); // move found element to head for O(1) access on future searches.
            return i;
        }
    }
    return -1;
}
int ArrayADT::BinarySearch(int key) {
    int low, mid, hi;
    low = 0;
    hi = length - 1;

    while(low < hi) {
        mid = (low + hi) / 2;

        if(key == A[mid]) {
            return mid;
        } else if (key > A[mid]) {
            low = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return -1;
}

int ArrayADT::Get(int index) {
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    return -1;
}

void ArrayADT::Set(int index, int x) {
    if (index >= 0 && index < length)
    {
        A[index] = x;
    }
}

int ArrayADT::Max() {
    int max = A[0];

    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

int ArrayADT::Min() {
    int min = A[0];

    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }

    return min;
}

int ArrayADT::Sum() {
    int s = 0;

    for (int i = 0; i < length; i++)
    {
        s += A[i];
    }

    return s;
}

float ArrayADT::Avg() {
    return (float) Sum() / length;
}

void ArrayADT::Reverse() {
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        Swap(&A[i], &A[j]);
    }
}

void ArrayADT::InsertSorted(int x) {
    int i = length - 1;

    if (length == size)
    {
        return;
    }

    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }

    A[i + 1] = x;
    length++;
}

int ArrayADT::IsSorted() {
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

ArrayADT* ArrayADT::Merge(ArrayADT arr2) {
    int i = 0, j = 0, k = 0;
    ArrayADT *arr3 = new ArrayADT(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2.A[j++];
        }
    }

    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }

    for (; j < arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }

    arr3->length = length + arr2.length;

    return arr3;
}

int main(void) {
    ArrayADT *arr = new ArrayADT(10);
    arr->Append(2);
    arr->Append(4);
    arr->Append(6);
    arr->Append(8);
    arr->Append(10);
    arr->Insert(1, 3);
    arr->Insert(3, 5);
    arr->Display();
    int i = arr->BinarySearch(5);
    std::cout << "5 found at index: " << i << std::endl;

    arr->Reverse();
    arr->Display();
    return 0;
}