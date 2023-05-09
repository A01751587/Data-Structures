#include <iostream>

int main()
{
    int min = 1'000'000'000;
    int max = 2'000'000'000;

    //Esto se acerca al Overflow, por lo que al hacer cualquier operacion con estos datos va a ocurrir overflow
    int mid = (min + max)/2;

    //Para resolver esto, la operacion se debe realizar de la siguiente forma:
    int midAntiOverflow = min + (max-min)/2;

    std::cout << min << '\n';
    std::cout << max << '\n';
    std::cout << mid << '\n';
    std::cout << midAntiOverflow << '\n';
}