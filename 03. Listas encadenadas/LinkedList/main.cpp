#include <iostream>
#include "linkedlist.h"

class Alumno {

};

int main()
{
    LinkedList<int> b;
    b.insert_front(1);
    b.insert_front(2);
    b.insert_front(3);
    b.insert_front(4);

    LinkedList<std::string> c;
    c.insert_front("alfa");
    c.insert_front("beta");
    c.insert_front("gamma");
    c.insert_front("delta");
    c.insert_front("épsilon");
    c.insert_front("dseta");

    b.remove_at(0);
    b.remove_at(1);
    std::cout << b.to_string() << std::endl;

    std::cout << c.to_string() << std::endl;
    c.remove_at(0);
    std::cout << c.to_string() << std::endl;

    return 0;
}