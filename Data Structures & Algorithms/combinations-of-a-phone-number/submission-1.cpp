class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty())
        {
            return {};
        }
        std::unordered_map<char, std::vector<char>> tMap;
        tMap['2'] = std::vector<char>{'a','b','c'};
        tMap['3'] = std::vector<char>{'d','e','f'};
        tMap['4'] = std::vector<char>{'g','h','i'};
        tMap['5'] = std::vector<char>{'j','k','l'};
        tMap['6'] = std::vector<char>{'m','n','o'};
        tMap['7'] = std::vector<char>{'p','q','r','s'};
        tMap['8'] = std::vector<char>{'t','u','v'};
        tMap['9'] = std::vector<char>{'w','x','y','z'};

        std::vector<string> tResult{};
        std::string tPush{};
        backTrack(0, digits, tResult, tPush, tMap);
        return tResult;
    }   

    void backTrack(int aIndex, std::string aDigit, std::vector<string> &aResult, std::string &aPush, std::unordered_map<char, std::vector<char>> &aMap)
    {
        // base cases
        if (aPush.size() == aDigit.size())
        {
            aResult.push_back(aPush);
            return;
        }

        if (aIndex >= aDigit.size())
        {
            return;
        }

        // loop through our value vector
        for (auto tChar : aMap[aDigit[aIndex]])
        {
            aPush.push_back(tChar);
            backTrack(aIndex + 1, aDigit, aResult, aPush, aMap);
            aPush.pop_back();
        }
    }
};
