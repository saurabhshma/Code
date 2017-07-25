//https://www.hackerrank.com/challenges/coin-change
#include <bits/stdc++.h>

using namespace std;

long table[251][51];

long getWays(int n, int m, vector < long > c){
    // Complete this function
    if(n < 0 || (m > c.size() - 1))
        return 0;
    if(table[n][m] == -1)
    {
        if(n == 0 && m < c.size())
            return 1;
        else
            table[n][m] = getWays(n - c[m], m, c) + getWays(n, m + 1, c);
    }
    return table[n][m];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            table[i][j] = -1;
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, 0, c);
    cout << ways << "\n";
    return 0;
}
