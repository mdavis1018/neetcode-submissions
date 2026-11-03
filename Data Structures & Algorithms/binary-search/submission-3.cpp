class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int tReturn = -1;
        int tLeft = 0;
        int tRight = nums.size() - 1;

        while (tLeft <= tRight)
        {
            int tMid = tLeft + (tRight - tLeft) / 2;

            if (nums.at(tMid) == target)
            {
                tReturn = tMid;
                break;
            }
            else if (nums.at(tMid) > target) 
            {
                tRight = tMid - 1;
                tMid = tLeft + (tRight - tLeft) / 2;
            }
            else 
            {
                tLeft = tMid + 1;
                tMid = tLeft + (tRight - tLeft) / 2;
            }
        }

        return tReturn;
    }
};
