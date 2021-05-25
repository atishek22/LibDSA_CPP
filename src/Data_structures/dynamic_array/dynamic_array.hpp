#ifndef DATA_STRUCTURES_DYNAMICARRAY_HPP
#define DATA_STRUCTURES_DYNAMICARRAY_HPP

// TODO(Optimsize deletions)

#include<bits/stdc++.h>

/*
 * Dynamic Array (Vector) Implementation using C-styled arrays
 */
template<typename T>
class DynamicArray {
private:
    T *arr;
    int len{};
    int capacity{};

    void increaseCapacity();
    void decreaseCapacity();


public:
    /* Constructor with initial size */
    DynamicArray(int sz);

    /* Default constructor with inital size = 2 */
    DynamicArray();

    /* Clearing up */
    ~DynamicArray();

    /* returns the size of the dynamic arrays */
    int size();

    /* checks if the array is empty */
    bool isEmpty();

    /* getter and setters */
    T get(int index);
    void set(int index, T value);

    /* clear the array */
    void clear();

    /* adding an element to the array */
    void add(T element);

    /* remove at a particular index */
    void removeAt(int index);

    /* remove a particular value from the array */
    bool remove(T value);

    /* return the index of the argument in the array */
    int indexOf(T element);

    /* checks if the array contains an element */
    bool contains(T element);

    /* printing function */
    void print();
};

#endif //DATA_STRUCTURES_DYNAMICARRAY_HPP


