class Solution {
public:
    vector<string> expand(string s) 
    {
        std::map<int, std::vector<char>> tPositionMap;

        int tIndex = 0;
        int tPosition = 0;
        while (tIndex < s.size())
        {
            if (s[tIndex] == '{')
            {
                ++tIndex;
                while (s[tIndex] != '}')
                {
                    if (s[tIndex] == ',')
                    {
                        
                    }
                    else 
                    {
                        tPositionMap[tPosition].push_back(s[tIndex]);
                    }
                    ++tIndex;
                }
            }
            else 
            {
                tPositionMap[tPosition].push_back(s[tIndex]);
            }

            ++tIndex;
            ++tPosition;
        }

        std::vector<string> tReturn = {{}};

        for (auto [tPosition, tCharVector] : tPositionMap)
        {
            vector<string> tNextVector;
            for (int i = 0; i < tCharVector.size(); ++i)
            {
                for (auto tReturnVector : tReturn)
                {
                    auto tCopy = tReturnVector;
                    tCopy.push_back(tCharVector[i]);
                    tNextVector.push_back(tCopy);
                }
            }
            tReturn = tNextVector;
        }

        std::sort(tReturn.begin(), tReturn.end());
        return tReturn;
    }
};
