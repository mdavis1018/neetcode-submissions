class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int tLeft = 0;
        int tRight = matrix.size() - 1;

        std::vector<int> tSearchVector{};
        while (tLeft <= tRight)
        {
            int tMid = tLeft + (tRight - tLeft) / 2;
            
            if (matrix[tMid][0] <= target && matrix[tMid][matrix[tMid].size() - 1] >= target)
            {
                tSearchVector = matrix[tMid];
                break;
            }
            else if (matrix[tMid][0] > target)
            {
                tRight = tMid - 1;
            }
            else 
            {
                tLeft = tMid + 1;
            }
        }    

        if (tSearchVector.empty())
        {
            return false;
        }

        tLeft = 0;
        tRight = tSearchVector.size() - 1;

        while (tLeft <= tRight)
        {
            int tMid = tLeft + (tRight - tLeft) / 2;

            if (tSearchVector[tMid] == target)
            {
                return true;
            }
            else if (tSearchVector[tMid] > target)
            {
                tRight = tMid - 1;
            }
            else 
            {
                tLeft = tMid + 1;
            }
        }

        return false;
    }


};
