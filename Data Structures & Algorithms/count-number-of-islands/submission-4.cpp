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

    void dfs (vector<vector<char>>& grid, int aRow, int aCol)
    {
        int tRowSize = grid.size();
        int tColSize = grid[0].size();

        if (aRow >= tRowSize || aCol >= tColSize)
        {
            return;
        }

        if (std::min(aRow, aCol) < 0)
        {
            return;
        }

        if (grid[aRow][aCol] == '0')
        {
            return;
        }

        grid[aRow][aCol] = '0';

        dfs(grid, aRow + 1, aCol);
        dfs(grid, aRow - 1, aCol);
        dfs(grid, aRow, aCol + 1);
        dfs(grid, aRow, aCol - 1);
    }
};

