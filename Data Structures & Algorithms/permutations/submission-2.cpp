class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        // So we know that we need to insert each num in vector at each position
        // We need to init with atleast one vector
        vector<vector<int>> tReturn{{}};

        for (int i = 0; i < nums.size(); ++i)
        {
            // we are going to want to overwrite the return vector 
            vector<vector<int>> tNext;

            for (auto tPermutation : tReturn)
            {
                // we must do the insertion now at each position
                for (int j = 0; j < i + 1; ++j)
                {
                    auto tCopy = tPermutation;
                    tCopy.insert(tCopy.begin() + j, nums[i]);
                    tNext.push_back(tCopy);
                }
            }
            tReturn = std::move(tNext);
        }    

        return tReturn;
    }
};
