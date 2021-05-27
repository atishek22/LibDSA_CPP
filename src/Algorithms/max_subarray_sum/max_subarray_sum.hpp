/**
 * @file max_subarray_sum.hpp
 * @brief Maximum Subarray Sum Algorithms
 * @details Implementations for calculating the maximum subarray sum using \a std::vector.
 *          The implementation is valid for arithmetic types as defined by 
 *          \a std::is_arithmetic<>.
 * @author Atishek Kumar
 * @date May 2021
 * @warning Not thread safe and minimal error handling
 */
#ifndef ALGORITHMS_MAX_SUBARRAY_SUM_HPP
#define ALGORITHMS_MAX_SUBARRAY_SUM_HPP


#include<bits/stdc++.h>

/** @brief Arithmetic concept
 * @details Template specialisation for arithmetic (numerical) types. 
 * 
 * Extension of \a std::integral and \a std::floating_point
 */
template<typename T>
concept arithmetic = std::integral<T> || std::floating_point<T>;

/**
 * @brief Maximum Subarray Sum
 *
 * Function for finding the maximum subarray sum for the \a std::vector \a v. The function
 * also computes the indices demarcating the required subarray. 
 *
 * \f$O(n \log n)\f$
 * 
 * @param v \a std::vector containing the array values
 * @tparam T Numerical data type of the \a std::vector elements
 * @return tuple consisting of the starting, ending subarray indices and the maximum sum
 */
template <arithmetic T>
extern std::tuple<int, int, T> max_subarray_sum(std::vector<T> v);

/**
 * @brief Maximum Subarray Sum Fast
 *
 * A faster implementation of max_subarray_sum(). The function calculates only the
 * maximum sum and not the indices of the subarray. 
 *
 * \f$O(n)\f$
 *
 * @param v \a std::vector containing the array values
 * @tparam T data type of the \a std::vector elements
 * @return maximum sum value
 */
template <arithmetic T>
extern T max_subarray_sum_fast(std::vector<T> v);

#endif //ALGORITHMS_MAX_SUBARRAY_SUM_HPP
