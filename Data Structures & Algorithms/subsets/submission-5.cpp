class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        std::vector<std::vector<int>> tReturn{};
        std::vector<int> tPush{};
        backTrack(nums, 0, tPush, tReturn);
        return tReturn;
    }

    void backTrack(std::vector<int> &aNums, int aIndex, std::vector<int> &aPush, std::vector<std::vector<int>> &aReturn)
    {
        if (aIndex == aNums.size())
        {
            aReturn.push_back(aPush);
            return;
        }

        // we have two options

        // Option 1: append the num at the index in the push vector
        aPush.push_back(aNums[aIndex]);
        backTrack(aNums, aIndex + 1, aPush, aReturn);
        // Option 2: leave the num at the index out of the vector
        aPush.pop_back();
        backTrack(aNums, aIndex + 1, aPush, aReturn);    
    }

};
