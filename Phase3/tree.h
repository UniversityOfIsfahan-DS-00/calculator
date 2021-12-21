#ifndef TREE_H
#define TREE_H

#include "tree_node.h"
#include "mystack.h"
#include "QString"

template <typename T>
class tree
{
private:
     tree_node<T> * root;

public:
    tree();
    ~tree();

    tree_node<T> * get_root();
    void set_root(tree_node<T> * root);

    void remove(tree_node<T> * begin);

    int height(tree_node<T> * begin);

    void print_current_level(tree_node<T> * begin, int level, QString *st);

    void print_level_order(tree_node<T> * begin, MyStack<QString> &st);
};

#endif // TREE_H
