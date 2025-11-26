#include <iostream>
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

void buildMaxHeap(int A[], int heapSize) {
    for (int i = heapSize / 2; i >= 1; i--)
        maxHeapify(A, heapSize, i);
}

void heapSortIncreasing(int A[], int heapSize) {
    buildMaxHeap(A, heapSize);

    for (int i = heapSize; i >= 2; i--) {
        swap(A[1], A[i]);
        heapSize--;
        maxHeapify(A, heapSize, 1);
    }
}

void heapSortDecreasing(int A[], int heapSize) {
    heapSortIncreasing(A, heapSize);

    int start = 1, end = heapSize;
    while (start < end) {
        swap(A[start], A[end]);
        start++;
        end--;
    }
}

int main() {
    int A[100] = {0, 4, 7, 3, 1, 2};
    int n = 5;

    heapSortIncreasing(A, n);
    cout << "Increasing Order: ";
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;

    int B[100] = {0, 4, 7, 3, 1, 2};
    heapSortDecreasing(B, n);
    cout << "Decreasing Order: ";
    for (int i = 1; i <= n; i++)
        cout << B[i] << " ";
    cout << endl;

    return 0;
}
