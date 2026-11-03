class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        std::vector<std::vector<int>> tPermutations = {{}};

        for (int i = 0; i < nums.size(); ++i)
        {
            std::map<std::string, std::vector<int>> tUnique;
            
            for (auto tPermutation : tPermutations)
            {
                for (int j = 0; j < i + 1; ++j)
                {
                    auto tCopy = tPermutation;
                    tCopy.insert(tCopy.begin() + j, nums[i]);

                    std::string tStringRep;
                    for (auto tInt : tCopy)
                    {
                        tStringRep+=std::to_string(tInt);
                    }

                    tUnique[tStringRep] = tCopy;
                }
            }

            tPermutations.clear();
            for (auto tPair : tUnique)
            {
                tPermutations.push_back(tPair.second);
            }
        }

        return tPermutations;
    }
};