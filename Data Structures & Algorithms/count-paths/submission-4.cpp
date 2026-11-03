class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        std::vector<std::vector<int>> tGrid(m, std::vector<int>(n, 0));
        return dp(tGrid); 
    }

    int dp(std::vector<std::vector<int>> &aGrid)
    {
        std::vector<int> tPrevRow = std::vector(aGrid[0].size(), 0);

        for (int i = aGrid.size() - 1; i >= 0; --i)
        {
            for (int j = aGrid[i].size() - 1; j>=0;--j)
            {
                if (i == aGrid.size() - 1 && j == aGrid[0].size() - 1)
                {
                    aGrid[i][j] = 1;
                }
                else 
                {
                    if (j + 1 >= aGrid[0].size())
                    {
                        aGrid[i][j] = tPrevRow[j];
                    }
                    else 
                    {
                        aGrid[i][j] = tPrevRow[j] + aGrid[i][j+1];
                    }
                }
            }

            tPrevRow = aGrid[i];
        }

        return aGrid[0][0];
    }


    int memoization(int aRow, int aCol, std::vector<std::vector<int>> &aGrid)
    {
        if (aRow >= aGrid.size() || aCol >= aGrid[0].size())
        {
            return 0;
        }

        if (aGrid[aRow][aCol] != 0)
        {
            return aGrid[aRow][aCol];
        }

        if (aRow == aGrid.size() - 1 && aCol == aGrid[0].size() - 1)
        {
            return 1;
        }


        aGrid[aRow][aCol] = memoization(aRow + 1, aCol, aGrid) + memoization(aRow, aCol + 1, aGrid);
        return aGrid[aRow][aCol];
    }
};
