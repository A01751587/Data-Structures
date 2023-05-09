/*----------------------------------------------------------
 * Práctica #6: Recursión
 * Implementación de funciones recursivas.
 *
 * Fecha: 12-Nov-2021
 * Autores:
 *           A01745912 Ricardo Antonio Cervantes Martínez
 *           A01751587 Paulo Ogando Gulias
 *----------------------------------------------------------*/

#include "intlist.h"
#include "recursion.h"

//Complejidad O(N)
int size(const IntList& a)
{
    if(is_empty(a)){
        return 0;
    } else {
        return size(rest(a)) + 1;
    }
}

//Complejidad O(N)
IntList cons_end(int value, const IntList& a)
{
    if (is_empty(a)){
        return IntList {value};
    } else{
        return cons(first(a), cons_end(value, rest(a)));
    }
}

//Complejidad O(N)
int sum(const IntList& a)
{
    if (is_empty(a)){
        return 0;
    } else{
        return first(a) + sum(rest(a));
    }
}

//Complejidad O(N)
IntList duplicate(const IntList& a)
{
    if(is_empty(a)){
        return IntList {};
    } else {
        return cons(first(a), cons (first(a), duplicate(rest(a))));
    }
}

//Complejidad O(N)
int last(const IntList& a)
{
    if (is_empty(rest(a))){
        return first(a);
    } else {
        return last(rest(a));
    }
}

//Complejidad O(N)
IntList but_last(const IntList& a)
{
    if (is_empty(rest(a))){
        return rest(a);
    }else {
        return cons (first(a), but_last(rest(a)));
    }
}

//Complejidad O(A)
int maximum(const IntList& a)
{
    if (is_empty(rest(a))){
        return first(a);
    } else {
        if(first(a) < last(a)){
            return maximum(rest(a));
        } else {
            return maximum(but_last(a));
        }
    }
}

//Complejidad O(A)
IntList append(const IntList& a, const IntList& b)
{
    if (is_empty(a)){
        return b;
    } else {
        return cons(first(a), append(rest(a),b));
    }
}

//Complejidad O(N)
IntList repeat(int n, int value)
{
    if(n == 0){
        return IntList {};
    } else {
        return cons(value, repeat(n-1, value));
    }
}

//Complejidad O(N)
IntList reverse(const IntList& a)
{
    if (is_empty(a)){
        return IntList {};
    }else {
        return cons_end(first(a), reverse(rest(a)));
    }
}

//Complejidad O(A/B)
IntList merge(const IntList& a, const IntList& b)
{
    if(is_empty(b)){
        return a;
    } else {
        return merge(insert(first(b),a), rest(b));
    }
}

//Complejidad O(A)
bool is_prefix(const IntList& a, const IntList& b)
{
    if(is_empty(a)){
        return true;
    } else if (is_empty(b)){
        return false;
    } else {
        return first(a) == first(b) & is_prefix(rest(a),rest(b));
    }
}

//Complejidad O(A)
IntList insert(int value, const IntList& a)
{
    if (is_empty(a)){
        return cons (value, a);
    } else if (value <= first(a)){
        return cons (value, a);
    } else if(value > first(a)){
        return cons (first(a), insert(value, rest(a)));
    }
}

//Complejidad O(A^2)
IntList insertion_sort(const IntList& a)
{
    if (is_empty(a)){
        return IntList {};
    } else {
        return insert(first (a), insertion_sort(rest(a)));
    }
}

//Complejidad O(N)
IntList binary(int n)
{
    if(n == 0){
        return IntList{};
    } else {
        return cons_end(n%2, binary(n/2));
    }
}