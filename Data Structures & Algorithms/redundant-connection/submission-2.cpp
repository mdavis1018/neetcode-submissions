class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        std::map<int,int> tParentMap;
        
        for (int i = 1; i <= edges.size(); ++i)
        {
            tParentMap[i] = i;
        }    

        std::vector<int> tReturn{};
        
        for (auto tEdge : edges)
        {
            if (unite(tEdge[0], tEdge[1], tParentMap) == false)
            {
                tReturn = tEdge;
            }
        }

        return tReturn;
    }

    int find(int aNode, std::map<int,int> &aParentMap)
    {
        if (aParentMap[aNode] != aNode)
        {
            // This also compresses the table
            aParentMap[aNode] = find(aParentMap[aNode], aParentMap);
        }

        return aParentMap[aNode];
    }

    bool unite(int aNodeA, int aNodeB, std::map<int,int> &aParentMap)
    {
        auto tParentA = find(aNodeA, aParentMap);
        auto tParentB = find(aNodeB, aParentMap);

        // If these two nodes already have the same parent then we consider this redundent
        if (tParentA == tParentB)
        {
            // Or this alternatively means we have detected a cycle
            return false;
        }

        aParentMap[tParentB] = tParentA;
        return true;
    }
};
