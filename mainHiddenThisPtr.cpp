#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <vector>
#include <limits>

/* hidden const nptr *this */

/* 
another.setNumber(4); 
EQUALS 
setNumber(&another, 4); // объект another конвертировался из объекта, который находился перед точкой, в аргумент функции! 

void setNumber(int number) { m_number = number; } // метод 
EQUALS
void setNumber(Another* const this, int number) { this->m_number = number; }
При компиляции обычного метода, компилятор неявно добавляет к нему параметр *this. 
Указатель *this — это скрытый константный указатель, содержащий адрес объекта, который вызывает метод класса.
Bсе обычные методы класса имеют указатель *this, который указывает на объект, связанный с вызовом метода класса.

Another X(3); // *this = &X внутри конструктора Another
Another Y(4); // *this = &Y внутри конструктора Another
X.setNumber(5); // *this = &X внутри метода setNumber
Y.setNumber(6); // *this = &Y внутри метода setNumber
*/

class Mathem
{
private:
    int m_value;
 
public:
    Mathem() { m_value = 0; }
 
    Mathem& add(int value) { m_value += value; return *this; }
    Mathem& sub(int value) { m_value -= value; return *this; }
    Mathem& multiply(int value) { m_value *= value; return *this; }
 
    int getValue() { return m_value; }
};

int main()
{
    Mathem operation;
    operation.sub(7).add(5).multiply(3);
 
    std::cout << operation.getValue() << '\n';
    return 0;
}

/* Сначала вызывается operation.add(7), который добавляет 7 к нашему m_value.
   Затем add() возвращает указатель *this, который является ссылкой на объект operation.
   Затем вызов operation.sub(5) вычитает 5 из m_value и возвращает operation.
   multiply(3) умножает m_value на 3 и возвращает operation, который уже игнорируется.
   Однако, поскольку каждая функция модифицировала operation, m_value объекта operation теперь содержит значение ((0 + 7) - 5) * 3), которое равно 6.*/