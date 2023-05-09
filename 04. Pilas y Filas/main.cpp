#include <iostream>
#include "stacks_and_queues.h"

int main()
{
    std::cout << postfix_evaluation("2 2 +") << std::endl;
    // std::cout << postfix_evaluation("1 *") << std::endl;//Error 1
    // std::cout << postfix_evaluation("1 2 3") << std::endl;// Error 2
    // std::cout << postfix_evaluation("1 % 2 3 *") << std::endl;// Error 3
    // char a = '(';
    // char b = ')';
    // std::string c = "";
    // c += a;
    // c += b;
    // std::cout << c << std::endl;
    bool a = balanced_brackets("[]{}()[]{})([])");
    if(a){
        std::cout << "True" << std::endl;
    } else {
        std::cout << "F" << std::endl;
    }
    return 0;
}