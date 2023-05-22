#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
int n, a[N], f[N][N];

int main() {
    while(cin >> n) {
        memset(f, 0x3f, sizeof f);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            f[i][i] = 0;

        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                for(int k = i; k < j; k++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
                }
            }
        }

        cout << f[0][n - 1] << endl;
    }
    return 0;
}
