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
#include <utility>

class Solution {
private:
    int matchingNodesCount = 0;

    std::pair<int, int> calculateSubtreeStats(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }

        auto [leftSum, leftCount] = calculateSubtreeStats(node->left);
        auto [rightSum, rightCount] = calculateSubtreeStats(node->right);

        int currentSum = node->val + leftSum + rightSum;
        int currentCount = 1 + leftCount + rightCount;

        if (currentSum / currentCount == node->val) {
            matchingNodesCount++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodesCount = 0;
        calculateSubtreeStats(root);
        return matchingNodesCount;
    }
};
