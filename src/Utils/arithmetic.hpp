/**@file arithmetic.hpp
 */

#ifndef DSA_CONCEPT_ARITHMETIC_HPP
#define DSA_CONCEPT_ARITHMETIC_HPP

#include<concepts>

/** @brief Arithmetic concept
 * @details Template specialisation for arithmetic (numerical) types. 
 * 
 * Extension of \a std::integral and \a std::floating_point
 */
template<typename T>
concept Arithmetic = std::integral<T> || std::floating_point<T>;

#endif //DSA_CONCEPT_ARITHMETIC_HPP
