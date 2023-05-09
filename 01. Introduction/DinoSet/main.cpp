#include <iostream>
#include "dinoset.h"

int main()
{
    DinoSet a; //Al ser creado por default, todos sus valores son falsos
    DinoSet b;
    DinoSet c;
    DinoSet d;

    a.add(DinoId::velocirraptor);
    a.add(DinoId::triceratops);
    b.add(DinoId::triceratops);
    b.add(DinoId::pteranodon);

    c = a + b;

    std::cout << a.to_string() << std::endl;
    std::cout << d.to_string() << std::endl;
    std::cout << a.contains(DinoId::velocirraptor) << std::endl;
    std::cout << a.contains(DinoId::tiranosaurio) << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << a.is_empty() << std::endl;
    std::cout << d.is_empty() << std::endl;
    return 0;
}