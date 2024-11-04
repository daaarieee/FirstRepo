#include <iostream>
#include <string>
#include <vector>
#include <limits>

class Employee
{
    private:
        int m_id;
        std::string m_name;

    public:
        Employee(int id = 0, const std::string &name = "") : m_id(id), m_name(name)
        {
            std::cout << "Employee " << m_name << " created.\n";
        }

        Employee(const std::string &name) : Employee(0, name) { }

        void print() const
        {
            std::cout << "Employee ID: " << m_id << ", Name: " << m_name << std::endl;
        }
};

int main()
{
    std::cout << "How many employees do you want to create? " << std::endl;
    int number;
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Employee> employees;

    for (int i = 0; i < number; ++i)
    {
        std::cout << "Enter name: " << std::endl;
        std::string name;
        std::getline(std::cin, name);
        employees.emplace_back(i+1, name);
    }

    std::cout << "List of employees:" << std::endl;
    for (const auto& employee : employees)
    {
        employee.print();
    }

    return 0;
}