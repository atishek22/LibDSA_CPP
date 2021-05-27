/**
 * @file linear_sorting.hpp
 * @brief Linear Time Sorting
 * @details Special Linear Time Sorting Algorithms 
 * @author Atishek Kumar
 * @date May 2021
 * @warning Not thread safe and no error handling, shouldn't really be used just proof of concepts
 */
#ifndef ALGORITHMS_LINEAR_SORTING_HPP
#define ALGORITHMS_LINEAR_SORTING_HPP

#include<bits/stdc++.h>
#include"sorting.hpp"

/**@namespace linear_sorting
 * @details Constant flags for determining the sorting sequence for the algorithm
 */
namespace linear_sorting{
    /** @brief Sorting in increasing order 
     */
    const int INCREASING_ORDER = 0;
    /** @brief Sorting in  decreasing order 
     */
    const int DECREASING_ORDER = 1;
}

/**@brief Counting Sort Algorithm
 * @details Sorting Integer values in the range 0 to \a maximum. Increasing order by default.
 *
 * \f$O(n)\f$
 * @param v \a std::vector of integral values to be sorted
 * @param maximum maximum value of the element in \a v
 * @param compareFlag @ref linear_sorting constant defining sorted order
 * @tparam T Data type of the \a std::vector elements and \a maximum - Should be Integral
 */
template<std::integral T>
extern std::vector<T> countingSort(std::vector<T> v, T maximum , int compareFlag = linear_sorting::INCREASING_ORDER);

/**@brief Radix Sort Algorithm
 * @details Recusively sort the elements using the least significant to the most significant 
 * digit using a variation of countingSort()
 *
 * \f$O(n)\f$
 * @param v \a std::vector of integral values to be sorted
 * @param digit maximum number of digits in an element of \a v
 * @param maximum maximum value of each digit in an element of \a v
 * @param compareFlag @ref linear_sorting constant defining sorted order
 * @tparam T Data type of the \a std::vector elements - Should be Integral
 */
template<std::integral T>
extern std::vector<T> radixSort(std::vector<T> v, int digits, int maximum = 9, int compareFlag = linear_sorting::INCREASING_ORDER);

/** @brief Normalise the \a std::vector for bucketSort()
 * @details Normalises the value in the vector to the range \f$[0,1)\f$
 *
 * Should be called before calling bucketSort().
 *
 *\f$O(n)\f$
 * @param v \a std::vector of values to be normalised
 * @tparam T Data type of the \a std::vector element - should be floating point
 */
//TODO(Implement the function and compute callback function)
template<std::floating_point T>
extern void normalise(std::vector<T> &v, std::function<T(T)> compute);

/**@brief Bucket Sort Algorithm
 * @details Sorts values in the range \f$[0,1)\f$ by bucketting the values then 
 * sorting the buckets using insertion sort
 *
 * Also see normalise()
 *
 * \f$O(n)\f$
 * @param v \a std::vector of integral values to be sorted
 * @param compareFlag @ref linear_sorting constant defining sorted order
 * @tparam T Data type of the \a std::vector elements - Should be floating_point 
 */
template<std::floating_point T>
extern std::vector<T> bucketSort(std::vector<T> v, int compareFlag = linear_sorting::INCREASING_ORDER);

#endif //ALGORITHMS_LINEAR_SORTING_HPP
