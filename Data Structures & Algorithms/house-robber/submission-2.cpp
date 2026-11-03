class Solution {
public:
    int rob(vector<int>& nums) 
    {
        // rucurrance relation = F(n) = {n + F(n-2), F(n-1)}
        
        // set up base cases
        if (nums.size() < 2)
        {
            return nums[0];
        }

        std::vector<int> tDP = {nums[0], std::max(nums[0], nums[1])};

        int tIndex = 2;

        while (tIndex < nums.size())
        {
            int tMax = std::max(nums[tIndex] + tDP[0], tDP[1]);
            std::swap(tDP[0], tDP[1]);
            tDP[1] = tMax;
            ++tIndex;
        }

        return std::max(tDP[0], tDP[1]);

    }
};
