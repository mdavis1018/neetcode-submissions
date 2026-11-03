class Solution {
public:
    int climbStairs(int n) 
    {
        return dynamicProgramming(n);
    }

    int dynamicProgramming(int n)
    {
       if (n < 2)
       {
            return n;
       }

        std::vector<int> tDP = {1,1};
        
        int tCounter = 2;

        while (tCounter <= n)
        {
            int tIndexNum = std::accumulate(tDP.begin(), tDP.end(), 0);
            std::swap(tDP[0], tDP[1]);
            tDP[1] = tIndexNum;
            ++tCounter;
        }
        return tDP[1];
    }
};
