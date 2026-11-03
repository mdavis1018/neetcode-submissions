class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) 
    {
        std::map<int, std::vector<std::pair<int,int>>> tAdList;
        std::unordered_map<int,int> tMinDistanceMap;
        for (auto tEdge : edges)
        {
            tAdList[tEdge[0]].push_back({tEdge[2], tEdge[1]});
        }

        for (int i = 0; i < n; ++i)
        {
            tMinDistanceMap[i] = std::numeric_limits<int>::max();
        }

        std::priority_queue<std::pair<int,int>, std::vector<pair<int,int>>, std::greater<std::pair<int,int>>> tMinHeap;

        tMinDistanceMap[src] = 0;

        // Priority queue will sort based on first element, this is important to note
        tMinHeap.push({tMinDistanceMap[src], src});

        while (tMinHeap.empty() == false)
        {
            int tLevelSize = tMinHeap.size();

            for (int i = 0; i < tLevelSize; ++i)
            {
                auto [tMinDistance, tNode] = tMinHeap.top();
                tMinHeap.pop();

                if (tMinDistance > tMinDistanceMap[tNode])
                {
                    continue;
                }

                for (auto [tDistance, tNeighborNode] : tAdList[tNode])
                {
                    auto tNewDistance = tMinDistance + tDistance;
                    
                    if (tNewDistance < tMinDistanceMap[tNeighborNode])
                    {
                        tMinDistanceMap[tNeighborNode] = tNewDistance;
                        tMinHeap.push({tNewDistance, tNeighborNode});
                    }
                }
            }
        }

        for (auto& [node, distance] : tMinDistanceMap)
        {
            if (distance == std::numeric_limits<int>::max())
            {
                distance = -1;
            }
        }

        return tMinDistanceMap;
    }
};
