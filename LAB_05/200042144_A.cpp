#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 55;
const int MAX_W = 255;

int n;
int coin[MAX_N];
long long dp[MAX_N][MAX_W];

long long calculateWays(int i, int w) {
    if (w == 0) return 1;
    if (i == n || w < 0) return 0;
    if (dp[i][w] != -1) return dp[i][w];

    dp[i][w] = calculateWays(i + 1, w) + calculateWays(i, w - coin[i]);

    return dp[i][w];
}

int main() {
    memset(dp, -1, sizeof(dp));
    int w;
    cin >> w >> n;

    for (int i = 0; i < n; i++)
        cin >> coin[i];

    cout << calculateWays(0, w) << endl;
}
