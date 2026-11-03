#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::set<int> tSet;
        for (const int tElement : nums)
        {
            tSet.insert(tElement);
        }    

        return tSet.size() != nums.size();
    }
};