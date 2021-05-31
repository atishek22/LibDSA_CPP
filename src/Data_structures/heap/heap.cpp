#include"heap.hpp"


/* Constructor Destructor */

template<typename T>
Heap<T>::Heap() {
    compare = max_heap;
    type = heap::MAX_HEAP;
}

template<typename T>
Heap<T>::Heap(int t) {
    if(t == heap::MIN_HEAP) {
        compare = min_heap;
        type = heap::MIN_HEAP;
    } else {
        compare = max_heap;
        type = heap::MAX_HEAP;
    }
}

template<typename T>
Heap<T>::Heap(std::vector<T> v, int t) {
    arr = v;
    if(t == heap::MIN_HEAP) {
        compare = min_heap;
        this->type = heap::MIN_HEAP;
    } else {
        compare = max_heap;
        this->type = heap::MAX_HEAP;
    }
    build_heap();
}

template<typename T>
Heap<T>::Heap(std::initializer_list<T> l, int t) {
    arr = std::vector<T>(l);
    if(t == heap::MIN_HEAP) {
        compare = min_heap;
        this->type = heap::MIN_HEAP;
    } else {
        compare = max_heap;
        this->type = heap::MAX_HEAP;
    }
    build_heap();
}

template<typename T>
Heap<T>::~Heap() {
    arr.clear();
}

/* Private functions */

template<typename T>
void Heap<T>::heapify_top_down(int i) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = 0;
    if(l < arr.size() && compare(arr[l], arr[i])) {
        largest = l;
    } else largest = i;
    if(r < arr.size() && compare(arr[r], arr[largest])) {
        largest = r;
    }

    if(largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify_top_down(largest);
    }
}

template<typename T>
void Heap<T>::heapify_bottom_up(int i) {
    int p = PARENT(i);
    if(p >= 0) {
        if(compare(arr[i], arr[p])) {
            std::swap(arr[i], arr[p]);
            heapify_bottom_up(p);
        }
    }
}

template<typename T>
bool Heap<T>::remove_at(int index) {
    for(int i = index; i < size() - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr.pop_back();
    return true;
}

template <typename T>
int Heap<T>::containsInternal(T key) {
    int index = -1;
    for(int i = 0; i < size(); i++) {
        if(arr[i] == key) {
            index = i;
        }
    }
    return index;
}

/* public functions/ Heap Opertions */

template<typename T>
void Heap<T>::heapify(int i) {
    heapify_top_down(i);
}

template<typename T>
void Heap<T>::build_heap() {
    for(int i = arr.size()/2; i >= 0; i--) {
        heapify(i);
    }
}

template<typename T>
bool Heap<T>::insert(T data) {
    arr.push_back(data);
    heapify_bottom_up(arr.size() - 1);
    return true;
}

template<typename T>
T Heap<T>::poll() {
    T ret;
    if(size() == 1) {
        ret = arr[0];
        clear();
    } else {
        ret = arr[0];
        arr[0] = arr.back();
        arr.pop_back();
        heapify(0);
    }
    return ret;
}

template<typename T>
T Heap<T>::peek() {
    return arr[0];
}

template<typename T>
bool Heap<T>::remove(T data) {
    int index = containsInternal(data);
    if(index != -1) {
        return remove_at(index);
    }
    return false;
}

template<typename T>
bool Heap<T>::contains(T key) {
    int index = containsInternal(key);
    if(index == -1) return false;
    else return true;
}

template <typename T>
bool Heap<T>::modifyKey(T oldKey, T newKey) {
    int index = containsInternal(oldKey);
    if(index == -1) return false;
    arr[index] = newKey;
    if(oldKey < newKey) {
        if(type == heap::MAX_HEAP) {
            heapify_bottom_up(index);
        } else {
            heapify_top_down(index);
        }
    } else {
        if(type == heap::MAX_HEAP) {
            heapify_top_down(index);
        } else {
            heapify_bottom_up(index);
        }
    }
    return true;
}
