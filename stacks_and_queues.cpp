#include <cctype>
#include <queue>
#include <regex>
#include <stack>
#include <stdexcept>
#include <string>
#include <iostream>
#include "stacks_and_queues.h"

std::queue<std::string> split(const std::string& input)
{
    std::regex exp(R"((\d+)|(\s)|(.))");
    std::smatch match;
    std::string next_input = input;
    std::queue<std::string> result;

    while(regex_search(next_input, match, exp)) {
        if (match[2] == "") {
            result.push(match[0]);
        }
        next_input = match.suffix();
    }

    return result;
}

int postfix_evaluation(const std::string& expr)
{
    std::queue<std::string> tokens = split(expr);//token es un nombre comun para estos casos de numeros y caracteres
    std::stack<int> eval_stack;

    while(not tokens.empty()){
        std::string element = tokens.front();
        tokens.pop();

        if (isdigit(element[0])){
            eval_stack.push(stoi(element));
        } else if (element == "+" or element == "-"
            or element == "*" or element == "/") {
                if (eval_stack.size() < 2){
                    throw std::invalid_argument(expr + "has too few operands for operator" + element);
                }
                int b = eval_stack.top();
                eval_stack.pop();
                int a = eval_stack.top();
                eval_stack.pop();

                int result;

                if(element == "+"){
                    result = a+b;
                } else if (element == "-") {
                    result = a-b;
                } else if (element == "*") {
                    result = a*b;
                } else {
                    result = a/b;
                }

                eval_stack.push(result);
            } else {
                throw std::invalid_argument(expr + "is not a valid argument");
            }
    }

    if(eval_stack.size() == 1) {
        return eval_stack.top();
    } else {
        throw std::invalid_argument("The stack has more than 1 argument");
    }

    return 0;
}

bool balanced_brackets(const std::string& expr)
{
    std::stack<char> brackets;

    for(int i = 0; i < expr.size(); ++i){
        char elem = expr[i];
        if(elem == '(' or elem == '{'
            or elem == '['){
                brackets.push(elem);
            } else if (elem == ')' or elem == '}'
                or elem == ']'){
                    if(brackets.size() == 0){
                        return false;
                    }
                    char a = brackets.top();

                    std::string c = "";
                    c += a;
                    c += elem;
                    std::cout << c << std::endl;

                    if (a == '{' and elem == '}'){
                        brackets.pop();
                    } else if (a == '[' and elem == ']'){
                        brackets.pop();
                    } else if (a == '(' and elem == ')'){
                        brackets.pop();
                    }
                }
    }
    if(brackets.size() == 0){
        return true;
    } else {
        return false;
    }
}