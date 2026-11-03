class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int tMaxSum = nums[0];
        int tCurrSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            // If the sum of the tCurrSum with nums[i] is negative discard
            if (tCurrSum < 0)
            {
                tCurrSum = 0;
            }
            
            tCurrSum += nums[i];
            tMaxSum = std::max(tCurrSum, tMaxSum);
        }

        return tMaxSum;
    }
};
