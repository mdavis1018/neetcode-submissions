class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        // Initialize a starting vector with a single empty vector
        std::vector<std::vector<int>> tStart = {{}};

        // Loop through each number in our vector
        for (int i = 0; i < nums.size(); ++i)
        {
            // Initialize a vector that will store this iterations permuations
            std::vector<std::vector<int>> tNextStage;

            // Loop through each existing permuation in our result vector
            for (auto tPermutation : tStart)
            {
                // we know that the number of places to insert nums[i] will be i + 1
                for (int j = 0; j < i + 1; ++j)
                {
                    // Copy out the vector
                    auto tCopy = tPermutation;

                    // run the insert on each spot
                    tCopy.insert(tCopy.begin() + j, nums[i]);

                    // push back
                    tNextStage.push_back(tCopy);
                }
            }
            // copy
            tStart = tNextStage;
        }

        return tStart;
    }
};
