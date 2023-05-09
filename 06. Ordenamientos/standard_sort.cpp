#include <algorithm>
#include <iostream>
#include <vector>

void print(std::vector<std::string>& values)
{
    for(std::string value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

bool mi_comparador(const std::string& a, const std::string& b)
{
    return a.size() < b.size();
}

int main()
{
    std::vector<std::string> months {
        "enero",
        "febrero",
        "marzo",
        "abril",
        "mayo",
        "junio",
        "julio",
        "agosto",
        "septiembre",
        "octubre",
        "noviembre",
        "diciembre"
    };

    print(months);
    //Ordenamiento normal
    std::sort(months.begin(),months.end());
    print(months);
    //Con indices
    // std::sort(months.begin() + 6,months.begin() + 10);
    // print(months);
    //Con comparador
    // std::sort(months.begin(),months.end(), mi_comparador);
    // print(months);

}