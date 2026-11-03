class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int tCurrSum = 0;
        int tMaxSum = nums[0];

        for (auto tNum : nums)
        {
            tCurrSum = std::max(tCurrSum, 0) + tNum;
            tMaxSum = std::max(tMaxSum, tCurrSum);
        }

        return tMaxSum;
    }
};
