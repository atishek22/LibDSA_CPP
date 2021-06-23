#include"hash_table.hpp"

// Constructors and Destructors
template<Hashable Key, typename Data>
HashTable<Key, Data>::HashTable(size_t capacity, float load_factor) {
    if(capacity < 0) throw std::invalid_argument("Capacity cannot be negative");
    if(load_factor <= 0 || 
            load_factor == std::numeric_limits<float>::infinity() || 
            load_factor == std::numeric_limits<float>::quiet_NaN()) 
        throw std::invalid_argument("Invalid load factor for the table");
    try {
        this->load_factor = load_factor;
        this->capacity = capacity;
        resize_threshold = (size_t) capacity * load_factor;
        table = new LinkedList<Element>[capacity];
        _size = 0;
    } catch(const std::bad_alloc& e) {
        std::cerr << "Unable to allocate the object";
        throw std::runtime_error("Unable to allocate the object");
    }
}

template<Hashable Key, typename Data>
HashTable<Key, Data>::~HashTable(){
    clear();
    delete[] table;
}

// Private Functions

template<Hashable Key, typename Data>
size_t HashTable<Key, Data>::get_normalised_index(Key key) {
    size_t hash_val = std::hash<Key>{}(key);
    return hash_val % capacity;
}

template<Hashable Key, typename Data>
void HashTable<Key, Data>::_resize_table() {
    if(_size >= resize_threshold) {
        auto old_capacity = capacity;
        try {
            this->capacity *= 2;
            resize_threshold = (size_t) load_factor * capacity;
            LinkedList<Element>* new_table = new LinkedList<Element>[capacity];
            for(int i = 0; i < old_capacity; i++) {
                while(!table[i].empty()) {
                    auto elm = table[i].remove_first();
                    auto new_index = get_normalised_index(elm.key);
                    new_table[new_index].add_first(elm);
                }
            }
            std::swap(new_table, table);
            delete[] new_table;
        } catch(const std::bad_alloc& e) {
            capacity = old_capacity;
            resize_threshold = (size_t) load_factor * capacity;
            std::cerr << "Unable to resize the table";
            std::runtime_error("Unable to resize the table");
        }
    }

}

// Table operations

template<Hashable Key, typename Data>
void HashTable<Key, Data>::clear() {
    try {
        for(int i = 0; i < capacity; i++) {
            table[i].clear();
        }
        _size = 0;
    } catch(const std::runtime_error& e) {
        std::cerr << "Unable to clear the table";
        throw std::runtime_error(e);
    }
}

template<Hashable Key, typename Data>
bool HashTable<Key, Data>::contains_key(Key key) noexcept {
    auto index = get_normalised_index(key);
    return table[index].contains(Element(key));
}

template<Hashable Key, typename Data>
void HashTable<Key, Data>::insert(Key key, Data data) {
    Element new_element = Element(key, data);
    auto index = get_normalised_index(key);
    table[index].add_first(new_element);
    _size++;
    _resize_table();
}

template<Hashable Key, typename Data>
void HashTable<Key, Data>::insert(std::pair<Key, Data> element) {
    insert(element.first, element.second);
}

template<Hashable Key, typename Data>
std::optional<Data> HashTable<Key, Data>::get(Key key) {
    auto index = get_normalised_index(key);
    auto element_index = table[index].index(Element(key));
    if(element_index == -1) return std::nullopt;
    return std::optional<Data>{table[index][element_index].data};
}

template<Hashable Key, typename Data>
std::optional<Data> HashTable<Key, Data>::remove(Key key) {
    auto index = get_normalised_index(key);
    auto element_index = table[index].index(Element(key));
    if(element_index == -1) return std::nullopt;
    _size--;
    return std::optional<Data>{table[index].remove_at(element_index).data};
}

template<Hashable Key, typename Data>
bool HashTable<Key, Data>::update(Key key, Data new_data) {
    auto index = get_normalised_index(key);
    auto element_index = table[index].index(Element(key));
    if(element_index == -1) return false;
    return table[index].update_at(element_index, Element(key, new_data));
}
