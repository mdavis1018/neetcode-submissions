class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        return dp(obstacleGrid);
    }

    int dp(vector<vector<int>>& aGrid)
    {
        if (aGrid[aGrid.size() - 1][aGrid[0].size() - 1] == 1)
        {
            return 0;
        }

        auto tPrevRow = std::vector<int>(aGrid[0].size(), 0);
        for (int tRowIndex = aGrid.size() - 1; tRowIndex >= 0; --tRowIndex)
        {
            auto tMaintainRow = aGrid[tRowIndex];
            for (int tColIndex = aGrid[0].size() - 1; tColIndex >= 0; --tColIndex)
            {

                // If we are at the start position just set to 1
                if (tRowIndex == aGrid.size() - 1 && tColIndex == aGrid[0].size() - 1)
                {
                    tMaintainRow[tColIndex] = 1;
                }
                // If the current index is a block then set to 0                
                else if (tMaintainRow[tColIndex] == 1)
                {
                    tMaintainRow[tColIndex] = 0;
                }
                // if we are at the right-most then only take underneath
                else if (tColIndex + 1 >= aGrid[0].size())
                {
                    tMaintainRow[tColIndex] = tPrevRow[tColIndex];
                }
                else 
                {
                    // Take underneath + right
                    tMaintainRow[tColIndex] = tMaintainRow[tColIndex + 1] + tPrevRow[tColIndex];
                }
            }
            tPrevRow = tMaintainRow;
        } 

        return tPrevRow.front();
    }


    int dfs(vector<vector<int>>& obstacleGrid, int aRow, int aCol)
    {
        if (aRow > obstacleGrid.size() - 1 || aCol > obstacleGrid[0].size() - 1)
        {
            return 0;
        }

        if (obstacleGrid[aRow][aCol] == 1)
        {
            return 0;
        }

        if (aRow == obstacleGrid.size() - 1 && aCol == obstacleGrid[0].size() - 1)
        {
            return 1;
        }

        return dfs(obstacleGrid, aRow + 1, aCol) + dfs(obstacleGrid, aRow, aCol + 1);
    }
};