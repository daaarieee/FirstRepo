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

    vector<int> prefixMax(n), prefixMin(n), suffixMax(n), suffixMin(n);
    vector<int> prefixMaxIndex(n), prefixMinIndex(n), suffixMaxIndex(n), suffixMinIndex(n);

    // Построение префиксов (максимум и минимум)
    prefixMax[0] = arr[0];
    prefixMaxIndex[0] = 0;
    prefixMin[0] = arr[0];
    prefixMinIndex[0] = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > prefixMax[i - 1]) {
            prefixMax[i] = arr[i];
            prefixMaxIndex[i] = i;
        } else {
            prefixMax[i] = prefixMax[i - 1];
            prefixMaxIndex[i] = prefixMaxIndex[i - 1];
        }

        if (arr[i] < prefixMin[i - 1]) {
            prefixMin[i] = arr[i];
            prefixMinIndex[i] = i;
        } else {
            prefixMin[i] = prefixMin[i - 1];
            prefixMinIndex[i] = prefixMinIndex[i - 1];
        }
    }

    // Построение суффиксов (максимум и минимум)
    suffixMax[n - 1] = arr[n - 1];
    suffixMaxIndex[n - 1] = n - 1;
    suffixMin[n - 1] = arr[n - 1];
    suffixMinIndex[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] > suffixMax[i + 1]) {
            suffixMax[i] = arr[i];
            suffixMaxIndex[i] = i;
        } else {
            suffixMax[i] = suffixMax[i + 1];
            suffixMaxIndex[i] = suffixMaxIndex[i + 1];
        }

        if (arr[i] < suffixMin[i + 1]) {
            suffixMin[i] = arr[i];
            suffixMinIndex[i] = i;
        } else {
            suffixMin[i] = suffixMin[i + 1];
            suffixMinIndex[i] = suffixMinIndex[i + 1];
        }
    }

    // Переменные для хранения индексов минимальной и максимальной разницы
    int i1 = -1, j1 = -1;  // Для минимальной разницы
    int i2 = -1, j2 = -1;  // Для максимальной разницы

    int maxDiff = numeric_limits<int>::min();
    int minDiff = numeric_limits<int>::max();

    // Поиск минимальной и максимальной разницы
    for (int i = 0; i < n - 1; ++i) {
        // Разница между суффиксным минимумом и префиксным максимумом
        int currentMinDiff = suffixMin[i + 1] - prefixMax[i];

        // Разница между суффиксным максимумом и префиксным минимумом
        int currentMaxDiff = suffixMax[i + 1] - prefixMin[i];

        // Обновляем минимальную разницу
        if (currentMinDiff < minDiff) {
            minDiff = currentMinDiff;
            i1 = prefixMaxIndex[i] + 1;  // Префиксный максимум
            j1 = suffixMinIndex[i + 1] + 1;  // Суффиксный минимум
        }

        // Обновляем максимальную разницу
        if (currentMaxDiff > maxDiff) {
            maxDiff = currentMaxDiff;
            i2 = prefixMinIndex[i] + 1;  // Префиксный минимум
            j2 = suffixMaxIndex[i + 1] + 1;  // Суффиксный максимум
        }
    }

    // Вывод результата
    cout << i1 << " " << j1 << endl;
    cout << i2 << " " << j2 << endl;

    return 0;
}
