class Solution {
public:
    bool isPalindrome(string s) 
    {
        std::string tReverse;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            const char tChar = std::tolower(s.at(i));
            if (std::isalnum(static_cast<unsigned char>(tChar)))
            {
                std::__exchange(s.at(i), std::tolower(s.at(i)));
                tReverse+=tChar;
            }
            else 
            {
                s.erase(i, 1);
            }
        }
        return tReverse == s;
    }
};
