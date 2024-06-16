#ifndef DATASTUCTUREASS_SORTINGFUNCTIONS_H
#define DATASTUCTUREASS_SORTINGFUNCTIONS_H

template <typename T>
void selectionSort(vector<T>& arr, int& comparisons) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            ++comparisons;
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

template<typename T>
void shellSort(vector<T>& arr, int& comparisons) {
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
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
                ++comparisons;
            }
            // put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

template<typename T>
void bubbleSort(vector<T>& arr, int& comparisons) {
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
                ++comparisons;
            }
        }

        // If no two elements were swapped in the inner loop, the array is sorted
        if (!swapped)
            break;
    }
}

#endif //DATASTUCTUREASS_SORTINGFUNCTIONS_H
