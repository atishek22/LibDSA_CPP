/**
 * @file sorting.hpp
 * @brief Sorting Algorithms.
 * @details Popular Sorting Algorithms using metaprogramming and comparison callback support.
 * @author Atishek Kumar
 * @date May 2021
 * @warning Not thread safe and minimal error handling.
 */

#ifndef ALGORITHMS_SORTING_HPP
#define ALGORITHMS_SORTING_HPP

#include<bits/stdc++.h>

#include"../../Data_structures/heap/heap.hpp"

/** @namespace sorting
 *  @brief Predefined Standard Comparison Functions
 * 
 *  Template lambda functions for comparing elements in comparison sorts
 *  @param first 
 *  @param second
 *  @tparam T Data type of the elements to be compared
 *  @return boolean value
 */
namespace sorting {
    /** @brief Comparator for sorting in increasing order
     */
    template<typename T>
        std::function<bool(T, T)> increasingOrder = [](const T &first, const T &second) {
            return first > second;
        };

    /** @brief Comparator for sorting in decreasing order
     */
    template<typename T>
        std::function<bool(T, T)> decreasingOrder = [](const T &first, const T &second) {
            return first < second;
        };

    /** @brief Comparator for sorting in order of increasing length.
     *
     * Only valid for strings and other containers that have well defined sizes
     */
    template<typename T>
        std::function<bool(T, T)> lengthOrder = [](const T &first, const T &second) {
            if (first.size() == second.size()) return first > second;
            else return first.size() > second.size();
        };
}


/**
 * @brief Partition Function for Quick Sort
 *
 * Selects the last element as a pivot and partition the array 
 * about the value and the returns the index for the final position 
 * for the pivot. \f$O(n)\f$
 *
 * @param v reference to the vector
 * @param compare comparison function
 * @param low starting index of the subarray
 * @param high ending index of the subarray
 * @tparam T data type of the \a std::vector elements
 * @return index of the pivot after partition
 */
template<typename T>
extern int partition(std::vector<T> &v, std::function<bool(T,T)> compare, int low, int high);

/**
 * @brief Randomised Partition function for Randomised Quick Sort
 *
 * Selects a random pivot and partitions the array like partition(). 
 * \f$O(n)\f$
 *
 * @param v reference to the vector
 * @param compare comparison function
 * @param low starting index of the subarray
 * @param high ending index of the subarray
 * @tparam T data type of the \a std::vector elements
 * @return index of the pivot after partition
 */
template<typename T>
extern int randomisedPartition(std::vector<T> &v, std::function<bool(T,T)> compare, int low, int high);

/*
 * Sorting Algorithms
 */

/**
 * @brief Insertion Sort
 *
 * Insertion Sort implementation, ideal for a small number of elements,
 * increasing order by default. \f$O(n^2)\f$
 *
 * @param v reference of the vector to be sorted
 * @param compare comparison function
 * @tparam T data type of the \a std::vector elements
 * @return none
 */
template<typename T>
extern void insertionSort(std::vector<T> &v, std::function<bool(T, T)> compare = sorting::increasingOrder<T>);


/**
 * @brief Merge Sort
 * 
 * Recursive implementation of the merge sort algorithm, increasing 
 * order by default. \f$O(n \log n)\f$
 *
 * @param v reference of the vector to be sorted
 * @param compare comparison function
 * @tparam T data type of the \a std::vector elements
 * @return none
 */
template<typename T>
extern void mergeSort(std::vector<T> &v, std::function<bool(T, T)> compare = sorting::increasingOrder<T>);


/**
 * @brief Heap Sort
 *
 * Sort the elements of a vector using the Heap Data Structure
 * increasing order by default. \f$O(n \log n)\f$

 *
 * @param v reference of the vector to be sorted
 * @param compare comparison function
 * @tparam T data type of the \a std::vector elements
 * @return none
 */
template<typename T>
extern void heapSort(std::vector<T> &v, std::function<bool(T, T)> compare = sorting::increasingOrder<T>);


/**
 * @brief Quick Sort
 *
 * Quick Sort implementation, increasing order by default.
 * \f$O(n \log n)\f$
 *
 * @param v reference of the vector to be sorted
 * @param compare comparison function
 * @tparam T data type of the \a std::vector elements
 * @return none
 */
template<typename T>
extern void quickSort(std::vector<T> &v, std::function<bool(T, T)> compare = sorting::increasingOrder<T>);

/**
 * @brief Randomised Quick Sort
 *
 * Randomised Quick Sort implementation using a randomised partition for 
 * balanced partition and better performance than quickSort(). \f$O(n \log n)\f$
 *
 * @param v reference of the vector to be sorted
 * @param compare comparison function
 * @tparam T data type of the \a std::vector elements
 * @return none
 */
template<typename T>
extern void randomisedQuickSort(std::vector<T> &v, std::function<bool(T,T)> compare = sorting::increasingOrder<T>);

#endif //ALGORITHMS_SORTING_HPP

