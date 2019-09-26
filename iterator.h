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
            current = nullptr;
        }

        Iterator(stack<Node<T>*>*nodes) {
            this->current = nodes;
        }

        Iterator<T>& operator=(const Iterator<T> &other) {
            this->current = other.current;
            this->dato = current->top();
        }

        bool operator!=(Iterator<T> other) {
            return this->current->top() != other.current->top();
        }

        Iterator<T>& operator++() {
            Node<T>* last = current->top();
            current->pop();
            Node<T>* iterado= nullptr;
           if (last->right != nullptr){
               iterado = last->right;
               current->push(iterado);
               while (iterado->left != nullptr){
                   iterado = iterado->left;
                   current->push(iterado);
               }
           }
            return *this;
        }

       /* Iterator<T>& operator--() {
            return *this;
        }*/

        T operator*() {
            return (this->current->top())->data;
        }
};

#endif
