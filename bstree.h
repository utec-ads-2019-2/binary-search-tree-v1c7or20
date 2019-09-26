#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"
#include <vector>

template <typename T> 
class BSTree {
    Node<T> *root;
    size_t nodes;

    void print(Node<T>* node){
        Node<T> *iterador = node;
        if(nodes>0){
            if (iterador->left != nullptr){
                print(iterador->left);
            }
            cout<<iterador->data<<" ";
            if (iterador->right != nullptr){
                print(iterador->right);
            }
        }
    }

     Node<T>* remove( Node<T> *node, int data) {
        if (node == nullptr) {
            return nullptr;
        }
        if (data < node->data) {
            node->left = remove(node->left, data);
        } else if (data > node->data) {
            node->right = remove(node->right, data);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                if (node == root)
                    root = nullptr;
                nodes--;
                delete(node);
                node = nullptr;
            }
            else if (node->left == nullptr) {
                Node<T> *temp = node;
                node = node->right;
                if (temp == root)
                    root = node;
                nodes--;
                delete temp;
            }
            else if (node->right == nullptr) {
                Node<T> *temp = node;
                node = node->left;
                if (temp == root)
                    root = node;
                nodes--;
                delete temp;
            }
            else {
                Node<T> *temp = avanza(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }

    Node<T> *avanza(Node<T> *node) {
        if (node->left != nullptr) {
            return avanza(node->left);
        }
        return node;
    }

public:
        BSTree() : root(nullptr), nodes(0){};

        bool find(T data) {
            if (root == nullptr){
                return false;
            }
            Node<T> *iterador = root;
            while(data != iterador->data){
                if (data<iterador->data and iterador->left ){
                    iterador = iterador->left;
                } else{
                    if (data> iterador->data and iterador->right ){
                        iterador = iterador->right;
                    } else return false;
                }
            }
            return true;
        } 

        void insert(T data) {
            Node<T> * nuevo = new Node<T>(data);
            if (nodes == 0){
                root = nuevo;
                nodes++;
            }else{
                Node<T> *iterador = root;
                bool  control = true;
                while (control){
                    if (data != iterador->data){
                        if (data< iterador->data){
                            if(iterador->left ){
                                iterador = iterador->left;
                            }else{
                                iterador->left = nuevo;
                              nodes++;
                                control = false;
                            }
                        }else{
                            if (iterador->right ){
                                iterador =iterador->right;
                            }else{
                                iterador->right = nuevo;
                                 nodes++;
                                control = false;
                            }
                        }
                    }else
                        control = false;
                }
            }
        }

        bool remove(T data) {
             return remove(root, data) != nullptr;
        }

        size_t size() {
            return nodes;
        }

        size_t height() {
            auto temp = root;
            if (!temp) {
                return 0;
            } else {
                size_t left = getHeight(temp->left);
                size_t rigth   = getHeight(temp->right);
                if (left > rigth) {
                    return (left + 1);
                } else {
                    return (rigth + 1);
                }
            }
        }


        void traversePreOrder() {
            Node<T> *iterador = root;
            if (iterador != nullptr){
                cout<<iterador->data<<" ";
                if (iterador->left != nullptr){
                    print(iterador->left);
                }
                if (iterador->right != nullptr){
                    print(iterador->right);
                }
            }else throw "No elements";
        }

        void traverseInOrder() {
            Node<T> *iterador = root;
            if (iterador != nullptr){
                if (iterador->left != nullptr){
                    print(iterador->left);
                }
                cout<<iterador->data<<" ";
                if (iterador->right != nullptr){
                    print(iterador->right);
                }
            } else throw out_of_range("No elements");
            cout<<endl;
        }

        void traversePostOrder() {
            Node<T> *iterador = root;
            if (iterador != nullptr){
                if (iterador->left != nullptr){
                    print(iterador->left);
                }
                if (iterador->right != nullptr){
                    print(iterador->right);
                }
                cout<<iterador->data<<" ";
            } else throw "No elements";
        }

        void armariterador( stack<Node<T>*> *iterador, Node<T>* actual){
            if (actual != nullptr){
                iterador->push(actual);
                armariterador(iterador,actual->left);
            }
        }

        Iterator<T> begin() {
            stack<Node<T>*>* stacks;
            stacks=new stack<Node<T>*>;
            Node<T>* nulo = nullptr;
            stacks->push(nulo);
            armariterador(stacks,root);
            return Iterator<T>(stacks);
        }

        Iterator<T> end() {
            stack<Node<T>*> *iterador = new stack<Node<T>*>;
            Node<T> * final = nullptr;
            iterador->push(final);
            return Iterator<T>(iterador);
        }

        ~BSTree() {
            root->killSelf();
            root = nullptr;
        }
};

#endif
