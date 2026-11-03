class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int tReturn = 0;
        int tLeftPtr = 0;
        int tRightPtr = tLeftPtr + k - 1;

        while (tRightPtr < arr.size())
        {
            // 
            if (std::accumulate(std::next(arr.begin(), tLeftPtr), std::next(arr.begin(), tRightPtr + 1), 0) / k >= threshold)
            {
                tReturn++;
            }

            ++tLeftPtr;
            ++tRightPtr;
        }

        return tReturn;
    }
};