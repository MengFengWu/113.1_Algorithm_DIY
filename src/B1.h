#ifndef B1_H
#define B1_H
#include <iostream>
#include <algorithm>

void Problem_B1_Bottom_Up(int n) {
    int round = 1;
    int groupSize = 1;
    while(groupSize <= n) {
        int firstMan = 1;
        while(firstMan + groupSize <= n) {
            if(firstMan + 2 * groupSize - 1 > n) {
                std::cout << round << " " << firstMan + groupSize - 1 << " " << n << std::endl;
            }
            else {
                std::cout << round << " " << firstMan + groupSize - 1 << " " << firstMan + 2 * groupSize - 1 << std::endl;
            }
            firstMan += 2 * groupSize;
        }
        groupSize *= 2;
        round++;
    }
}

int Problem_B1_DC(int L, int R) {
    if(R == L + 1) {
        std::cout << 1 << " " << L << " " << R << std::endl;
        return 1;
    }
    else if(R == L) return 0;

    int mid = (L + R) / 2;
    int round = std::max(Problem_B1_DC(L, mid), Problem_B1_DC(mid + 1, R));
    std::cout << round + 1 << " " << mid << " " << R << std::endl;
    return round + 1;
}

#endif // B1_H