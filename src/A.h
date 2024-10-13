#ifndef A_H
#define A_H
#include <algorithm>

int Problem_A_Greedy(int n, int *a) {
    int minValue = a[n - 1];
    int totalTime = 0;
    for(int i = n - 2; i >= 0; i--) {
        totalTime = totalTime + std::max(a[i], minValue);
        minValue = std::min(a[i], minValue);
    }
    return totalTime;
}

#endif // A_H