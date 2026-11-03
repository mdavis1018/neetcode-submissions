class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        std::vector<int> tPush{};
        std::vector<std::vector<int>> tReturn;
        std::sort(nums.begin(), nums.end());
        backTrack(0, nums, target, tPush, tReturn);
        return tReturn;
    }
    
    void backTrack(int aIndex, vector<int>& aNums, int tRemaining, std::vector<int> aPushVector, std::vector<std::vector<int>> &aFinal)
    {
        if (tRemaining == 0)
        {
            aFinal.push_back(aPushVector);
            return;
        }

        // A sorted vector allows us to get an even earlier exit when we know next won't produce an answer
        for (int i = aIndex; i < aNums.size(); ++i)
        {
            // do the back tracking within here
            if (tRemaining - aNums[i] < 0)
            {
                return;
            }
            aPushVector.push_back(aNums[i]);
            backTrack(i, aNums, tRemaining - aNums.at(i), aPushVector, aFinal);
            aPushVector.pop_back();
        }
    }
};
