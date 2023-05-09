#include <iostream>

struct Node{
    int value;
    Node *next; // apuntador de tipo node, estructura que representa un nodo.
};

//Complejidad O(1)
Node* insert_first(Node *first, int value)
{
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = first;
    return new_node;
}

//Complejidad O(N)
void print_list(Node *first)
{
    while(first != nullptr){
        std::cout << first -> value << " ";
        first = first -> next;
    }
    std::cout << std::endl;
}

//Complejidad O(N)
void free_list(Node *first)
{
    Node *current = first;
    while (first != nullptr){
        first = first -> next;
        delete current;
        current = first;
    }

}

//Complejidad O(N)
int size(Node *first)
{
    int contador = 0;
    while (first != nullptr){
        contador += 1;
        first = first -> next;
    }
    return contador;
}

//Complejidad O(N)
int sum(Node *first)
{
    int suma = 0;
    while (first != nullptr){
        suma += first -> value;
        first = first -> next;
    }
    return suma;
}

void dup(Node *first)
{
    while (first != nullptr){
        Node *new_node = new Node;
        new_node -> value = first -> value;
        new_node -> next = first -> next;
        first -> next = new_node;
        first = new_node -> next;
    }
}

int main()
{
    Node *lst = nullptr;
    lst = insert_first(lst, 5); //Insertar un nodo en la lista con un valor.
    lst = insert_first(lst, 10); //Insertar otro nodo al inicio de la lista.
    lst = insert_first(lst, 15); //Insertar otro nodo
    print_list(lst);
    std::cout << "size = " << size(lst) << std::endl;
    std::cout << "sumatoria = " << sum(lst) << std::endl;
    lst = insert_first(lst, 20);
    lst = insert_first(lst, 30);
    dup(lst);
    print_list(lst);
    std::cout << "size = " << size(lst) << std::endl;
    std::cout << "sumatoria = " << sum(lst) << std::endl;
    free_list(lst);
    return 0;
}