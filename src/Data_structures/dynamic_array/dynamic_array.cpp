#include "dynamic_array.hpp"

template<typename T> DynamicArray<T>::DynamicArray() {
  arr = new T[2];
  len = 0;
  capacity = 2;
}

template<typename T> DynamicArray<T>::DynamicArray(int sz){
  arr = new T[sz];
  len = 0;
  capacity = sz;
}

template<typename T> DynamicArray<T>::~DynamicArray() {
  delete[] arr;
}

template<typename T> int DynamicArray<T>::size() {
  return len;
}

template<typename T> bool DynamicArray<T>::isEmpty() {
  return size() == 0;
}

template<typename T> T DynamicArray<T>::get(int index) {
  return arr[index];
}

template<typename T> void DynamicArray<T>::set(int index, T value) {
  arr[index] = value;
}

template<typename T> void DynamicArray<T>::clear() {
  delete[] arr;
  arr = new T[capacity];
  len = 0;
}

template<typename T> void DynamicArray<T>::increaseCapacity() {
  if(capacity == 0) capacity = 1;
  else if(len+1 >= capacity) capacity *= 2;
}

template<typename T> void DynamicArray<T>::decreaseCapacity() {
  if(len - 1 == 0) capacity = 0;
  else if(len - 1 <= capacity / 2) capacity /= 2;
}

template<typename T> void DynamicArray<T>::add(T element) {
  if(len+1 >= capacity){
    increaseCapacity();
    T *newarr = new T[capacity];
    for(int i = 0; i < len; i++) newarr[i] = arr[i];
    delete[] arr;
    arr = newarr;
  }
  arr[len++] = element;
}

template<typename T> void DynamicArray<T>::removeAt(int index) {
  
  if(index >= len || index < 0) throw std::out_of_range("Index out of bounds");

  T data = arr[index];
  decreaseCapacity();
  T *newarr = new T[capacity];
  for(int i = 0, j = 0; i < len; i++, j++){
      if(i == index) j--;
      else newarr[j] = arr[i];
  }
  delete[] arr;
  arr = newarr;
  len--;
}

template<typename T> bool DynamicArray<T>::remove(T value){
  int index;
  index = indexOf(value);
  if(index == -1) return false;
  removeAt(index);
  return true;
}

template<typename T> int DynamicArray<T>::indexOf(T element) {
  for(int i = 0; i < len; i++){
      if(element == arr[i])
          return i;
  }
  return -1;
}

template<typename T> bool DynamicArray<T>::contains(T element) {
  return indexOf(element) != -1;
}

template<typename T> void DynamicArray<T>::print() {
  if(isEmpty()) {
    std::cout << "Array is empty \n";
    return;
  }
  for(int i = 0; i < len-1; i++){
      std::cout<<arr[i]<<",";
  }
  std::cout<<arr[len-1]<<std::endl;
}

