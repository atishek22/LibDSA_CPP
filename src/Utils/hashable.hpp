/**@file hashable.hpp
 */

#ifndef DSA_CONCEPT_HASHABLE_HPP
#define DSA_CONCEPT_HASHABLE_HPP

#include<concepts>
#include<functional>

/** @brief Hashable Concept
 *  @details Constraint for the Key type in the hash table to types that have a \a std::hash implementation
 */
template<typename T>
concept Hashable = requires(T a) {
    {std::hash<T>{}(a)} -> std::convertible_to<size_t>;
};

#endif //DSA_CONCEPT_HASHABLE_HPP
