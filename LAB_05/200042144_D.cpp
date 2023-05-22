#include <bits/stdc++.h>

using namespace std;

int main() {
    

    string s;
    int n;
    cin >> n >> s;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
