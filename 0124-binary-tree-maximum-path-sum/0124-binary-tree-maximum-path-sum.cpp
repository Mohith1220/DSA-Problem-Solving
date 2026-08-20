/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int globalMax = INT_MIN;

    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftGain = max(0, maxGain(node->left));
        int rightGain = max(0, maxGain(node->right));
        int currentPathSum = node->val + leftGain + rightGain;
        globalMax = max(globalMax, currentPathSum);

        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return globalMax;
    }
};
