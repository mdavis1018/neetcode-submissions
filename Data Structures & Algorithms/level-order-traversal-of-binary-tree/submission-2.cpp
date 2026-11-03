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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> tReturn{};
        if (root == nullptr)
        {
            return tReturn;
        }
        std::queue<TreeNode*> tQueue; 
        tQueue.push(root);
        int tCounter = 0;

        while (tQueue.empty() == false)
        {
            int tSize = tQueue.size();
            for (int i = 0; i < tSize; ++i)
            {
                TreeNode* tNode = tQueue.front();
                tQueue.pop();
                if (tCounter == tReturn.size())
                {
                    tReturn.emplace_back();
                }
                tReturn[tCounter].push_back(tNode->val);
                
                if (tNode->left)
                {
                    tQueue.push(tNode->left);
                }

                if (tNode->right)
                {
                    tQueue.push(tNode->right);
                }
            }

            ++tCounter;
        }

        return tReturn;
    }
};
