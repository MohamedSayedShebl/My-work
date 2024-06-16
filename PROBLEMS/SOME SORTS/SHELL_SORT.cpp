#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void shellSort(vector<T>& arr) {
    int n = arr.size();

    for (int gap = n/2; gap>0; gap/=2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i += 1) {
            // add arr[i] to the elements that have been gap sorted
            // save arr[i] in temp and make a hole at position i
            T temp = arr[i];

            // shift earlier gap-sorted elements up until the correct location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            // put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

int main() {
    vector<int> arr = {15, 26, 33, 5, 2};
    
    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    
    shellSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}