/**
 * @file dynamic_array.hpp
 * @brief Dynamic Arrays (DynamicArray)
 * @details DynamicArray template class implementing the Dynamic array (Vector) data structure using \a C static arrays
 * @author atishek22 <kumaratishek22@gmail.com>
 * @date May 2021
 * @warning Not thread safe
 */
#ifndef DATA_STRUCTURES_DYNAMICARRAY_HPP
#define DATA_STRUCTURES_DYNAMICARRAY_HPP

#include<stddef.h>
#include<initializer_list>
#include<stdexcept>
#include<iostream>

//TODO(std::initializer_list integratiion)

/**
 * @brief DynamicArray (Vector) class.
 * @details Dynamic array (Vector) data structure implementation using metaprogramming and \a C static sized arrays.
 * @tparam T Data type for the array elements.
 */
template<typename T>
class DynamicArray {
private:
    T *arr;
    size_t len{};
    size_t capacity{};

    void increaseCapacity();
    void decreaseCapacity();


public:
    /** @brief Default constructor 
     * @details Initialises the array with \f$capacity = 2\f$ 
     * @tparam T Data type for the array elements.
     * @exception std::bad_alloc()
     */
    DynamicArray();

    /**@brief Constructor
     * @details Initialise the array with \f$capacity = sz\f$.
     * @param sz initial array capacity
     * @tparam T Data type for the array elements.
     * @exception std::bad_alloc()
     */
    DynamicArray(int sz);

    /**@brief Constructor
     * @details Initialise the array with the \a std::initializer_list passed in.
     * @param _list initial list of values.
     * @tparam T Data type for the array elements.
     * @exception std::bad_alloc()
     */
    DynamicArray(std::initializer_list<T> _list);

    /**@brief Destructor
     * @details Deallocates the memory assigned to the array.
     */
    ~DynamicArray();

    /** @brief Size of the array
     * @details Returns the number of elements in the array. 
     *
     * \f$O(1)\f$
     * @return size of the array
     */
    size_t size() noexcept;

    /**@brief Checks if array is empty.
     * @details Returns \a true if the array is empty \a i.e. size() \f$ == 0\f$
     *
     * \f$O(1)\f$
     * @return boolean value
     */
    bool isEmpty() noexcept;

    /**@brief Getter
     * @details Returns the value of the element at the \a index.
     *
     * Also see @ref operator[].
     *
     * \f$O(1)\f$
     *
     * @param index of the element 
     * @return value of the required element
     * @exception std::out_of_range() - invalid \a index
     */
    T get(int index);

    /**@brief Setter
     * @details Set the value of the element at the \a index to the \a value.
     * 
     * Also see @ref operator[].
     *
     * \f$O(1)\f$
     * 
     * @param index of the element to be updated
     * @param value to be set/updated
     * @exception std::out_of_range() - invalid \a index
     */
    void set(int index, T value);

    /**@brief Clear the array 
     * @details Removes all the elements from the array and sets the \a size to \f$0\f$
     *
     * \f$O(1)\f$
     * @exception std::bad_alloc()
     */
    void clear();

    /**@brief Adding an element to the array
     * @details Adds an element at the end of the array. The array may be resized as needed.
     *
     *\f$O(1)\f$
     * @param element value
     * @exception std::runtime_error()
     */
    void add(T element);

    /** @brief Remove at \a index 
     * @details Removes the element at the \a index and returns the deletion status. The array may be resized if needed.
     *
     *\f$O(n)\f$
     * @param index of the element to be deleted
     * @return boolean status value
     * @exception std::runtime_error()
     */
    bool removeAt(int index);

    /** @brief Remove a \a value 
     * @details Removes the element with the \a value and returns the deletion status. The array may be resized if needed.
     *
     *\f$O(n)\f$
     * @param value of the element to be deleted
     * @return boolean status value
     * @exception std::runtime_error()
     */
    bool remove(T value);

    /**@brief Index of \a element
     * @details Finds the index of the \a element if present else returns -1.
     *
     * \f$O(n)\f$
     * @param element value
     * @return index of the element if present or -1
     */
    int indexOf(T element) noexcept;

    /**@brief Check \a element
     * @details Checks if the \a element is present and returns an appropirate boolean value.
     *
     * \f$O(n)\f$
     * @param element value to be searched
     * @return boolean value indicating \a element's presence.
     */
    bool contains(T element) noexcept;

    /**@brief Prints the array to standard output
     *
     * \f$O(n)\f$
     */
    void print() noexcept;

    /**@brief Array subscript operator
     * @details Operator overload of the array subscript operator, also supports negative array indices.
     *
     * \f$ arr[-1] \f$ is equivalent to \f$ arr[size() - 1] \f$
     *
     * \f$O(1)\f$
     *
     * @param index of the element
     * @exception std::out_of_range() - invalid \a index
     */
    T& operator[](int index);
};

#endif //DATA_STRUCTURES_DYNAMICARRAY_HPP


