#include "dynamic_array.hpp"

/*
 * Constructors and Destructor
 */
template<typename T> DynamicArray<T>::DynamicArray() {
    try {
        len = 0;
        capacity = 2;
        arr = new T[2];
    } catch(std::bad_alloc &e) {
        std::cerr << "Unable to allocate the array \n";
        throw std::bad_alloc();
    }
}

template<typename T> DynamicArray<T>::DynamicArray(int sz){
    try {
        len = 0;
        capacity = sz;
        arr = new T[sz];
    } catch(std::bad_alloc &e) {
        std::cerr << "Unable to allocate the array \n";
        throw std::bad_alloc();
    }
}

template<typename T> DynamicArray<T>::DynamicArray(std::initializer_list<T> l) {
    try {
        len = 0;
        capacity = l.size();
        arr = new T[capacity];
        for(const auto & val: l) {
            add(val);
        }
    } catch(std::bad_alloc &e) {
        std::cerr << "Unable to allocate the array \n";
        throw std::bad_alloc();
    }
}

template<typename T> DynamicArray<T>::~DynamicArray() {
    delete[] arr;
}

/*
 * Private functions
 */

template<typename T> void DynamicArray<T>::increaseCapacity() {
    if(capacity == 0) capacity = 1;
    else if(len+1 >= capacity) capacity *= 2;
    else return;
    T *newarr = new T[capacity];
    for(int i = 0; i < len; i++) newarr[i] = arr[i];
    delete[] arr;
    arr = newarr;
}

template<typename T> void DynamicArray<T>::decreaseCapacity() {
    if(len - 1 == 0) capacity = 0;
    else if(len - 1 <= capacity / 2) capacity /= 2;
    else return;
    T *newarr = new T[capacity];
    for(int i = 0; i < len; i++) newarr[i] = arr[i];
    delete[] arr;
    arr = newarr;
}

/*
 * Public Functions
 */
template<typename T> size_t DynamicArray<T>::size() noexcept{
    return len;
}

template<typename T> bool DynamicArray<T>::isEmpty() noexcept{
    return size() == 0;
}

template<typename T> T DynamicArray<T>::get(int index) {
    if(index >= size() || index < 0)
        throw std::out_of_range("Index out of range");
    return arr[index];
}

template<typename T> void DynamicArray<T>::set(int index, T value) {
    if(index >= size() || index < 0)
        throw std::out_of_range("Index out of range");
    arr[index] = value;
}

template<typename T> void DynamicArray<T>::clear() {
    delete[] arr;
    arr = new T[capacity];
    len = 0;
}


template<typename T> void DynamicArray<T>::add(T element) {
    if(len+1 >= capacity){
        try{
            increaseCapacity();
        } catch(std::bad_alloc &e) {
            throw std::runtime_error("Couldn't add the element to the array");
        }
    }
    arr[len++] = element;
}

template<typename T> bool DynamicArray<T>::removeAt(int index) {

    if(index >= len || index < 0) throw std::out_of_range("Index out of bounds");

    for(int i = index; i < len; i++) {
        arr[i] = arr[i+1];
    }
    try {
        decreaseCapacity();
    } catch(std::bad_alloc &e) {
        throw std::runtime_error("Couldn't remove the element");
    }
    len--;
    return true;
}

template<typename T> bool DynamicArray<T>::remove(T value){
    int index;
    index = indexOf(value);
    if(index == -1) return false;
    return removeAt(index);
}

template<typename T> int DynamicArray<T>::indexOf(T element) noexcept{
    for(int i = 0; i < len; i++){
        if(element == arr[i])
            return i;
    }
    return -1;
}

template<typename T> bool DynamicArray<T>::contains(T element) noexcept{
    return indexOf(element) != -1;
}

template<typename T> void DynamicArray<T>::print() noexcept {
    if(isEmpty()) {
        std::cout << "Array is empty \n";
        return;
    }
    for(int i = 0; i < len-1; i++){
        std::cout<<arr[i]<<",";
    }
    std::cout<<arr[len-1]<<std::endl;
}

template<typename T>
T& DynamicArray<T>::operator[](int index) {
    if(index < 0) {
        index = size() + index;
    }
    if(index >= size() || index < 0)
        throw std::out_of_range("Index out of range");
    return arr[index];
}
