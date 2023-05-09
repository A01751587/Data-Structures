#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

const int max_value = 1'000;

void countingsort(std::vector<int>& values, int max)
{
    int counts[max];
    for(int i = 0; i <= max; ++i){
        counts[i] = 0;
    }
    for(int i = 0; i < values.size(); ++i){
        counts[values[i]] = counts[values[i]] + 1;
    }
    int index = 0;
    for(int i = 0; i <= max; ++i){
        for(int j = 1; j <= counts[i]; ++j){
            values[index] = i;
            index = index + 1;
        }
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
    std::vector<int> a(10'000'000);

    std::cout << std::boolalpha;

    fill_decremental(a, max_value);
    std::cout << "Ordenado inicialmente: "
        << std::is_sorted(a.begin(), a.end()) << '\n';

    auto start = std::chrono::high_resolution_clock::now();
    countingsort(a, *std::max_element(a.begin(), a.end()));
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop - start);
    double total_time = duration.count() / 1000000.0;

    std::cout << "Ordenado finalmente:   "
        << std::is_sorted(a.begin(), a.end()) << '\n';
    std::cout << "Tiempo de ejecución: "
        << total_time << " segundos \n";

    return 0;
}