#ifndef MYSTACK_H
#define MYSTACK_H

#include "node.h"
#include "node.cpp"

template <typename T>
class MyStack
{
private:
    Node<T> * top;
    int size;

public:
    MyStack();
    ~MyStack();

    Node<T> * get_top();
    int get_size();
    void set_top(Node<T> * top);
    void set_size(int size);

    bool isEmpty();
    void push(T data);
    Node<T> * peek();
    void pop();

};

#endif // MYSTACK_H
