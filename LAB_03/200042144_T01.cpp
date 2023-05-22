class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjacencyList;
        vector<int> result;
        vector<int> incomingEdges(numCourses, 0);

        for (const auto& prerequisite : prerequisites) {
            adjacencyList[prerequisite[1]].push_back(prerequisite[0]);
            incomingEdges[prerequisite[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (incomingEdges[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);

            if (adjacencyList.count(course) > 0) {
                for (int neighbor : adjacencyList[course]) {
                    incomingEdges[neighbor]--;
                    if (incomingEdges[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }

        if (result.size() == numCourses) {
            return result;
        }

        return {};
    }
};
