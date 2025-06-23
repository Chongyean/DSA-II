#include <iostream>
using namespace std;

//Partition function that rearranges the array elements
int PartitionIt(int arr[], int left, int right, int pivot) {
    int leftPtr = left - 1;
    int rightPtr = right;

    while (true) {
        while (arr[++leftPtr] < pivot) { // ++leftPtr like pre-increment and use value to access the array
        
            // move right
        }
        while (rightPtr > 0 && arr[--rightPtr] > pivot) {
            // move left
        }
        if (leftPtr >= rightPtr) {
            break;
        } else {
            swap(arr[leftPtr], arr[rightPtr]);
        }
    }
    swap(arr[leftPtr], arr[right]);
    return leftPtr;
}

void recQuickSort(int arr[], int left, int right) {
    if (left >= right) {
        return; // Already sorted
    } else {
        int pivot = arr[right];
        int partition = PartitionIt(arr, left, right, pivot);
        recQuickSort(arr, left, partition - 1);
        recQuickSort(arr, partition + 1, right);
    }
}

void quickSort(int arr[], int size) {
    recQuickSort(arr, 0, size - 1);
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {24, 2, 45, 20, 56, 75, 2, 56, 99, 53, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, size);
    
    quickSort(arr, size);
    
    cout << "Sorted array: ";
    printArray(arr, size);
    
    return 0;
}
