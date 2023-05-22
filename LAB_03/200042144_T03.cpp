class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> result;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> currentLevel;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                Node* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);

                for (Node* child : node->children) {
                    if (child != nullptr) {
                        q.push(child);
                    }
                }
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};
