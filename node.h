#ifndef NODE_H
#define NODE_H

template <typename T>
class BSTree; 

template <typename T>
class Iterator; 

template <typename T>
class Node {
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T data): data(data), left(nullptr), right(nullptr){}

    void killSelf() {
        if(left != nullptr){
            left->killSelf();
        }
        if(right != nullptr){
            right->killSelf();
        }
        delete this;
    }


    template<class>
    friend class BSTree; 

    template<class>
    friend class Iterator; 
};

#endif