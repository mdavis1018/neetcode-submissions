class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int tMax = nums[0];
        int tCurrSum = 0;

        for (auto tNum : nums)
        {
            tCurrSum += tNum;
            tMax = std::max(tMax, tCurrSum);
            tCurrSum = std::max(tCurrSum, 0);
        }

        return tMax;
    }
};
