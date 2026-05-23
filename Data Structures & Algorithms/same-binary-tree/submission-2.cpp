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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;

        stack<TreeNode*> ps;
        stack<TreeNode*> qs;

        ps.push(p);
        qs.push(q);
        while (!ps.empty() && !qs.empty())
        {
            TreeNode* tempp = ps.top();
            TreeNode* tempq = qs.top();

            if (tempp->val != tempq-> val)
                return false;
            
            ps.pop();
            qs.pop();

            if ((!tempp->left || !tempq->left) && tempp->left != tempq->left)
                return false;
            if ((!tempp->right || !tempq->right) && tempp->right != tempq->right)
                return false;

            if (tempp->left) ps.push(tempp->left);
            if (tempp->right) ps.push(tempp->right);

            if (tempq->left) qs.push(tempq->left);
            if (tempq->right) qs.push(tempq->right);
        }
        return true;
    }
};
