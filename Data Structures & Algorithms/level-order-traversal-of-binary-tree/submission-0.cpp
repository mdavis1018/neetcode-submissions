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
        // we know that we are going to need a queue
        // add pop from the queue the value and push back
        // add left and right to the queue

        if (root == nullptr)
        {
            return std::vector<std::vector<int>>{};
        }

        std::queue<TreeNode*> tQueue;
        vector<vector<int>> tReturn;
        TreeNode* tCurrent = root;
        int tLevel = 0;
        tQueue.push(tCurrent);

        while (tQueue.empty() == false)
        {
            std::size_t tSize = tQueue.size();
            tReturn.push_back({});
            for (int i = 0; i < tSize; ++i)
            {
                tCurrent = tQueue.front();
                tReturn[tLevel].push_back(tCurrent->val);
                tQueue.pop();

                if (tCurrent->left)
                {
                    tQueue.push(tCurrent->left);
                }
                if (tCurrent->right)
                {
                    tQueue.push(tCurrent->right);
                }
            }

            ++tLevel;
        }

        return tReturn;
    }
};
