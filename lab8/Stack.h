#ifndef STACK
#define STACK
#include <vector>
#include <stdexcept>
using namespace std;


template <typename T>
class Stack
{
private:
    vector<T> data;

public:
    Stack();

    Stack(const Stack<T> &other);

    ~Stack();

    Stack<T> &operator<<(const T &value);

    Stack<T> &operator>>(T &value);

    Stack<T> &operator=(const Stack<T> &other);

    bool operator==(const Stack<T> &other) const;

    bool operator<(const Stack<T> &other) const;

    T &operator[](size_t index);

    const T &operator[](size_t index) const;

    bool empty() const;

    size_t size() const;
};

#endif