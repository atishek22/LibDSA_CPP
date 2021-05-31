#include"./stack.hpp"

template<typename T>
Stack<T>::Stack() {
    stack = new DynamicArray<T>();
    _top = -1;
}

template<typename T>
Stack<T>::Stack(std::initializer_list<T> v) {
    stack = new DynamicArray<T>(v);
    _top = stack->size() - 1;
}

template<typename T>
Stack<T>::~Stack(){
    delete stack;
}

template<typename T>
void Stack<T>::push(T element) {
    try {
        stack->add(element);
        _top++;
    } catch(std::runtime_error &e) {
        std::cout << e.what();
        throw std::runtime_error("Couldn't add the element to the stack");
    }
}

template<typename T>
bool Stack<T>::pop() {
    if(isEmpty()) throw std::runtime_error("Stack is empty");
    try {
        bool ret = stack->removeAt(_top--);
    } catch(std::runtime_error &e) {
        throw std::runtime_error("Unable to pop the stack");
    }
}

template<typename T>
T Stack<T>::top() {
    if(isEmpty()) throw std::runtime_error("Stack is empty");
    try {
        return (*stack)[_top];
    } catch(std::out_of_range &e) {
        throw std::runtime_error("Unable to retrieve the top element");
    }
}

template<typename T>
bool Stack<T>::isEmpty() noexcept{
    return stack->isEmpty();
}

