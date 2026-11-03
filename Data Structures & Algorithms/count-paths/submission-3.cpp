class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        std::vector<std::vector<int>> tGrid(m, std::vector<int>(n, 0));
        return memoization(0,0,tGrid); 
    }

    int dp(std::vector<std::vector<int>> &aGrid)
    {
        std::vector<int> tPrevRow = std::vector(aGrid[0].size(), 0);

        int tIndex = aGrid.size() - 1;

        while (tIndex >= 0)
        {   
            for (int i = aGrid.at(tIndex).size() - 1; i >= 0; --i)
            {
                if ((i + 1) < aGrid.at(tIndex).size())
                {
                    aGrid.at(tIndex).at(i) = tPrevRow.at(i) + aGrid.at(tIndex).at(i + 1);
                }
                else
                {
                    aGrid.at(tIndex).at(i) = tPrevRow.at(i);
                }
            }

            tPrevRow = aGrid.at(tIndex);
            --tIndex;
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
