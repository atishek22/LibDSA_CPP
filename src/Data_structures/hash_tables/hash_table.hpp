/**
 * @file hash_table.hpp
 * @brief Generic Hash Table with chaining implementation
 * @details HashTable template class implementing generic Hash Table using \a std::hash for calculating the table index
 * from the key,
 * @author atishek22 <kumaratishek22@gmail.com>
 * @date Jun 2021
 * @warning Not thread safe
 */

#ifndef DATA_STRUCTURES_HASH_TABLE_HPP
#define DATA_STRUCTURES_HASH_TABLE_HPP

#include<stddef.h>
#include<memory>
#include<stdexcept>
#include<iostream>
#include<concepts>
#include<limits>
#include<optional>
#include<vector>

#include"../linked_list/linked_list.hpp"
#include "../../Utils/hashable.hpp"

/**@brief HashTable Template Class 
 * @details Hash table implementation using separate chaining as the method for hashing conflict resolution
 *
 * @tparam Key Hashable Key data type
 * @tparam Data Type of data to be stored by the table
 *
 * @warning Not thread safe
 */
template<Hashable Key, typename Data>
class HashTable {
private:
    static constexpr int DEFAULT_CAPACITY = 3;
    static constexpr float DEFAULT_LOAD_FACTOR = 1.2;

    class Element {
    public:
        size_t hash_val;
        Key key;
        Data data;

        Element(Key key, Data data = Data()) { 
            this->key = key;
            this->data = data;
            this->hash_val = std::hash<Key>{}(key);
        }

        bool operator==(const Element& other) {
            if(this->hash_val != other.hash_val) return false;
            return this->key == other.key;
        }
    };

    LinkedList<Element>* table;
    float load_factor;
    size_t capacity, _size, resize_threshold;

    size_t get_normalised_index(Key key);

    void _resize_table();


public:
    /**@brief Default constructor
     * @details Creates an empty hash table with the specified \a loadFactor and \a capacity. Fall backs to the
     * default if not specified.
     * @param capacity Max capacity of the table - index range - \f$[0, capacity)\f$
     * @param loadFactor \f$(\alpha)\f$  ratio the number of elements to the capacity - define the resize threshold for the table
     * @tparam Key Hashable Key data type
     * @tparam Data Type of data to be stored by the table
     * @exception std::illegal_argument Invalid \a capacity or \a loadFactor
     * @exception std::runtime_error Unable to allocate the table
     */
    HashTable(size_t capacity = DEFAULT_CAPACITY, float loadFactor = DEFAULT_LOAD_FACTOR);

    /**@brief Default Destructor
     * @details Clears and deallocates the table.
     */
    ~HashTable();
    
    /**@brief Get the number of elements from the table
     * @details \f$O(1)\f$
     * @return \b size_t indicating the number of elements
     */
    size_t size() noexcept {
        return _size;
    }

    /**@brief Check if the table is empty
     * @return \b Boolean \b true if the table is empty
     */
    bool empty() noexcept {
        return _size == 0;
    }

    /**@brief Clear the table
     * @details Removes all the elements and maintains the table size. \f$O(\alpha n)\f$
     * @exception std::runtime_error Unable to clear the table.
     */
    void clear();

    /**@brief Check if the table contains the \a key
     * @details \f$O(\alpha)\f$
     * @param key Key that needs to be checked
     * @return \b Boolean \b true if the key is present in the table
     */
    bool contains_key(Key key) noexcept;

    /**@brief Insert an entry in the table
     * @details \f$O(1)\f$
     * @param key Key for the entry
     * @param data Data element of the entry
     * @exception std::runtime_error
     */
    void insert(Key key, Data data);

    /**@brief Insert an entry in the table
     * @details \f$O(1)\f$
     * @param element \a std::pair containing the key and data values.
     * @exception std::runtime_error
     */
    void insert(std::pair<Key, Data> element);

    /**@brief Get element using \a key
     * @details Get the \a data value to the corresponding \a key value. If the key doesn't exist 
     * \a std::nullopt is returned. \f$O(\alpha)\f$
     * @param key Key whose corresponding data value is to be found
     * @return \b Data value wrapped in \a std::optional if the key is present else \b std::nullopt
     */
    std::optional<Data> get(Key key);

    /**@brief Remove an element from \a key
     * @details Remove the element from the table if the key value exists in the table.
     * \f$O(\alpha)\f$
     *
     * @param key Key whose corresponding element is to be removed
     * @exception std::runtime_error
     * @return \b Data value wrapped in \a std::optional if the key is removed else \b std::nullopt
     */
    std::optional<Data> remove(Key key);

    /**@brief Update an element value
     * @details Update the element data value corresponding to the key value
     * \f$O(\alpha)\f$
     * @param key Key value whose corresponding data value is to be updated
     * @param newData Updated data value
     * @return \b Boolean \b true if the value is updated successfully
     */
    bool update(Key key, Data new_data);


    /** @brief Iterator for the hash table
     *
     * @todo Iterator implementation
     */
    struct Iterator {
        //TODO: Iterator Implementation
    };

    //TODO: Keys, Values and Key-Value lists
    /**
     * @brief Key-Value pairs from the table
     * @details 
     *
     * @warning Function not yet implemented
     * @todo Implement function
     */
    std::vector<std::pair<Key, Data>> key_value();

    /**
     * @brief Keys from the table
     *
     * @warning Function not yet implemented
     * @todo Implement function
     */
    std::vector<Key> keys();

    /**
     * @brief Values from the table
     *
     * @warning Function not yet implemented
     * @todo Implement function
     */
    std::vector<Data> values();
};

#endif //DATA_STRUCTURES_HASH_TABLE_HPP
