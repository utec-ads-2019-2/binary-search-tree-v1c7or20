#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

template <typename T> 
class Iterator {
    private:
        stack<Node<T>*>* current;

    public:
        Iterator() {
            // TODO
        }

        Iterator(stack<Node<T>*>*nodes) {
            // TODO
        }

        Iterator<T>& operator=(const Iterator<T> &other) {
            // TODO
        }

        bool operator!=(Iterator<T> other) {
            // TODO
        }

        Iterator<T>& operator++() {
            // TODO
        }

        Iterator<T>& operator--() {
            // TODO
        }

        T operator*() {
            // TODO
        }
};

#endif
