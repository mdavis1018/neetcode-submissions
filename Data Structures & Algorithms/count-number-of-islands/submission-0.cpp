class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {   
        int tRowLength = grid.size();
        int tColLength = grid[0].size();
        int tCounter = 0;

        for (std::size_t i = 0; i < tRowLength; ++i)
        {
            for (std::size_t j = 0; j < tColLength; ++j)
            {
                if (grid[i][j] == '1')
                {
                    tCounter += islandDfs(grid, i, j);
                }
            }
        }
        return tCounter;    
    }

    int islandDfs(vector<vector<char>>& grid, int aRow, int aCol)
    {
        int tRowLength = grid.size();
        int tColLength = grid[0].size();

        // Most important base cases are in bounds
        if (std::min(aRow, aCol) < 0)
        {
            return 0;
        }

        if (aRow > tRowLength - 1 || aCol > tColLength - 1)
        {
            return 0;
        }

        if (grid[aRow][aCol] == '0')
        {
            return 0;
        }

        if (grid[aRow][aCol] == '1')
        {
            grid[aRow][aCol] = '0';
        }

        islandDfs(grid, aRow + 1, aCol);
        islandDfs(grid, aRow - 1, aCol);
        islandDfs(grid, aRow, aCol + 1);
        islandDfs(grid, aRow, aCol - 1);

        return 1;
    }
};
