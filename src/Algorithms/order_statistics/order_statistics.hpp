/** @file order_statistics.hpp
 * @brief Order Statistics
 * @details Algorithms for finding and element using its \a order in the \a std::vector
 * @author Atishek Kumar
 * @date May 2021
 * @warning Not thread safe and minimal error handling
 */
#ifndef ALGORITHMS_ORDER_STATISTICS_HPP
#define ALGORITHMS_ORDER_STATISTICS_HPP

#include<bits/stdc++.h>
#include"../sorting/sorting.hpp"
#include"../../Utils/comparable.hpp"

/** @brief Maximum Value
 * @details Get the \a maximum value in the \a std::vector
 * @param v \a std::vector containing the values
 * @tparam T Data type of the \a std::vector elements
 * @return Maximum value in the \a std::vector
 * @exception std::runtime_error - When the \a std::vector is empty  
 */
template<Comparable T>
T maxVal(std::vector<T> v);

/** @brief Minimum Value
 * @details Get the \a minimum value in the \a std::vector
 * @param v \a std::vector containing the values
 * @tparam T Data type of the \a std::vector elements
 * @return Mimimum value in the \a std::vector
 * @exception std::runtime_error - When the \a std::vector is empty  
 */
template<Comparable T>
T minVal(std::vector<T> v);

/** @brief Maximum and Minimum Value
 * @details Get the \a maximum and \a minimum value in the \a std::vector
 * @param v \a std::vector containing the values
 * @tparam T Data type of the \a std::vector elements
 * @return std::pair containing the minimum and maximum values respectively
 * @exception std::runtime_error - When the \a std::vector is empty  
 */
template<Comparable T>
std::pair<T, T> minmaxVal(std::vector<T> v);

/** @brief \a Order element's value
 * @details Get the value of the \a order element in the \a std::vector 
 * @param v \a std::vector containing the values
 * @param order of the element
 * @tparam T Data type of the \a std::vector elements
 * @return Maximum value in the \a std::vector
 * @exception std::runtime_error - When the \a std::vector is empty  
 * @exception std::out_of_range - Invalid \a order value.
 */
template<Comparable T>
T selectElement(std::vector<T> v, int order);

#endif //ALGORITHMS_ORDER_STATISTICS
