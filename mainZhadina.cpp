#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

/*бронь переговорки*/

struct Times {int start, endd;};

bool compareRightTime (const Times &a, const Times &b) {
    return a.endd < b.endd;
}

int main()
{
    int n, i, j;
    std::cin >> n;
    assert(n<=100&&n>=1);
    std::vector<Times> times(n);
    for (i = 0; i < n; ++i)
    {
        std::cin >> times[i].start >> times[i].endd;
    }
//    std::cout << n << "\n";
//    for (j = 0; j < n; ++j)
//    {
//        std::cout << times[j][0] << " " << times[j][1] << "\n";
//    }
    std::sort(times.begin(), times.end(), compareRightTime);

    int numOfTimes = 0;
    int lastChampEnd = 0;

    for (const Times &time : times) {
        if (time.start > lastChampEnd) {
            lastChampEnd = time.endd;
            ++numOfTimes;
            }
        }

    std::cout << numOfTimes << std::endl;
    return 0;
}
