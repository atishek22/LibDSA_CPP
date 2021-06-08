/** @file comparable.hpp
 * @brief Comparable concept 
 * @author Atishek Kumar
 * @date May 2021
 */
#ifndef DSA_COMPARABLE_HPP
#define DSA_COMPARABLE_HPP

#include<concepts>

/**@brief Comparable concept
 * @details Concept defining template objects that are comparable
 * i.e. have a total ordering.  
 */
template<typename T>
concept Comparable = requires(T a, T b) {
    {a == b} -> std::convertible_to<bool>;
    {a != b} -> std::convertible_to<bool>;
    {a > b} -> std::convertible_to<bool>;
    {a >= b} -> std::convertible_to<bool>;
    {a < b} -> std::convertible_to<bool>;
    {a <= b} -> std::convertible_to<bool>;
};

#endif //DSA_COMPARABLE_HPP
