#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

const int max_value = 1'000;

// Complejidad: O(N^2)
void insertionsort(std::vector<int>& values)
{
     for(int i = 0; i < values.size(); i++){// 20 10 5
        int valor = values[i];//10
        int j = i - 1;//0
        while (j >= 0 and values[j] > valor){
            values[j + 1] = values[j];
            j = j - 1;
        }
        values[j + 1] = valor;
    }
}

// Complejidad: O(N)
void fill_random(std::vector<int>& values, int max_value)
{
    std::srand(0);
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = std::rand() % max_value;
    }
}

// Complejidad: O(N)
void print_vector(std::vector<int> values)
{
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> a(10);

    std::cout << std::boolalpha;

    //print_vector(a);

    fill_random(a, max_value);
    std::cout << "Ordenado inicialmente: "
        << std::is_sorted(a.begin(), a.end()) << '\n';

    print_vector(a);

    auto start = std::chrono::high_resolution_clock::now();
    insertionsort(a);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop - start);
    double total_time = duration.count() / 1000000.0;

    std::cout << "Ordenado finalmente:   "
        << std::is_sorted(a.begin(), a.end()) << '\n';
    std::cout << "Tiempo de ejecución: "
        << total_time << " segundos \n";

    print_vector(a);

    //Bubblesort su for inicia en 1

    return 0;
}