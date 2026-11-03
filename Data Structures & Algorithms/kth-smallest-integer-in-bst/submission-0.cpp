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
    int kthSmallest(TreeNode* root, int &k) 
    {
        if (root == nullptr)
        {
            return -1;
        }    

        // we have to do an inorder traversal
        int tResult = kthSmallest(root->left, k);
        if (tResult != -1)
        {
            return tResult;
        }
        --k;
        if (k == 0)
        {
            return root->val;
        }
        return kthSmallest(root->right, k);
    }
};
