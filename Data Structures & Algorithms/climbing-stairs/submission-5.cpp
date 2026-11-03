class Solution {
public:
    int climbStairs(int n) 
    {
        std::map<int,int> tMemoization{};
        return dynamicProgramming(n, tMemoization);
    }

    int dynamicProgramming(int n, std::map<int,int> &aMemoizationMap)
    {
        if (n <= 1)
        {
            return 1;
        }

        if (aMemoizationMap.count(n))
        {
            return aMemoizationMap.at(n);
        }
        aMemoizationMap[n] = dynamicProgramming(n - 1, aMemoizationMap) + dynamicProgramming(n - 2, aMemoizationMap);
        return aMemoizationMap[n];
    }
};
