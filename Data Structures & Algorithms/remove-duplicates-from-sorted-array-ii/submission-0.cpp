class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int tSize = nums.size();
        std::unordered_map<int,int> tHashMap;
        auto tLeft = nums.begin();
        auto tRight = nums.begin() + 1;
        ++tHashMap[*tLeft];
        int tCounter = 0;

        while (tRight != nums.end())
        {
            ++tHashMap[*tRight];

            // We need to check if 
            if (tHashMap[*tRight] > 2)
            {
                ++tCounter;
                nums.erase(tRight);
            }
            else 
            {
                ++tRight;
            }            
        }    

        return tSize - tCounter;
    }
};