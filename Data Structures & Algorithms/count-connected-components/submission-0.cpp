class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        std::unordered_map<int,int> tParentMap;
        for (int i = 0; i < n; ++i)
        {
            tParentMap[i] = i;
        }

        for (auto tEdge : edges)
        {
            unite(tParentMap, tEdge[0], tEdge[1]);
        }

        // we can get the number of connected components based on the num of unique roots
        std::set<int> tUniqueRoots;
        for (auto tPair : tParentMap)
        {
            tUniqueRoots.insert(find(tParentMap, tPair.first));
        }

        return tUniqueRoots.size();
    }

    int find(std::unordered_map<int,int> &aParentMap, int aNode)
    {
        if (aParentMap[aNode] != aNode)
        {
            aParentMap[aNode] = find(aParentMap, aParentMap[aNode]);
        }

        return aParentMap[aNode];
    }

    bool unite(std::unordered_map<int,int> &aParentMap, int t1, int t2)
    {
        auto a = find(aParentMap, t1);
        auto b = find(aParentMap, t2);

        // root are the same
        if (a == b)
        {
            return false;
        }   

        // set b's root to a
        aParentMap[b] = a;
        return true;
    } 
};
