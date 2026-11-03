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
    vector<int> rightSideView(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return std::vector<int>{};
        }

        std::queue<TreeNode*> tQueue;
        tQueue.push(root);
        std::vector<int> tReturn;
        TreeNode* tCurrent = root;

        while (tQueue.empty() == false)
        {
            int tSize = tQueue.size();
            std::vector<int> tLevel{};

            for (int i = 0; i < tSize; ++i)
            {
                tCurrent = tQueue.front();
                tQueue.pop();
                tLevel.push_back(tCurrent->val);

                if (tCurrent->left)
                {
                    tQueue.push(tCurrent->left);
                }
                if (tCurrent->right)
                {
                    tQueue.push(tCurrent->right);
                }
            }

            tReturn.push_back(tLevel.back());
        }

        return tReturn;
    }
};
