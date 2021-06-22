#include "sorting.hpp"

namespace {
    /*
     * Helper Merge function
     */
    template<Comparable T>
        void merge(std::vector<T> &v, int low, int mid, int high, std::function<bool(T, T)> compare) {
            std::vector<T> L, R;
            for (int i = low; i <= mid; i++) L.push_back(v[i]);
            for (int i = mid + 1; i <= high; i++) R.push_back(v[i]);

            int i = 0, j = 0;
            for (int k = low; k <= high; k++) {
                if (i == L.size()) {
                    v[k] = R[j++];
                } else if (j == R.size()) {
                    v[k] = L[i++];
                } else {
                    if (compare(R[j], L[i])) {
                        v[k] = L[i++];
                    } else {
                        v[k] = R[j++];
                    }
                }
            }
        }

    /*
     * Recursive merge sort helper function
     */
    template<Comparable T>
        void mergeSortRecur(std::vector<T> &v, int low, int high, std::function<bool(T, T)> compare) {
            if (low < high) {
                int mid = (low + high) / 2;
                mergeSortRecur(v, low, mid, compare);
                mergeSortRecur(v, mid + 1, high, compare);
                merge(v, low, mid, high, compare);
            }
        }

    template<Comparable T>
        void quickSortRecur(std::vector<T> &v, int low, int high, std::function<bool(T,T)> compare) {
            if(low < high) {
                int q = partition(v, compare, low, high);
                quickSortRecur(v, low, q-1, compare);
                quickSortRecur(v, q+1, high, compare);
            }
        }

    template<Comparable T>
        void randomisedQuickSortRecur(std::vector<T> &v, int low, int high, std::function<bool(T,T)> compare) {
            if(low < high) {
                int q = randomisedPartition(v, compare, low, high);
                randomisedQuickSortRecur(v, low, q-1, compare);
                randomisedQuickSortRecur(v, q+1, high, compare);
            }
        }
}

template<Comparable T>
void insertionSort(std::vector<T> &v, std::function<bool(T, T)> compare) {
    for (int j = 1; j < v.size(); j++) {
        T key = v[j];
        int i = j - 1;
        while (i >= 0 && compare(v[i], key)) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;
    }
}



template<Comparable T>
void mergeSort(std::vector<T> &v, std::function<bool(T, T)> compare) {
    mergeSortRecur(v, 0, v.size() - 1, compare);
}


template<Comparable T>
void heapSort(std::vector<T> &v, int compareFlag) {
    Heap<T> h(v, compareFlag);
    for(int i = v.size() - 1; i >= 0; i--) {
        v[i] = h.poll();
    }
}

template<Comparable T>
int partition(std::vector<T> &v, std::function<bool(T,T)> compare, int low, int high) {
    T pivot = v[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(compare(pivot, v[j])) {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i+1], v[high]);
    return i+1;
}

template<Comparable T>
void quickSort(std::vector<T> &v, std::function<bool(T,T)> compare) {
    quickSortRecur(v, 0, v.size() - 1, compare);
}

template<Comparable T>
int randomisedPartition(std::vector<T> &v, std::function<bool(T,T)> compare, int low, int high) {
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<> randomInt(low, high);
    int i = randomInt(e);
    std::swap(v[i], v[high]);
    return partition(v, compare, low, high);
}

template<Comparable T>
void randomisedQuickSort(std::vector<T> &v, std::function<bool(T,T)> compare) {
    randomisedQuickSortRecur(v, 0, v.size() - 1, compare);
}

