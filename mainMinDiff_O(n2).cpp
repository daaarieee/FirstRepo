#include <iostream>
#include <vector>
#include <limits>

int main() 
{
    int n;
    std::cin >> n;
   
    std::vector<int> numericVector(n); 
    for (int cnt = 0; cnt < n; cnt++) 
    {
        std::cin >> numericVector[cnt];
    }
    
    int i1, j1, i2, j2 ;

    int minDiff = std::numeric_limits<int>::max();
    int maxDiff = std::numeric_limits<int>::min();
    
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            int diff = numericVector[i] - numericVector[j];  

            if (diff < minDiff) 
            {
                minDiff = diff;
                i1 = i;  
                j1 = j;  
            }

         
            if (diff > maxDiff) 
            {
                maxDiff = diff;
                i2 = i;  
                j2 = j;  
            }

        }
    }

    std::cout << i1+1 << " " << j1+1 << std::endl;  // Индексы для минимальной разницы
    std::cout << i2+1 << " " << j2+1 << std::endl;  // Индексы для максимальной разницы

    return 0;
}
