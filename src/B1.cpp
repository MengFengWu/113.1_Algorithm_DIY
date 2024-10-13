#include <iostream>
#include "B1.h"
using namespace std;

int main() {
    int n;
    cin >> n;
#ifdef BU
    Problem_B1_Bottom_Up(n);
#elif defined DC
    Problem_B1_DC(1, n);
#endif
    return 0;
}

/*
5
*/