class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty())
        {
            return 0;
        }
        std::map<int,int> tParentMap;
        std::map<int,int> tSizeMap;

        for (int i = 0; i < nums.size(); ++i)
        {
            tParentMap[nums[i]] = nums[i];
            tSizeMap[nums[i]] = 1;
        }

        int tMax = 1;
        for (auto tPair : tParentMap)
        {
            if (tParentMap.count(tPair.first + 1))
            {
                tMax = std::max(tMax, unite(tPair.first, tPair.first + 1, tParentMap, tSizeMap));
            }
        }

        return tMax;
    }

    int find(int aNode, std::map<int,int> &aParentMap)
    {
        if (aParentMap[aNode] != aNode)
        {
            aParentMap[aNode] = find(aParentMap[aNode], aParentMap);
        }

        return aParentMap[aNode];
    }

    int unite(int aNodeA, int aNodeB, std::map<int,int> &aParentMap, std::map<int,int> &aSizeMap)
    {
        auto tParentA = find(aNodeA, aParentMap);
        auto tParentB = find(aNodeB, aParentMap);

        if (tParentA == tParentB)
        {
            return -1;
        }

        if (aSizeMap[tParentA] < aSizeMap[tParentB])
        {
            std::swap(tParentA, tParentB);
        }

        aParentMap[tParentB] = tParentA;
        aSizeMap[tParentA]+= aSizeMap[tParentB];
        return aSizeMap[tParentA];
    }
};
