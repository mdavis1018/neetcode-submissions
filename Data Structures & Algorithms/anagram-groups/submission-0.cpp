class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> tReturn;
        std::map<std::vector<int>, std::vector<std::string>> tBuckets{};

        for (int i = 0; i < strs.size(); ++i)
        {
            std::vector<int> tAnagramHash(255,0);
            std::string tAnagram = strs.at(i);
            for (int j = 0; j < tAnagram.length(); ++j)
            {
                ++tAnagramHash.at(static_cast<int>(tAnagram.at(j)));
            }
            tBuckets[tAnagramHash].push_back(tAnagram);
        }  

        for (auto tPair = tBuckets.begin(); tPair != tBuckets.end(); ++tPair)
        {
            tReturn.push_back(tPair->second);
        }

        return tReturn;  
    }
};
