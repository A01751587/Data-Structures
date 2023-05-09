#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<char> char_set {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'c'}; //el tipo de dato de los set debe ser inmutable, ya que se usa como key

    char_set.insert('d');
    char_set.insert('e');
    //char_set.erase('b');

    for (char c : char_set){
        std::cout << c << ' ';
    }
    std::cout << '\n';

    std::cout << char_set.count('b') << '\n';
    std::cout << char_set.count('x') << '\n';

    std::unordered_set<int> int_set {4, 8, 15, 16, 23, 42};
    int_set.insert(108);
    for (int i : int_set){
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::unordered_set<std::string> string_set {"uno", "dos", "tres"};
    std::cout << string_set.erase("cuatro") << '\n';
    for(std::string s : string_set) {
        std::cout << s << ' ';
    }
    std::cout << '\n';
    return 0;
}