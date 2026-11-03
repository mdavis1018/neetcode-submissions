class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int tMax = 0;
        int tCounter = 0;

        for (const int tInt : nums)
        {
            if (tInt == 0)
            {
                tCounter = 0;
            }
            else 
            {
                ++tCounter;
                if (tCounter > tMax)
                {
                    tMax = tCounter;
                }
            }
        }

        return tMax;
    }
};