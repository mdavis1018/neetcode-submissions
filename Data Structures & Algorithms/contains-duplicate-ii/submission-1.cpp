class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        std::set<int> tSet;
        int tLeftPtr = 0;
        int tRightPtr = 1;
        tSet.insert(nums[tLeftPtr]);

        while (tRightPtr < nums.size())
        {           
            if (std::abs(tLeftPtr - tRightPtr) > k) 
            {
                tSet.erase(nums[tLeftPtr]);
                ++tLeftPtr;
            }

            if (tSet.count(nums[tRightPtr]))
            {
                return true;
            }

            if (std::abs(tLeftPtr - tRightPtr) <= k)
            {
                // Insert
                tSet.insert(nums[tRightPtr]);
            }

            ++tRightPtr;

        }        

        return false;
    }
};