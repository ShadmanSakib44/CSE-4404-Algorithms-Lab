#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string fruit1, fruit2;
    while (cin >> fruit1 >> fruit2) {
        int m = fruit1.length(), n = fruit2.length();
        int lcs[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    lcs[i][j] = 0;
                } else if (fruit1[i - 1] == fruit2[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
        
        int index = lcs[m][n];
        string common = "";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (fruit1[i - 1] == fruit2[j - 1]) {
                common = fruit1[i - 1] + common;
                i--;
                j--;
                index--;
            } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        
        cout << common + fruit2.substr(index) << endl;
    }
    return 0;
}
