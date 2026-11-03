class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int tReturn = 0;
        // Start: Compute the sum of the first window
        int tCurrSum = 0;
        for (int i = 0; i < k; ++i)
        {
            tCurrSum+= arr[i];
        }

        if (tCurrSum / k >= threshold)
        {
            ++tReturn;
        }

        // Sliding window time
        for (int i = k; i < arr.size(); ++i)
        {
            // subtract index that just went out of range
            tCurrSum -= arr[i - k];
            tCurrSum += arr[i];
            if (tCurrSum / k >= threshold)
            {
                ++tReturn;
            }
        }

        return tReturn;

    }
};