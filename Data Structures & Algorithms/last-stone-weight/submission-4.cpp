class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        std::multiset<int> tQueue(stones.begin(), stones.end());

        while (tQueue.size() > 1)
        {
            auto tBack = std::prev(tQueue.end());
            auto tSecondBack = std::prev(tBack);

            const auto tResult = *tBack - *tSecondBack;
            tQueue.erase(std::prev(tQueue.end()));
            tQueue.erase(std::prev(tQueue.end()));

            if (tResult != 0)
            {
                tQueue.insert(tResult);
            }
        }

        if (tQueue.empty())
        {
            return 0;
        }
        else 
        {
            return *tQueue.begin();
        }
    }
};
