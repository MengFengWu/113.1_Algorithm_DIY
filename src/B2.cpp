#include <iostream>
#include "B2.h"
using namespace std;

int main() {
    int a;
    vector<pair<int, int> > data(0);
    for(int i = 0; i < 8; i++) {
        cin >> a;
        data.push_back(make_pair(i + 1, a));
    }
#ifdef DC
    Problem_B2_DC(data, 8, 2, 3);
#elif defined DP
    int memo[2][2][2][2][2][2][2][2] = {};
    vector<vector<int> > method[2][2][2][2][2][2][2][2];
    vector<int> query;
    for(int i = 0; i < 8; i++) query.push_back(i);
    int ans = Problem_B2_DP(data, memo, method, query, 8);
    cout << ans << endl;
    Problem_B2_DP_Print(method, query, 8);
#endif
    return 0;
}

/*
2 2 2 2 1 1 1 1
1 2 1 2 1 2 1 2
2 2 1 1
*/