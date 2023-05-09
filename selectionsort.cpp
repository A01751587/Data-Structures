#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

const int max_value = 1'000;

void selectionsort(std::vector<int>& values)
{
    for (int i = 0; i < values.size() - 1; ++i){
        int min_index = i;
        for (int j = i + 1; j < values.size(); ++j){
            if (values.at(j) < values.at(min_index)){
                min_index = j;
            }
        }
        std::swap(values.at(i),values.at(min_index));
    }
}

void fill_random(std::vector<int>& values, int max_value)
{
    std::srand(0);
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = std::rand() % max_value;
    }
}

void fill_incremental(std::vector<int>& values, int max_value)
{
    double section = max_value / static_cast<double>(values.size());
    double current = 0.0;
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = static_cast<int>(current);
        current += section;
    }
}

void fill_decremental(std::vector<int>& values, int max_value)
{
    double section = max_value / static_cast<double>(values.size());
    double current = 0.0;
    for (int i = values.size() - 1; i >= 0; --i) {
        values.at(i) = static_cast<int>(current);
        current += section;
    }
}

void print_vector(std::vector<int> values)
{
    for (int value : values){
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> a(1'000'000);

    //Manipulador de true y false.
    std::cout << std::boolalpha;

    fill_decremental(a, max_value);
    std::cout << "Ordenado: " << std::is_sorted(a.begin(), a.end()) << '\n';

    auto start = std::chrono::high_resolution_clock::now();
    selectionsort(a);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop - start);
    double total_time = duration.count() / 1000000.0;

    std::cout << "Ordenado: " << std::is_sorted(a.begin(), a.end()) << '\n';
    std::cout << "Tiempo de ejecucion: " << total_time << " segundos." << '\n';

    return 0;
}