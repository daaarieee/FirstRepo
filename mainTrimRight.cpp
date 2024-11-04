#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstring>


void trimRight (char *longStr)
{
    char *rightSym;

    std::size_t len = strlen(longStr);
    if (len == 0)
        std::cout << "String's length is 0 " << std::endl;
    else
        rightSym = longStr + len - 1;

    while (rightSym >= longStr && *rightSym == ' ')
    {
        --rightSym;
    }

    rightSym = rightSym+1;
    *rightSym = '\0';
}

int main ()
{
    char strTest[] = "dcsfxgvhbjn sderfftghj sedrfftgyhuji dsfecfsrtgyhujikolpjkhjgfc frt frrf  gverbh fdsgtyhj ";
//    char strTest[] = "dcsfxgvhbjn sderfftghj sedrfftgyhuji dsfecfsrtgyhujikolpjkhjgfc frt frrf  gverbh fdsgtyhj";
//    char strTest[] = "";
    std::cout << "Before trimming: \"" << strTest << "\"" << std::endl;
    trimRight(strTest);
    std::cout << "After trimming: \"" << strTest << "\"" << std::endl;
    return 0;

}
