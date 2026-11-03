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
    int kthSmallest(TreeNode* root, int k) 
    {
        std::vector<int> tInorderVector;
        inOrder(root, tInorderVector);
        return tInorderVector[k - 1];
    }

    void inOrder(TreeNode *aRoot, std::vector<int> &aVector)
    {
        if (aRoot == nullptr)
        {
            return;
        }

        inOrder(aRoot->left, aVector);
        aVector.push_back(aRoot->val);
        inOrder(aRoot->right, aVector);
    }
};
