class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        // Dijkstra's algorithm is a clean solution to this problem

        // Adjacency list        
        std::map<int, std::vector<std::pair<int, int>>> tAdList;

        // Distance map
        std::map<int, int> tMinDistanceMap;

        // min priority queue (Node, distance)
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int,int>>, 
                            std::greater<std::pair<int,int>>> tMinHeap;

        // Initalize everything before 
        for (auto tEntry : times)
        {
            tAdList[tEntry[0]].push_back({tEntry[1], tEntry[2]});
            tMinDistanceMap[tEntry[0]] = std::numeric_limits<int>::max();
            tMinDistanceMap[tEntry[1]] = std::numeric_limits<int>::max();
        }
        
        // Early return
        if (tMinDistanceMap.size() != n)
        {
            return -1;
        }
        
        // We know we start at node k
        tMinDistanceMap[k] = 0;
        tMinHeap.push({k, 0});

        while (tMinHeap.empty() == false)
        {
            auto [tNode, tCurrentDistance] = tMinHeap.top();
            tMinHeap.pop();

            // First we don't want to keep processing, if we have already found a better sol
            if (tMinDistanceMap[tNode] < tCurrentDistance)
            {
                continue;
            }

            // We need to process neighbors
            for (const auto& [tNeighbor, tWeight] : tAdList[tNode])
            {
                int tNewDistance = tCurrentDistance + tWeight;
                if (tNewDistance < tMinDistanceMap[tNeighbor])
                {
                    tMinDistanceMap[tNeighbor] = tNewDistance;
                    tMinHeap.push({tNeighbor, tNewDistance});
                }
            }
        }

        int tMaxTime = std::numeric_limits<int>::min();

        for (const auto& [tNode, tDistance] : tMinDistanceMap)
        {
            if (tDistance == std::numeric_limits<int>::max())
            {
                return -1;
            }
            else 
            {
                tMaxTime = std::max(tMaxTime, tDistance);
            }
        }

        return tMaxTime;
    }
};
