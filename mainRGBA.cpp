#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdint>


class RGBA
{
    private:
        std::uint8_t m_red, m_green, m_blue, m_alpha;

    public:

        RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 0) :
                            m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
        {
        }

        void print()
        {
            std::cout << "r = " << static_cast<int>(m_red) << " " 
                      << "g = " << static_cast<int>(m_green) << " "
                      << "b = " << static_cast<int>(m_blue) << " "
                      << "a = " << static_cast<int>(m_alpha) << std::endl;        
        }
};

int main ()
{
    // RGBA col(0, 0, 0);
    int r, g, b, a;
    std::cout << "type r, g, b, a nominals" << "\n";
    std::cin >> r >> g >> b >> a;
    RGBA col(static_cast<std::uint8_t>(r),
             static_cast<std::uint8_t>(g),
             static_cast<std::uint8_t>(b),
             static_cast<std::uint8_t>(a));
    col.print();
    return 0;
}
