#include"linked_list.hpp"

template<typename T>
LinkedList<T>::LinkedList() {
    _size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> l) {
    LinkedList();
    try {
        for(const auto& val: l) {
            addLast(val);
        }
    } catch(const std::runtime_error &e) {
        std::cerr << "Unable to initializer the LinkedList object \n";
        throw std::runtime_error(e.what());
    }
}

/* Private functions */
template<typename T>
T LinkedList<T>::_remove(Node *elm) {
    if(elm->prev == nullptr) return remove_first();
    if(elm->next == nullptr) return remove_last();

    elm->next->prev = elm->prev;
    elm->prev->next = elm->next;

    T ret = elm->getData();
    delete elm;
    _size--;
    return ret;
}

/* List Operations */
template<typename T>
void LinkedList<T>::add_last(T element) {
    try {
        if(empty())
            head = tail = new Node(element);
        else {
            tail->next = new Node(element, tail);
            tail = tail->next;
        }
        _size++;
    } catch(const std::bad_alloc& e) {
        std::cerr << "Unable to allocate a new element \n";
        throw std::runtime_error(e.what());
    }
}

template<typename T>
void LinkedList<T>::add_first(T element) {
    try {
        if(empty())
            head = tail = new Node(element);
        else {
            head->prev = new Node(element, nullptr, head);
            head = head->prev;
        }
        _size++;

    } catch(const std::bad_alloc& e) {
        std::cerr << "Unable to allocate a new element \n";
        throw std::runtime_error(e.what());
    }
}

template<typename T>
void LinkedList<T>::add_at(int index, T element) {
    try {
        if(index < 0 || index > _size) throw std::out_of_range("Invalid index not allowed");
        if(index == 0) return addFirst(element);
        if(index == _size) return addLast(element);

        Node* temp = head;
        for(int i = 0 ;i < index - 1; i++) {
            temp = temp->next;
        }

        Node *newNode = new Node(element, temp, temp->next);
        temp->next->prev = newNode;
        temp->next = newNode;
        _size++;
    } catch(const std::bad_alloc& e) {
        std::cerr << "Unable to allocate a new element \n";
        throw std::runtime_error(e.what());
    }
}

template<typename T>
T LinkedList<T>::peek_first() {
    if(empty()) throw std::runtime_error("Invalid: Empty List Peeking");
    return head->getData();
}

template<typename T>
T LinkedList<T>::peek_last() {
    if(empty()) throw std::runtime_error("Invalid: Empty List Peeking");
    return tail->getData();
}

template<typename T>
T LinkedList<T>::remove_first() {
    if(empty()) throw std::runtime_error("Invalid: Empty Queue Deletion");
    T ret = head->getData();
    Node *temp = head;
    head = head->next;
    _size--;

    if(empty()) tail = nullptr;
    else head->prev = nullptr;

    delete temp;
    return ret;
}

template<typename T>
T LinkedList<T>::remove_last() {
    if(empty()) throw std::runtime_error("Invalid: Empty Queue Deletion");
    T ret = tail->getData();
    Node *temp = tail;
    tail = tail->prev;
    _size--;

    if(empty()) head = nullptr;
    else tail->next = nullptr;

    delete temp;
    return ret;
}

template<typename T>
T LinkedList<T>::remove_at(int index) {
    if(index < 0 || index >= _size) throw std::out_of_range("Invalid index");
    int i;
    Node *trav;

    if(index < _size / 2) {
        for(i = 0, head = trav; i != index; i++)
            trav = trav->next;
    } else {
        for(i = _size - 1, trav = tail; i != index; i--)
            trav = trav->prev;
    }
    return _remove(trav);
}

template<typename T>
bool LinkedList<T>::remove(T element) {
    Node *trav;
    for(trav = head; trav != nullptr; trav = trav->next) {
        if(trav->getData() == element){
            _remove(trav);
            return true;
        }
    }
    return false;
}

template<typename T>
int LinkedList<T>::index(T element) noexcept {
    int index = 0;
    Node *trav;
    for(trav = head; trav != nullptr; trav = trav->next, index++) {
        if(trav->getData() == element)
            return index;
    }
    return -1;
}

template<typename T>
bool LinkedList<T>::contains(T element) noexcept {
    return index(element) != -1;
}

template<typename T>
bool LinkedList<T>::update_first(T val) {
    if(empty()) throw std::runtime_error("Invalid: Empty Queue Updation");
    return head->setData(val);
}

template<typename T>
bool LinkedList<T>::update_last(T val) {
    if(empty()) throw std::runtime_error("Invalid: Empty Queue Updation");
    return tail->setData(val);
}

template<typename T>
bool LinkedList<T>::update_at(int index, T val) {
    if(empty()) throw std::runtime_error("Invalid: Empty Queue Updation");
    if(index < 0 || index >= _size) throw std::out_of_range("Invalid index");
    int i;
    Node *trav;

    if(index < _size / 2) {
        for(i = 0, head = trav; i != index; i++)
            trav = trav->next;
    } else {
        for(i = _size - 1, trav = tail; i != index; i--)
            trav = trav->prev;
    }
    return trav->setData(val);
}

template<typename T>
bool LinkedList<T>::update_element(T old, T val) {
    if(empty()) throw std::runtime_error("Invalid: Empty Queue Updation");
    Node *trav;
    for(trav = head; trav != nullptr; trav = trav->next) {
        if(trav->getData() == old)
            return trav->setData(val);
    }
    return false;
}

template<typename T>
T LinkedList<T>::operator[](int index) {
    if(index < 0) {
        index += _size;
    }
    if(index > _size || index < 0)
        throw std::out_of_range("Invalid Index");
    Node *trav;
    int i;
    if(index < _size / 2) {
        for(i = 0, trav = head; i != index; i++, trav = trav->next);
    } else {
        for(i = _size - 1, trav = tail; i != index; i--, trav = trav->prev);
    }
    return trav->getData();
}

template<typename T>
void LinkedList<T>::clear() noexcept {
    if(empty()) return;
    Node *trav = head;
    while(trav != nullptr) {
        Node *temp = trav;
        trav = trav->next;
        delete temp;
    }
    head = tail = nullptr;
    _size = 0;
}
