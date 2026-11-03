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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr && q != nullptr)
        {
            return false;
        }
        if (q == nullptr && p != nullptr)
        {
            return false;
        }

        bool tRight = isSameTree(p->right, q->right);
        bool tLeft = isSameTree(p->left, q->left);

        return (q->val == p->val) && tRight && tLeft;
    }
};
