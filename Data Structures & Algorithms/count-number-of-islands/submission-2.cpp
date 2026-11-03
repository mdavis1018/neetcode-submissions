class Solution {
public:
    int numIslands(vector<vector<char>>& aGrid) 
    {
        int tRowLength = aGrid.size();
        int tColLength = aGrid[0].size();
        int tNumOfIslands = 0;

        for (int i = 0; i < tRowLength; ++i)
        {
            for (int j = 0; j < tColLength; ++j)
            {
                if (aGrid[i][j] == '1')
                {
                    ++tNumOfIslands;
                    dfs(aGrid, i, j);
                }
            }
        }

        return tNumOfIslands;
    }

    // void bfs()

    void dfs(vector<vector<char>>& aGrid, int aRow, int aCol)
    {
        // Safety
        int tRowLength = aGrid.size();
        int tColLength = aGrid[0].size();

        if (std::min(aRow, aCol) < 0)
        {
            return;
        }

        if (aRow >= tRowLength || aCol >= tColLength)
        {
            return;
        }

        // Do nothing with 0

        if (aGrid[aRow][aCol] == '0')
        {
            return;
        }
        else 
        {
            aGrid[aRow][aCol] = '0';
        }

        dfs(aGrid, aRow + 1, aCol);
        dfs(aGrid, aRow - 1, aCol);
        dfs(aGrid, aRow, aCol + 1);
        dfs(aGrid, aRow , aCol - 1);
    }
};
