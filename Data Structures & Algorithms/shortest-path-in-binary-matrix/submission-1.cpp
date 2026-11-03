class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if (grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1)
        {
            return -1;
        }
        // Here are our eight directions
        std::vector<std::pair<int, int>> tDirections =
        {
            {-1,-1},
            {-1,0},
            {-1,1},
            {0,-1},
            {0,1},
            {1,1},
            {1,0},
            {1,-1}
        };

        std::queue<std::pair<int,int>> tQueue;
        vector<vector<int>> tDistanceMatrix(grid.size(), vector<int>(grid[0].size(), -1));
        std::pair<int,int> tStart = {0,0};
        tDistanceMatrix[tStart.first][tStart.second] = 1;
        tQueue.push(tStart);

        while (tQueue.empty() == false)
        {
            auto tCord = tQueue.front();
            tQueue.pop();

            if (tCord.first == grid.size() - 1 && tCord.second == grid[0].size() - 1)
            {
                return tDistanceMatrix[tCord.first][tCord.second];
            }

            for (const std::pair<int,int> &tDirection : tDirections)
            {
                int tRow = tCord.first + tDirection.first;
                int tCol = tCord.second + tDirection.second;
                if (std::min(tRow, tCol) >= 0
                && tRow < grid.size()
                && tCol < grid[0].size()
                && grid[tRow][tCol] != 1
                && tDistanceMatrix[tRow][tCol] == -1)
                {
                    tQueue.push(std::pair<int,int>{tRow, tCol});
                    tDistanceMatrix[tRow][tCol] = 
                                        tDistanceMatrix[tCord.first][tCord.second] + 1;
                }
            }
        }

        return -1;
    }
};