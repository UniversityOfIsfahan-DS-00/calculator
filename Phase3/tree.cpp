#include "tree.h"

template <typename T>
tree<T>::tree()
{
    this->root = nullptr;
}

template <typename T>
void tree<T>::remove(tree_node<T> * begin)
{
    if(begin == nullptr)
    {
        return;
    }

    remove(begin->get_left());
    remove(begin->get_right());

    delete begin;
}

template <typename T>
tree<T>::~tree()
{
    remove(this->root);
}

template <typename T>
void tree<T>::set_root(tree_node<T> * root)
{
    this->root = root;
    return;
}

template <typename T>
tree_node<T> * tree<T>::get_root()
{
    return this->root;
}

template <typename T>
int tree<T>::height(tree_node<T> *begin)
{
    if(begin == nullptr)
    {
        return -1;
    }
    else
    {
        int left_height = height(begin->get_left());
        int right_height = height(begin->get_right());

        if(left_height > right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }
}

template <typename T>
void tree<T>::print_current_level(tree_node<T> * begin, int level, QString *str)
{
    if(begin == nullptr)
    {
        *str += "x";
        return;
    }
    if(level == 1)
    {
        *str += begin->get_data() + " ";
    }
    else if(level > 1)
    {
        print_current_level(begin->get_left(), level-1, str);
        for(int i = 0; i < level; i++)
        {
            *str += " ";
        }
        print_current_level(begin->get_right(), level-1, str);
        for(int i = 0; i < level; i++)
        {
            *str += " ";
        }
    }
}

template <typename T>
void print_level_order(tree_node<T> *begin, MyStack<QString> *st)
{
    tree<QString> *t = new tree<QString>;
    QString str;
    t->set_root(begin);
    int h = t->height(begin);
    for(int i = 1; i <= h+1; i++)
    {
        str = "";
        t->print_current_level(begin, i, &str);
        st->push(str);
    }
    return;
}
