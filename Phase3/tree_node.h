#ifndef TREE_NODE_H
#define TREE_NODE_H


template<typename T>
class tree_node
{
private:
    T data;
    tree_node * parent;
    tree_node * left;
    tree_node * right;

public:
    tree_node(T data, tree_node<T> * parent, tree_node<T> * left, tree_node<T> * right);
    tree_node();

    T get_data();
    tree_node * get_parent();
    tree_node * get_left();
    tree_node * get_right();

    void set_data(T data);
    void set_parent(tree_node * parent);
    void set_left(tree_node * left);
    void set_right(tree_node * right);
};

#endif // TREE_NODE_H
