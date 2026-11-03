class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        // The important thing to note here is that there are two cases:
        // 1. The max subarray wraps around
        // 2. Max subarray doesn't wrap

        int tGlobalMax = nums[0];     
        int tGlobalMin = nums[0];     
        int tCurrMax = 0;     
        int tCurrMin = 0;     
        int tTotal = 0;

        // We have to see whether removing a certain portion in the middle can improve our answer
        for (auto tNum : nums)
        {
            // Do we extend or start array from new point?
            tCurrMax = std::max(tCurrMax + tNum, tNum);
            tGlobalMax = std::max(tCurrMax, tGlobalMax);

            // Find the smallest sum ending here
            tCurrMin = std::min(tCurrMin + tNum, tNum);
            tGlobalMin = std::min(tCurrMin, tGlobalMin);

            tTotal += tNum;
        }

        if (tGlobalMax < 0)
        {
            return tGlobalMax;
        }

        return std::max(tTotal - tGlobalMin, tGlobalMax);
    }
};