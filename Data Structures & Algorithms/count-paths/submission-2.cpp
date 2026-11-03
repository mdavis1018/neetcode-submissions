class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        std::vector<std::vector<int>> tGrid(m, std::vector<int>(n, 0));
        return memoization(0,0,tGrid); 
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
