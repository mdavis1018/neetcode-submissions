class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::unordered_map<int, int> tHash{};

        for (auto tNum : nums)
        {
            ++tHash[tNum];
            if (tHash[tNum] > 1)
            {
                return true;
            }
        }    

        return false;
    }
};