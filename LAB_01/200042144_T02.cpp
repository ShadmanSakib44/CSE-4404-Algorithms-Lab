#include <iostream>
#include <map>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    int adj[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    map<int, bool> visited;
    stack<int> stack;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && adj[i][j] == 1) {
                    stack.push(j);
                    visited[j] = true;
                }
            }
        }

        n -= stack.size();
    }

    cout << n << endl;

    return 0;
}
