#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;

void DFS(unordered_map<int, vector<int>>& adj, unordered_set<int>& visited, int node) {
    visited.insert(node);
    for (int neighbor : adj[node]) {
        if (visited.count(neighbor) == 0) {
            DFS(adj, visited, neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adj;
    unordered_set<int> allNodes;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        allNodes.insert(a);
        allNodes.insert(b);
    }

    int t;
    cin >> t;

    vector<int> start(t);
    for (int i = 0; i < t; i++) {
        cin >> start[i];
    }

    for (int j = 0; j < t; j++) {
        unordered_set<int> visited;

        DFS(adj, visited, start[j]);

        int count = allNodes.size() - visited.size();
        cout << count << " ";

        for (int node : allNodes) {
            if (visited.count(node) == 0) {
                cout << node << " ";
            }
        }

        cout << endl;
    }
}
