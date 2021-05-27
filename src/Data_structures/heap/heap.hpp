/**
 * @file heap.hpp
 * @brief Heap Data Structure (Heap)
 * @details Implementation of a template heap data structure using \a std::vector
 * @author Atishek Kumar
 * @date May 2021
 * @warning Not thread safe and minimal error handling
 */
#ifndef DATA_STRUCTURES_HEAP_HPP
#define DATA_STRUCTURES_HEAP_HPP

#include<bits/stdc++.h>

//TODO(std::initializer_list integration)

/**@namespace heap
 * @brief Heap constants
 * @details The namespace defines contants defining the type to heap the class object implements.
 */
namespace heap {
    /** @brief Constant for creating a MaxHeap Object
     */
    const int MAX_HEAP = 0;
    /** @brief Constant for creating a MinHeap Object
     */
    const int MIN_HEAP = 1;
}

/** @def LEFT(i)
 * @brief Calculates the index for the left child of an element
*/
/** @def RIGHT(i)
 * @brief Calculates the index for the right child of an element
 */
/** @def PARENT(i)
 * @brief Calculates the index for the parent of an element
 */
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)
#define PARENT(i) ((i - 1) / 2)


/**
 * @brief Template Heap Data Structure 
 * @details Heap data structure implementation using \a std::vector. 
 * Supports both MinHeap and MaxHeap objects as defined by @ref heap namespace constants.
 * @tparam T Data type for the heap elements
 */
template<typename T>
class Heap {
    private:
        std::vector<T> arr{};
        std::function<bool(T,T)> compare;
        int type;

        /* Private Functions */

        void heapify_bottom_up(int i);

        void heapify_top_down(int i);

        bool remove_at(int i);

        int containsInternal(T key);

        std::function<bool(T, T)> max_heap = [](T first, T second) {
            return first > second;
        };

        std::function<bool(T, T)> min_heap = [](T first, T second) {
            return first < second;
        };

    public:
        /**
         * @brief Default constructor
         * @details Creates an empty max-heap. 
         * @tparam T Data type for the heap elements
         */
        Heap();

        /**
         * @brief Constructor
         * @details Creates an empty heap based on the argument \a type.
         * @param type @ref heap constant defining the type of object to create
         * @tparam T Data type for the heap elements
         */
        Heap(int type);

        /** @brief Constructor
         * @details Create a heap object defined by \a type with the elements of \a std::vector \a v.
         *
         * @param v std::vector of initial elements
         * @param type @ref heap constant defining the type of object to create
         * @tparam T Data type for the heap elements
         */
        Heap(std::vector<T> v, int type);

        /** @brief Destructor
         * @details Clears the heap's internal \a std::vector
         */
        ~Heap();

        /**@brief Size of the heap
         * @details Returns the number of elements in the heap.
         *
         *\f$O(1)\f$
         * @return number of elements
         */
        size_t size() noexcept {
            return arr.size();
        }

        /* Heap Opertions */

        /**@brief Float down the value to maintain the heap invariant.
         * @details Moves down the value at index \a i till the heap invariant is satisfied.
         * Assumes that the sub-trees rooted at the children of the element \a i are heaps.
         *
         *\f$O(\log n)\f$
         *
         * @param i index of the element
         */
        void heapify(int i);

        /** @brief Build the heap
         * @details Build out the heap from the internal \a std::vector.
         *
         * \f$O(n)\f$
         */
        void build_heap();

        /** @brief Insert an element
         * @details Inserts the element at the end of the \a std::vector and moves up the element
         * if needed to maintain the heap invariant.
         *
         * \f$O(\log n)\f$
         * 
         * @param data element to be inserted
         * @return Boolean true if the element is inserted, else false.
         */
        bool insert(T data);

        /** @brief Remove the root element.
         * @details Replaces the root with the last element, heapify() the new root and return the 
         * old root's value.
         *
         * \f$O(\log n)\f$
         * @return Value of the root element
         */
        T poll();

        /**@brief Get the root's value.
         * @details Returns the value of the root element, no deletion is performed.
         *
         * \f$O(1)\f$
         * @return Value of the root element.
         */
        T peek();

        /** @brief Remove an element
         * @details Remove a particular element \a data from the heap
         *
         * \f$O(n)\f$
         * @param data element to be removed
         * @return Boolean true if the element is removed, else false
         */
        bool remove(T data);

        /**@brief Clear the heap 
         * @details \f$O(1)\f$
         */
        void clear() noexcept{
            arr.clear();
        }

        /** @brief Check \a element
         * @details Checks if the \a element is present in the heap and returns an appropirate boolean value.
         *
         * \f$O(n)\f$
         * @param element value to be searched
         * @return boolean value indicating \a element's presence
         *
        */
        bool contains(T element);

        /** @brief Modify element
         * @details Update an element's value and place it appropirately to maintain
         * the heap value.
         *
         * \f$O(n)\f$
         * @param oldKey value to be updated
         * @param newKey new value
         * @return true if the element is modified, else false
         */
        bool modifyKey(T oldKey, T newKey);

};

#endif //DATA_STRUCTURES_HEAP_HPP
