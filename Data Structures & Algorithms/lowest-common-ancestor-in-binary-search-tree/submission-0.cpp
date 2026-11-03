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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode*> ppath;
        vector<TreeNode*> qpath;

        TreeNode* temp1 = root;
        while(temp1->val != p->val)
        {
            ppath.insert(temp1);
            if (temp1->val > p->val)
                temp1 = temp1->left;
            else
                temp1 = temp1->right;
        }
        ppath.insert(p);

        TreeNode* temp2 = root;
        while(temp2->val != q->val)
        {
            qpath.push_back(temp2);
            if (temp2->val > q->val)
                temp2 = temp2->left;
            else
                temp2 = temp2->right;
        }
        qpath.push_back(temp2);

        int b = qpath.size()-1;

        while (b >= 0)
        {
            if (ppath.find(qpath[b]) != ppath.end())
            {
                return qpath[b];
            }
             b--;
        }

    }
};
