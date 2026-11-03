class Solution {
public:
    vector<int> countBits(int n) 
    {
        std::vector<int> tReturn;

        for (int i = 0; i <= n; ++i)
        {
            std::bitset<sizeof(int) * 8> tBitset(i);
            int tCount = 0;
            for (std::size_t j = 0; j < sizeof(int) * 8; ++j)
            {
                tCount += tBitset.test(j);
            }
            tReturn.push_back(tCount);
        }

        return tReturn;
    }
};
