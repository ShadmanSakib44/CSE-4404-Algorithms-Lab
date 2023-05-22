#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<limits>
using namespace std;
typedef pair<int, int> pii;

struct Compare {
    bool operator()(const pii& a, const pii& b) const {
        return a.second > b.second;
    }
};

void Dijkstra(map<int, vector<pii>>& adj, priority_queue<pii, vector<pii>, Compare>& pq,
              set<int>& visited, int source, int dist[]) {

    if (!visited.count(source)) {
        visited.insert(source);

        for (const pii& neighbor : adj[source]) {
            int node = neighbor.first;
            int weight = neighbor.second + pq.top().second;

            pq.push(make_pair(node, weight));

            if (!pq.empty()) {
                dist[node - 1] = min(dist[node - 1], weight);
            }
        }
    }

    pq.pop();
    if (!pq.empty()) {
        Dijkstra(adj, pq, visited, pq.top().first, dist);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    map<int, vector<pii>> adj;

    int node = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            if (j != 0) {
                adj[node].push_back(make_pair(node - 1, arr[i][j - 1]));
            }

            
            if (j != m - 1) {
                adj[node].push_back(make_pair(node + 1, arr[i][j + 1]));
            }

            
            if (i != 0) {
                adj[node].push_back(make_pair(node - m, arr[i - 1][j]));
            }

            
            if (i != n - 1) {
                adj[node].push_back(make_pair(node + m, arr[i + 1][j]));
            }

            node++;
        }
    }

    node--;
    
    int source = 1;
    int finish = n * m;

    int dist[n * m];

    for (int i = 0; i < n * m; i++) {
        dist[i] = numeric_limits<int>::max();
    }

    dist[source - 1] = 0;

    priority_queue<pii, vector<pii>, Compare> pq;
    pq.push(make_pair(1, 0));
    set<int> visited;

    Dijkstra(adj, pq, visited, source, dist);

    cout << dist[finish - 1] << endl;
}
