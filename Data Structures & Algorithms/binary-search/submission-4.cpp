class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int tLeft = 0;
        int tRight = nums.size() - 1;

        while (tLeft <= tRight)
        {
            int tMid = tLeft + (tRight - tLeft) / 2;

            if (nums[tMid] == target)
            {
                return tMid;
            }
            else if (nums[tMid] > target)
            {
                tRight = tMid - 1;
            }
            else 
            {
                tLeft = tMid + 1;
            }
        }

        return -1;
    }
};
