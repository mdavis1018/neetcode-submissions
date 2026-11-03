class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>> tReturn;
        quickSort(points, 0, static_cast<int>(points.size() - 1));
        for (int i = 0; i < k; ++i)
        {
            tReturn.push_back(points[i]);
        }

        return tReturn;
    }

    void quickSort(vector<vector<int>> &aVector, int aStart, int aEnd)
    {
        if (aStart >= aEnd)
        {
            return;
        }

        int tPivot = aEnd;
        int tTracker = aStart;
        int tSwapPosition = aStart;
        int tPivotDistance = std::pow(aVector[tPivot][0], 2) + std::pow(aVector[tPivot][1], 2);
        for (int i = aStart; i < tPivot; ++i)
        {
            int tDistance = std::pow(aVector[i][0], 2) + std::pow(aVector[i][1], 2);
            if (tDistance <= tPivotDistance)
            {
                std::swap(aVector[i], aVector[tSwapPosition]);
                ++tSwapPosition;
            }
            ++tTracker;
        }

        std::swap(aVector[tSwapPosition], aVector[tPivot]);

        quickSort(aVector, aStart, tSwapPosition - 1);
        quickSort(aVector, tSwapPosition + 1, aEnd);
    }
};
