/**@file linked_list.hpp
 * @brief Linked List Implemetation using C++ templates
 * @author Atishek Kumar
 * @date June 2021
 * @warning Not thread safe
 */
#ifndef DATA_STRUCTURES_LINKED_LISTS
#define DATA_STRUCTURES_LINKED_LISTS

#include<stddef.h>
#include<initializer_list>
#include<stdexcept>
#include<iostream>

//TODO - Iterator implementation

/**@brief Linked List Implemetation
 * @details Doubly Linked List Implemetation using metaprogramming
 * @tparam T Data type of list elements
 */
template<typename T>
class LinkedList {

private:
    class Node {
    private:
        T data;
    public:
        Node *prev;
        Node *next;

        explicit Node(T d, Node *p = nullptr, Node *n = nullptr): 
          data(d), prev(p), next(n) {}

        T getData(){
            return data;
        }

        bool setData(T new_value) {
            data = new_value;
            return true;
        }
    };

    size_t _size;
    Node *head;
    Node *tail;

    T _remove(Node* elm);

public:
    /**@brief Default Constructor
     * @details Create an empty LinkedList object
     * @tparam T Data type of the List elements
     */
    LinkedList();

    /**@brief Constructor
     * @details Creates a List object with the elements from the \a std::initializer_list
     * @param _list \a std::initializer_list of initial elements
     * @tparam T Data type of the list elements
     * @exception std::runtime_error
     */
    LinkedList(std::initializer_list<T> _list);

    /**@brief Size of the list
     * @return size of the list / number of elements
     */
    size_t size() noexcept {
        return _size;
    }

    /**@brief Check for empty list
     * @return Boolean true if the list is empty else false
     */
    bool empty() noexcept {
        return _size == 0;
    }

    /**@brief Add \a element at the end of the list
     * @details \f$O(1)\f$
     * @param element to be added
     * @exception std::runtime_error
     */
    void add_last(T element);

    /**@brief Add \a element at the start of the list
     * @details \f$O(1)\f$
     * @param element to be added
     * @exception std::runtime_error
     */
    void add_first(T element);

    /**@brief Add \a element at the \a index of the list
     * @details \f$O(n)\f$
     * @param index position in the list
     * @param element to be added
     * @exception std::runtime_error
     * @exception std::out_of_range Invalid index
     */
    void add_at(int index, T element);

    /**@brief Get the first element of the list
     * @details \f$O(1)\f$
     * @return Value of the first element in the list
     * @exception std::runtime_error
     */
    T peek_first();

    /**@brief Get the last element of the list
     * @details \f$O(1)\f$
     * @return Value of the last element in the list
     * @exception std::runtime_error
     */
    T peek_last();

    /**@brief Remove the first element of the list
     * @details \f$O(1)\f$
     * @return Value of the removed element
     * @exception std::runtime_error
     */
    T remove_first();

    /**@brief Remove the last element of the list
     * @details \f$O(1)\f$
     * @return Value of the removed element
     * @exception std::runtime_error
     */
    T remove_last();

    /**@brief Remove the \a element from the list 
     * @details \f$O(n)\f$
     * @return Boolean true if the element is removed else false
     * @exception std::runtime_error
     */
    bool remove(T element);

    /**@brief Remove the element at \a index
     * @details \f$O(n)\f$
     * @return Value of the removed element
     * @exception std::runtime_error
     * @exception std::out_of_range Invalid index
     */
    T remove_at(int index);

    /**@brief Get the index of the \a element
     * @details \f$O(n)\f$
     * @return Index position of the element if present else -1
     */
    int index(T element) noexcept;

    /**@brief Checks if the list contains the \a element 
     * @details \f$O(n)\f$
     * @return Boolean true if the element is present else false
     */
    bool contains(T element) noexcept;

    /**@brief Updates the value of the first element in the list
     * @details \f$O(1)\f$
     * @return Boolean true if the element is updated
     * @exception std::runtime_error
     */
    bool update_first(T value);

    /**@brief Updates the value of the last element in the list
     * @details \f$O(1)\f$
     * @return Boolean true if the element is updated
     * @exception std::runtime_error
     */
    bool update_last(T value);

    /**@brief Updates the element at \a index with \a value
     * @details \f$O(n)\f$
     * @return Boolean true if the element is updated
     * @exception std::runtime_error
     * @exception std::out_of_range Invalid index
     */
    bool update_at(int index, T value);

    /**@brief Updates the \a old_value with the \a new_value
     * @details \f$O(n)\f$
     * @return Boolean true if the element is updated
     * @exception std::runtime_error
     */
    bool update_element(T old_value, T updated_value);

    /**@brief Get the element at \a index position 
     * @details For updating the value use @ref update_at()
     *
     * \f$O(n)\f$
     * @return Value at \a index
     * @exception std::out_of_range Invalid index
     */
    T operator[](int index);

    /**@brief Clear the list / Remove all elements
     * @exception std::runtime_error
     */
    void clear() noexcept;
}; 
#endif //DATA_STRUCTURES_LINKED_LISTS
