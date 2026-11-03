class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        std::vector<int> tCopy(nums.begin(), nums.end());
        
        for (int tInt : nums)
        {
            tCopy.push_back(tInt);
        }     

        return tCopy;
    }
};