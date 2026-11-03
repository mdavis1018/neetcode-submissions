class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> tResult;
        vector<int> tPush;
        backTrack(1, n, k, tResult, tPush);
        return tResult;
    }

    void backTrack(int aIndex, int n, int k, std::vector<std::vector<int>> &aResult, std::vector<int> &aPush)
    {
        if (aPush.size() == k)
        {
            aResult.push_back(aPush);
            return;
        }

        if (aIndex > n)
        {
            return;
        }

        aPush.push_back(aIndex);
        backTrack(aIndex + 1, n, k, aResult, aPush);

        aPush.pop_back();
        backTrack(aIndex + 1, n, k, aResult, aPush);
    }
};