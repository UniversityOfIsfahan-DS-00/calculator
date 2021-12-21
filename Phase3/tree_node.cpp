#include "tree_node.h"


template <typename T>
tree_node<T>::tree_node(T data, tree_node<T> * parent, tree_node<T> * left, tree_node<T> * right)
{
    this->data = data;
    this->parent = parent;
    this->left = left;
    this->right = right;
}

template <typename T>
tree_node<T>::tree_node()
{
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template <typename T>
T tree_node<T>::get_data()
{
    return this->data;
}

template <typename T>
tree_node<T> * tree_node<T>::get_parent()
{
    return this->parent;
}

template <typename T>
tree_node<T> * tree_node<T>::get_left()
{
    return this->left;
}

template <typename T>
tree_node<T> * tree_node<T>::get_right()
{
    return this->right;
}

template <typename T>
void tree_node<T>::set_data(T data)
{
    this->data = data;
}

template <typename T>
void tree_node<T>::set_parent(tree_node<T> * parent)
{
    this->parent = parent;
}

template <typename T>
void tree_node<T>::set_left(tree_node<T> * left)
{
    this->left = left;
}

template <typename T>
void tree_node<T>::set_right(tree_node<T> * right)
{
    this->right = right;
}
