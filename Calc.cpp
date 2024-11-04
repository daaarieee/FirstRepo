#include "Calc.h"
#include <cassert>
#include <iostream>

void printError()
{
    std::cout << "Error!" << std::endl;
}

void Mathem::add(double value1, double value2) 
{
    m_value1 = value1;
    m_value2 = value2;
    m_result = value1 + value2;
}

void Mathem::sub(double value1, double value2) 
{
    m_value1 = value1;
    m_value2 = value2;
    m_result = value1 - value2;
}

void Mathem::divide(double value1, double value2) 
{
    m_value1 = value1;
    m_value2 = value2;
    if (value2 != 0)
    {
        m_result = value1 / value2;
    }
    else
    {
        // m_result = 0; // Защита от деления на 0
        printError();
        assert(value2!=0);
    }
}

void Mathem::multiply(double value1, double value2) // метод умножения
{
    m_value1 = value1;
    m_value2 = value2;
    m_result = value1 * value2;
}

