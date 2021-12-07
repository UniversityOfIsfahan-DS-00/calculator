#include "mystack.h"

template<typename T>
MyStack<T>::MyStack()
{
    this->top = nullptr;
    this->size = 0;

    return;
}

template<typename T>
MyStack<T>::~MyStack()
{
    Node<T> * current = new Node<T>;
    current = this->top;

    while(current != nullptr)
    {
        Node<T> *temp;
        temp = current;
        current = current->get_next();
        delete temp;
    }

    delete current;

    return;
}

template<typename T>
Node<T> * MyStack<T>::get_top()
{
    return this->top;
}

template<typename T>
int MyStack<T>::get_size()
{
    return this->size;
}

template <typename T>
void MyStack<T>::set_top(Node<T> * top)
{
    this->top = top;
    return;
}

template <typename T>
void MyStack<T>::set_size(int size)
{
    this->size = size;
    return;
}

template <typename T>
bool MyStack<T>::isEmpty()
{
    return this->size == 0;
}

template <typename T>
void MyStack<T>::push(T data)
{
    Node<T> * temp = new Node<T>;
    temp->set_data(data);

    if(this->size == 0)
    {
        this->top = temp;
    }
    else
    {
        temp->set_next(this->top);
        this->top = temp;
    }

    this->size++;

    return;
}

template <typename T>
Node<T> * MyStack<T>::peek()
{
    if(this->size == 0)
    {
        return nullptr;
    }
    else
    {
        return this->top;
    }
}

template <typename T>
void  MyStack<T>::pop()
{
    if(this->size == 0)
    {
        return;
    }
    else
    {
        Node<T> * temp = new Node<T>;
        temp = this->top;
        this->top = this->top->get_next();
        this->size--;
        temp->set_next(nullptr);
        delete temp;
    }
}
