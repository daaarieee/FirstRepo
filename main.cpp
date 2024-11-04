#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> prefixMax(n-1), prefixMin(n-1), suffixMax(n-1), suffixMin(n-1);
    vector<int> prefixMaxIndex(n-1), prefixMinIndex(n-1), suffixMaxIndex(n-1), suffixMinIndex(n-1);

    // Построение префиксов (максимум и минимум)
    prefixMax[0] = arr[0];
    prefixMaxIndex[0] = 1;
    prefixMin[0] = arr[0];
    prefixMinIndex[0] = 1;

    for (int i = 1; i < n - 1; i++) 
    {
        if (arr[i] > prefixMax[i - 1]) 
        {
            prefixMax[i] = arr[i];
            prefixMaxIndex[i] = i + 1;
        } 
        else 
        {
            prefixMax[i] = prefixMax[i - 1];
            prefixMaxIndex[i] = prefixMaxIndex[i - 1];
        }

        if (arr[i] < prefixMin[i - 1]) 
        {
            prefixMin[i] = arr[i];
            prefixMinIndex[i] = i + 1;
        } 
        else 
        {
            prefixMin[i] = prefixMin[i - 1];
            prefixMinIndex[i] = prefixMinIndex[i - 1];
        }
    }

    // cout << "prefixMin" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << prefixMinIndex[i] << " " << prefixMin[i] << endl;
    // }
    // cout << "prefixMax" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << prefixMaxIndex[i] << " " << prefixMax[i] << endl;
    // }

    // Построение суффиксов (максимум и минимум)
    suffixMax[n - 2] = arr[n - 1];
    suffixMaxIndex[n - 2] = n;
    suffixMin[n - 2] = arr[n - 1];
    suffixMinIndex[n - 2] = n;

    for (int i = n - 3; i >= 0; i--)
    {
        if (arr[i + 1] > suffixMax[i + 1]) 
        {
            suffixMax[i] = arr[i + 1];
            suffixMaxIndex[i] = i + 2;
        } 
        else 
        {
            suffixMax[i] = suffixMax[i + 1];
            suffixMaxIndex[i] = suffixMaxIndex[i + 1];
        }

        if (arr[i + 1] < suffixMin[i + 1]) 
        {
            suffixMin[i] = arr[i + 1];
            suffixMinIndex[i] = i + 2;
        } 
        else 
        {
            suffixMin[i] = suffixMin[i + 1];
            suffixMinIndex[i] = suffixMinIndex[i + 1];
        }
    }

    // cout << "suffixMin:" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << suffixMinIndex[i] << " " << suffixMin[i] << endl;
    // }
    // cout << "suffixMax:" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << suffixMaxIndex[i] << " " << suffixMax[i] << endl;
    // }

    int i1 = 0, j1 = 0;  
    int i2 = 0, j2 = 0;  

    int maxDiff = numeric_limits<int>::min();
    int minDiff = numeric_limits<int>::max();

    for (int i = 0; i < n - 1; i++)
    {
        // Разница между суффиксным минимумом и префиксным максимумом
        int currentMinDiff = prefixMin[i] - suffixMax[i];

        // Разница между суффиксным максимумом и префиксным минимумом
        int currentMaxDiff = prefixMax[i] - suffixMin[i];

        if (currentMinDiff < minDiff) 
        {
            minDiff = currentMinDiff;
            i1 = prefixMinIndex[i];  // Префиксный максимум
            j1 = suffixMaxIndex[i];  // Суффиксный минимум
        }

        // Обновляем максимальную разницу
        if (currentMaxDiff > maxDiff) 
        {
            maxDiff = currentMaxDiff;
            i2 = prefixMaxIndex[i];  // Префиксный минимум
            j2 = suffixMinIndex[i];  // Суффиксный максимум
        }
    }

    // Вывод результата
    cout << i1 << " " << j1 << endl;
    cout << i2 << " " << j2 << endl;

    return 0;
}
