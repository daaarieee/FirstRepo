#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <vector>
#include <limits>
#include "Calc.cpp"

/*calc*/
int main()
{
    Mathem operation;
    double a, b, res;
    char op;
    
    std::cout << "Type the task (e.g., 5 + 7)" << std::endl;
    std::cin >> a >> op >> b;
    
    switch (op)
    {
    case '+':
        operation.add(a, b);
        break;
    case '-':
        operation.sub(a, b);
        break;
    case '*':
        operation.multiply(a, b);
        break;
    case '/':
        operation.divide(a, b);
        break;
    default:
        printError();
        return 1; 
    }

    res = operation.getResult();
    std::cout << "The result is: " << res << std::endl;
    
    return 0;
}