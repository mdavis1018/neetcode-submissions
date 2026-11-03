class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int tMax = *nums.begin();
        int tCurrentSum = 0;

        for (int tInt : nums)
        {
            if (tCurrentSum < 0)
            {
                tCurrentSum = 0;
            }

            tCurrentSum += tInt;
            tMax = std::max(tCurrentSum, tMax);
        }

        return tMax;
    }
};
