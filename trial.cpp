#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
int knapsack(vector<vector<int>>& t, vector<int>& wt, vector<int>& val, int w, int n) {
    if (n == 0 || w == 0) { 
        return 0;
    } 
    if (t[n][w] != -1) {
        return t[n][w];
    }
    if (wt[n-1] <= w) {
        return t[n][w] = max(val[n-1] + knapsack(t, wt, val, w-wt[n-1], n-1), knapsack(t, wt, val, w, n-1));
    } else if (wt[n-1] > w) {
        return t[n][w] = knapsack(t, wt, val, w, n-1);
    }
}
*/

int knapsack(vector<int>& wt, vector<int>& val, int w, int n) {
    int rows = n + 1;
    int cols = w + 1;

    vector<vector<int>> t(rows, vector<int>(cols, 0));

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (wt[i-1] <= j) {
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]], t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}
