class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        std::unordered_set<int> tWindow;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > k)
            {
                tWindow.erase(nums[i - k - 1]);
            }

            if (tWindow.count(nums[i]))
            {
                return true;
            }
            else 
            {
                tWindow.insert(nums[i]);
            }
        }    

        return false;
    }
};