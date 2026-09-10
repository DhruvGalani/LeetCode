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
public:
    int result = 0;

    pair<int, int> traverse(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }

        auto [leftSum, leftCount] = traverse(node->left);
        auto [rightSum, rightCount] = traverse(node->right);

        int currSum = node->val + leftSum + rightSum;
        int currCount = 1 + leftCount + rightCount;

        if (currSum / currCount == node->val) {
            result++;
        }

        return {currSum, currCount};
    }

    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return result;
        
    }
};