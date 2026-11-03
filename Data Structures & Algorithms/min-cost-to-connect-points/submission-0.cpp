class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        // Init parent map
        std::map<pair<int,int>, pair<int,int>> tParentMap;
        // Generate all edges

        // Set stores this format [manhattanDistance, point1.x, point1.y, point2.x, point2.y]
        std::set<vector<int>> tEdges;

        for (int i = 0; i < points.size(); ++i)
        {
            tParentMap[{points[i][0], points[i][1]}] = {points[i][0], points[i][1]};
            for (int j = 0; j < points.size(); ++j)
            {
                if (i == j)
                {
                    continue;
                }

                int tManhattan = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                std::vector<int> tInsert = {tManhattan, points[i][0], points[i][1], points[j][0], points[j][1]};
                tEdges.insert(tInsert);
            }
        }

        int tCounter = 0;
        int tReturn = 0;

        for (auto tEdge : tEdges)
        {
            if (tCounter == points.size() - 1)
            {
                break;
            }         

            if (unite({tEdge[1], tEdge[2]},{tEdge[3],tEdge[4]},tParentMap))
            {
                ++tCounter;
                tReturn += tEdge[0];
            }
        }

        return tReturn;    
    }

    pair<int,int> find(pair<int,int> aNode, std::map<pair<int,int>, pair<int,int>> &aParentMap)
    {
        if (aParentMap[aNode] != aNode)
        {
            // compress the tree
            aParentMap[aNode] = find(aParentMap[aNode], aParentMap);
        }

        return aParentMap[aNode];
    }

    bool unite(pair<int,int> aNodeA, pair<int,int> aNodeB, std::map<pair<int,int>, pair<int,int>> &aParentMap)
    {
        auto tParentA = find(aNodeA, aParentMap);
        auto tParentB = find(aNodeB, aParentMap);

        if (tParentA == tParentB)
        {
            // return false because we don't want to form a cycle
            return false;
        }

        aParentMap[tParentB] = tParentA;
        return true;
    }
};
