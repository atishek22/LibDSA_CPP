#include"hash_table_open_addressing.hpp"

// Private Functions
//
template<Hashable Key, typename Data>
size_t HashTableOA<Key, Data>::get_normalised_index(Key key) {
    size_t hash_val = std::hash<Key>{}(key);
    return hash_val % capacity;
}

template<Hashable Key, typename Data>
size_t HashTableOA<Key, Data>::normalise(size_t index) {
    return index % capacity;
}

template<Hashable Key, typename Data>
void HashTableOA<Key, Data>::_resize_table() {
    if(_size >= resize_threshold) {
        auto old_capacity = capacity;
        try {
            get_adjusted_capacity();
            this->resize_threshold = load_factor * capacity;
            Element* new_table = new Element[capacity];
            std::swap(new_table, table);
            _size = 0;
            for(int i = 0; i < old_capacity; i++) {
                if(!new_table[i].empty() && !new_table[i].deleted()) {
                    insert(new_table[i].key, new_table[i].data);
                }
            }
            delete[] new_table;    
        } 
        catch(const std::bad_alloc& e) {
            capacity = old_capacity;
            resize_threshold = (size_t) load_factor * capacity;
            std::cerr << "Unable to resize the table";
            std::runtime_error("Unable to resize the table");
        }
    } 
}

template<Hashable Key, typename Data>
void HashTableOA<Key, Data>::get_adjusted_capacity() {
    capacity *= 2;
}

// Constructors and Destructors
template<Hashable Key, typename Data>
HashTableOA<Key, Data>::HashTableOA(
        std::function<size_t(size_t)> probe_function,
        size_t capacity,
        float load_factor
        ) {
    if(capacity < 0) throw std::invalid_argument("Capacity cannot be negative");
    if(load_factor <= 0 ||
            load_factor == std::numeric_limits<float>::infinity() ||
            load_factor == std::numeric_limits<float>::quiet_NaN())
        throw std::invalid_argument("Invalid load factor for the table");
    try {
        this->load_factor = load_factor;
        this->capacity = capacity;
        this->probe = probe_function;
        resize_threshold = (size_t)capacity * load_factor;
        table = new Element[capacity];
        _size = 0;
    } catch(const std::bad_alloc& e) {
        std::cerr << "Unable to allocate the table";
        throw std::runtime_error("Unable to allocate the table");
    }
}

template<Hashable Key, typename Data>
HashTableOA<Key, Data>::~HashTableOA() {
    delete[] table;
}
// Operations

template<Hashable Key, typename Data>
void HashTableOA<Key, Data>::clear() {
    try{
        delete[] table;
        table = new Element[capacity];
        _size = 0;
    }catch(const std::bad_alloc& e) {
        std::cerr << "Unable to clear the table";
        throw std::runtime_error(e.what());
    }
}

template<Hashable Key, typename Data>
bool HashTableOA<Key, Data>::contains_key(Key key) noexcept {
    auto index = get_normalised_index(key);
    for(size_t i = index, found = -1, x = 1; ;i = normalise(i + probe(x++))){
        // The position has been deleted but there may be more elements ahead
        if(table[i].deleted()) {
            if(found == -1) {
                found = i;
            }
        } else if(!table[i].empty()) {
            if(table[i] == Element(key)) {
                // There is a deleted place 
                if(found != -1) {
                    table[found] = table[i];
                    table[i] = DELETED;
                }
                return true;
            }
        } else return false;
    }
}

template<Hashable Key, typename Data>
void HashTableOA<Key, Data>::insert(Key key, Data data) {
    _resize_table();
    Element new_element = Element(key, data);
    auto index = get_normalised_index(key);
    size_t found = -1;
    for(size_t i = index, x = 1; ;i = normalise(i + probe(x++))){
        if(table[i].deleted() || table[i].empty()) {
            found = i;
            break;
        } 
    }
    table[found] = new_element;
    _size++;
}

template<Hashable Key, typename Data>
void HashTableOA<Key, Data>::insert(std::pair<Key, Data> element) {
    insert(element.first, element.second);
}

template<Hashable Key, typename Data>
std::optional<Data> HashTableOA<Key, Data>::get(Key key) {
    auto index = get_normalised_index(key);
    for(size_t i = index, x = 1, found = -1; ;i = normalise(i + probe(x++))) {
        if(table[i].deleted()) {
            if(found == -1) {
                found = i;
            }
        }
        else if(table[i] == Element(key)) {
            Element ret = table[i];
            if(found != -1) {
                table[found] = table[i];
                table[i] = DELETED;
            }
            return std::optional<Data>{ret.data};
        } else if(table[i].empty()) {
            return std::nullopt;
        }
    }
    return std::nullopt;
}

template<Hashable Key, typename Data>
std::optional<Data> HashTableOA<Key, Data>::remove(Key key) {
    auto index = get_normalised_index(key);
    for(size_t i = index, x = 1, found = -1; ;i= normalise(i + probe(x++))) {
        if(table[i].deleted()) {
            continue;
        } else if(table[i].empty()) {
            return std::nullopt;
        } else if(table[i] == Element(key)) {
            auto ret = table[i];
            table[i] = DELETED;
            _size--;
            return std::optional<Data>{ret.data};
        }
    }
}

template<Hashable Key, typename Data>
bool HashTableOA<Key, Data>::update(Key key, Data new_data) {
    auto index = get_normalised_index(key);
    for(size_t i = index, found = -1, x = 1; ;i = normalise(i + probe(x++))){
        // The position has been deleted but there may be more elements ahead
        if(table[i].deleted()) {
            if(found == -1) {
                found = i;
            }
        } else if(!table[i].empty()) {
            if(table[i] == Element(key)) {
                table[i].data = new_data;
                // There is a deleted place 
                if(found != -1) {
                    table[found] = table[i];
                    table[i] = DELETED;
                }
                return true;
            }
        } else return false;
    }
}
