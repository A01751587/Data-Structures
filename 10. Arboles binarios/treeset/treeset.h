#pragma once

#include <functional>
#include <initializer_list>
#include <algorithm>
#include <queue>

template<typename T> //Permite que el dato sea de cualquier tipo
class TreeSet {

public:

    //Complejidad O(1)
    TreeSet() {}

    //Complejidad O(N)
    TreeSet(std::initializer_list<T> args)
    {
        for (T value : args) {
            add(value);
        }
    }

    //Complejidad O(N)
    ~TreeSet()
    {
        _destroy(_root);
    }

    //Complejidad O(log N)
    bool add(T value)
    {
        if (_root == nullptr) {
            _root = new Node(value);
            ++_size;
            return true;
        } else {
            Node* p = _root;
            while (true) {
                if (value == p->value) {
                    return false;
                } else if (value < p->value) {
                    if (p->left == nullptr){
                        p->left = new Node(value);
                        ++_size;
                        return true;
                    } else {
                        p = p->left;
                    }
                } else {
                    if (p->right == nullptr){
                        p->right = new Node(value);
                        ++_size;
                        return true;
                    } else {
                        p = p->right;
                    }
                }
            }
        }
    }

    int size() const
    {
        return _size;
    }

    bool is_empty() const
    {
        if(_size == 0){
            return true;
        } else {
            return false;
        }
    }

    //Complejidad O(log N)
    bool contains(T value) const
    {
        return _contains(value, _root);
    }

    //Complejidad O(N)
    void inorder(std::function<void(T)> fn) const
    {
        _inorder(fn, _root);
    }

    void preorder(std::function<void(T)> fn) const
    {
        _preorder(fn, _root);
    }

    void postorder(std::function<void(T)> fn) const
    {
        _postorder(fn, _root);
    }

    //Complejidad O(N)
    void levelorder(std::function<void(T)> fn) const
    {
        std::queue<Node*> queue;

        queue.push(_root);

        while(not queue.empty()){
            Node* p = queue.front();
            queue.pop();

            if (p != nullptr){
                fn(p->value);
                queue.push(p->left);
                queue.push(p->right);
            }
        }
    }

    int height() const
    {
        return _height(_root);
    }

private:

    struct Node {
        Node(T v): value(v) {}
        T value;
        Node* left = nullptr; //Apuntador
        Node* right = nullptr; //Apuntador
    };

    void _destroy(Node* p) //Utiliza recursividad
    {
        if (p != nullptr) {
            _destroy(p->left);
            _destroy(p->right);
            delete p;
            p = nullptr;
        }
    }

    void _inorder(std::function<void(T)> fn, Node* p) const
    {
        if (p != nullptr) {
            _inorder(fn, p->left);
            fn(p->value);
            _inorder(fn, p->right);
        }
    }

    void _preorder(std::function<void(T)> fn, Node *p) const
    {
        if (p != nullptr) {
            fn(p->value);
            _preorder(fn, p -> left);
            _preorder(fn, p->right);
        }
    }

    void _postorder(std::function<void(T)> fn, Node *p) const
    {
        if (p != nullptr) {
            _postorder(fn, p->left);
            _postorder(fn, p->right);
            fn(p -> value);
        }
    }

    int _height(Node* p) const
    {
        if(p == nullptr){
            return -1;
        } else {
            return std::max(_height(p -> left),
            _height(p -> right)) + 1;
        }
    }

    bool _contains(T value, Node* p) const
    {
        if (p == nullptr){
            return false;
        } else if (value == p -> value){
            return true;
        } else if (value < p->value){
            return _contains(value, p -> left);
        } else {
            return _contains(value, p -> right);
        }
    }

    Node* _root = nullptr;
    int _size = 0;
};