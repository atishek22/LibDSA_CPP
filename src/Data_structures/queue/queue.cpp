#include"queue.hpp"

/* Constructors and Destructors */
template<typename T>
Queue<T>::Queue() {
    try {
        head = tail = -1;
        _size = 0;
        capacity = 2;
        arr = new T[capacity];
    } catch(const std::bad_alloc& e) {
        std::cerr << "Unable to allocate the object \n";
        throw std::bad_alloc(e);
    }
}

template<typename T>
Queue<T>::Queue(size_t sz) {
    try {
        head = tail = -1;
        _size = 0;
        capacity = sz;
        arr = new T[capacity];
    } catch(const std::bad_alloc& e) {
        std::cerr << "Unable to allocate the object \n";
        throw std::bad_alloc(e);
    }
}

template<typename T>
Queue<T>::Queue(std::initializer_list<T> l) {
    try {
        head = 0;
        tail = _size - 1;
        _size = l.size();
        capacity = l.size() * 2;
        arr = new T[capacity];
        int i = 0;
        for(const auto& val: l) {
            arr[i++] = val;
        }
    } catch(const std::bad_alloc& e) {
        std::cerr << "Unable to allocate the object \n";
        throw std::bad_alloc(e);
    }
}

template<typename T>
Queue<T>::~Queue() {
    delete arr;
}

/* Private Functions */

template<typename T>
void Queue<T>::increaseCapacity() {
    size_t oldCapacity = capacity;
    capacity *= 2;
    T* newarr = new T[capacity];
    if(tail >= head) {
        //Normal case
        int k = 0;
        for(int i = head; i <= tail; i++) {
            newarr[k++] = arr[i];
        }
    } else {
        //wraparound case
        int k = 0;
        for(int i = head; i < oldCapacity; i++)
            newarr[k++] = arr[i];
        for(int i = 0; i <= tail; i++)
            newarr[k++] = arr[i];
    }
    head = 0;
    tail = oldCapacity - 1;
    T* temp = arr;
    arr = newarr;
    delete temp;
}

template<typename T>
void Queue<T>::decreaseCapacity() {
    size_t oldCapacity = capacity;
    capacity /= 2;
    T* newarr = new T[capacity];
    if(tail >= head) {
        int k = 0;
        for(int i = head; i <= tail; i++) {
            newarr[k++] = arr[i];
        }
    } else {
        int k = 0;
        for(int i = head; i < oldCapacity; i++)
            newarr[k++] = arr[i];
        for(int i = 0; i <= tail; i++)
            newarr[k++] = arr[i];
    }
    head = 0;
    tail = _size - 1;
    T* temp = arr;
    arr = newarr;
    delete temp;
}

/* Queue Operations */
template<typename T>
void Queue<T>::enqueue(T element) {
    if(empty()) {
        head = 0;
    }
    if(full()) {
        try {
            increaseCapacity();
        } catch(const std::bad_alloc& e) {
            throw std::runtime_error("Unable to enqueue the element");
        }
    }
    tail = (tail + 1) % capacity;
    arr[tail] = element;
    _size++;
}

template<typename T>
T Queue<T>::dequeue() {
    if(empty()) {
        throw std::out_of_range("Invalid: Empty Queue Dequeue");
    }
    T ret = arr[head];
    head++;
    _size--;
    if(_size < capacity / 2 && !empty()) {
        try {
            decreaseCapacity();
        } catch(const std::bad_alloc& e) {
            throw std::runtime_error("Unable to remove the element");
        }
    }
    return ret;
}

template<typename T>
T Queue<T>::front() {
    if(empty())
        throw std::runtime_error("Queue is empty");
    return arr[head];
}

template<typename T>
T Queue<T>::back() {
    if(empty())
        throw std::runtime_error("Queue is empty");
    return arr[tail];
}

template<typename T>
void Queue<T>::clear() noexcept{
    head = tail = -1;
    _size = 0;
}
