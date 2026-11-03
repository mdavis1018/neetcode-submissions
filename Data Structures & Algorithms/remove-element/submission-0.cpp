class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        
        std::vector<int>::iterator tIter = nums.begin();
        
        while (tIter != nums.end())
        {
            if (*tIter == val)
            {
                // will return the iterator to the next element in resized vector
                tIter = nums.erase(tIter);
            }
            else 
            {
                ++tIter;
            }
        }
        return nums.size();
    }
};