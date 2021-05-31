/** @file stack.hpp
 * @brief Stack Data Structure
 * @details Stack implementation using metaprogramming
 * @author Atishek Kumar
 * @date May 2021
 * @warning Not thread safe
 */
#ifndef DATA_STRUCTURES_STACK_HPP
#define DATA_STRUCTURES_STACK_HPP

#include<bits/stdc++.h>
#include"../dynamic_array/dynamic_array.hpp"

/**@brief Stack Data Structure Implementation
 * @details Stack Data Structure using @ref DynamicArray template class.
 * @tparam T Data type of the stack elements
 */
template<typename T>
class Stack {
private:
    DynamicArray<T>* stack;
    long long _top;
public:
    /** @brief Default constructor
     * @details Create an empty stack object
     * @tparam T Data type of the stack elements
     * @exception std::bad_alloc
     */
    Stack();

    /**@brief Constructor
     * @details Initialise the Stack object with the /a std::initializer_list elements
     * @param l \a std::initializer_list of initial elements
     * @tparam T Data type of the stack elements
     * @exception std::bad_alloc
     */
    Stack(std::initializer_list<T> l);

    /**@brief Destructor
     * @details Clear the stack object
     */
    ~Stack();

    /**@brief Push an \a element
     * @details Add the an \a element to the stack top
     * @param element to be added
     * @exception std::runtime_error 
     */
    void push(T element);

    /**@brief Pop the top \a element
     * @details Remove the top element from the stack
     * @return Boolean true for successful removal else false
     * @exception std::runtime_error
     */
    bool pop();

    /**@brief Get the top \a element
     * @details Get the top element's value from the stack
     * @return Top element's value
     * @exception std::runtime_error
     */
    T top();

    /**@brief Size of the stack - Number of elements
     * @return stack size
     */
    size_t size() noexcept {
        return stack->size();
    }

    /**@brief Check for empty stack
     * @return Boolean true if empty else false
     */
    bool isEmpty() noexcept;

};

#endif //DATA_STRUCTURES_STACK_HPP
