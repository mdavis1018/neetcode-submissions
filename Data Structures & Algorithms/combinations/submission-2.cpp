class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> tResult;
        vector<int> tPush;
        backTrack(1, n, k, tResult, tPush);
        return tResult;
    }

    void backTrack(int aNum, int n, int k, std::vector<std::vector<int>> &aResult, std::vector<int> &aPush)
    {
        // Establish base cases
        if (aPush.size() == k)
        {
            aResult.push_back(aPush);
            return;
        }

        if (aNum > n)
        {
            return;
        }

        auto tLeft = aPush;
        tLeft.push_back(aNum);
        backTrack(aNum + 1, n, k, aResult, tLeft);
        backTrack(aNum + 1, n, k, aResult, aPush);
    }
};