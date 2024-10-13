#ifndef B2_H
#define B2_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int Problem_B2_DC(vector<pair<int, int> >& data, int n, int print, int round) {
    if(data.size() == 2) {
        if(print > 0) {
            cout << data[0].first << " " << data[1].first << " ";
        }
        return max(data[0].second, data[1].second);
    }

    vector<pair<int, int> > sol1(n/2), sol2(n/2);
    vector<pair<int, int> > group1(0), group2(0);
    vector<int> ind(n/2, 0);
    int best_time = INT16_MAX;
    int temp = INT16_MAX;
    for(int i = 0; i < n/2; i++) {
        ind[i] = i;
    }
    int furthestInd = n/2 - 1;
    while(ind[0] != n/2 - 1) {
        int k = 0;
        for(int i = 0; i < n; i++) {
            if(k < n/2 && ind[k] == i) {
                group1.push_back(data[i]);
                k++;
            }
            else group2.push_back(data[i]);
        }

        temp = Problem_B2_DC(group1, n/2, 0, round - 1) + Problem_B2_DC(group2, n/2, 0, round - 1) + max(group1[n/2 - 1].second, group2[n/2 - 1].second);
        if(temp < best_time) {
            best_time = temp;
            copy(group1.begin(), group1.end(), sol1.begin());
            copy(group2.begin(), group2.end(), sol2.begin());
        }

        int i = furthestInd;
        while(i >= 0) {
            if(ind[i] == n - 2 + i - furthestInd){
                i--;
            }
            else break;
        }
        ind[i]++;
        for(int j = i + 1; j <= furthestInd; j++) {
            ind[j] = ind[i] + j - i;
        }
        group1.clear();
        group2.clear();
    }

    if(print > 0) {
        if(print == 2) {
            cout << best_time << endl;
        }
        Problem_B2_DC(sol1, n/2, 1, round - 1);
        Problem_B2_DC(sol2, n/2, 1, round - 1);
        if(print == 2) {
            cout << endl;
        }
    }
    return best_time;
}

int Problem_B2_DP(vector<pair<int, int> >& data, int memo[2][2][2][2][2][2][2][2], vector<vector<int> > method[2][2][2][2][2][2][2][2], vector<int> query, int n) {
    int q[8] = {};
    // cout << "Function: ";
    for(int i = 0; i < query.size(); i++) {
        // cout << query[i] << " ";
        q[query[i]] = 1;
    }
    // cout << endl;
    
    if(memo[q[0]][q[1]][q[2]][q[3]][q[4]][q[5]][q[6]][q[7]] > 0) {
        return memo[q[0]][q[1]][q[2]][q[3]][q[4]][q[5]][q[6]][q[7]];
    }
    
    if(n == 2) {
        memo[q[0]][q[1]][q[2]][q[3]][q[4]][q[5]][q[6]][q[7]] = max(data[query[0]].second, data[query[1]].second);
        return memo[q[0]][q[1]][q[2]][q[3]][q[4]][q[5]][q[6]][q[7]];
    }
    else {
        vector<int> group1, group2;
        vector<int> ind(n/2, 0);
        for(int i = 0; i < n/2; i++) {
            ind[i] = i;
        }
        int furthestInd = n/2 - 1;
        int best_time = INT16_MAX;
        int temp = INT16_MAX;
        while(ind[0] != 1) {
            int k = 0;
            for(int i = 0; i < n; i++) {
                if(ind[k] == i) {
                    group1.push_back(data[query[i]].first - 1);
                    k++;
                }
                else group2.push_back(data[query[i]].first - 1);
            }

            // for(int i = 0; i < n/2; i++) {
            //     cout << ind[i] << " ";
            // }
            // cout << endl;

            temp = Problem_B2_DP(data, memo, method, group1, n/2) + Problem_B2_DP(data, memo, method, group2, n/2) + max(data[group1[n/2 - 1]].second, data[group2[n/2 - 1]].second);
            if(temp < best_time) {
                best_time = temp;
                method[q[0]][q[1]][q[2]][q[3]][q[4]][q[5]][q[6]][q[7]].clear();
                method[q[0]][q[1]][q[2]][q[3]][q[4]][q[5]][q[6]][q[7]].push_back(group1);
                method[q[0]][q[1]][q[2]][q[3]][q[4]][q[5]][q[6]][q[7]].push_back(group2);
            }

            int i = furthestInd;
            while(i >= 0) {
                if(ind[i] > n - 2 + i - furthestInd){
                    i--;
                }
                else break;
            }
            ind[i]++;
            for(int j = i + 1; j <= furthestInd; j++) {
                ind[j] = ind[i] + j - i;
            }
            group1.clear();
            group2.clear();
        }
        memo[q[0]][q[1]][q[2]][q[3]][q[4]][q[5]][q[6]][q[7]] = best_time;
        return best_time;
    }
}

void Problem_B2_DP_Print(vector<vector<int> > method[2][2][2][2][2][2][2][2], vector<int> query, int n) {
    int q[8] = {};
    for(int i = 0; i < query.size(); i++) {
        q[query[i]] = 1;
    }
    
    if(n == 2) {
        cout << query[0] + 1 << " " << query[1] + 1 << " ";
        return;
    }

    Problem_B2_DP_Print(method, method[q[0]][q[1]][q[2]][q[3]][q[4]][q[5]][q[6]][q[7]][0], n/2);
    Problem_B2_DP_Print(method, method[q[0]][q[1]][q[2]][q[3]][q[4]][q[5]][q[6]][q[7]][1], n/2);
}

#endif // B2_H