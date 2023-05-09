#include <iostream>

int main()
{
    int i;  //i es un entero
    int *p; //p es un apuntador a un entero

    i = 5;
    p = &i; // p apunta a la direccion de i.

    std::cout << " i = " << i << std::endl;
    std::cout << " p = " << p << std::endl; //cada que se corre el progrma, la direccion cambia
    std::cout << "*p = " << *p << std::endl;
    std::cout << "&p = " << &p << std::endl; //direccion de p, se encuentra 4 bytes mas adelante de i
    std::cout << "sizeof(i) = " << sizeof(i) << std::endl;
    std::cout << "sizeof(p) = " << sizeof(p) << std::endl;

    ++(*p);
    std::cout << " i = " << i << std::endl;

    return 0;
}