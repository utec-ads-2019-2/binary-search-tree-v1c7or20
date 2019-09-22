#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <vector>

template <typename T> 
class Iterator {
    private:
        vector<Node<T>*>* current;
        int actual=0;
        Node<T>* dato;
    public:
        Iterator() {
            // TODO
        }

        Iterator(vector<Node<T>*>*nodes) {
            this->current = nodes;
            this->dato = nodes->at(0);
        }

        Iterator<T>& operator=(const Iterator<T> &other) {
            this->current = other.current;
            this->dato = current->at(0);
        }

        bool operator!=(Iterator<T> other) {
            return this->dato != other.dato;
        }

        Iterator<T>& operator++() {
            actual++;
            dato = current->at(actual);
            return *this;
        }

        Iterator<T>& operator--() {
            actual--;
            dato = current->at(actual);
            return *this;
        }

        T operator*() {
            return this->dato->data;
        }
};

#endif
