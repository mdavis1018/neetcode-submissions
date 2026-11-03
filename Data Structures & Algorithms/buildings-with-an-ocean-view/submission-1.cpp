class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) 
    {
        vector<int> tReturn;

        int tTallest = 0;
        
        for (int j = heights.size() - 1; j >= 0; --j)
        {
            if (heights[j] > tTallest)
            {
                tReturn.push_back(j);
                tTallest = heights[j];
            }
        }

        std::reverse(tReturn.begin(), tReturn.end());
        return tReturn;
    }
};