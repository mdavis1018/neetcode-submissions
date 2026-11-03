class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        std::vector<int> tPush{};
        backTrack(nums, 0, tPush);
        return mReturn;
    }

    void backTrack(std::vector<int> &aVector, std::size_t aIndex, std::vector<int> aPushVector)
    {
        if (aIndex >= aVector.size())
        {
            mReturn.push_back(aPushVector);
            return;
        }

        auto tLeft = aPushVector;
        auto tRight = aPushVector;

        tLeft.push_back(aVector.at(aIndex));

        backTrack(aVector, aIndex + 1, tLeft);
        backTrack(aVector, aIndex + 1, tRight);
    }

    vector<vector<int>> mReturn;
};
