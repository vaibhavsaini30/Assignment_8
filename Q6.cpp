#include <iostream>
#include <climits>
using namespace std;

void maxHeapify(int A[], int heapSize, int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if (left <= heapSize && A[left] > A[largest])
        largest = left;

    if (right <= heapSize && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, heapSize, largest);
    }
}

int heapMaximum(int A[]) {
    return A[1];
}

int heapExtractMax(int A[], int &heapSize) {
    if (heapSize < 1) {
        cout << "Heap underflow\n";
        return -1;
    }

    int max = A[1];
    A[1] = A[heapSize];
    heapSize--;
    maxHeapify(A, heapSize, 1);
    return max;
}

void heapIncreaseKey(int A[], int i, int key) {
    if (key < A[i]) {
        cout << "New key smaller than current key\n";
        return;
    }

    A[i] = key;
    while (i > 1 && A[i/2] < A[i]) {
        swap(A[i], A[i/2]);
        i = i / 2;
    }
}

void maxHeapInsert(int A[], int &heapSize, int key) {
    heapSize++;
    A[heapSize] = INT_MIN;      
    heapIncreaseKey(A, heapSize, key);  
}

int main() {
    int A[100];
    int heapSize = 0;

    maxHeapInsert(A, heapSize, 5);
    maxHeapInsert(A, heapSize, 3);
    maxHeapInsert(A, heapSize, 17);
    maxHeapInsert(A, heapSize, 10);
    maxHeapInsert(A, heapSize, 84);
    maxHeapInsert(A, heapSize, 19);
    maxHeapInsert(A, heapSize, 6);
    maxHeapInsert(A, heapSize, 22);
    maxHeapInsert(A, heapSize, 9);

    cout << "Max element: " << heapMaximum(A) << endl;

    cout << "Extract max: " << heapExtractMax(A, heapSize) << endl;

    cout << "Extract max: " << heapExtractMax(A, heapSize) << endl;

    return 0;
}
