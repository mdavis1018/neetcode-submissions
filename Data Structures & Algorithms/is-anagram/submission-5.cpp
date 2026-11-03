
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length())
        {
            return false;
        } 
        else
        {
            for (auto tIter = s.begin(); tIter != s.end() ; ++tIter)
            {
                std::size_t tIndex = t.find(*tIter);
                if (tIndex == std::string::npos)
                {
                    return false;
                }
                else 
                {
                    t.erase(tIndex, 1);
                }
            }
        }

        return true;
    }
};
