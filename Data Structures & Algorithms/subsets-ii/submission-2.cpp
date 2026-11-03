class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());    
        vector<vector<int>> tReturn{};
        vector<int> tPush;
        backTrack(0, nums, tPush, tReturn);
        return tReturn;
    }

    void backTrack(int aIndex, vector<int> &aNums, vector<int> &aCurrent, vector<vector<int>> &aReturn)
    {
        if (aIndex == aNums.size())
        {
            aReturn.push_back(aCurrent);
            return;
        }

        // Our two options need to be slightly modified, 

        // Option 1: Regurlar, just add the index to our subset
        aCurrent.push_back(aNums[aIndex]);
        backTrack(aIndex + 1, aNums, aCurrent, aReturn);
        // Option 2: Pop back of the candidate and skip all indexes that are equal to our index, this only works with sorted values
        aCurrent.pop_back();
        while (aIndex + 1 < aNums.size() && aNums[aIndex] == aNums[aIndex + 1])
        {
            aIndex = aIndex + 1;
        }
        backTrack(aIndex + 1, aNums, aCurrent, aReturn);
    }
};
