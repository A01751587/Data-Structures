/*----------------------------------------------------------
 * Práctica #2: Listas encadenadas
 * Implementación de la clase LinkedList.
 *
 * Fecha: 10-Sep-2021
 * Autores:
 *           A01745912 Ricardo Antonio Cervantes Martínez
 *           A01751587 Paulo Ogando Gulias
 *----------------------------------------------------------*/

#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>

template<typename T>//Plantilla que permite dejarlo de forma parametrica, al declararlo asi nos permite definir en el main que tipo de dato contendra la lista
class LinkedList {

public:

    //Constructor por omision
    //Complejidad (0)
    LinkedList()
    {
        _sentinel = new Node;
        _sentinel -> next = _sentinel;
        _sentinel -> prev = _sentinel;
        _size = 0;
    }

    //Constructor con inicialzador
    LinkedList(std::initializer_list<T>args): LinkedList()
    {
        for(T arg: args) {
            insert_back(arg);
        }
    }

    //Deshabilitar Constructor de copiado
    LinkedList(const LinkedList<T>&) = delete;

    //Deshabilitar Operador de asignacion
    LinkedList<T>& operator=(const LinkedList<T>&) = delete;

    //Complejidad O(N)
    ~LinkedList() // el simbolo ~ se llama tilde
    {
        //std::cout << "Destructor invocado" << std::endl;
        Node *p = _sentinel -> next;
        while (p != _sentinel) {
            Node *current = p;
            p = p -> next;
            delete current;
            current = nullptr; //Esto en realidad es innecesario, pero es una proteccion
        }
        delete _sentinel;
        _sentinel = nullptr; //despues de un delete, colocar el pointer como null
    }

    //Complejidad O(N)
    bool contains(T value) const
    {
        Node *p = _sentinel -> next;
        while (p != _sentinel){
            if (p->value == value){
                std::cout << "True" << std::endl;
                return true;
            }
            p = p->next;
        }
        return false;
    }

    //Complejidad O(N)
    void extend(const LinkedList<T>&other)
    {
        Node *p = other._sentinel->next;
        while(p != other._sentinel){
            insert_back(p->value);
            p = p->next;
        }
    }

    //Complejidad O(N)
    T get(int index) const
    {
        T result;
        Node* p = _sentinel->next;
        if ((index < 0) or (index > (size() - 1))){
            throw std::out_of_range("Index out of range");
        } else {
            for (int i = 0; i < _size; i++ ){
                if (i == index){
                    result = p->value;
                }
                p = p->next;
            }
        }
        return result;
    }
    //Complejidad O(N)
    void insert_at(int index,T value)
    {
        if ((index > _size) or (index < 0)) {
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

    //Complejidad O(1)
    void insert_back(T value)
    {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = _sentinel;
        new_node -> prev = _sentinel->prev;
        _sentinel->prev->next = new_node;
        _sentinel->prev = new_node;
        ++_size;
    }

    //Complejidad O(1)
    void insert_front(T value)
    {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = _sentinel -> next;
        new_node -> prev = _sentinel;
        _sentinel->next->prev = new_node;
        _sentinel->next = new_node;
        ++_size;
    }

    //Complejidad O(1)
    bool is_empty() const
    {
        if (_size == 0){
            return true;
        } else {
            return false;
        }
    }

    //Complejidad O(N)
    T remove_at(int index)
    {
        if ((index >= _size) or (index < 0)) {
            throw std::out_of_range("Index out of range");
        } else if (index == 0){
            T result = remove_front();
            return result;
        } else if (index == (_size - 1)){
            T result = remove_back();
            return result;
        } else {
            Node *current;
            current = _sentinel->next;
            for(int i = 0; i < index; ++i){
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current -> prev;

            T result = current->value;
            delete current;
            current = nullptr;
            --_size;
            return result;
        }
    }

    //Complejidad O(1)
    T remove_back()
    {
        if (is_empty()) {
            throw std::length_error(
                "Can't remove anything from an empty list");
        } else {
            Node *current = _sentinel ->prev;
            _sentinel->prev = current->prev;
            current->prev->next = _sentinel;
            T result = current -> value;
            delete current;
            current = nullptr;
            --_size;
            return result;
        }
    }

    //Complejidad O(1)
    T remove_front()
    {
        if (is_empty()) {
            throw std::length_error(
                "Can't remove anything from an empty list");
        } else {
            Node *current = _sentinel ->next;
            _sentinel->next = current->next;
            current->next->prev = _sentinel;
            T result = current -> value;
            delete current;
            current = nullptr;
            --_size;
            return result;
        }

    }

    //Complejidad O(1)
    int size() const
    {
        return _size;
    }

    //Complejidad O(N)
    std::string to_string() const
    {
        std::ostringstream result; //Un flujo de salida de string
        result << "[";

        bool first_time = true;
        Node *p = _sentinel -> next;
        while (p != _sentinel){
            if (first_time){
                first_time = false;
            } else {
                result << ", ";
            }
            result << p->value;
            p = p->next;
        }

        result << "]";
        return result.str();
    }

private:

    struct Node {
        T value;
        Node *next;
        Node *prev;
    };

    Node *_sentinel;
    int _size;
};