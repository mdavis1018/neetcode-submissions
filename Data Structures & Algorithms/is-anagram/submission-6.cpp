class Solution {
public:
    bool isAnagram(string s, string t) 
    {
       if (s.length() != t.length())
       {
            return false;
       } 

       std::unordered_map<char, int> t1{};
       std::unordered_map<char, int> t2{};

        for (std::size_t tIndex = 0; tIndex < s.length(); ++tIndex)
        {
            ++t1[s[tIndex]];
            ++t2[t[tIndex]];
        }

        return t1 == t2;
    }
};
