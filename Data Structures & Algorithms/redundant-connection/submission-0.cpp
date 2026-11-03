class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        std::vector<int> tReturn;
        std::unordered_map<int,int> tParent;
        std::unordered_map<int,int> tRank;

        for (auto tEdge : edges)
        {
            for (auto tIndex : tEdge)
            {
                // set the parent to itself
                tParent[tIndex] = tIndex;
                tRank[tIndex] = 1;
            }
        }

        for (auto tEdge : edges)
        {
            if (unite(tParent, tRank, tEdge[0], tEdge[1]) == false)
            {
                tReturn.clear();
                tReturn = {tEdge[0], tEdge[1]};
            }
        }

        return tReturn;
    }

    int find(std::unordered_map<int,int> &aParent, int aNode)
    {
        if (aParent[aNode] != aNode)
        {
            // path compression
            aParent[aNode] = find(aParent, aParent[aNode]);
        }

        return aParent[aNode];
    }

    bool unite(std::unordered_map<int,int> &aParent, std::unordered_map<int,int> &aRank, int aNodeA, int aNodeB)
    {
        auto tRootA = find(aParent, aNodeA);
        auto tRootB = find(aParent, aNodeB);

        if (tRootA == tRootB)
        {
            // These nodes already share the same root therefore in same group
            return false;
        }

        // Ensure A is the larger group
        if (aRank[tRootA] < aRank[tRootB])
        {
            std::swap(tRootA, tRootB);
        }

        // Attach the smaller group's root to the larger root
        aParent[tRootB] = tRootA;

        // Update group size 
        aRank[tRootA] += aRank[tRootB];

        return true;
    }
};
