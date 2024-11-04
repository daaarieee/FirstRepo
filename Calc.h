// #ifndef CALC_H
// #define CALC_H
#pragma once

class Mathem
{
private:
    double m_value1 = 0;
    double m_value2 = 0;
    double m_result = 0;
 
public:
    Mathem() = default;  // Конструктор по умолчанию

    // Методы для операций
    void add(double value1, double value2);
    void sub(double value1, double value2);
    void divide(double value1, double value2);
    void multiply(double value1, double value2);

    // Получить результат
    double getResult() const { return m_result; }
};

// #endif