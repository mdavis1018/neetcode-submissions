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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        std::vector<int> tReturn{};
        std::stack<TreeNode*> tStack;
        TreeNode *tCurr = root;

        while (tCurr || tStack.empty() == false)
        {
            while (tCurr != nullptr)
            {
                tStack.push(tCurr);
                tCurr = tCurr->left;
            }
            
            // we are now furtherst left 
            tCurr = tStack.top();
            tStack.pop();

            // do work
            tReturn.push_back(tCurr->val);

            // get right
            tCurr = tCurr->right;
        }

        return tReturn;
    }
};