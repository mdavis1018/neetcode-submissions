class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        std::map<int,std::vector<int>> tAdList;
        std::vector<int> tTopSort;
        std::set<int> tVisited;
        std::set<int> tPath;

        // Build adjacency list
        for (auto &tEdge : prerequisites)
        {
            tAdList[tEdge[0]].push_back(tEdge[1]); 
        }
        for (int i = 0; i < numCourses; ++i)
        {   
            if (!dfs(tAdList, tTopSort, tVisited, tPath, i))
            {
                return false;
            }
        }

        return true;
    }

    bool dfs(std::map<int,std::vector<int>> &aAdList,
            std::vector<int> &aTopSort, 
            std::set<int> &aVisited,
            std::set<int> &aPath,
            int aNode)
    {
        // Base cases
        if (aPath.count(aNode))
        {
            // cycle detected
            return false;
        }

        if (aVisited.count(aNode))
        {
            return true;
        }

        aPath.insert(aNode);

        for (auto tNeighbor : aAdList[aNode])
        {
            if (!dfs(aAdList, aTopSort, aVisited, aPath, tNeighbor))
            {
                return false;
            }
        }

        aVisited.insert(aNode);
        aTopSort.push_back(aNode);
        aPath.erase(aNode);
        return true;
    }
};
