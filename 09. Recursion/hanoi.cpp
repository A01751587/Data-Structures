#include <iostream>

void hanoi(int n,
        std::string origen,
        std::string auxiliar,
        std::string destino)
{
    if (n > 0){
        hanoi(n - 1, origen, destino, auxiliar);
        std::cout << "Mover disco " << n << " de " << origen
        << " a " << destino << '\n';
        hanoi(n - 1, auxiliar, origen, destino);
    }
}

int main()
{
    hanoi(3, "A", "B", "C");
    return 0;
}