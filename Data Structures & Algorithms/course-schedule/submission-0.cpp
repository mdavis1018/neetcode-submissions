class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // first we will need to build the adjacency list
        // then we will need to run dfs on each node in the list to get the topological sort
        // no need to reverse since we have    

        // Build adjacency list
        std::vector<std::vector<int>> tAdList(numCourses);
        for (auto tEdge : prerequisites)
        {
            tAdList[tEdge[1]].push_back(tEdge[0]);
        }

        std::set<int> tPath;
        std::set<int> tVisited;
        for (int i = 0; i < numCourses; ++i)
        {
            if (dfs(i, tAdList, tPath, tVisited) == false)
            {
                return false;
            }

        }


        return true;

    }

    bool dfs(int tNode, std::vector<std::vector<int>> &aList, std::set<int> &aPath, std::set<int> &aVisited)
    {
        if (aPath.count(tNode))
        {
            // This graph has a cycle
            return false;
        }

        if (aVisited.count(tNode))
        {
            // Node is already visited
            return true;
        }

        aPath.insert(tNode);
        aVisited.insert(tNode);

        for (auto tNeighbor : aList[tNode])
        {
            if (dfs(tNeighbor, aList, aPath, aVisited) == false)
            {
                return false;
            }
        }

        aPath.erase(tNode);
        return true;
    }
};
