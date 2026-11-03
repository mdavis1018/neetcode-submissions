class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::unordered_map<int, std::size_t> tHashMap;

        for (std::vector<int>::const_iterator tIter = nums.cbegin(); tIter != nums.cend(); ++tIter)
        {
            const int tDiff = target - *tIter;

            if (tHashMap.find(tDiff) != tHashMap.end())
            {
                return std::vector<int>{
                    static_cast<int>(tHashMap.find(tDiff)->second), 
                    static_cast<int>(std::distance(nums.cbegin(), tIter))};
            }
            else 
            {
                tHashMap.insert({*tIter, static_cast<int>(std::distance(nums.cbegin(), tIter))});
            }
        }
       return std::vector<int>{};
    }
};
