class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int tMaxReturn = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    tMaxReturn = std::max(tMaxReturn, bfs(grid, i, j));
                }
            }
        }
        return tMaxReturn;
    }

    int bfs(vector<vector<int>> &aGrid, int aRow, int aCol)
    {
        int tReturn = 0;
        auto tRowLength = aGrid.size();
        auto tColLength = aGrid[0].size();

        std::vector<std::pair<int,int>> tDirections = 
        {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
        };

        std::queue<pair<int,int>> tQueue;
        tQueue.push({aRow, aCol});
        aGrid[aRow][aCol] = 0;

        while (tQueue.empty() == false)
        {
            auto [tRow, tCol] = tQueue.front();
            tQueue.pop();

            for (auto [tRowDirect, tColDirect] : tDirections)
            {
                auto tNewRow = tRow + tRowDirect;
                auto tNewCol = tCol + tColDirect;

                if (tNewRow < tRowLength 
                    && tNewCol < tColLength
                    && std::min(tNewRow, tNewCol) >= 0
                    && aGrid[tNewRow][tNewCol] != 0)
                {
                    tQueue.push({tNewRow, tNewCol});
                    aGrid[tNewRow][tNewCol] = 0;
                }
            }

            ++tReturn;
        }

        return tReturn;
    }
};
