#include <string>
#include "Stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack() : data() {}

template <typename T>
Stack<T>::Stack(const Stack<T>& other) : data(other.data) {}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
Stack<T>& Stack<T>::operator<<(const T& value) {
    data.push_back(value);
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator>>(T& value) {
    if (data.empty()) {
        throw underflow_error("Stack is empty");
    }
    value = data.back();
    data.pop_back();
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

template <typename T>
bool Stack<T>::operator==(const Stack<T>& other) const {
    return data == other.data;
}

template <typename T>
bool Stack<T>::operator<(const Stack<T>& other) const {
    return data.size() < other.data.size();
}

template <typename T>
T& Stack<T>::operator[](size_t index) {
    if (index >= data.size()) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& Stack<T>::operator[](size_t index) const {
    if (index >= data.size()) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
bool Stack<T>::empty() const {
    return data.empty();
}

template <typename T>
size_t Stack<T>::size() const {
    return data.size();
}

template class Stack<int>;
template class Stack<double>;