#include <iostream>
#include <cassert>
#include <cstdlib>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
 
public:
    // Конструктор по умолчанию
    Fraction(int numerator=0, int denominator=1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }
 
    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

class Ball 
{
    private:
        std::string m_color;
        double m_radius;
    
    public:
    Ball (double radius) //radius settings
    {
        assert(radius != 0);
        m_color = "Red";
        m_radius = radius;
    }

    Ball (const std::string &color="Red", double radius=20.0) //default
    {
        assert(radius != 0);
        m_color = color;
        m_radius = radius;
    }
    
    int getRadius ()
    {
        return m_radius;
    }

    std::string getColor ()
    {
        return m_color;
    }

    void printInfo () 
    {
        std::cout << "color is " << m_color << " and the radius is " << m_radius << std::endl;
    }
};

int main()
{
    Ball def;
    def.printInfo ();

    // Ball zeroRad {0};
    // zeroRad.printInfo ();

    Ball Red {"Red"};
    Red.printInfo ();

    Ball radius20 {20.0};
    radius20.printInfo ();

    Ball kakashka {"blue kakashka", 228.3};
    kakashka.printInfo ();


    return 0;
}