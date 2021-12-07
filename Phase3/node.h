#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
private:
    Node * next;
    T data;
public:
    Node();

    Node * get_next();
    T get_data();
    void set_next(Node * next);
    void set_data(T data);
};

#endif // NODE_H
