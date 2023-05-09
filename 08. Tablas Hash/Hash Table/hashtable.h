/*----------------------------------------------------------
 * Práctica #5: Tablas hash
 * Implementación de la clase HashTable.
 *
 * Fecha: 5-Nov-2021
 * Autores:
 *           A01745912 Ricardo Antonio Cervantes Martínez
 *           A01751587 Paulo Ogando Gulias
 *----------------------------------------------------------*/

#pragma once

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename K, typename T>
class HashTable {

public:

    HashTable(const HashTable<K, T>&) = delete;
    HashTable<K, T>& operator=(const HashTable<K, T>&) = delete;

    //Complejidad: O(N)
    HashTable(int num_buckets)
    {
        _bucket = new Pair*[num_buckets];
        _num_buckets = num_buckets;
        _size = 0;
        for (int i = 0; i < _num_buckets; ++i) {
            _bucket[i] = new Pair;
        }
    }

    //Complejidad O(N/B)
    ~HashTable()
    {
        for (int i = 0; i < _num_buckets; ++i) {
            Pair *p = _bucket[i]->next;
            while (p != nullptr) {
                Pair *current = p;
                p = p->next;
                delete current;
                current = nullptr;
            }
        }
        for (int i = 0; i < _num_buckets; ++i) {
            Pair *p = _bucket[i];
            delete p;
            p = nullptr;
        }
        delete[] _bucket;
        _bucket = nullptr;
    }

    //Complejidad O(N / B)
    bool put(K key, T value)
    {
        int hash = _hash(key);
        Pair *p = _bucket[hash]->next;
        while (p != nullptr) {
            if (key == p->key) {
                p->value = value;
                return false;
            }
            p = p->next;
        }
        Pair *new_pair = new Pair;
        new_pair->key = key;
        new_pair->value = value;
        new_pair->next = _bucket[hash]->next;
        _bucket[hash]->next = new_pair;
        ++_size;
        return true;
    }

    //Complejidad O(N / B)
    bool contains_key(K key) const
    {
        int hash = _hash(key);
        Pair *p = _bucket[hash]->next;
        while (p != nullptr) {
            if(key == p->key) {
                return true;
            }
            p = p->next;
        }
        return false;
    }

    //Complejidad O(N / B)
    T get(K key) const
    {
        int hash = _hash(key);
        Pair *p = _bucket[hash]->next;
        while (p != nullptr) {
            if(key == p->key) {
                return p->value;
            }
            p = p->next;
        }
        throw std::invalid_argument("key not found");
    }

    //Complejidad O(N / B)
    T get_or_default(K key, T default_value) const
    {
        int hash = _hash(key);
        Pair *p = _bucket[hash]->next;
        while (p != nullptr) {
            if(key == p->key) {
                return p->value;
            }
            p = p->next;
        }
        return default_value;
    }

    //Complejidad O(1)
    bool is_empty() const
    {
        if(_size == 0){
            return true;
        } else {
            return false;
        }
    }

    //Complejidad O(1)
    int size() const
    {
        return _size;
    }

    //Complejidad O(N/B)
    bool remove(K key)
    {
        int hash = _hash(key);
        Pair *p = _bucket[hash]->next;
        Pair *current = _bucket[hash];
        while (p != nullptr) {
            if(key == p->key) {
                current->next = p->next;
                delete p;
                --_size;
                p = nullptr;
                return true;
            }
            p = p->next;
            current = current->next;
        }
        return false;
    }

    //Complejidad O(N)
    void clear()
    {
        if (not(is_empty())){
            for (int i = 0; i < _num_buckets; ++i) {
                Pair *p = _bucket[i]->next;
                Pair *sentinel = _bucket[i];
                while (p != nullptr) {
                    Pair *current = p;
                    p = p->next;
                    delete current;
                    --_size;
                    current = nullptr;
                    sentinel->next = p;
                }
            }
        }
    }

    //Complejidad O(NlogN)
    std::vector<K> keys() const
    {
        std::vector<K> llaves;
        for (int i = 0; i < _num_buckets; ++i) {
            Pair *p = _bucket[i]->next;
            while (p != nullptr) {
                llaves.push_back(p->key);
                p = p->next;
            }
        }
        std::sort(llaves.begin(), llaves.end());
        return llaves;
    }

    //Complejidad O(B)
    void put_all(const HashTable<K, T>& other)
    {
        for (int i = 0; i < other._num_buckets; ++i) {
            Pair *p = other._bucket[i]->next;
            while (p != nullptr) {
                put(p->key, p->value);
                p = p->next;
            }
        }
    }

    //Complejidad O(N/B)
    bool operator==(const HashTable<K, T>& other) const
    {
        if (_size == other._size){
            for (int i = 0; i < _num_buckets; ++i) {
                Pair *p = _bucket[i]->next;
                while (p != nullptr) {
                    if ((other.contains_key(p->key))&(p->value==other.get(p->key))){
                        p = p->next;
                    } else {
                        return false;
                    }
                }
            }
        } else {
            return false;
        }
        return true;
    }

private:

    struct Pair {
        K key{};
        T value{};
        Pair *next{nullptr};
    };

    std::size_t _hash(K key) const
    {
        std::hash<K> h;
        return h(key) % _num_buckets;
    }

    Pair **_bucket;
    int _num_buckets;
    int _size;

};