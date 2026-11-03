class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // Build adjacency list
        std::vector<std::vector<int>> tAdjList(numCourses);
        for (auto tEdge : prerequisites)
        {
            tAdjList[tEdge[0]].push_back(tEdge[1]);
        }

        std::set<int> tVisited;
        std::set<int> tPath;
        std::vector<int> tTopSort;

        for (int i = 0; i < numCourses; ++i)
        {
            if (dfs(i, tAdjList, tVisited, tPath, tTopSort) == false)
            {
                return {};
            }
        }

        return tTopSort;
    }

    bool dfs(int tNode, std::vector<std::vector<int>> &aList, std::set<int> &aVisitedSet, std::set<int> &aPathSet, std::vector<int> &aTopSort)
    {
        if (aPathSet.count(tNode))
        {
            // We have a cycle
            return false;
        }

        if (aVisitedSet.count(tNode))
        {
            // We have already been here, return
            return true;
        }

        aVisitedSet.insert(tNode);
        aPathSet.insert(tNode);

        for (auto tNeighbor : aList[tNode])
        {
            if (dfs(tNeighbor, aList, aVisitedSet, aPathSet, aTopSort) == false)
            {
                return false;
            }
        }

        aTopSort.push_back(tNode);
        aPathSet.erase(tNode);
        return true;
    }
};
