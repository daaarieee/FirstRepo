#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <vector>
#include <limits>

/*destructors*/

class Another
{
private:
    int m_nID;
 
public:
    Another(int nID)
    {
        std::cout << "Constructing Another " << nID << '\n';
        m_nID = nID;
    }
 
    ~Another()
    {
        std::cout << "Destructing Another " << m_nID << '\n';
    }
 
    int getID() { return m_nID; }
};
 
int main()
{
    // Выделяем объект класса Another из стека
    Another object(1);
    std::cout << object.getID() << '\n';
 
    // Выделяем объект класса Another динамически из кучи
    Another *pObject = new Another(2);
    std::cout << pObject->getID() << '\n';
    delete pObject;
 
    return 0;
} // объект object выходит из области видимости здесь