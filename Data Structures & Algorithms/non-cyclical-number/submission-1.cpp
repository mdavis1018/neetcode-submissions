class Solution {
public:
    bool isHappy(int n) 
    {
        std::set<int> tVisited;
        
        while (tVisited.find(n) == tVisited.end())
        {
            tVisited.insert(n);

            std::vector<int> tSoS;
            while (n != 0)
            {
                tSoS.push_back(n % 10);
                n /= 10;
            }

            for (const int tIndex : tSoS)
            {
                n += std::pow(tIndex, 2);
            }
        }
        
        return n == 1;
    }
};
