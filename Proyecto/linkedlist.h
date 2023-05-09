/*----------------------------------------------------------
 * Práctica #1: DinoSets
 * Implementación de la clase DinoSet.
 *
 * Fecha: 1-Oct-2021
 * Autores:
 *           A01745912 Ricardo Antonio Cervantes Martínez
 *           A01751587 Paulo Ogando Gulias
 *----------------------------------------------------------*/

#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>

template<typename T>
class LinkedList{

public:

    //Constructor por omisión.
    //Complejidad O(1)
    LinkedList()
    {
        _sentinel = new Node;
        _sentinel->next = _sentinel;
        _sentinel->prev = _sentinel;
        _size = 0;
    }

    //Manda a llamar al otro constructor con los ":", se efecuta primero el que se manda a llamar.
    LinkedList(std::initializer_list<T> args): LinkedList()
    {
        for (T arg: args){
            insert_back(arg);
        }
    }

    // Deshabilitar el constructor de copiado.
    LinkedList(const LinkedList<T>& other) = delete;

    // Deshabilitar el operador de asignación.
    LinkedList<T>& operator=(const LinkedList<T>& other) = delete;

    // Complejidad O(N).
    ~LinkedList()
    {
        Node *p = _sentinel->next;
        while (p != _sentinel){
            Node *current = p;
            p = p->next;
            delete current;
            current = nullptr;
        }
        delete _sentinel;
        _sentinel = nullptr;
    }

    //Complejidad O(N)
    std::string to_string() const
    {
        std::ostringstream result; // es un flujo de salida que lo usa como un string.
        result << "[";

        Node *p = _sentinel->next;
        bool first_time = true;
        while (p != _sentinel){
            if (first_time){
                first_time = false;
            }else{
                result << ", ";
            }
            result << p->value;
            p = p->next;
        }
            result << "]";
            return result.str();
    }

    // Complejidad: O(1).
    void insert_front(T value)
    {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = _sentinel->next;
        new_node->prev = _sentinel;
        _sentinel->next->prev = new_node; //Se actualiza el apuntador previo del next de sentinel.
        _sentinel->next = new_node;
        ++_size;
    }

    //Complejidad O(1).
    int size() const
    {
        return _size;
    }

    //Complejidad O(1)
    void insert_back(T value)
    {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = _sentinel;
        new_node->prev = _sentinel->prev;
        _sentinel->prev->next = new_node;
        _sentinel->prev = new_node;
        ++_size;
    }

    //Complejidad O(1)
    T remove_front()
    {
        if(is_empty()){
            throw std::length_error("Can't remove from the front of empty list.");
        }else{
           Node *current = _sentinel->next;
           _sentinel->next = current->next;
           current->next->prev = _sentinel;
           T result = current->value;
           delete current;
           current = nullptr;
           --_size;
           return result;
        }
    }

    //Complejidad O(1)
    bool is_empty() const
    {
        if (_size == 0){
            return true;
        }else{
            return false;
        }
    }

    //Complejidad O(N)
    void insert_at(int index, T value)
    {
        if ((index >= _size) or (index < 0)) {
            throw std::out_of_range("Index out of range");
        } else if (index == 0){
            insert_front(value);
        } else if (index == _size){
            insert_back(value);
        } else {
            Node *p;
            p = _sentinel->next;
            Node *new_node = new Node;
            new_node->value = value;
            for(int i = 0; i < index; ++i){
                p = p->next;
            }
            new_node->next = p;
            new_node->prev = p->prev;
            p->prev->next = new_node;
            p->prev = new_node;
            ++_size;
        }
    }

    //Complejidad O(N)
    void extend(const LinkedList<T>& other)
    {
        Node* p = other._sentinel->next;
        while (p != other._sentinel){
            insert_back(p->value);
            p = p->next;
        }
    }

    //Complejidad O(N)
    bool contains(T value) const
    {
        Node* p = _sentinel->next;
        bool result = false;
        while (p != _sentinel){
            if (p->value == value){
                result = true;
            }
            p = p->next;
        }
        return result;
    }

    //Complejidad O(N)
    T get(int index) const
    {
        T result;
         if ((index > (_size - 1)) or (index < 0)) {
            throw std::out_of_range("Index out of range");
        } else {
            Node* p = _sentinel->next;
            for (int i = 0; i < _size; i++ ){
                if (i == index){
                    result = p->value;
                }
                p = p->next;
            }
        }
        return result;
    }

private:

    struct Node {
        T value;
        Node *next; //Apuntador al siguiente.
        Node *prev; //Apuntador al anterior.
    };

    Node *_sentinel;
    int _size;


};