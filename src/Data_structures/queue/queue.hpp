/** @file queue.hpp
 *  @brief Queue Data Structure
 *  @details Queue implementation using metaprogramming
 *  @author Atishek Kumar
 *  @date June 2021
 *  @warning Not thread safe
 */
#ifndef DATA_STRUCTURES_QUEUE_HPP
#define DATA_STRUCTURES_QUEUE_HPP

#include<bits/stdc++.h>
/**@brief Queue Data Structure Implementation
 * @details Dynamically resizing Queue data structure using static arrays
 * @tparam T Data type of the Queue elements
 */
template<typename T>
class Queue {
private:
    T* arr;
    size_t head, tail;
    size_t _size;
    size_t capacity;

    void increaseCapacity();

    void decreaseCapacity();

public:
    /**@brief Default Constructor
     * @details Create an empty queue object
     * @tparam T Data type of the Queue element
     * @exception std::bad_alloc
     */
    Queue();

    /**@brief Constructor
     * @details Create an empty queue object with the initial queue size of \a sz
     * @param sz initial size / capacity
     * @tparam T Data type of the Queue element
     * @exception std::bad_alloc
     */
    Queue(size_t sz);

    /**@brief Constructor
     * @details Create a queue object with the elements of the \a std::initializer_list
     * @param _list initial list of elements
     * @tparam T Data type of the Queue element
     * @exception std::bad_alloc
     */
    Queue(std::initializer_list<T> _list);

    /**@brief Destructor
     * @details Clears the queue
     */
    ~Queue();

    /*Queue Operations */

    /**@brief Insert an element
     * @details Add an \a element at the end of the queue
     * @param element to be added
     * @exception std::runtime_error 
     */
    void enqueue(T element);

    /**@brief Remove the first element
     * @details Remove the first element from the queue and returns its value
     * @return First element's value;
     * @exception std::runtime_error 
     */
    T dequeue();

    /**@brief Front/First element
     * @details Get the value of the front/first element
     * @return Value of the first/front element
     * @exception std::runtime_error
     */
    T front();

    /**@brief Back/Last element
     * @details Get the value of the back/last element
     * @return Value of the back/last element
     * @exception std::runtime_error
     */
    T back();

    /**@brief Size of the queue
     * @return Number of elements in the queue
     */
    size_t size() noexcept {
        return _size;
    }

    /**@brief Checks if queue is empty
     * @return Boolean true if the queue is empty else false
     */
    bool empty() noexcept {
        return _size == 0;
    }

    /**@brief Checks if the queue is full
     * @return Boolean true if the queue is full
     */
    bool full() noexcept {
        return _size == capacity;
    }

    /**@brief Clears the queue 
     * @details Clears the queue and updates the required queue parameters accordingly
     */
    void clear() noexcept;
};

#endif //DATA_STRUCTURES_QUEUE_HPP

