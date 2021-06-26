/** @file container.hpp
 */

#ifndef DSA_CONCEPT_CONTAINER_HPP
#define DSA_CONCEPT_CONTAINER_HPP

#include<concepts>
#include<functional>

#include "comparable.hpp"

/** @brief Order Container concept
 * @details Concept defining containers that have a total ordering
 */
template<typename T>
concept OrderedContainer = Comparable<T> && requires(T a) {
    { a.size() } -> std::same_as<typename T::size_type>;
};

#endif //DSA_CONCEPT_CONTAINER_HPP
