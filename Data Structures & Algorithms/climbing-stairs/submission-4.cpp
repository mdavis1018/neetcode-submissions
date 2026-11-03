class Solution {
public:
    int climbStairs(int n) 
    {
        std::vector<int> tMemoizationVector(n + 1, -1);
        return memoization(n, tMemoizationVector);
    }

    int memoization(int aIteration ,std::vector<int> &aMemoizationVector)
    {
        if (aMemoizationVector[aIteration] != -1)
        {
            return aMemoizationVector[aIteration];
        }

        if (aIteration <= 1)
        {
            return 1;
        }

        aMemoizationVector[aIteration] = memoization(aIteration - 1, aMemoizationVector) + memoization(aIteration - 2, aMemoizationVector);

        return aMemoizationVector[aIteration];
    }
};
