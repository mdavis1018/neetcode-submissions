class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int tTotal = 0;
        int tGlobalMax = nums[0];
        int tGlobalMin = nums[0];
        int tLocalMin = 0;
        int tLocalMax = 0;

        for (auto tNum : nums)
        {
            tTotal += tNum;
            tLocalMin += tNum;
            tLocalMax += tNum;
            tGlobalMax = std::max(tLocalMax, tGlobalMax);
            tGlobalMin = std::min(tLocalMin, tGlobalMin);
            tLocalMax = std::max(tLocalMax, 0);
            tLocalMin = std::min(tLocalMin, 0);
        }    

        if (tGlobalMax < 0)
        {
            return tGlobalMax;
        }
        return std::max(tGlobalMax, tTotal - tGlobalMin);
    }
};