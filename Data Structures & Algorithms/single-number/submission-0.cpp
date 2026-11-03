class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int tComp = 0;
        for (auto tNum : nums)
        {   
            tComp ^= tNum;
        }
        return tComp;
    }
};
