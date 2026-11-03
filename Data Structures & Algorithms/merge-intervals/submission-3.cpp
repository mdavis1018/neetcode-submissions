class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        std::vector<std::vector<int>> tReturn;
        std::sort(intervals.begin(), intervals.end());      
        tReturn.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i)
        {
            auto& tLast = tReturn.back();

            if (tLast[1] >= intervals[i][0])
            {
                // merge time
                tLast[0] = std::min(tLast[0], intervals[i][0]);
                tLast[1] = std::max(tLast[1], intervals[i][1]);
            }
            else 
            {
                tReturn.push_back(intervals[i]);
            }
        }     

        return tReturn;
    }
};
