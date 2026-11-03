class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }


        std::unordered_map<char, int> tRansomHashMap;
        std::unordered_map<char, int> tMagazineHashMap;

        for (auto tChar : ransomNote)
        {
            ++tRansomHashMap[tChar];
        }

        for (auto tChar : magazine)
        {
            ++tMagazineHashMap[tChar];
        }

        for (auto tPair : tRansomHashMap)
        {
            if (tMagazineHashMap[tPair.first] >= tPair.second)
            {

            }
            else 
            {
                return false;
            }
        }

        return true;
    }
};