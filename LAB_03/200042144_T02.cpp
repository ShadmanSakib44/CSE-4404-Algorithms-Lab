class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        TreeNode* currentNode = root;

        queue<pair<TreeNode*, bool>> q;
        q.push({currentNode, false});

        int sum = 0;
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            bool isLeftChild = q.front().second;
            q.pop();

            if (isLeftChild && node->left == nullptr && node->right == nullptr) {
                sum += node->val;
            }

            if (node->left != nullptr) {
                q.push({node->left, true});
            }

            if (node->right != nullptr) {
                q.push({node->right, false});
            }
        }

        return sum;
    }
};
