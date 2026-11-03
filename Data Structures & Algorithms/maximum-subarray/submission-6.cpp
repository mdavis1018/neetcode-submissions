class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int tMax = nums[0];
        int tCurrSum = 0;

        for (auto tNum : nums)
        {
            tCurrSum = std::max(tCurrSum, 0) + tNum;
            tMax = std::max(tCurrSum, tMax);
        }

        return tMax;
    }
};
