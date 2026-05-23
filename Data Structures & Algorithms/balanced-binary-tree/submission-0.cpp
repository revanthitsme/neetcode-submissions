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
    bool isBalancedInt(TreeNode* root, int *height)
    {
        if (!root)
        {
            *height = 0;
            return true;
        }
        int left = 0;
        int right = 0;

        bool isleft =  isBalancedInt(root->left, &left);
        bool isright = isBalancedInt(root->right, &right);
        int hdif = isleft - isright;
        if (isBalancedInt(root->left, &left) && 
            isBalancedInt(root->right, &right) && 
            (left - right == -1 || 
              left - right == 0 || 
              left - right == 1))
        {
            *height = 1 + max(left, right);
            return true;
        }
        else
        {
            return false;
        }

    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalancedInt(root, &height);
    }
};
