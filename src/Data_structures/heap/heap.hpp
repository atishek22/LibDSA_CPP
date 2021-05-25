#ifndef DATA_STRUCTURES_HEAP_HPP
#define DATA_STRUCTURES_HEAP_HPP

#include<bits/stdc++.h>

/*
 * Heap Implementation using std::vector
 */

// Min-heap and Max-heap constants

namespace heap {
  const int MAX_HEAP = 0;
  const int MIN_HEAP = 1;
}

// macros

#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)
#define PARENT(i) ((i - 1) / 2)

// class implementation

template<typename T>
class Heap {
  private:
    std::vector<T> arr{};
    std::function<bool(T,T)> compare;
    int type;

    /* Private Functions */

    void heapify_bottom_up(int i);

    void heapify_top_down(int i);

    bool remove_at(int i);

    int containsInternal(T key);

    std::function<bool(T, T)> max_heap = [](T first, T second) {
      return first > second;
    };

    std::function<bool(T, T)> min_heap = [](T first, T second) {
      return first < second;
    };

  public:
    /* Default constructor: creates an empty max-heap */
    Heap();

    /* Constructor: Empty heap of the argument-type */
    Heap(int type);

    /* Constructor: Create the heap with the vector and type specified */
    Heap(std::vector<T> v, int type);

    ~Heap();

    size_t size() {
      return arr.size();
    }

    /* Heap Opertions */
    /* Floats down the value at index i if it violates the heap invariant */
    void heapify(int i);

    /* Build out the heap from the vector */
    void build_heap();

    /* Insert a value in the heap */
    bool insert(T data);

    /* Remove the root of the heap */
    T poll();

    /* Just return the root of the heap */
    T peek();

    /* Remove a paricular element from the heap (slow) */
    bool remove(T data);

    /* Clear the heap */
    void clear() {
      arr.clear();
    }

    /* check if the heap contains the  */
    bool contains(T key);

    /* modify key */
    bool modifyKey(T oldKey, T newKey);

};

#endif //DATA_STRUCTURES_HEAP_HPP
