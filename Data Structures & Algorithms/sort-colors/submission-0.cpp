class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        std::map<int, int> tMap;
        
        for (int tNum : nums)
        {
            ++tMap[tNum];
        }

        std::map<int,int>::iterator tIter = tMap.begin();

        nums.clear();
        std::vector<int>::iterator tVectorIterator = nums.begin();
        while (tIter != tMap.end())
        {
            tVectorIterator = nums.insert(tVectorIterator,tIter->second,tIter->first);
            ++tIter;
            tVectorIterator = nums.end();
        }
    }
};