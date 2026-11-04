class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        std::unordered_set<std::string> tBank;
        std::unordered_set<std::string> tAnswers;
        std::vector<std::string> tReturn;
        std::string tCandidate;
        for (int i = 0; i < s.size(); ++i)
        {
            tCandidate.push_back(s[i]);

            if (tCandidate.size() >= 10)
            {                
                if (tAnswers.count(tCandidate))
                {
                    
                }
                else if (tBank.count(tCandidate))
                {
                    tReturn.push_back(tCandidate);
                    tAnswers.insert(tCandidate);
                }
                else 
                {
                    tBank.insert(tCandidate);
                }

                tCandidate.erase(tCandidate.begin());

            }
        }

        return tReturn;
    }
};
