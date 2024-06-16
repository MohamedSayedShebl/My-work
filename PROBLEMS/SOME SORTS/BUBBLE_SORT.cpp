#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        // Last i elements are already sorted, no need to check them
        for (int j = 0; j < n - i - 1; ++j) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped in the inner loop, the array is sorted
        if (!swapped)
            break;
    }
}

int main() {
    vector<int> arr = {12, 34, 54, 2, 3};
    
    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    
    bubbleSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
