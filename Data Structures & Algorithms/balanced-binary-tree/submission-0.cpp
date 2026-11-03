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
    bool isBalanced(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return true;
        }

        int tLeft = height(root->left);
        int tRight = height(root->right);

        if (std::abs(tLeft - tRight) > 1)
        {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

    
    int height(TreeNode *aNode)
    {
        // To find the height of a node in a binary
        // tree, one must get the max of it's left and right 
        // subtrees
        if (aNode == nullptr)    
        {
            return 0;
        }

        int tRight = 1 + height(aNode->right);
        int tLeft = 1 + height(aNode->left);

        return std::max(tRight, tLeft);
    }   
};
