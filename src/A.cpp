#include <iostream>
#include "A.h"
using namespace std;

int main() {
    int n, ans;
    int *a;
    cin >> n;
    a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ans = Problem_A_Greedy(n, a);
    cout << ans << endl;
    delete a;
    return 0;
}

/*
5
5 2 2 1 1
*/