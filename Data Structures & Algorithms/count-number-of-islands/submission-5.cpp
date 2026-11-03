class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int tCounter = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++tCounter;
                }
            }
        }

        return tCounter;
    }

    void dfs(vector<vector<char>> &aGrid, int aRow, int aCol)
    {
        int tRowSize = aGrid.size();
        int tColSize = aGrid[0].size();

        // Base case in bounds checks
        if (aRow >= tRowSize || aCol >= tColSize)
        {
            return;
        }

        if (std::min(aRow, aCol) < 0)
        {
            return;
        }

        if (aGrid[aRow][aCol] == '0')
        {
            return;
        } 

        aGrid[aRow][aCol] = '0';

        dfs(aGrid, aRow + 1, aCol);
        dfs(aGrid, aRow - 1, aCol);
        dfs(aGrid, aRow, aCol + 1);
        dfs(aGrid, aRow, aCol - 1);
    }
};
