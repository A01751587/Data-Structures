#include <iostream>
#include <vector>

int main ()
{
    //std::vector<int> a(10); //inicializa el vector con 10 0
    std::vector<int> a(10,42); // inicializa el vector con 10 42
    //a.reserve(1024); //Solo se usa si la memoria es importante

    a.push_back(4);
    a.push_back(8);
    a.push_back(15);
    a.push_back(16);
    a.push_back(32);

    a[0] = 77;
    a[100] = 66;
    //a.at(100) = 55 //Lanza excepcion porque el vector no tiene ese tamaño
    // Es mejor usar at en vez de corchetes, el costo es un poco de velocidad en el programa
    for (int i = 0; i < a.size(); ++i){ //si colocamos menor o igual, el at lanza excepcion porque se pasa de la cantidad de datos del vector
        // std::cout << a[i] << ' ';
        std::cout << a.at(i) << ' ';
    }
    std::cout << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << a.capacity() << std::endl;

    int b[5];

}