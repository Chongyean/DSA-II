#include <iostream>
#include <vector>
using namespace std;

// Partition function
int PartitionIt(vector<int>& arr, int left, int right, int pivot) {
    int leftPtr = left - 1;
    int rightPtr = right;

    while (true) {
        while (arr[++leftPtr] < pivot) {
            // Move right
        }
        while (rightPtr > 0 && arr[--rightPtr] > pivot) {
            // Move left
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

// Recursive Quicksort function
void recQuickSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return; // Already sorted
    } else {
        int pivot = arr[right]; // Pivot is the rightmost element
        int partition = PartitionIt(arr, left, right, pivot);
        recQuickSort(arr, left, partition - 1);     // Sort left side
        recQuickSort(arr, partition + 1, right);    // Sort right side
    }
}

// Helper function to call recQuickSort
void quickSort(vector<int>& arr) {
    recQuickSort(arr, 0, arr.size() - 1);
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {24, 2, 45, 20, 56, 75, 2, 56, 99, 53, 12};
    
    cout << "Original array: ";
    printArray(arr);
    
    quickSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}
