class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int tMaxProfit = 0;
        int tMin = prices.front();
        for (const int &aValue : prices)
        {
            if (aValue < tMin)
            {
                tMin = aValue;
            }
            if (tMaxProfit < (aValue - tMin))
            {
                tMaxProfit = aValue - tMin;
            }
        }

        return tMaxProfit;
    }
};
