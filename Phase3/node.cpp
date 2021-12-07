#include "node.h"

template<typename T>
Node<T>::Node()
{
    this->next = nullptr;
}

template<typename T>
Node<T> * Node<T>::get_next()
{
    return this->next;
}

template<typename T>
T Node<T>::get_data()
{
    return this->data;
}

template<typename T>
void Node<T>::set_next(Node<T> * next)
{
    this->next = next;
    return;
}

template<typename T>
void Node<T>::set_data(T data)
{
    this->data = data;
    return;
}
