class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int tSum = 0;
        int tReturn = 0;

        for (int i = 0; i < arr.size(); ++i)
        {
            tSum += arr[i];

            if (i >= k)
            {
                tSum -= arr[i - k];
            }

            if (i >= k - 1 && tSum / k >= threshold)
            {
                ++tReturn;
            }
        }    

        return tReturn;
    }
};