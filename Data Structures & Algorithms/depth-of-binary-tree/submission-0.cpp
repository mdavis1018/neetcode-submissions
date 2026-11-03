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
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return 0;
        }     

        int tLeft = 1 + maxDepth(root->left);
        int tRight = 1 + maxDepth(root->right);

        if (tLeft > tRight)
        {
            return tLeft;
        }
        else 
        {
            return tRight;
        }
    }
};
