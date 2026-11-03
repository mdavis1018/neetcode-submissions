class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> tResult;
        vector<int> tPush;
        backTrack(1, tPush, tResult, n, k);
        return tResult;
    }

    void backTrack(int aNum, std::vector<int> &aPush, std::vector<std::vector<int>> &aResult, int n, int k)
    {
        // Base cases are if we are greater than n or == k
        if (aPush.size() == k)
        {
            aResult.push_back(aPush);
            return;
        }

        
        if (aNum > n)
        {
            return;
        }

        aPush.push_back(aNum);
        backTrack(aNum + 1, aPush, aResult, n, k);
        aPush.pop_back();
        backTrack(aNum + 1, aPush, aResult, n, k);
    }
};