class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        std::vector<int> tTopSort;
        std::set<int> tVisited;
        std::set<int> tPath;
        std::map<int, std::vector<int>> tAdList;

        for (int i = 0; i < numCourses; ++i)
        {
            tAdList[i];
        }

        for (auto tEdge : prerequisites)
        {
            tAdList[tEdge[1]].push_back(tEdge[0]);
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (dfs(tTopSort, tAdList, tVisited, tPath, i) == false)
            {
                return {};
            }
        }

        std::reverse(tTopSort.begin(), tTopSort.end());
        return tTopSort;
    }

    bool dfs(std::vector<int> &aTopSort, 
             std::map<int, std::vector<int>> &aAdList,
             std::set<int> &aVisited,
             std::set<int> &aPath,
             int aNode)
    {
        if (aPath.count(aNode))
        {
            // Cycle detection
            return false;
        }

        if (aVisited.count(aNode))
        {
            return true;
        }

        aPath.insert(aNode);

        for (auto tNeighbor : aAdList[aNode])
        {
            if (dfs(aTopSort, aAdList, aVisited, aPath, tNeighbor) == false)
            {
                return false;
            }
        }

        aPath.erase(aNode);
        aVisited.insert(aNode);
        aTopSort.push_back(aNode);
        return true;
    }
};
